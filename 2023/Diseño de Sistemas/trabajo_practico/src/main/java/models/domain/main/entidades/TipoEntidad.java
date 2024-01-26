package models.domain.main.entidades;

import lombok.Getter;

import javax.persistence.Embeddable;

@Getter
@Embeddable
public class TipoEntidad {
  private String tipoEntidad;
  private String tipoEstablecimiento;

  public TipoEntidad(String tipoEntidad, String tipoEstablecimiento) {
    this.tipoEntidad = tipoEntidad;
    this.tipoEstablecimiento = tipoEstablecimiento;
  }

  public TipoEntidad() {

  }
}
