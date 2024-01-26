package models.validadorDeContrasenias.validaciones;

import models.validadorDeContrasenias.excepciones.ExcepcionContraseniaInvalida;

public interface Validacion {
  boolean validarContrasenia(String nombre, String contrasenia) throws ExcepcionContraseniaInvalida;
}
