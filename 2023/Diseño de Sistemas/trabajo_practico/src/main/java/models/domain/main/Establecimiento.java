package models.domain.main;

import models.domain.main.localizacion.Localidad;
import models.domain.main.entidades.Entidad;
import models.domain.main.incidentes.Incidente;
import models.domain.main.servicio.Servicio;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Persona;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.lang.invoke.StringConcatFactory;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Entity
@Getter
@Setter
@Table(name="establecimiento")
public class Establecimiento {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name="denominacion", columnDefinition = "TEXT")
  private String denominacion;

  @ManyToOne
  @JoinColumn(name = "entidad_id", referencedColumnName = "id")
  private Entidad entidad;

  @Setter
  @ManyToOne
  @JoinColumn(name = "localidad_id", referencedColumnName = "id")
  private Localidad localidad = null;

  @Column(name="estaActivo")
  private Boolean estaActivo;

  @Getter
  @OneToMany(mappedBy = "establecimiento", cascade = CascadeType.ALL, orphanRemoval = true)
  private final List<PrestacionDeServicio> prestaciones = new ArrayList<>();

  @ManyToMany(mappedBy = "establecimientosObservados")
  private List<Comunidad> comunidadesAsociadas = new ArrayList<>();

  private Boolean pertenece = false;

  public Establecimiento() {
    this.denominacion = null;
    this.entidad = null;
    this.estaActivo=true;
  }

  public Establecimiento(String denominacion, Entidad entidad, Localidad localidad) {
    this.denominacion = denominacion;
    this.entidad = entidad;
    this.localidad = localidad;
    this.estaActivo=true;
  }

  public List<Incidente> obtenerIncidentesTotales() {
    return prestaciones.stream()
        .flatMap(prestacion -> prestacion.getIncidentes().stream())
        .collect(Collectors.toList());
  }



  public Establecimiento(Entidad entidad, String denominacion) {
    this.entidad = entidad;
    this.denominacion = denominacion;
    this.estaActivo=true;
  }

  public Integer obtenerCantidadMiembrosAfectados() {
    return comunidadesAsociadas.stream().mapToInt(Comunidad::obtenerCantidadMiembrosAfectados).sum();
  }

  public void editar(String denominacion, Entidad entidad, Localidad localidad) {
    this.entidad = entidad;
    this.denominacion = denominacion;
    this.localidad=localidad;
  }
}