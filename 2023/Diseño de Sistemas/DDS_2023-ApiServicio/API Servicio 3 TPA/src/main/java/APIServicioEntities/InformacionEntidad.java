package APIServicioEntities;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class InformacionEntidad{
    private Integer idEntidad;
    private Integer sumatoriaTiemposResolucion;
    private Integer cantidadIncidentesNoResueltos;
    //private Integer coeficienteIncidentesNoResueltos;
    private Integer cantidadMiembrosAfectados;
    private Integer nivelImpactoIncidente;
    private Integer puestoRanking;
}