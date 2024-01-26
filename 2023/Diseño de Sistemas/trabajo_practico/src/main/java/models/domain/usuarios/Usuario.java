package models.domain.usuarios;

import lombok.Getter;
import lombok.Setter;
import models.domain.usuarios.roles.Rol;

import javax.persistence.*;

@Getter
@Entity
@Table(name="usuario")
public class Usuario {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Setter
  @Column(name="nombre", columnDefinition = "TEXT", unique = true)
  private String nombre;

  @Column(name="contrasenia", columnDefinition = "TEXT")
  private String contraseniaEncriptada;

  @ManyToOne
  @JoinColumn(name = "rol_id", referencedColumnName = "id")
  private Rol rol;

  public Usuario(String nombre, String contraseniaEncriptada, Rol rol) {
    this.nombre = nombre;
    this.contraseniaEncriptada = contraseniaEncriptada;
    this.rol = rol;
  }
  public Usuario() {

  }
}
