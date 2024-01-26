package models.domain.main.localizacion;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Setter
@Getter
@Entity
@Table(name = "localidad")
public class Localidad {
  @Id
  @Column(name = "id")
  private Long id;

  @Column(name = "nombre_localidad")
  private String nombre;


  @ManyToOne
  @JoinColumn(name = "localizacion_id")
  private Localizacion localizacion;

  private Boolean pertenece;

  public Localidad(String nombre, Localizacion localizacion) {
    this.nombre = nombre;
    this.localizacion = localizacion;
  }

  public Localidad() {
    this.id = null;
    this.nombre = null;
    this.localizacion = null;
  }

  public boolean esIgualA(Localidad localidad) {
    return this.id.equals(localidad.getId()) && this.nombre.equals(localidad.getNombre()) && this.localizacion.esIgualA(localidad.getLocalizacion());
  }
}
