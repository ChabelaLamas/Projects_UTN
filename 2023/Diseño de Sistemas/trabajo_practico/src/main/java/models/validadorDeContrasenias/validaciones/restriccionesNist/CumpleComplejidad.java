package models.validadorDeContrasenias.validaciones.restriccionesNist;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import models.validadorDeContrasenias.excepciones.ExcepcionComplejidad;


public class CumpleComplejidad implements RestriccionNist {
  public boolean cumpleRestriccion(String contrasenia) throws ExcepcionComplejidad {
    Pattern regex = Pattern.compile("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@#$%^&+=!])\\S+$");
    Matcher matcher = regex.matcher(contrasenia);
    if (!matcher.find()) {
      throw new ExcepcionComplejidad("La contrasenia debe contener un numero, una mayuscula, una minuscula y un simbolo");
    }
    return true;
  }
}
