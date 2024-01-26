package models.validadorDeContrasenias.validaciones;

import models.validadorDeContrasenias.excepciones.ExcepcionCredencial;
import models.validadorDeContrasenias.validaciones.Validacion;

public class CredencialesPorDefecto implements Validacion {
  public boolean validarContrasenia(String nombre, String contrasenia) throws ExcepcionCredencial {
    if (nombre.equals(contrasenia)) {
      throw new ExcepcionCredencial("El nombre y la contrasenia deben ser distintos");
    }
    return true;
  }
}
