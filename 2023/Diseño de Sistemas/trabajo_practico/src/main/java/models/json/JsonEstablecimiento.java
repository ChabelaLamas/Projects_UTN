package models.json;

import lombok.Getter;
import lombok.Setter;

import java.util.List;
@Getter @Setter
public class JsonEstablecimiento {
  private String denominacion;
  private Long entidad;
  private Long localidad;
  private List<Long> prestaciones;
}
