package models.validadorDeContrasenias.encriptadores;

import java.security.NoSuchAlgorithmException;

public interface Encriptador {
  String encriptarContrasenia(String contrasenia) throws NoSuchAlgorithmException;
}
