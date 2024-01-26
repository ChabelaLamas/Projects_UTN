package APIServicioUtils;

import APIServicioEntities.InformacionEntidad;

import java.util.Comparator;
import java.util.List;

public class CalculadoraRanking {

    private static Integer coeficienteIncidentesNoResueltos = 1;
    public static List<InformacionEntidad> calcularRanking(List<InformacionEntidad> listadoEntidades) {

        listadoEntidades.sort(Comparator.comparingInt(InformacionEntidad::getNivelImpactoIncidente).reversed());
        for(InformacionEntidad entidad : listadoEntidades) {
            entidad.setPuestoRanking(listadoEntidades.indexOf(entidad)+1);
        }
        return listadoEntidades;

    }

    public static void calcularImpacto(InformacionEntidad entidad) {
            Integer nivelImpactoIncidente = (entidad.getSumatoriaTiemposResolucion()
                    + entidad.getCantidadIncidentesNoResueltos() * coeficienteIncidentesNoResueltos)
                    * entidad.getCantidadMiembrosAfectados();

            entidad.setNivelImpactoIncidente(nivelImpactoIncidente);
    }

    public static void modificarCnf(Integer nuevoCnf) {
        coeficienteIncidentesNoResueltos = nuevoCnf;
    }
}
