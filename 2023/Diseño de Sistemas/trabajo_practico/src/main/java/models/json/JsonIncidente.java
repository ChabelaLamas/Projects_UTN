package models.json;

import lombok.Getter;
import lombok.Setter;

@Getter @Setter
public class JsonIncidente {
  private Long prestacion_id;
  private String incidente_denominacion;
  private String incidente_observaciones;
  private Long comunidad_id;
}
