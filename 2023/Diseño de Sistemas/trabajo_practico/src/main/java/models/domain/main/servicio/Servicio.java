package models.domain.main.servicio;

import lombok.Setter;
import models.domain.main.OrganismoDeControl;
import models.domain.main.PrestacionDeServicio;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Persona;
import lombok.Getter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Inheritance(strategy = InheritanceType.SINGLE_TABLE)
@Getter
@Setter
@DiscriminatorColumn(name = "tipo")
public abstract class Servicio {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name="descripcion")
  private String descripcion;

  @OneToMany(mappedBy = "servicio", cascade = CascadeType.ALL, orphanRemoval = true)
  private List<PrestacionDeServicio> prestacionesDeServicio = new ArrayList<>();

  @ManyToOne
  @JoinColumn(name = "organismo_de_control_id", referencedColumnName = "id")
  private OrganismoDeControl organismoDeControl;

  @ManyToMany(mappedBy = "serviciosObservados")
  private List<Comunidad> comunidadesAsociadas = new ArrayList<>();

  @Setter
  private Boolean pertenece = false;

  public Servicio(String descripcion) {
    this.descripcion = descripcion;
  }

  public Servicio() {

  }
}
