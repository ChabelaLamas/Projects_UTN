package server.handlers;

import io.javalin.Javalin;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;
import server.exceptions.AccessDeniedException;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AccessDeniedHandler implements IHandler {

    @Override
    public void setHandle(Javalin app) {

        app.exception(AccessDeniedException.class, (e, cxt) -> {
            cxt.status(403); // Establecer código de estado 403.hbs - Forbidden
            cxt.render("403.hbs");
        });


    }

}
