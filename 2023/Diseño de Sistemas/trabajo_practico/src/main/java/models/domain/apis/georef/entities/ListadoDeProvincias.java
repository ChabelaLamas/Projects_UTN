package models.domain.apis.georef.entities;

import models.domain.main.localizacion.Provincia;
import lombok.Getter;

import java.util.List;

public class ListadoDeProvincias {
  @Getter
  public List<Provincia> provincias;
}