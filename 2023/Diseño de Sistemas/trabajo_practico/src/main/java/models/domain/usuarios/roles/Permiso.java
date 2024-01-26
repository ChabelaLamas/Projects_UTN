package models.domain.usuarios.roles;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Entity
@Table(name = "permiso")
@Setter @Getter
public class Permiso {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name = "nombre")
  private String nombre;

  @Column(name = "nombreInterno")
  private String nombreInterno;

  public Permiso(String nombre, String nombreInterno) {
    this.nombre = nombre;
    this.nombreInterno = nombreInterno;
  }

  public Permiso() {

  }


  public boolean coincideConNombreInterno (String nombre) {
    return this.nombreInterno.equals(nombre);
  }

}
