package models.validadorDeContrasenias.encriptadores;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5 implements Encriptador {
  public String encriptarContrasenia(String contrasenia) throws NoSuchAlgorithmException {
    MessageDigest md = MessageDigest.getInstance("MD5");
    md.update(contrasenia.getBytes());

    return hashToString(md.digest());
  }

  private String hashToString(byte[] digest) {
    StringBuilder sb = new StringBuilder();
    for (byte b : digest) {
      String hex = String.format("%02x", b);
      sb.append(hex);
    }
    return sb.toString();
  }
}
