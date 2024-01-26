package models.domain.main.informes.rankings;

import models.domain.main.EntidadPrestadora;
import models.domain.main.exportar.Exportable;
import models.domain.main.informes.PosicionRanking;

import javax.persistence.Entity;
import javax.persistence.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "reporte")
public class Reporte implements Exportable {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public Long id;

    @Column(name = "tipo_reporte")
    private String descripcion;

    @ManyToOne(cascade = {CascadeType.PERSIST, CascadeType.MERGE})
    @JoinColumn(name = "entidad_id", referencedColumnName = "id")
    private EntidadPrestadora destinatario;


    @Transient
    private List<PosicionRanking> entradas;

    @Transient
    private Map<String, List<String>> datos;

    @Column(name = "path")
    private String path;

    @Column(name = "download")
    private String download;

    @Column(name = "fecha", columnDefinition = "DATE")
    private LocalDateTime fecha;


    @Column(name = "nombre_archivo")
    private String nombre_archivo;

    public Reporte(String descripcion, EntidadPrestadora destinatario, List<PosicionRanking> entradas) {
        this.descripcion = descripcion;
        this.destinatario = destinatario;
        this.entradas = entradas;
    }

    public Reporte() {

    }

    @Override
    public Map<String, List<String>> getDatos() {
        return this.getDatosEntidades();
    }

    @Override
    public String descripcion() {
        return this.descripcion;
    }

    @Override
    public void setNombre(String nombre) {
        this.nombre_archivo = nombre;
    }

    public Map<String, List<String>> getDatosEntidades() {
        Map<String, List<String>> datos = new HashMap<>();
        int nro_posicion = 1;
        for (PosicionRanking entrada : entradas) {
            String posicion = "Posicion";
            String nombre = "Nombre";
            String puntaje = "Puntaje";
            String nombre_valor = entrada.getEntidad().getDenominacion();
            String puntaje_valor = String.valueOf(entrada.getPuntaje());

            List<String> valores = datos.getOrDefault(String.valueOf(nro_posicion), new ArrayList<>());

            valores.add(posicion + ": " + nro_posicion);
            valores.add(nombre + ": " + nombre_valor);
            valores.add(puntaje + ": " + puntaje_valor);

            datos.put(String.valueOf(nro_posicion), valores);

            nro_posicion++;
        }

        return datos;
    }

    public boolean isImpacto() {
        return this.descripcion.equals("MAYOR_GRADO_IMPACTO");
    }

    public boolean isCantidad() {
        return this.descripcion.equals("MAYOR_CANTIDAD_INCIDENTES");
    }

    public boolean isPromedio() {
        return this.descripcion.equals("PROMEDIO_CIERRE_INCIDENTES");
    }
}