package models.indice;

import lombok.Getter;
import lombok.Setter;
import models.domain.usuarios.roles.TipoRol;

import javax.persistence.*;

@Entity
@Table(name = "menu")
@Getter
@Setter
public class Menu {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name = "nombre")
  private String nombre;

  @Column(name = "link")
  private String link;

  @Enumerated(EnumType.STRING)
  @Column(name = "tipo")
  private TipoRol tipo;

  private Boolean activo;

  public Menu(String link, String nombre, TipoRol tipo) {
    this.nombre = nombre;
    this.link = link;
    this.tipo = tipo;
  }

  public Menu() {

  }
}
