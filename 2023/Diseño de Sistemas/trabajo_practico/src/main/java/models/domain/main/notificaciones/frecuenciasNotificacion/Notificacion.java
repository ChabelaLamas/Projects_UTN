package models.domain.main.notificaciones.frecuenciasNotificacion;

import models.domain.converter.LocalDateTimeAttributeConverter;
import models.domain.main.Establecimiento;
import models.domain.main.incidentes.Incidente;
import models.domain.main.servicio.Servicio;
import models.domain.usuarios.Persona;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
@Getter
@Entity
public class Notificacion {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @ManyToOne
  @JoinColumn(name = "persona_id", referencedColumnName = "id")
  private Persona destinatario;

  @Setter
  @Column(name = "mensaje")
  private String mensaje;

  @Enumerated(EnumType.STRING)
  private EstadoNotificacion estado;

  @Convert(converter = LocalDateTimeAttributeConverter.class)
  @Column(name="fechaAperturaIncidente")
  private LocalDateTime fechaAperturaIncidente;
  @Convert(converter = LocalDateTimeAttributeConverter.class)
  @Column(name="fechaCierreIncidente")
  private LocalDateTime fechaCierreIncidente;

  public Notificacion (Persona destinatario, Incidente incidente, Boolean esDeSugerencia) {
    this.destinatario = destinatario;
    this.mensaje = this.generarMensaje(incidente, esDeSugerencia);
    estado = EstadoNotificacion.PENDIENTE_A_ENVIAR;
    fechaAperturaIncidente = incidente.getFechaApertura();
    fechaCierreIncidente = incidente.getFechaCierre();
  }

  public Notificacion() {

  }

  public String generarMensaje(Incidente incidente, Boolean esdeSugerencia) {
    Establecimiento establecimiento = incidente.getPrestacion().getEstablecimiento();
    Servicio servicio = incidente.getPrestacion().getServicio();
    if(esdeSugerencia) {
      return "Por favor, revise el estado del servicio " + servicio.getDescripcion() + " en " + establecimiento.getDenominacion();
    }
    else {
      if (incidente.isAbierto()) {
        return "Nuevo incidente en " + establecimiento.getDenominacion() + " en el servicio " + servicio.getDescripcion()
                + " abierto a las " + incidente.getFechaApertura().format(DateTimeFormatter.ofPattern("HH:mm:ss"));
      } else {
        return "Cierre de incidente en " + establecimiento.getDenominacion() + " en el servicio " + servicio.getDescripcion()
                + " cerrado a las " + incidente.getFechaCierre().format(DateTimeFormatter.ofPattern("HH:mm:ss"));
      }
    }

  }

  public void cambiarEstadoAEnviado() {
    estado = EstadoNotificacion.ENVIADO;
  }
}
