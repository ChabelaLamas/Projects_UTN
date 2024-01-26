package models.domain.apis.georef.entities;

import models.domain.main.localizacion.Localizacion;
import lombok.Getter;

import java.util.List;

public class ListadoDeDepartamentos {
  @Getter
  public List<Localizacion> departamentos;
}
