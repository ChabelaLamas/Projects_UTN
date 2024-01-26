package models.domain.main.exportar;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public class Exportador {

    private EstrategiaExportacionPDF estrategia;

    public Exportador(EstrategiaExportacionPDF estrategiaExportacion) {
        this.setEstrategia(estrategiaExportacion);
    }

    public String exportar(Exportable exportable) {
        return estrategia.exportar(exportable);
    }

}
