package APIServicioEntities;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.Getter;

@Schema(name = "RequestEntidadDTO")
@Getter
public class RequestEntidadDTO {
    private Integer idEntidad;
    private Integer sumatoriaTiemposResolucion;
    private Integer cantidadIncidentesNoResueltos;
    //private Integer coeficienteIncidentesNoResueltos;
    private Integer cantidadMiembrosAfectados;
}
