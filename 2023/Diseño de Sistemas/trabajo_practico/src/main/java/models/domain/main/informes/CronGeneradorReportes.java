package models.domain.main.informes;

import models.config.Config;
import models.domain.main.entidades.Entidad;
import models.domain.main.exportar.ApachePDFBox;
import models.domain.main.exportar.EstrategiaExportacionPDF;
import models.domain.main.exportar.Informe;
import models.domain.main.informes.rankings.CantidadIncidentesReportados;
import models.domain.main.informes.rankings.InformeExportable;
import models.domain.main.informes.rankings.PromedioCierre;
import models.repositorios.EntidadPrestadoraRepository;
import models.repositorios.EntidadRepository;
import models.repositorios.InformeExportableRepository;

import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

public class CronGeneradorReportes extends TimerTask {

    private EntidadPrestadoraRepository repositorioDeEntidadPrestadora = new EntidadPrestadoraRepository();
    private InformeExportableRepository repositorioDeInformesExportables =  new InformeExportableRepository();
    private EntidadRepository entidadRepository = new EntidadRepository();

    public CronGeneradorReportes() {
        Timer t = new Timer();
        t.scheduleAtFixedRate(this, 0, Config.TIEMPO_REPORTES);
    }

    @Override
    public void run() {
        GeneradorDeReportes generadorDeReportes = new GeneradorDeReportes(new EstrategiaExportacionPDF(new ApachePDFBox()));
        List<Entidad> entidades = this.entidadRepository.todos();
        PromedioCierre p = new PromedioCierre();
        Informe informeCierre = new Informe(p.elaborarRanking(entidades));
        CantidadIncidentesReportados c = new CantidadIncidentesReportados();
        Informe informeIncidentes = new Informe(c.elaborarRanking(entidades));
        InformeExportable informeExpCierre = new InformeExportable("Promedio_de_cierre", informeCierre);
        InformeExportable informeExpIncidentes = new InformeExportable("Cantidad_incidentes_reportados", informeIncidentes);
        try {
            String rutaInformeCierre = generadorDeReportes.generadorSemanalDeReportes(informeExpCierre);
            String rutaInformeIncidentes = generadorDeReportes.generadorSemanalDeReportes(informeExpIncidentes);
            informeExpCierre.setPath(rutaInformeCierre);
            informeExpIncidentes.setPath(rutaInformeIncidentes);

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        repositorioDeInformesExportables.guardar(informeExpCierre);
        repositorioDeInformesExportables.guardar(informeExpIncidentes);
    }
}