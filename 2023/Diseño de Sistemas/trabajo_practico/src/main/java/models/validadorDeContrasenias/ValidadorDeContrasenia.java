package models.validadorDeContrasenias;

import java.lang.reflect.InvocationTargetException;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;
import models.config.Config;
import models.validadorDeContrasenias.encriptadores.Encriptador;
import models.validadorDeContrasenias.excepciones.ExcepcionContraseniaInvalida;
import models.validadorDeContrasenias.validaciones.Validacion;

public class ValidadorDeContrasenia {
  // Haciendo validaciones una variable de instancia en lugar de estática
  private final List<Validacion> validaciones = new ArrayList<>();

  public ValidadorDeContrasenia() {
    this.agregarValidaciones();
  }

  private void agregarValidaciones() {
    String[] validacionesPorAgregar = Config.obtenerInstancia().obtenerDelConfig("validaciones").split(",");
    for (String validacion : validacionesPorAgregar) {
      try {
        Validacion instancia = crearInstanciaValidacion(validacion);
        validaciones.add(instancia);
      } catch (ClassNotFoundException | IllegalAccessException
               | InstantiationException | NoSuchMethodException
               | InvocationTargetException e) {
        // Reemplazando printStackTrace con un comentario genérico (puede ser reemplazado con una herramienta de registro real)
        System.err.println("Error al agregar la validación: " + validacion);
      }
    }
  }

  private Validacion crearInstanciaValidacion(String nombreClase) throws ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException {
    Class<? extends Validacion> clazz = Class.forName("models.validadorDeContrasenias.validaciones." + nombreClase).asSubclass(Validacion.class);
    return clazz.getDeclaredConstructor().newInstance();
  }

  public boolean verificarValidez(String nombre, String contrasenia) throws ExcepcionContraseniaInvalida {
    return validaciones.stream().allMatch(validacion ->
            validacion.validarContrasenia(nombre, contrasenia));
  }

  public String encriptarContrasenia(String contrasenia) throws NoSuchAlgorithmException, ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
    String hash = Config.obtenerInstancia().obtenerDelConfig("hash");
    // Obtener la clase correspondiente al nombre del algoritmo de hash
    Class<? extends Encriptador> clazz = Class.forName("models.validadorDeContrasenias.encriptadores." + hash).asSubclass(Encriptador.class);
    // Crear una instancia de la clase
    Encriptador encriptador = clazz.getDeclaredConstructor().newInstance();
    return encriptador.encriptarContrasenia(contrasenia);
  }
}
