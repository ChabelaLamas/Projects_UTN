package models.validadorDeContrasenias.validaciones.restriccionesNist;

import models.validadorDeContrasenias.excepciones.ExcepcionLongitud;

public class CumpleLongitud implements RestriccionNist {
  public int cantidadDeCaracteresMaxima = 64;
  public int cantidadDeCaracteresMinima = 8;

  public boolean cumpleRestriccion(String contrasenia) throws ExcepcionLongitud {
    return cumpleCaracteresMinima(contrasenia) && cumpleCaracteresMaxima(contrasenia);
  }

  public boolean cumpleCaracteresMinima(String contrasenia) throws ExcepcionLongitud {
    if (contrasenia.length() < cantidadDeCaracteresMinima) {
      throw new ExcepcionLongitud("La contrasenia debe tener al menos " + cantidadDeCaracteresMinima + " caracteres");
    }
    return true;
  }

  public boolean cumpleCaracteresMaxima(String contrasenia) throws ExcepcionLongitud {
    if (contrasenia.length() > cantidadDeCaracteresMaxima) {
      throw new ExcepcionLongitud("La contrasenia debe tener menos de " + cantidadDeCaracteresMaxima + " caracteres");
    }
    return true;
  }
}
