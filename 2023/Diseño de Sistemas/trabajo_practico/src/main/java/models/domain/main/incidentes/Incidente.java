package models.domain.main.incidentes;

import models.domain.converter.LocalDateTimeAttributeConverter;
import models.domain.main.PrestacionDeServicio;
import models.domain.main.localizacion.Localidad;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Miembro;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.time.temporal.WeekFields;
import java.util.Locale;
import java.util.Objects;

@Setter @Getter
@Entity
@Table(name="incidente")
public class Incidente {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name="observaciones", columnDefinition = "TEXT")
  private String observaciones;

  @Column(name="denominacion", columnDefinition = "TEXT")
  private String denominacion;

  @ManyToOne
  @JoinColumn(name = "prestacion_de_servicio_id", referencedColumnName = "id")
  private PrestacionDeServicio prestacion;

  @Convert(converter = LocalDateTimeAttributeConverter.class)
  @Column(name="fechaApertura")
  private LocalDateTime fechaApertura;

  @Convert(converter = LocalDateTimeAttributeConverter.class)
  @Column(name="fechaCierre")
  private LocalDateTime fechaCierre;

  @ManyToOne
  @JoinColumn(name = "comunidad_id", referencedColumnName = "id")
  private Comunidad comunidad;

  @Column(name="abierto", columnDefinition = "BOOLEAN")
  private boolean abierto;

  @OneToOne
  @JoinColumn(name = "creador_id", referencedColumnName = "id")
  private Miembro creador;

  public Incidente(String observaciones, String denominacion, Comunidad comunidad, PrestacionDeServicio prestacion, Miembro creador) {
    this.fechaApertura = LocalDateTime.now();
    this.denominacion = denominacion;
    this.observaciones = observaciones;
    this.comunidad = comunidad;
    this.fechaCierre = null;
    this.abierto = true;
    this.prestacion = prestacion;
    this.creador = creador;
  }

  public Incidente() {

  }

  public void cerrar() {
    setFechaCierre(LocalDateTime.now());
    setAbierto(false);
  }

  public Duration calcularTiempoCierre() {
    LocalDateTime fechaApertura = this.getFechaApertura();
    LocalDateTime fechaCierre = this.getFechaCierre();
    return Duration.between(fechaApertura, fechaCierre);
  }

  public boolean perteneceSemanaActual() {
    LocalDateTime fechaHoraActual = LocalDateTime.now();
    LocalDate inicioSemanaActual = fechaHoraActual.toLocalDate()
        .with(WeekFields.of(Locale.getDefault()).dayOfWeek(), 1);

    LocalDateTime inicioSemanaActualDateTime = inicioSemanaActual.atStartOfDay();

    LocalDateTime finSemanaActualDateTime = inicioSemanaActualDateTime.plusDays(6)
        .withHour(23).withMinute(59).withSecond(59);

    return !fechaApertura.isBefore(inicioSemanaActualDateTime) && !fechaApertura.isAfter(finSemanaActualDateTime);
}

  public boolean esReciente(){
    LocalDateTime fechaHoraActual = LocalDateTime.now();
    LocalDateTime fechaHoraApertura = this.getFechaApertura();
    long horasDiferencia = ChronoUnit.HOURS.between(fechaHoraApertura, fechaHoraActual);
    return horasDiferencia <= 24;
  }

  // MÉTODOS PARA PODER COMPARAR INCIDENTES:
  // Dos incidentes son iguales si tienen misma denominación y si pertenecen a la misma comunidad.
  // Si hace falta más cosas para que sean iguales diganme y lo agrego.
  @Override
  public boolean equals(Object o) {
    if (this == o) return true;
    if (o == null || getClass() != o.getClass()) return false;
    Incidente incidente = (Incidente) o;
    return Objects.equals(denominacion, incidente.getDenominacion()) &&
        Objects.equals(comunidad, incidente.getComunidad());
  }

  @Override
  public int hashCode() {
    return Objects.hash(denominacion, comunidad);
  }

  public Localidad getLocalidad() {
    return this.prestacion.getEstablecimiento().getLocalidad();
  }

}
