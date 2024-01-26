package validadorDeContrasenias;

import models.validadorDeContrasenias.excepciones.ExcepcionComplejidad;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import static org.junit.jupiter.api.Assertions.*;

import models.validadorDeContrasenias.validaciones.restriccionesNist.CumpleComplejidad;

public class CumpleComplejidadTest {
  private CumpleComplejidad restriccionComplejidad;
  private String contrasenia;

  @BeforeEach
  public void init() {
    this.restriccionComplejidad = new CumpleComplejidad();
  }

  @Test
  @DisplayName("Se ingresa una contrasenia compleja, debe aprobarse")
  public void contraseniaCompleja(){
    contrasenia = "Prueba123$";

    assertTrue(restriccionComplejidad.cumpleRestriccion(contrasenia));
  }

  @Test
  @DisplayName("Se ingresa una contrasenia sin numero, debe fallar")
  public void noTieneNumero(){
    contrasenia = "pruebA$";

    assertThrows(ExcepcionComplejidad.class,
        () -> restriccionComplejidad.cumpleRestriccion(contrasenia));
  }

  @Test
  @DisplayName("Se ingresa una contrasenia sin mayuscula, debe fallar")
  public void noTieneMayuscula(){
    contrasenia = "prueba1$";

    assertThrows(ExcepcionComplejidad.class,
        () -> restriccionComplejidad.cumpleRestriccion(contrasenia));
    }

  @Test
  @DisplayName("Se ingresa una contrasenia sin minuscula, debe fallar")
  public void noTieneMinuscula(){
    contrasenia = "PRUEBA1$";

    assertThrows(ExcepcionComplejidad.class,
        () -> restriccionComplejidad.cumpleRestriccion(contrasenia));
  }

  @Test
  @DisplayName("Se ingresa una contrasenia sin simbolo, debe fallar")
  public void noTieneSimbolo(){
    contrasenia = "pruebA123";

    assertThrows(ExcepcionComplejidad.class,
        () -> restriccionComplejidad.cumpleRestriccion(contrasenia));
  }
}
