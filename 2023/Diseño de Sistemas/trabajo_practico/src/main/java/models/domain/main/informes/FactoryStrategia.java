package models.domain.main.informes;

import models.domain.main.informes.rankings.CantidadIncidentesReportados;
import models.domain.main.informes.rankings.GradoImpactoProblematicas;
import models.domain.main.informes.rankings.PromedioCierre;
import models.domain.main.informes.rankings.Ranking;

public class FactoryStrategia {

        public static Ranking crear(String reporte){
            /*
             * Teniendo en cuenta que tenemos tres reportes vamos a sesgar el Diseño a los reportes que decidimos determinar como:
             * PROMEDIO_CIERRE_INCIDENTES
             * MAYOR_CANTIDAD_INCIDENTES
             * MAYOR_GRADO_IMPACTO
             * */
            Ranking ranking = null;
            switch (reporte) {
                case "PROMEDIO_CIERRE_INCIDENTES":
                    ranking = new PromedioCierre();
                    break;
                case "MAYOR_CANTIDAD_INCIDENTES":
                    ranking = new CantidadIncidentesReportados();
                    break;
                case "MAYOR_GRADO_IMPACTO":
                    ranking = new GradoImpactoProblematicas();
                    break;
            }
            return ranking;
        }

}
