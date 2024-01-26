package models.domain.main.informes.rankings;

import lombok.Getter;
import lombok.Setter;
import models.domain.main.exportar.Exportable;
import models.domain.main.exportar.Informe;

import javax.persistence.*;
import java.util.List;
import java.util.Map;

@Getter
@Setter
@Entity
@Table(name = "informe")
public class InformeExportable implements Exportable {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public Long id;

    @Column(name = "path")
    public String path;

    @Column(name = "tipo_reporte")
    private String descripcion;

    @Transient
    private Map<String, List<String>> datos;

    public InformeExportable(String descripcion, Informe informe) {this.datos = informe.procesoDatosEntrantes();
        this.descripcion = descripcion;
    }

    public InformeExportable() {

    }

    @Override
    public String descripcion() {
        return descripcion;
    }

    @Override
    public void setNombre(String nombre) {

    }
}
