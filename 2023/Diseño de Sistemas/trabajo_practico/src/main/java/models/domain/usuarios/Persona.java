package models.domain.usuarios;

import models.domain.converter.FrecuenciaDeNotificacionAttributeConverter;
import models.domain.converter.LocalDateTimeAttributeConverter;
import models.domain.main.localizacion.Localidad;
import models.domain.main.notificaciones.frecuenciasNotificacion.FrecuenciaNotificacion;
import models.domain.main.notificaciones.frecuenciasNotificacion.NotificacionCuandoSucedeIncidente;
import models.domain.main.notificaciones.mediosNotificacion.PreferenciaMedioNotificacion;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;


@Entity
@Table(name="persona")
@Getter @Setter
public class Persona {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @OneToOne
  @JoinColumn(name = "usuario_id", referencedColumnName = "id")
  private Usuario usuario;

  @OneToMany(mappedBy = "persona", cascade = CascadeType.ALL, orphanRemoval = true)
  private List<Miembro> miembros = new ArrayList<>();


  @ManyToOne
  @JoinColumn(name = "localidad_id", referencedColumnName = "id")
  private Localidad localidad = null;

  @Column(name="email", columnDefinition = "TEXT")
  private String email;

  @Column(name="telefono", columnDefinition = "TEXT")
  private String telefono;

  @Column(name="frecuencia_notificacion")
  @Convert(converter = FrecuenciaDeNotificacionAttributeConverter.class)
  @Setter
  private FrecuenciaNotificacion frecuenciaNotification;

  @Enumerated(EnumType.STRING)
  @Column(name="medio_de_notificacion")
  @Setter
  private PreferenciaMedioNotificacion preferenciaMedioNotificacion;

  @ElementCollection
  @CollectionTable(name="horarioDeNotificacion", joinColumns = @JoinColumn(name="persona_id"))
  @Convert(converter = LocalDateTimeAttributeConverter.class)
  @Column(name="horario")
  private List<LocalDateTime> horariosDeNotificaciones;

  public Persona(Usuario usuario, String email, String telefono){
    this.usuario = usuario;
    this.email = email;
    this.telefono = telefono;
    this.frecuenciaNotification = new NotificacionCuandoSucedeIncidente();
    this.preferenciaMedioNotificacion = null;
    this.horariosDeNotificaciones = new ArrayList<>();
  }

  public Persona() {

  }

  public List<Comunidad> getComunidades() {
    return miembros.stream().map(miembro -> miembro.getComunidad()).toList();
  }

  public Long getId() {
    return id;
  }



}
