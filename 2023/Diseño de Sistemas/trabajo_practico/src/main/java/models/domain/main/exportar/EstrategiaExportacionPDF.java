package models.domain.main.exportar;


public class EstrategiaExportacionPDF implements EstrategiaExportacion {

    public PDFAdapter adapter;

    public EstrategiaExportacionPDF(PDFAdapter adapter) {
        this.adapter = adapter;
    }

    @Override
    public String exportar(Exportable exportable) {
        return adapter.generarInforme(exportable);
    }

}
