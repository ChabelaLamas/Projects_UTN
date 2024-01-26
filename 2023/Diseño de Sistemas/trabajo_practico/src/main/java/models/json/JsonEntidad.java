package models.json;

import lombok.Getter;
import lombok.Setter;

@Getter@Setter
public class JsonEntidad {
  private String denominacion;
  private String tipoEntidad;
  private String tipoEstablecimiento;
  private Long entidadPrestadoraId;

}
