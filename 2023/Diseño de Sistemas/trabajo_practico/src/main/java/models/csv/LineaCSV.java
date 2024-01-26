package models.csv;

import lombok.Getter;

@Getter
public class LineaCSV {
  private final String denominacion;
  private final String tipo;
  private final String nombreDelegado;
  private final String emailDelegado;

  public LineaCSV(String denominacion, String tipo, String nombreDelegado, String emailDelegado) {
    this.denominacion = denominacion;
    this.tipo = tipo;
    this.nombreDelegado = nombreDelegado;
    this.emailDelegado = emailDelegado;
  }
}
