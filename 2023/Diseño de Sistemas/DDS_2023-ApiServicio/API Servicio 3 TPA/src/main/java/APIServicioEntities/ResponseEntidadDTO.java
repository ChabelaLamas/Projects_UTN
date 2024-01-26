package APIServicioEntities;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.Getter;
import lombok.Setter;

@Schema(name = "ResponseEntidadDTO")
@Getter
@Setter
public class ResponseEntidadDTO {
    public Integer idEntidad;
    public Integer nivelImpactoEntidad;
    public Integer puestoRanking;
}

