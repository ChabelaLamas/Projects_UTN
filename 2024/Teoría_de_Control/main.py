import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from utils import get_double, get_deviations

# Parametros fijos de la simulación
time_step = 1  # Paso de tiempo en minutos
total_time = 300  # Tiempo total de la simulación en minutos

# Parámetros variables de la simulación

# Temperatura deseada (grados Celsius) (setpoint de 22 grados se uso en simulación)
set_point = get_double("Ingrese la temperatura deseada (set point) en grados Celsius: ",18, 23)
# Temperatura inicial de la habitación (grados Celsius) (t0 de 26 grados se uso en simulación)
initial_temperature = get_double("Ingrese la temperatura inicial de la habitación en grados Celsius: ", 10, 40)

deviations = get_deviations()

# Coeficientes del controlador PID ajustados
Kp = 0.2
Ki = 0.01
Kd = 0.005

# Restricción en la cantidad máxima de enfriamiento
max_cooling_rate = -0.2  # Grados Celsius por minuto. Se tuvo en cuenta este límite para que no se pase del valor nominal, ya que en este caso no se puede aumentar la temperatura.

# Inicialización de variables
temperature = initial_temperature
integral = 0
previous_error = set_point - temperature
temperatures = [temperature]
times = [0]

# Inicialización de variables para el compresor y la válvula
compressor_speed = [0]  # Velocidad del compresor
valve_opening = [1]     # Apertura de la válvula (1 = completamente abierta, 0 = completamente cerrada)

for t in range(1, total_time + 1):
    # Aplicar desviación si corresponde
    if deviations and t >= deviations[0][0]:
        deviation = deviations.pop(0)
        temperature = temperature + deviation[1]
    
    error = set_point - temperature
    integral += error * time_step
    derivative = (error - previous_error) / time_step
    
    # Salida del controlador PID
    control_signal = Kp * error + Ki * integral + Kd * derivative
    
    # Limitar la cantidad máxima de enfriamiento
    control_signal = max(control_signal, max_cooling_rate)
    
    # Anti-reset windup: Evitar acumulación del término integral
    if control_signal == max_cooling_rate:
        integral -= error * time_step
    
    # Actualización de la temperatura (modelo simple)
    temperature += control_signal * time_step
    temperatures.append(temperature)
    times.append(t)
    
    previous_error = error
    
    # Actualización de la velocidad del compresor y la apertura de la válvula
    compressor_speed.append(abs(control_signal) / abs(max_cooling_rate))  # Normalizado entre 0 y 1
    valve_opening.append(1 - (abs(control_signal) / abs(max_cooling_rate)))  # Inverso del control signal

# Creación del DataFrame para análisis
data = pd.DataFrame({
    'Tiempo (min)': times,
    'Temperatura (°C)': temperatures,
    'Velocidad del compresor': compressor_speed,
    'Apertura de la válvula': valve_opening
})

# Análisis y gráficos
plt.figure(figsize=(15, 10))

# Gráfico de temperatura
plt.subplot(3, 1, 1)
plt.plot(data['Tiempo (min)'], data['Temperatura (°C)'], label='Temperatura de la habitación')
plt.axhline(y=set_point, color='r', linestyle='--', label='Temperatura deseada')
plt.xlabel('Tiempo (min)')
plt.ylabel('Temperatura (°C)')
plt.title('Simulación de Control de Temperatura de un Aire Acondicionado (Solo Frío)')
plt.legend()
plt.grid(True)

# Gráfico de velocidad del compresor
plt.subplot(3, 1, 2)
plt.plot(data['Tiempo (min)'], data['Velocidad del compresor'], label='Velocidad del compresor')
plt.xlabel('Tiempo (min)')
plt.ylabel('Velocidad del compresor (normalizado)')
plt.legend()
plt.grid(True)

# Gráfico de apertura de la válvula
plt.subplot(3, 1, 3)
plt.plot(data['Tiempo (min)'], data['Apertura de la válvula'], label='Apertura de la válvula')
plt.xlabel('Tiempo (min)')
plt.ylabel('Apertura de la válvula (normalizado)')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()

# Análisis de los resultados
print("Temperatura final de la habitación: {:.2f} °C".format(temperatures[-1]))
print("Tiempo total de la simulación: {} minutos".format(total_time))
print("Temperatura deseada: {} °C".format(set_point))
print("\nResumen de desviaciones:")
print(data.describe())
