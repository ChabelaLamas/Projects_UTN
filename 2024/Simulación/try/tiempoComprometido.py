import pandas as pd
import numpy as np
from datetime import datetime
from scipy import stats
import matplotlib.pyplot as plt
import re


# Variables globales
global m, s, u
global ntm, nts, ntu
global t, tpi, tf

global ptom, stom
global ptos, stos
global ptou, stou

global ppsm, stem
global ppss, stes
global ppsu, steu

global perm, pers, peru
global sts, stu, stm


# Inicializar variables globales
ntm = nts = ntu = 0
t = tpi = 0
tf = 1000000

ptom = stom = 0
ptos = stos = 0
ptou = stou = 0

ppsm = stem = 0
ppss = stes = 0
ppsu = steu = 0

perm = pers = peru = 0
sts = stu = stm = 0


def optimize_kde(kde, num_points=1000, max_time=120):
    """
    Precompute KDE values for faster sampling.
    """
    x_range = np.linspace(0, max_time, num_points)
    density_values = kde(x_range)
    density_values /= np.sum(density_values)
    return x_range, density_values


def is_time_format(s):
    if not isinstance(s, str):
        return False
    if len(s) != 5:
        return False
    if s[2] != ':':
        return False
    hours, minutes = s.split(':')
    if not (hours.isdigit() and minutes.isdigit()):
        return False
    if not (0 <= int(hours) <= 23 and 0 <= int(minutes) <= 59):
        return False
    return True


def classify_time_of_day(datetime_obj):
    hour = datetime_obj.hour
    if 6 <= hour < 12:  # 6:00 a 11:59
        return 'Morning'
    elif 12 <= hour < 16:  # 12:00 a 15:59
        return 'Midday'
    elif 16 <= hour < 20:  # 16:00 a 19:59
        return 'Afternoon'
    else:  # 20:00 a 23:59 y 0:00 a 5:59
        return 'Night'


def load_and_preprocess_data(file_path):
    df = pd.read_csv(file_path)
    df = df.drop(['multiple_deliveries', 'Vehicle_condition', 'Type_of_order', 'Delivery_location_longitude',
                  'Festival', 'Road_traffic_density', 'Delivery_person_Ratings', 'Restaurant_latitude', 'Restaurant_longitude',
                  'Weather_conditions', 'Delivery_location_latitude', 'Delivery_person_Age', 'ID', 'Type_of_vehicle'], axis=1)
    
    # Eliminar espacios en blanco y filtrar las filas en las que Time_Orderd tiene un formato de hora válido
    df['Time_Orderd'] = df['Time_Orderd'].astype(str).str.strip()
    df = df[df['Time_Orderd'].apply(is_time_format)].copy()
    
    # Convertir Time_Orderd en datetime.time
    df['Time_Orderd'] = pd.to_datetime(df['Time_Orderd'], format='%H:%M').dt.time
    df['Order_Date'] = pd.to_datetime(df['Order_Date'], format='%d-%m-%Y')

    df['DateTime'] = df.apply(lambda row: datetime.combine(row['Order_Date'], row['Time_Orderd']), axis=1)
    df = df.sort_values('DateTime')
    df['Time_Between_Orders'] = df['DateTime'].diff().dt.total_seconds() / 60
    df = df.dropna(subset=['Time_Between_Orders'])

    # Clasificar franjas horarias y agregar columna 'Time_of_Day'
    df['Time_of_Day'] = df['DateTime'].apply(classify_time_of_day)

    return df


def calculate_kde_arrivals(df):
    morning_df = df[df['Time_of_Day'] == 'Morning']
    midday_df = df[df['Time_of_Day'] == 'Midday']
    afternoon_df = df[df['Time_of_Day'] == 'Afternoon']
    night_df = df[df['Time_of_Day'] == 'Night']

    ip_manana = stats.gaussian_kde(morning_df['Time_Between_Orders'])
    ip_mediodia = stats.gaussian_kde(midday_df['Time_Between_Orders'])
    ip_tarde = stats.gaussian_kde(afternoon_df['Time_Between_Orders'])
    ip_noche = stats.gaussian_kde(night_df['Time_Between_Orders'])

    ip_manana_x, ip_manana_density = optimize_kde(ip_manana)
    ip_mediodia_x, ip_mediodia_density = optimize_kde(ip_mediodia)
    ip_tarde_x, ip_tarde_density = optimize_kde(ip_tarde)
    ip_noche_x, ip_noche_density = optimize_kde(ip_noche)
    
    ip_config = {
    "manana": (ip_manana_x, ip_manana_density),
    "mediodia": (ip_mediodia_x, ip_mediodia_density),
    "tarde": (ip_tarde_x, ip_tarde_density),
    "noche": (ip_noche_x, ip_noche_density),
    }

    return ip_config


def calculate_kde_delivery(df):
    morning_df = df[df['Time_of_Day'] == 'Morning']
    midday_df = df[df['Time_of_Day'] == 'Midday']
    afternoon_df = df[df['Time_of_Day'] == 'Afternoon']
    night_df = df[df['Time_of_Day'] == 'Night']

    te_manana = stats.gaussian_kde(morning_df['Time_taken (min)'])
    te_mediodia = stats.gaussian_kde(midday_df['Time_taken (min)'])
    te_tarde = stats.gaussian_kde(afternoon_df['Time_taken (min)'])
    te_noche = stats.gaussian_kde(night_df['Time_taken (min)'])

    te_manana_x, te_manana_density = optimize_kde(te_manana)
    te_mediodia_x, te_mediodia_density = optimize_kde(te_mediodia)
    te_tarde_x, te_tarde_density = optimize_kde(te_tarde)
    te_noche_x, te_noche_density = optimize_kde(te_noche)

    te_config = {
    "manana": (te_manana_x, te_manana_density),
    "mediodia": (te_mediodia_x, te_mediodia_density),
    "tarde": (te_tarde_x, te_tarde_density),
    "noche": (te_noche_x, te_noche_density),
    }
    
    return te_config


