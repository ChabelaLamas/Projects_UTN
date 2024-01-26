package APIServicio;

import APIServicioEntities.InformacionEntidad;
import APIServicioUtils.CalculadoraRanking;
import APIServicioUtils.ConverterDTO;
import APIServicioEntities.RequestEntidadDTO;
import APIServicioEntities.ResponseEntidadDTO;
import com.fasterxml.jackson.databind.ObjectMapper;
import io.javalin.http.Context;
import io.javalin.http.Handler;
import io.javalin.openapi.*;
import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.List;

public class ServicioController {
    @OpenApi(
            summary = "Obtener ranking inicidentes",
            operationId = "RankingImpactoIncidentes",
            path = "/RankingImpactoIncidentes/GenerarRanking",
            methods = HttpMethod.POST,
            requestBody = @OpenApiRequestBody(
                    content = {@OpenApiContent(from = RequestEntidadDTO[].class)}
                    ,description = "Servicio que recibe informacion de los incidentes de cada entidad y genera un ranking" +
                    "de las entidades cuyos incidentes tuvieron el mayor impacto."
                    ,required = true
            ),
            tags = {"Ranking"},
            responses = {
                    @OpenApiResponse(
                            status = "200",
                            content = {@OpenApiContent(from = ResponseEntidadDTO[].class)}
                            ),
                    @OpenApiResponse(status = "400", content = {}),
                    @OpenApiResponse(status="500")
            }
    )
    public static void generarRanking(@NotNull Context context) throws Exception {

        try {

            ObjectMapper objectMapper = new ObjectMapper();

            RequestEntidadDTO[] arrayDTOsRequest = objectMapper.readValue(context.body(), RequestEntidadDTO[].class);
            List<InformacionEntidad> listadoEntidades = new ArrayList<>();
            String valorNulo;
            //Conversion de DTOs a entidades con sus niveles calculados
            for(RequestEntidadDTO requestEntidadDto : arrayDTOsRequest) {
                InformacionEntidad informacionEntidad = ConverterDTO.convertirRequestAEntidad(requestEntidadDto);
                CalculadoraRanking.calcularImpacto(informacionEntidad);
                listadoEntidades.add(informacionEntidad);
            }

            if(listadoEntidades.isEmpty())
//                context.status(400);
//                context.result("El listado de entidades no posee ningun elemento);
                throw new Exception("El listado de entidades no posee ningun elemento.");

            //Una vez que tengo todas las entidades, las ordeno segun el nivel de impacto
            CalculadoraRanking.calcularRanking(listadoEntidades);

            List<ResponseEntidadDTO> listadoDTOsResponse = new ArrayList<>();

            for(InformacionEntidad entidad : listadoEntidades) {
                listadoDTOsResponse.add(ConverterDTO.convertirEntidadAResponse(entidad));
            }
            context.json(listadoDTOsResponse);
            //context.result(objectMapper.writeValueAsString(listadoDTOsResponse));
        }
        catch(Exception e) {
            context.status(500);
            context.result("Ha ocurrido un error: \n" + e.getMessage());
        }
    }

    @OpenApi(
            summary = "Establecer un nuevo CNF",
            operationId = "ConfigurarCnf",
            path = "/RankingImpactoIncidentes/CambiarCNF/{nuevoCnf}",
            methods = HttpMethod.POST,
            pathParams = @OpenApiParam(
              name = "nuevoCnf",
              type = Integer.class,
              description = "El nuevo CNF a utilizar",
              required = true
            ),
            tags = {"Ranking"},
            responses = {
                    @OpenApiResponse(
                            status = "200",
                            content = {
                                    @OpenApiContent(
                                            type = "string"
                                    )
                            }
                    ),
                    @OpenApiResponse(
                            status = "400"
                            , content = {}),
                    @OpenApiResponse(
                            status="500"
                    )
            }
    )
    public static void cambiarCnf(Context context) {
        try {
            String strNuevoCnf = context.pathParam("nuevoCnf");
            Integer nuevoCnf = Integer.parseInt(strNuevoCnf);
            if(nuevoCnf <= 0)
                throw new RuntimeException("El CNF no puede ser menor o igual a cero");
            CalculadoraRanking.modificarCnf(nuevoCnf);
            context.status(200);
            context.result("CNF modificado exitosamente");
        }
        catch(Exception e) {
            context.status(500);
            context.result("Ha ocurrido un error: \n " + e.getMessage());
        }
    }
}