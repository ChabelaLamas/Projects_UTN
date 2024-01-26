package APIServicioUtils;

import APIServicioEntities.InformacionEntidad;
import APIServicioEntities.RequestEntidadDTO;
import APIServicioEntities.ResponseEntidadDTO;

import java.lang.reflect.Field;

public class ConverterDTO {

    public static InformacionEntidad convertirRequestAEntidad(RequestEntidadDTO requestEntidadDTO) {
            InformacionEntidad informacionEntidad = new InformacionEntidad();

            informacionEntidad.setPuestoRanking(0);
            informacionEntidad.setIdEntidad(requestEntidadDTO.getIdEntidad());
            informacionEntidad.setCantidadMiembrosAfectados(requestEntidadDTO.getCantidadMiembrosAfectados());
            informacionEntidad.setCantidadIncidentesNoResueltos(requestEntidadDTO.getCantidadIncidentesNoResueltos());
            informacionEntidad.setSumatoriaTiemposResolucion(requestEntidadDTO.getSumatoriaTiemposResolucion());
            //informacionEntidad.setCoeficienteIncidentesNoResueltos(requestEntidadDTO.getCoeficienteIncidentesNoResueltos());

            return informacionEntidad;
    }

    public static ResponseEntidadDTO convertirEntidadAResponse(InformacionEntidad informacionEntidad) {
        ResponseEntidadDTO responseDTO = new ResponseEntidadDTO();

        responseDTO.setIdEntidad(informacionEntidad.getIdEntidad());
        responseDTO.setNivelImpactoEntidad(informacionEntidad.getNivelImpactoIncidente());
        responseDTO.setPuestoRanking(informacionEntidad.getPuestoRanking());

        return responseDTO;
    }
}
