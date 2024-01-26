# API de Sugerencias y Fusiones para Monitoreo de Transporte Público

![Versión](https://img.shields.io/badge/Versión-1.0.0-brightgreen)
![OpenAPI](https://img.shields.io/badge/OpenAPI-3.0-blue)

Esta API proporciona funcionalidades para sugerir y realizar fusiones de comunidades en un sistema de monitoreo del estado de servicios de transporte público y establecimientos relacionados.

## Tabla de Contenidos

- [Descripción](#descripción)
- [Características](#características)
- [Documentación](#documentación)
- [Uso](#uso)


## Descripción

Esta API está diseñada para facilitar la colaboración y el seguimiento de comunidades relacionadas con el transporte público y los establecimientos que ofrecen estos servicios. Permite a los usuarios sugerir cambios, mejoras y fusiones para garantizar un monitoreo eficiente y actualizado del estado de estos servicios.
**Tras la creación de una fusión entre dos comunidades, el identificador de ésta se establecerá en cero, permitiendo que el receptor actualice el valor de manera acorde a su contexto.**

## Características

- Sugerir fusiones de datos de comunidades relacionadas.
- Realizar fusiones de datos de comunidades relacionadas.
- API basada en OpenAPI 3.0.
- Fácil integración con otras aplicaciones y sistemas.
- Documentación completa para desarrolladores.

## Documentación

Para obtener información detallada sobre cómo utilizar esta API, consulta nuestra [documentación](https://app.swaggerhub.com/apis/LSANGRONI/API_Fusion_Comunidades/1.0.0).

## Uso

A continuación, se muestra un ejemplo básico de cómo usar la API:

```bash
# Ejemplo de solicitud API
POST http://localhost:8080 -d '{
  "comunidades": [
    {
        "id": 1,
        "idEstablecimientoObservados": [1, 2, 3, 4],
        "idServiciosObservados": [1, 2, 3, 4],
        "gradoDeConfianza": 1,
        "idMiembros": [1, 2, 3, 4],
        "estado": "ACTIVADA"
    },
    {
        "id": 2,
        "idEstablecimientoObservados": [1, 2, 3, 5],
        "idServiciosObservados": [1, 2, 3, 5],
        "gradoDeConfianza": 1,
        "idMiembros": [1, 2, 3, 5],
        "estado": "ACTIVADA"
    },
    {
        "id": 3,
        "idEstablecimientoObservados": [2],
        "idServiciosObservados": [2],
        "gradoDeConfianza": 2,
        "idMiembros": [2],
        "estado": "ACTIVADA"
    },
    {
        "id": 4,
        "idEstablecimientoObservados": [2],
        "idServiciosObservados": [2],
        "gradoDeConfianza": 2,
        "idMiembros": [2],
        "estado": "ACTIVADA"
    }
  ],
  "fusiones": [
      {
            "estado": "ACEPTADA",
            "comunidad1": {
                "id": 1,
                "idEstablecimientoObservados": [
                    1,
                    2,
                    3,
                    4
                ],
                "idServiciosObservados": [
                    1,
                    2,
                    3,
                    4
                ],
                "gradoDeConfianza": 1,
                "idMiembros": [
                    1,
                    2,
                    3,
                    4
                ]
            },
            "comunidad2": {
                "id": 2,
                "idEstablecimientoObservados": [
                    1,
                    2,
                    3,
                    5
                ],
                "idServiciosObservados": [
                    1,
                    2,
                    3,
                    5
                ],
                "gradoDeConfianza": 1,
                "idMiembros": [
                    1,
                    2,
                    3,
                    5
                ]
            },
            "fechaCreada": "2023-09-07T17:14:25.5677323"
        }
  ]
}'
