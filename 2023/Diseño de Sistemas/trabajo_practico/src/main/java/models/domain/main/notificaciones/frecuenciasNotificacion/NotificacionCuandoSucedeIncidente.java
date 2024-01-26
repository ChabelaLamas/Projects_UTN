package models.domain.main.notificaciones.frecuenciasNotificacion;

import models.domain.main.incidentes.Incidente;
import models.domain.main.notificaciones.Notificador;
import models.domain.usuarios.Persona;


public class NotificacionCuandoSucedeIncidente implements FrecuenciaNotificacion {

  public void gestionarInicidente(Persona persona, Incidente incidente) {
    Notificacion notificacion = new Notificacion(persona, incidente, false);
    Notificador.obtenerInstancia().enviarNotificacion(notificacion);
  }

}
