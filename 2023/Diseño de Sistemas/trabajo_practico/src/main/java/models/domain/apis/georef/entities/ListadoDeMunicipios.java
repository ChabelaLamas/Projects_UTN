package models.domain.apis.georef.entities;

import models.domain.main.localizacion.Localizacion;
import lombok.Getter;

import java.util.List;

public class ListadoDeMunicipios {
  @Getter
  public List<Localizacion> municipios;
}