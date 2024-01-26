package models.domain.main.informes;

import models.config.Config;
import models.domain.main.EntidadPrestadora;
import models.domain.main.entidades.Entidad;
import models.domain.main.exportar.ApachePDFBox;
import models.domain.main.exportar.EstrategiaExportacionPDF;
import models.domain.main.exportar.Exportador;
import models.domain.main.informes.rankings.InformeExportable;
import models.domain.main.informes.rankings.Ranking;
import models.domain.main.informes.rankings.Reporte;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class GeneradorDeReportes {

    public EstrategiaExportacionPDF estrategiaExportacion;

    public GeneradorDeReportes(EstrategiaExportacionPDF estrategiaExportacion){
        this.estrategiaExportacion = estrategiaExportacion;
    }

    public String generadorSemanalDeReportes(InformeExportable informe) throws Exception {
        ApachePDFBox pdfBox = new ApachePDFBox();
       String rutaCompleta = pdfBox.generarInforme(informe);
       return rutaCompleta;
    }

    /*public List<Reporte> generadorSemanalDeReportes(EntidadPrestadora entidadPreestadora) throws Exception {
        Exportador exportador = this.exportador();
        List<String> nombre_reportes = Arrays.asList("MAYOR_GRADO_IMPACTO", "MAYOR_CANTIDAD_INCIDENTES", "PROMEDIO_CIERRE_INCIDENTES");
        List<Reporte> reportes = new ArrayList<>();
        String ruta = null;
        for (String nombre_reporte : nombre_reportes) {
            List<PosicionRanking> posiciones = this.generarReporte(entidadPreestadora.getEntidades(), nombre_reporte);
            Reporte reporte = new Reporte(nombre_reporte, entidadPreestadora, this.ordenar(posiciones));
            String path = exportador.exportar(reporte);
            reporte.setPath(path);
            reporte.setDownload(Config.DOWNLOAD + reporte.getNombre_archivo());
            reporte.setFecha(LocalDateTime.now());
            reportes.add(reporte);
        }
        return reportes;
    }*/


    public List<PosicionRanking> ordenar(List<PosicionRanking> posiciones)
    {
        return posiciones.stream()
                    .sorted((c1, c2) -> Integer.compare(c1.getPuntaje(), c2.getPuntaje()))
                    .collect(Collectors.toList());
    }

    public Exportador exportador()
    {
        return new Exportador(this.estrategiaExportacion);
    }

    //Metodo que no puede faltar
    public List<PosicionRanking> generarReporte(List<Entidad> entidades, String reporte) throws Exception {
        Ranking estrategia = FactoryStrategia.crear(reporte);
        return estrategia.elaborarRanking(entidades);
    }
}