def time_for_fdp_optimized(x_range, density_values):
    """
    Optimized version of time_for_fdp using precomputed values.
    """
    return np.random.choice(x_range, p=density_values)


def calculate_time_for_part_of_the_day (part_of_the_day, config):
    x, density = config[part_of_the_day]
    return time_for_fdp_optimized(x, density)


def order_arrival(nt, part_of_the_day, te_config, tc, sto, ste, st):
    global t
    nt += 1
    te = calculate_time_for_part_of_the_day(part_of_the_day, te_config) # Calcular el tiempo de entrega
    i = np.argmin(tc) # Buscar repartidor con menor tiempo comprometido

    if t >= tc[i]:
        sto += t - tc[i]
        tc[i] = t + te
    else:
        ste += tc[i] - t
        tc[i] += te
    
    st += tc[i] - t

    return (nt, sto, ste, st)


def input_valid_part_of_a_day():
    parts_of_a_day = ["manana", "mediodia", "tarde", "noche"]
    while True:
        part_of_the_day = input("Introduce una parte del día: ").strip().lower()
        if part_of_the_day in parts_of_a_day:
            return part_of_the_day
        print("Entrada no válida. Por favor, introduce una parte del día válida.")


def input_delivery_personnel(zone):
    return int(input(f"Ingrese la cantidad de repartidores de la zona {zone}: "))


def simulation(ip_config, te_config):
    global m, s, u
    global ntm, nts, ntu
    global t, tpi, tf

    global stom, stos, stou
    global stem, stes, steu
    global sts, stu, stm

    m = input_delivery_personnel("Metropolitana")
    u = input_delivery_personnel("Urbana")
    s = input_delivery_personnel("Semi-Urbana")
    part_of_the_day = input_valid_part_of_a_day()

    tcm = np.full(m, 0)
    tcu = np.full(u, 0)
    tcs = np.full(s, 0)
    
    while t < tf:        
        t = tpi
        ip = calculate_time_for_part_of_the_day(part_of_the_day, ip_config) # Calcular el intervalo de tiempo para el arribo del próximo pedido
        tpi = t + ip

        # Identificar la zona del pedido entrante
        r = np.random.random()
        if r <= 0.768:
            ntm, stom, stem, stm = order_arrival(ntm, part_of_the_day, te_config, tcm, stom, stem, stm)
        elif r <= 0.996:
            ntu, stou, steu, stu = order_arrival(ntu, part_of_the_day, te_config, tcu, stou, steu, stu)
        else:
            nts, stos, stes, sts = order_arrival(nts, part_of_the_day, te_config, tcs, stos, stes, sts)
    
    # Verificar si hay repartidores ociosos
    for tc in tcs:
        if tc < t:
            stos += t - tc
    for tc in tcm:
        if tc < t:
            stom += t - tc
    for tc in tcu:
        if tc < t:
            stou += t - tc

    print(f"Parte del dia: {part_of_the_day}")


def calcular_y_mostrar_resultados():
    global stom, stos, stou
    global stm, sts, stu
    global ntm, nts, ntu
    global stem, stes, steu
    global t, m, s, u

    print(f"M = {m}, S = {s}, U = {u}")
    print(f"Total de pedidos en la zona metropolitana: {ntm}")
    print(f"Total de pedidos en la zona semi-urbana: {nts}")
    print(f"Total de pedidos en la zona urbana: {ntu}")

    print(f"Porcentaje de tiempo ocioso de repartidores en la zona metropolitana: {round((stom / (t*m)) * 100, 4)} %")
    print(f"Porcentaje de tiempo ocioso de repartidores en la zona semi-urbana: {round((stos / (t*s)) * 100, 4)} %")
    print(f"Porcentaje de tiempo ocioso de repartidores en la zona urbana: {round((stou / (t*u)) * 100, 4)} %")

    print(f"Promedio de permanencia en sistema en la zona metropolitana: {stm / ntm:.2f} minutos")
    print(f"Promedio de permanencia en sistema en la zona semi-urbana: {sts / nts:.2f} minutos")
    print(f"Promedio de permanencia en sistema en la zona urbana: {stu / ntu:.2f} minutos")

    print(f"Promedio de espera hasta que un pedido es atendido por un repartidor en la zona metropolitana: {stem / ntm:.2f} minutos")
    print(f"Promedio de espera hasta que un pedido es atendido por un repartidor en la zona semi-urbana: {stes / nts:.2f} minutos")
    print(f"Promedio de espera hasta que un pedido es atendido por un repartidor en la zona urbana: {steu / ntu:.2f} minutos")


if __name__ == "__main__":
    df = load_and_preprocess_data('zomato-dataset.csv')
    ip_config = calculate_kde_arrivals(df)
    te_config = calculate_kde_delivery(df)
    simulation(ip_config, te_config)
    calcular_y_mostrar_resultados()