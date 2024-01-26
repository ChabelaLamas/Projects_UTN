package models.domain.main.localizacion;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Getter @Setter
@Entity
@Table(name="provincia")
public class Provincia {
  @Id
  @Column(name = "id")
  private Long id;

  @Column(name = "nombre")
  private String nombre;

  public Provincia(String nombre) {

    this.nombre = nombre;
  }

  public Provincia() {
    this.id = null;
    this.nombre = null;
  }

  public boolean esIgualA(Provincia provincia) {
    return this.id.equals(provincia.getId()) && this.nombre.equals(provincia.getNombre());
  }
}