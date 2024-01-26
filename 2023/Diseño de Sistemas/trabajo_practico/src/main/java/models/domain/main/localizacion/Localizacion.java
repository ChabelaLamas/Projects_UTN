package models.domain.main.localizacion;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
@Getter
@Setter
@Entity
public class Localizacion {
  @Id
  @Column(name = "id")
  private Long id;

  @Column(name="nombre")
  private String nombre;

  @ManyToOne
  @JoinColumn(name="provincia_id", referencedColumnName = "id")
  private Provincia provincia;

  @Enumerated(EnumType.STRING)
  @Column(name = "tipo_localizacion")
  private TipoLocalizacion tipoLocalizacion;

  public Localizacion(String nombre, Provincia provincia, TipoLocalizacion tipo) {
    this.nombre = nombre;
    this.provincia = provincia;
    this.tipoLocalizacion = tipo;
  }

  public Localizacion() {

  }

  public boolean esIgualA(Localizacion localizacion) {
    return this.id.equals(localizacion.getId()) && this.nombre.equals(localizacion.getNombre()) && this.provincia.esIgualA(localizacion.getProvincia());
  }
}

