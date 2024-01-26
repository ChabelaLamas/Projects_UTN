package server.middlewares;

import io.javalin.config.JavalinConfig;
import io.javalin.http.Context;
import models.domain.usuarios.roles.TipoRol;
import server.exceptions.AccessDeniedException;

import java.util.Arrays;
import java.util.List;

public class AuthMiddleware {
    public static void apply(JavalinConfig config) {
        List<String> allowedPaths = Arrays.asList("/login", "/signup");

        config.accessManager((handler, context, routerRoles) ->
        {
            if (context.sessionAttribute("usuario_id") == null && !allowedPaths.contains(context.path())) {
                context.redirect("/login");
            } else {
                handler.handle(context);
            }
        });
    }

    /*
    public static void apply(JavalinConfig config) {
        List<String> allowedPaths = Arrays.asList("/login", "/signup");

        config.accessManager((handler, context, routerRoles) ->
        {
            if (context.sessionAttribute("usuario_id") == null && !allowedPaths.contains(context.path())) {
                context.redirect("/login");
            } else {
                TipoRol userRole = getUserRoleType(context);

                if(routerRoles.size() == 0 || routerRoles.contains(userRole)) {
                    handler.handle(context);
                }else{
                    throw new AccessDeniedException();
                }
            }

        });
    }

     */

    private static TipoRol getUserRoleType (Context context) {
        return context.sessionAttribute("tipo_rol")!= null?
            TipoRol.valueOf(context.sessionAttribute("tipo_rol")) : null;
    }
}
