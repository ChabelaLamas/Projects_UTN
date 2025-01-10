def get_double(prompt, min, max):
    while True:
        try:
            value = float(input(prompt))
            if not (min <= value <= max):
                raise ValueError()
            return value
        except ValueError:
            print(f"Por favor, ingrese un número válido float entre {min} y {max} grados Celcius.")

# Función para obtener una lista de tuplas de desviaciones del usuario
def get_deviations():
    print()
    deviations = []
    print("Ingrese las desviaciones")
    while True:
        time = input(f"Ingrese el tiempo de la desviacion {len(deviations)+1}(o 'done' para terminar o 'default' para un set por defecto): ")
        if time.lower() == 'done':
            break
        elif time.lower() == 'default':
            deviations = [(100, 0.5), (240, 0.3)]
            break
        try:
            time = float(time)
        except ValueError:
            print("Por favor, ingrese un número válido.")
            continue
        
        temperature = input(f"Ingrese la variacion de temperatura {len(deviations)+1}: ")
        try:
            temperature = float(temperature)
        except ValueError:
            print("Por favor, ingrese un número válido.")
            continue

        deviations.append((time, temperature))
    return deviations


