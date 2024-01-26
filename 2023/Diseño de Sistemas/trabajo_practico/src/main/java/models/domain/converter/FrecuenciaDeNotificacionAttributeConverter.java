package models.domain.converter;

import models.domain.main.notificaciones.frecuenciasNotificacion.FrecuenciaNotificacion;
import models.domain.main.notificaciones.frecuenciasNotificacion.NotificacionCuandoSucedeIncidente;
import models.domain.main.notificaciones.frecuenciasNotificacion.NotificacionSinApuros;

import javax.persistence.AttributeConverter;
import javax.persistence.Converter;

@Converter(autoApply = true)
public class FrecuenciaDeNotificacionAttributeConverter implements AttributeConverter<FrecuenciaNotificacion, String> {

  // Convertir la entidad FrecuenciaNotificacion a su representación en la base de datos.
  @Override
  public String convertToDatabaseColumn(FrecuenciaNotificacion frecuenciaNotificacion) {
    if (frecuenciaNotificacion == null) {
      return null;
    }

    if (frecuenciaNotificacion instanceof NotificacionCuandoSucedeIncidente) {
      return "Cuando sucede";
    }

    if (frecuenciaNotificacion instanceof NotificacionSinApuros) {
      return "Sin apuros";
    }

    // Si no es ninguno de los tipos esperados, lanzamos una excepción
    throw new IllegalArgumentException("Tipo de FrecuenciaNotificacion desconocido: " + frecuenciaNotificacion.getClass().getSimpleName());
  }

  // Convertir la representación en cadena de la base de datos a la entidad FrecuenciaNotificacion.
  @Override
  public FrecuenciaNotificacion convertToEntityAttribute(String frecuencia) {
    if (frecuencia == null) {
      return null;
    }

    switch (frecuencia) {
      case "Cuando sucede":
        return new NotificacionCuandoSucedeIncidente();
      case "Sin apuros":
        return new NotificacionSinApuros();
      default:
        // Si no es ninguna de las cadenas esperadas, lanzamos una excepción
        throw new IllegalArgumentException("Valor de columna desconocido para FrecuenciaNotificacion: " + frecuencia);
    }
  }
}
