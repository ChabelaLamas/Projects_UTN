package csv;

import models.csv.ImportadorCSV;
import models.domain.main.EntidadPrestadora;
import models.domain.main.OrganismoDeControl;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.io.File;
import java.util.List;
import java.util.Objects;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ImportadorCSVTest {
  private static List<EntidadPrestadora> entidadesPrestadoras;
  private static List<OrganismoDeControl> organismosDeControl;

  @BeforeAll
  public static void init() {
    ImportadorCSV importadorCSV = new ImportadorCSV();
    String archivoDePrueba = obtenerArchivoDePrueba();
    entidadesPrestadoras = importadorCSV.importarEntidadesPrestadoras(archivoDePrueba);
    organismosDeControl = importadorCSV.importarOrganismosDeControl(archivoDePrueba);
  }

  private static String obtenerArchivoDePrueba() {
    ClassLoader classLoader = ImportadorCSVTest.class.getClassLoader();
    File file = new File(Objects.requireNonNull(classLoader.getResource("prueba.csv")).getFile());
    return file.getAbsolutePath();
  }

  @Test
  @DisplayName("Se corrobora que se hayan instanciado la cantidad correcta de elementos")
  public void importarEntidadesPrestadorasCantidad(){
    assertEquals(2,entidadesPrestadoras.size());
  }

  @Test
  @DisplayName("Se corrobora que se hayan instanciado correctamente la denominacion del primer elemento")
  public void importarEntidadesPrestadorasDenominacion(){
    assertEquals("hola SA", entidadesPrestadoras.get(0).getDenominacion());
  }

  @Test
  @DisplayName("Se corrobora que se hayan instanciado la cantidad correcta de elementos")
  public void importarOrganismosDeControlCantidad(){
    assertEquals(1, organismosDeControl.size());
  }

  @Test
  @DisplayName("Se corrobora que se hayan instanciado correctamente la denominacion del primer elemento")
  public void importarOrganismosDeControlDenominacion(){
    assertEquals("pepe OC", organismosDeControl.get(0).getDenominacion());
  }
}
