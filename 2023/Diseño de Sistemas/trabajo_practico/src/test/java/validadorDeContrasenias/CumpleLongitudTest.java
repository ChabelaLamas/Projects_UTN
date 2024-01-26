package validadorDeContrasenias;

import models.validadorDeContrasenias.validaciones.restriccionesNist.CumpleLongitud;
import models.validadorDeContrasenias.excepciones.ExcepcionLongitud;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import static org.junit.jupiter.api.Assertions.*;

public class CumpleLongitudTest {
  private CumpleLongitud restriccionLongitud;
  private String contrasenia;

  @BeforeEach
  public void init() {
    this.restriccionLongitud = new CumpleLongitud();
  }

  @Test
  @DisplayName("Se ingresa una contrasenia adecuada, debe aprobarse")
  public void contraseniaDeLongitudAdecuada() throws ExcepcionLongitud {
    contrasenia = "12345678910";

    assertTrue(restriccionLongitud.cumpleRestriccion(contrasenia));
  }

  @Test
  @DisplayName("Se ingresa una contrasenia muy corta, debe fallar")
  public void contraseniaCorta(){
    contrasenia = "12345";

    assertThrows(ExcepcionLongitud.class,
        () -> restriccionLongitud.cumpleCaracteresMinima(contrasenia));
  }

  @Test
  @DisplayName("Se ingresa una contrasenia muy larga, debe fallar")
  public void contraseniaLarga(){
    contrasenia = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    assertThrows(ExcepcionLongitud.class,
        () -> restriccionLongitud.cumpleCaracteresMaxima(contrasenia));
  }
}
