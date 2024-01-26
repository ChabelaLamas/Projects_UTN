package models.domain.apis.fusionComunidades.entities;

import java.time.LocalDateTime;

public class FusionMolde {
  public EstadoFusion estado;
  public ComunidadMolde comunidad1;
  public ComunidadMolde comunidad2;
  public LocalDateTime fechaCreada;

  public enum EstadoFusion {
    PROPUESTA,
    ACEPTADA,
    RECHAZADA
  }
}
