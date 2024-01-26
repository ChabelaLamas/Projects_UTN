package models.csv;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class LectorCSV {
  public List<LineaCSV> leerArchivoCSV(String archivoCSV) {
    try (BufferedReader br = new BufferedReader(new FileReader(archivoCSV))) {
      List<LineaCSV> lineas = new ArrayList<>();
      String linea;
      boolean primeraLinea = true;

      while ((linea = br.readLine()) != null) {
        if (primeraLinea) {
          primeraLinea = false;
          continue;
        }

        String[] datos = linea.split(";");

        LineaCSV nuevaLinea = new LineaCSV(datos[0],datos[1],datos[2],datos[3]);

        lineas.add(nuevaLinea);
      }
      return lineas;
    } catch (IOException e) {
      e.printStackTrace();
      return null;
    }
  }
}
