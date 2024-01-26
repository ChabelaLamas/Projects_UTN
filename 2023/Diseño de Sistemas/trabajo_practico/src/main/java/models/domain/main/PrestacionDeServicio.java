package models.domain.main;

import lombok.Setter;
import models.domain.main.incidentes.Incidente;
import models.domain.main.notificaciones.Notificador;
import models.domain.main.notificaciones.frecuenciasNotificacion.Notificacion;
import models.domain.main.servicio.Servicio;
import lombok.Getter;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Miembro;
import models.domain.usuarios.Persona;

import javax.persistence.*;
import java.util.*;
import java.util.stream.Collectors;

@Entity

@Table(name="prestacionDeServicio")
public class  PrestacionDeServicio {
  @Getter
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Getter
  @ManyToOne
  @JoinColumn(name = "establecimiento_id", referencedColumnName = "id")
  private Establecimiento establecimiento;

  @Getter
  @ManyToOne
  @JoinColumn(name = "servicio_id", referencedColumnName = "id")
  private Servicio servicio;

  @Getter@Setter
  @Column(name="estaActivo", columnDefinition = "TEXT")
  private Boolean estaActivo;

  @OneToMany(mappedBy = "prestacion", cascade = CascadeType.ALL, orphanRemoval = true)
  private List<Incidente> incidentes = new ArrayList<>();

  public PrestacionDeServicio() {
    this.establecimiento = null;
    this.servicio = null;
    this.estaActivo=true;
  }

  public List<Incidente> getIncidentes() {
    return incidentes;
  }

  public PrestacionDeServicio(Establecimiento establecimiento, Servicio servicio) {
    this.establecimiento = establecimiento;
    this.servicio = servicio;
    this.estaActivo=true;
  }

  public void notificarAMiembros (Incidente incidente) {
    Set<Persona> listadoPersonasInteresadas = new HashSet<>(incidente.getComunidad().getMiembros().stream().map(Miembro::getPersona).toList());
    for (Persona persona : listadoPersonasInteresadas){
      persona.getFrecuenciaNotification().gestionarInicidente(persona, incidente);
    }
  }

  public void ocurrioUnIncidente(Miembro miembro, String descripcion, String denominacion) {
    Comunidad comunidadMiembro = miembro.getComunidad();
    if (comunidadMiembro.leInteresa(this)) {
      Incidente incidente = new Incidente(descripcion, denominacion, comunidadMiembro, this, miembro);
      incidentes.add(incidente);
      comunidadMiembro.agregarIncidente(incidente);
      notificarAMiembros(incidente);
    }

  }

  public void cerrarUnIncidente(Incidente incidente) {
    incidente.cerrar();
    notificarAMiembros(incidente);
  }

  public boolean disponibleParaComunidad(Comunidad comunidad) {
    return incidentes.stream().noneMatch(incidente -> incidente.getComunidad().equals(comunidad) && incidente.isAbierto());
  }

  public void editar(Establecimiento establecimiento, Servicio servicio) {
    this.establecimiento = establecimiento;
    this.servicio = servicio;
  }
}
