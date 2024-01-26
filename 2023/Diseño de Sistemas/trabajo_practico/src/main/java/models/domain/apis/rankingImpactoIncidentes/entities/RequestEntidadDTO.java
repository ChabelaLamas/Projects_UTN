package models.domain.apis.rankingImpactoIncidentes.entities;

import lombok.Getter;

@Getter
public class RequestEntidadDTO {
  public Integer idEntidad;
  public Integer sumatoriaTiemposResolucion;
  public Integer cantidadIncidentesNoResueltos;
  public Integer cantidadMiembrosAfectados;
}