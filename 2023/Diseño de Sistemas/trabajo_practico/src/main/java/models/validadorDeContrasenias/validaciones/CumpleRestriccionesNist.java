package models.validadorDeContrasenias.validaciones;

import java.util.ArrayList;
import java.util.List;

import models.validadorDeContrasenias.excepciones.ExcepcionContraseniaInvalida;
import models.validadorDeContrasenias.validaciones.Validacion;
import models.validadorDeContrasenias.validaciones.restriccionesNist.CumpleComplejidad;
import models.validadorDeContrasenias.validaciones.restriccionesNist.CumpleLongitud;
import models.validadorDeContrasenias.validaciones.restriccionesNist.CumpleRotacion;
import models.validadorDeContrasenias.validaciones.restriccionesNist.RestriccionNist;

public class CumpleRestriccionesNist implements Validacion {
  private final List<RestriccionNist> restricciones = new ArrayList<>();

  public CumpleRestriccionesNist() {
    this.agregarRestriccionesNist();
  }

  public void agregarRestriccionesNist() {
    restricciones.add(new CumpleRotacion());
    restricciones.add(new CumpleComplejidad());
    restricciones.add(new CumpleLongitud());
  }

  public boolean validarContrasenia(String nombre, String contrasenia) throws ExcepcionContraseniaInvalida {
    return restricciones.stream().allMatch(restriccion ->
        restriccion.cumpleRestriccion(contrasenia));
  }
}