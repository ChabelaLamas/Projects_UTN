package models.domain.usuarios.roles;

import lombok.Getter;
import lombok.Setter;
import org.hibernate.Hibernate;

import javax.persistence.*;
import java.util.Collections;
import java.util.ConcurrentModificationException;
import java.util.HashSet;
import java.util.Set;

@Entity
@Table(name = "rol")
@Getter @Setter
public class Rol {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name = "nombre")
  private String nombre;

  @Enumerated(EnumType.STRING)
  @Column(name = "tipo")
  private TipoRol tipo;

  @ManyToMany
  private Set<Permiso> permisos;

  public Rol() {this.permisos = new HashSet<>();}

  public Rol(String nombre, TipoRol tipo, Set<Permiso> permisos) {
    this.nombre = nombre;
    this.tipo = tipo;
    this.permisos = permisos;
  }

  public void agregarPermisos(Permiso ... permisos) {
    Collections.addAll(this.permisos, permisos);
  }

  public boolean tienePermiso(String nombreInterno) {
    try {
      Hibernate.initialize(this.permisos); // Cargar los permisos antes de cerrar la sesión
      if (this.permisos != null) {
        int cantidadPermisos = this.permisos.size();
        boolean tienePermiso = this.permisos.stream().anyMatch(p -> p.coincideConNombreInterno(nombreInterno));
        return tienePermiso;
      } else {
        throw new NullPointerException("El conjunto de permisos es nulo.");
      }
    } catch (NullPointerException e) {
      e.printStackTrace(); // Manejo de excepción de conjunto de permisos nulo
      return false; // O cualquier otra acción que consideres adecuada
    } catch (Exception e) {
      e.printStackTrace(); // Manejo de otras excepciones no previstas
      return false; // O cualquier otra acción que consideres adecuada
    }
  }






  public boolean tienePermiso(Permiso permiso) { return this.permisos.contains(permiso); }
}
