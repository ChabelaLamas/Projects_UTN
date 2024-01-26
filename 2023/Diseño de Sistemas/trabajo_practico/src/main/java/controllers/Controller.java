package controllers;

import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import io.javalin.http.Context;
import models.domain.usuarios.Usuario;

public abstract class Controller implements WithSimplePersistenceUnit {

  protected Usuario usuarioLogueado(Context context){
      if(context.sessionAttribute("id_usuario") == null) {
        return null;
      }
      return entityManager().find(Usuario.class, Long.parseLong(context.sessionAttribute("id_usuario")));
  }

}
