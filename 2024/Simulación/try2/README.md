# Simulación de Sistema de Delivery

Este repositorio contiene los archivos necesarios para ejecutar una simulación de un sistema de delivery que optimiza la cantidad de repartidores por zona, maximizando la capacidad de entrega diaria y minimizando los tiempos de espera. A continuación, se describen los archivos incluidos en el proyecto:

## Contenido del Repositorio

- **`zomato-dataset.csv`**: Dataset utilizado en la simulación, que incluye los datos de pedidos por zona y días de la semana.
  
- **`Grupo 9 - Paper.pdf`**: Documento que explica el desarrollo completo de la simulación, su enfoque y los resultados obtenidos.

- **`Grupo 9 - Diagrama.png`**: Diagrama visual que representa el flujo de la simulación, incluyendo las variables clave y la lógica implementada.
  
- **`Grupo 9 - Presentación.pdf`**: Presentación que se va a uitilizar para la exposición del trabajo practico.

- **`requirements.txt`**: Archivo que contiene las dependencias necesarias para ejecutar el código de simulación.

- **`main.py`**: Script principal que ejecuta la simulación. Incluye la carga de datos, la lógica de optimización y los cálculos de tiempos de espera y ociosidad de los repartidores.

## Instalación y Ejecución

Para ejecutar el proyecto, sigue los siguientes pasos:

1. Clona el repositorio en tu máquina local:

   ```bash
   git clone https://github.com/usuario/proyecto-simulacion.git
   ```
2. Navega a la carpeta del proyecto:

   ```bash
    cd proyecto-simulacion
   ```
3. Instala las dependencias necesarias ejecutando el siguiente comando:
    ```bash
      pip install -r requirements.txt
     ```
4. Ejecuta la simulación:

    ```bash
      python main.py
     ```
## Visualización de Resultados

Puedes encontrar el análisis completo de la simulación en el archivo PDF del paper:

[Grupo 9 - Paper.pdf](./Grupo%209%20-%20Paper.pdf)

También puedes encontrar la presentación utilizada para exponer el trabajo práctico en el archivo:

[Grupo 9 - Presentación.pdf](./Grupo%209%20-%20Presentación.pdf)

Además, el siguiente diagrama muestra gráficamente el flujo de la simulación:

![Diagrama de Simulación](./Grupo%209%20-%20Diagrama.png)

## Conclusión

La simulación realizada demuestra cómo la correcta asignación de repartidores según la zona geográfica y los días de la semana puede optimizar los recursos y reducir los tiempos de espera. El balance entre el tiempo de ocio de los repartidores y la experiencia del cliente es clave para lograr un sistema eficiente y rentable.

A través de la simulación, se obtuvieron configuraciones específicas para cada escenario, permitiendo una mejor toma de decisiones operativas, especialmente en días de alta demanda. Esto ofrece una guía clara para optimizar tanto los costos operativos como la calidad del servicio.

Para más detalles, consulta el [paper completo](./Grupo%209%20-%20Paper.pdf) y el [diagrama de simulación](./Grupo%209%20-%20Diagrama.png).
