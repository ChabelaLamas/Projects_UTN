package models.domain.main.entidades;

import lombok.Setter;
import models.domain.main.localizacion.Localidad;
import models.domain.main.EntidadPrestadora;
import models.domain.main.Establecimiento;
import models.domain.main.OrganismoDeControl;
import models.domain.main.incidentes.Incidente;
import models.domain.main.servicio.Servicio;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Persona;
import lombok.Getter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Entity
@Table(name="entidad")
public class Entidad {

  @Getter
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Getter
  @Embedded
  private TipoEntidad tipo;

  @Getter
  @Column(name = "denominacion", columnDefinition = "TEXT")
  private String denominacion;

  @Getter
  @ManyToOne
  @JoinColumn(name = "entidad_prestadora_id", referencedColumnName = "id")
  private EntidadPrestadora entidadPrestadora;

  @Getter
  @OneToMany(mappedBy = "entidad", cascade = CascadeType.ALL, orphanRemoval = true)
  private final List<Establecimiento> establecimientos = new ArrayList<>();

  @Getter@Setter
  @Column(name="estaActivo")
  private Boolean estaActivo;

  @ManyToMany(cascade = {CascadeType.ALL})
  @JoinTable(
      name = "Entidades_X_Organismo",
      joinColumns = {@JoinColumn(name = "entidad_id")},
      inverseJoinColumns = {@JoinColumn(name = "organismo_de_control_id")}
  )
  private final List<OrganismoDeControl> organismosDeControl = new ArrayList<>();

  @Setter @Getter
  private Boolean pertenece;


  public Entidad(TipoEntidad tipo, String denominacion) {
    this.tipo = tipo;
    this.denominacion = denominacion;
    this.estaActivo = true;
  }

  public Entidad() {

  }

  public Entidad(TipoEntidad tipo, String denominacion, EntidadPrestadora entidadPrestadora) {
    this.tipo = tipo;
    this.denominacion = denominacion;
    this.entidadPrestadora = entidadPrestadora;
    this.estaActivo = true;
  }

  public List<Incidente> obtenerIncidentesTotales() {
    return establecimientos.stream()
        .flatMap(establecimiento -> establecimiento.obtenerIncidentesTotales().stream())
        .collect(Collectors.toList());
  }

  public Integer obtenerIncidentesNoResueltos() {
    return obtenerIncidentesTotales().stream().filter(Incidente::isAbierto).toList().size();
  }

  public List<Incidente> obtenerIncidentesSemanales() {
    return this.obtenerIncidentesTotales().stream().filter(Incidente::perteneceSemanaActual).toList();
  }

  public long obtenerPromedioCierreIncidentes() {
    List<Incidente> incidentes = this.obtenerIncidentesSemanales().stream().
        filter(incidente -> !incidente.isAbierto()).collect(Collectors.toList());
    long totalSegundos = incidentes.stream().mapToLong(incidente -> incidente.calcularTiempoCierre().toSeconds()).sum();
    long cantidadIncidentes = incidentes.size();
    if (cantidadIncidentes == 0) {
      return 0;
    }
    return totalSegundos / cantidadIncidentes;
  }

  public Integer obtenerCantidaMiembrosAfectados() {
    return establecimientos.stream().mapToInt(Establecimiento::obtenerCantidadMiembrosAfectados).sum();
  }

  public Integer obtenerSumatoriaTiemposResolucion() {
    return this.obtenerIncidentesTotales().stream().filter(incidente -> !incidente.isAbierto()).mapToInt(incidente -> Math.toIntExact(incidente.calcularTiempoCierre().toSeconds())).sum();
  }

  public void editar(TipoEntidad tipo, String denominacion, EntidadPrestadora entidadPrestadora) {
    this.tipo = tipo;
    this.denominacion = denominacion;
    this.entidadPrestadora = entidadPrestadora;
  }
}