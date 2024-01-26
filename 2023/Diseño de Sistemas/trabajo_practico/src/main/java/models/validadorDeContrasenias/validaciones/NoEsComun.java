package models.validadorDeContrasenias.validaciones;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import models.config.Config;
import models.validadorDeContrasenias.excepciones.ExcepcionComun;
import models.validadorDeContrasenias.validaciones.Validacion;

public class NoEsComun implements Validacion {

  private static final List<String> contraseniasComunes = new ArrayList<>();

  public boolean validarContrasenia(String nombre, String contrasenia) throws ExcepcionComun {
    if (contraseniasComunes.contains(contrasenia)) {
      throw new ExcepcionComun("La contrasenia no debe ser una contrasenia comun");
    }
    return true;
  }

  public NoEsComun() {
    this.procesarArchivoDeContrasenasComunes();
  }

  public void procesarArchivoDeContrasenasComunes() {
    if (contraseniasComunes.isEmpty()) {
      String archivo10kContrasenias = Config.obtenerInstancia().obtenerDelConfig("archivo10kContrasenias");

      // Usa getResourceAsStream para leer el archivo como un recurso del classpath
      try (InputStream inputStream = getClass().getClassLoader().getResourceAsStream(archivo10kContrasenias)) {
        if (inputStream == null) {
          // Si el inputStream es null, el archivo no se encontró en el classpath
          throw new FileNotFoundException("No se pudo encontrar el archivo " + archivo10kContrasenias);
        }
        Scanner myReader = new Scanner(inputStream);

        while (myReader.hasNextLine()) {
          String data = myReader.nextLine();
          contraseniasComunes.add(data);
        }
        // No es necesario cerrar el Scanner aquí ya que está dentro de un try-with-resources
      } catch (IOException e) {
        System.out.println("No se pudo encontrar el archivo " + archivo10kContrasenias);
        e.printStackTrace();
      }
    }
  }
}