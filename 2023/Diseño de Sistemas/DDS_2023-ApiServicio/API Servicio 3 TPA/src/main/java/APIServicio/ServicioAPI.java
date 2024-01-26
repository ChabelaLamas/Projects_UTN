package APIServicio;

import io.javalin.Javalin;
import io.javalin.openapi.plugin.OpenApiConfiguration;
import io.javalin.openapi.plugin.OpenApiPlugin;
import io.javalin.openapi.plugin.redoc.ReDocConfiguration;
import io.javalin.openapi.plugin.redoc.ReDocPlugin;
import io.javalin.openapi.plugin.swagger.SwaggerConfiguration;
import io.javalin.openapi.plugin.swagger.SwaggerPlugin;

import static io.javalin.apibuilder.ApiBuilder.*;

public class ServicioAPI {
    public static void main(String[] args) {
        Javalin app = Javalin.create(
                    config -> {
                        OpenApiConfiguration openApiConfiguration = new OpenApiConfiguration();
                        openApiConfiguration.getInfo().setTitle("Ranking de Impacto de Incidentes");
                        config.plugins.register(new OpenApiPlugin(openApiConfiguration));
                        config.plugins.register(new SwaggerPlugin(new SwaggerConfiguration()));
                        config.plugins.register(new ReDocPlugin(new ReDocConfiguration()));
                    }
                ).routes(() -> {
                  path("/RankingImpactoIncidentes/GenerarRanking",() -> {
                     post(ServicioController::generarRanking);
                  });
                  path("/RankingImpactoIncidentes/CambiarCNF/{nuevoCnf}",() -> {
                        post(ServicioController::cambiarCnf);
                  });
                })
                .start(8080);
    }

}