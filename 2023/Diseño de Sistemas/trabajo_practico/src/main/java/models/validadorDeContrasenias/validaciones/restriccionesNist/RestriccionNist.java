package models.validadorDeContrasenias.validaciones.restriccionesNist;

import models.validadorDeContrasenias.excepciones.ExcepcionContraseniaInvalida;

public interface RestriccionNist {
  boolean cumpleRestriccion(String contrasenia) throws ExcepcionContraseniaInvalida;
}
