package validadorDeContrasenias;

import models.validadorDeContrasenias.excepciones.ExcepcionComun;
import models.validadorDeContrasenias.validaciones.NoEsComun;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import static org.junit.jupiter.api.Assertions.*;

public class NoEsComunTest {
  private NoEsComun restriccionNoEsComun;
  private String contrasenia;

  @BeforeEach
  public void init() {
    this.restriccionNoEsComun = new NoEsComun();
  }

  @Test
  @DisplayName("Se ingresa una contrasenia que no esta en el archivo de 10k peores contrasenias, debe aprobarse")
  public void noEsContraseniaComun(){
    contrasenia = "noestaenelarchivoniahi";

    assertTrue(restriccionNoEsComun.validarContrasenia("", contrasenia));
  }

  @Test
  @DisplayName("Se ingresa una contrasenia que esta en el archivo de 10k peores contrasenias, debe fallar")
  public void esContraseniaComun(){
    contrasenia = "qwerty";

    assertThrows(ExcepcionComun.class,
        () -> restriccionNoEsComun.validarContrasenia("", contrasenia));
  }
}
