package models.json;

import lombok.Getter;
import lombok.Setter;

import java.util.List;

@Getter @Setter
public class JsonComunidad {
  private String nombre;
  private String denominacion;
  private List<Long> servicios;
  private List<Long> establecimientos;

}
