package models.domain.usuarios.roles;

import io.javalin.security.RouteRole;

public enum TipoRol implements RouteRole {
  ADMINISTRADOR,
  CONSUMIDOR
}
