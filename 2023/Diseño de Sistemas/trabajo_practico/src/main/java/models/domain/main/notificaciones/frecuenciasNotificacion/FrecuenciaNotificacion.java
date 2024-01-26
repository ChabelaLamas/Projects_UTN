package models.domain.main.notificaciones.frecuenciasNotificacion;

import models.domain.main.incidentes.Incidente;
import models.domain.usuarios.Persona;


public interface FrecuenciaNotificacion {
  void gestionarInicidente (Persona persona, Incidente incidente);
}
