package models.domain.usuarios;

import lombok.Setter;
import models.domain.main.Establecimiento;
import models.domain.main.PrestacionDeServicio;
import models.domain.main.entidades.Entidad;
import models.domain.main.incidentes.Incidente;
import models.domain.main.servicio.Servicio;
import models.domain.main.servicio.ServicioCompuesto;
import lombok.Getter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter
@Setter
@Table(name="comunidad")
public class Comunidad {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name="nombre")
  private String nombre;

  @Column(name="descripcion")
  private String descripcion;

  @Getter@Setter
  @Column(name="estaActivo", columnDefinition = "TEXT")
  private Boolean estaActivo;

  @OneToMany(mappedBy = "comunidad", cascade = CascadeType.ALL, orphanRemoval = true)
  private List<Miembro> miembros = new ArrayList<>();

  public Comunidad() {

  }

  public Comunidad(String nombre, String descripcion, List<Servicio> serviciosObservados, List<Establecimiento> establecimientosObservados) {
    this.nombre = nombre;
    this.descripcion = descripcion;
    this.estaActivo= true;
    this.serviciosObservados = serviciosObservados;
    this.establecimientosObservados = establecimientosObservados;
  }

  public List<Miembro> getAdministradores() {
    return miembros.stream()
            .filter(Miembro::getEsAdministrador)
            .toList();
  }

  public List<Miembro> getMiembrosRegulares() {
    return miembros.stream()
            .filter(miembro -> !miembro.getEsAdministrador())
            .toList();
  }

  @OneToMany(mappedBy = "comunidad", cascade = CascadeType.ALL, orphanRemoval = true)
  private List<Incidente> incidentes = new ArrayList<>();


  @ManyToMany(cascade = { CascadeType.ALL })
  @JoinTable(
      name = "Asociados_Servicios_Comunidad",
      joinColumns = { @JoinColumn(name = "comunidad_id") },
      inverseJoinColumns = { @JoinColumn(name = "servicio_id") }
  )
  private List<Servicio> serviciosObservados = new ArrayList<>();


  @ManyToMany(cascade = { CascadeType.ALL })
  @JoinTable(
      name = "Asociados_Establecimientos_Comunidad",
      joinColumns = { @JoinColumn(name = "comunidad_id") },
      inverseJoinColumns = { @JoinColumn(name = "establecimiento_id") }
  )
  private List<Establecimiento> establecimientosObservados = new ArrayList<>();


  public Comunidad(Long id, String nombre, String descripcion, List<Miembro> miembros, List<Servicio> serviciosObservados, List<Establecimiento> establecimientosObservados) {
    this.id = id;
    this.nombre = nombre;
    this.descripcion = descripcion;
    this.estaActivo = true;
    this.miembros = miembros;
    this.incidentes = new ArrayList<>();
    this.serviciosObservados = serviciosObservados;
    this.establecimientosObservados = establecimientosObservados;
  }

  public void agregarIncidente(Incidente incidente) {
    incidentes.add(incidente);
  }
  public ServicioCompuesto crearServicioCompuesto(String descripcion, Servicio... otrosServicios){
    return new ServicioCompuesto(descripcion, otrosServicios);
  }

  public void agregarMiembro(Miembro miembro) {
    miembros.add(miembro);
  }

  public Integer obtenerCantidadMiembrosAfectados() {
    return miembros.stream().filter(miembro -> miembro.getTipo().equals(TipoMiembro.AFECTADO)).toList().size();
  }

  public boolean leInteresa (PrestacionDeServicio prestacion) {
    return serviciosObservados.contains(prestacion.getServicio()) && establecimientosObservados.contains(prestacion.getEstablecimiento());
  }

  public void editar(String nombre, String descripcion, List<Servicio> servicios, List<Establecimiento> establecimientos) {
    this.nombre = nombre;
    this.descripcion = descripcion;
    serviciosObservados.clear();
    serviciosObservados.addAll(servicios);
    establecimientosObservados.clear();
    establecimientosObservados.addAll(establecimientos);
  }

}
