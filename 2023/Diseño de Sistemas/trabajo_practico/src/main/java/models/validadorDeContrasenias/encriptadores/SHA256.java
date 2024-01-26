package models.validadorDeContrasenias.encriptadores;

import com.google.common.hash.Hashing;
import java.nio.charset.StandardCharsets;

public class SHA256 implements Encriptador {
  public String encriptarContrasenia(String contrasenia) {
    return Hashing.sha256()
        .hashString(contrasenia, StandardCharsets.UTF_8)
        .toString();
  }
}
