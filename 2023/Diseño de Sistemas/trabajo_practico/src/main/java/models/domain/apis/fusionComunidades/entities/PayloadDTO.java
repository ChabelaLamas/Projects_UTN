package models.domain.apis.fusionComunidades.entities;

import lombok.Getter;

import java.util.List;

@Getter
public class PayloadDTO {
  public List<ComunidadMolde> comunidades;
  public List<FusionMolde> fusiones;
}
