package models.domain.main.notificaciones.mediosNotificacion.Email;

import models.domain.main.notificaciones.frecuenciasNotificacion.Notificacion;


public interface EmailAdapter {
  void mandar(Notificacion notificacion);
}
