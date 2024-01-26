package models.csv;

import models.domain.main.EntidadPrestadora;
import models.domain.main.OrganismoDeControl;

import java.util.ArrayList;
import java.util.List;

public class ImportadorCSV {
  public List<EntidadPrestadora> importarEntidadesPrestadoras(String archivoCSV) {
    List<LineaCSV> lineas = new LectorCSV().leerArchivoCSV(archivoCSV);
    List<EntidadPrestadora> entidadesPrestadoras = new ArrayList<>();

    for(LineaCSV linea : lineas) {
      if (linea.getTipo().equals("Entidad prestadora")){
        EntidadPrestadora nuevaEntidadPrestadora = new ParserCSV().instanciarEntidadPrestadora(linea);
        entidadesPrestadoras.add(nuevaEntidadPrestadora);
      }
    }

    return entidadesPrestadoras;
  }

  public List<OrganismoDeControl> importarOrganismosDeControl(String archivoCSV) {
    List<LineaCSV> lineas = new LectorCSV().leerArchivoCSV(archivoCSV);
    List<OrganismoDeControl> organismosDeControl = new ArrayList<>();

    for(LineaCSV linea : lineas) {
      if (linea.getTipo().equals("Organismo de control")){
        OrganismoDeControl nuevoOrganismoDeControl = new ParserCSV().instanciarOrganismoDeControl(linea);
        organismosDeControl.add(nuevoOrganismoDeControl);
      }
    }

    return organismosDeControl;
  }
}
