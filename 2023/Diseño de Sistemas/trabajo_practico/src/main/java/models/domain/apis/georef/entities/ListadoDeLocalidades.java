package models.domain.apis.georef.entities;

import models.domain.main.localizacion.Localidad;
import lombok.Getter;

import java.util.List;

public class ListadoDeLocalidades {
  @Getter
  public List<Localidad> localidades;
}
