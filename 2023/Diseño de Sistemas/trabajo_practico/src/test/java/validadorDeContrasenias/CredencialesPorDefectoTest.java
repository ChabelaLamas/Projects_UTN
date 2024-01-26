package validadorDeContrasenias;

import models.validadorDeContrasenias.excepciones.ExcepcionCredencial;
import models.validadorDeContrasenias.validaciones.CredencialesPorDefecto;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import static org.junit.jupiter.api.Assertions.*;

public class CredencialesPorDefectoTest {
  private CredencialesPorDefecto credencialesPorDefecto;
  private String contrasenia;
  private String nombre;

  @BeforeEach
  public void init() {
    this.credencialesPorDefecto = new CredencialesPorDefecto();
    this.nombre = "nombre";
  }

  @Test
  @DisplayName("Se ingresa una contrasenia distinta al nombre, debe aprobarse")
  public void credencialesDistintas(){
    contrasenia = "Prueba123";

    assertTrue(credencialesPorDefecto.validarContrasenia(nombre, contrasenia));
  }

  @Test
  @DisplayName("Se ingresa una contrasenia igual al nombre, debe fallar")
  public void credencialesPorDefecto(){
    contrasenia = "nombre";

    assertThrows(ExcepcionCredencial.class,
        () -> credencialesPorDefecto.validarContrasenia(nombre, contrasenia));
  }
}
