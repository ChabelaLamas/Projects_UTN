package models.domain.main.servicio;
import models.domain.usuarios.Persona;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@Entity
@DiscriminatorValue("Compuesto")
public class ServicioCompuesto extends Servicio {
  @ManyToMany
  @JoinTable(
          name = "servicio_compuesto",
          joinColumns = @JoinColumn(name = "servicio_compuesto_id"),
          inverseJoinColumns = @JoinColumn(name = "servicio_id"))
  private List<Servicio> servicios = new ArrayList<>();

  public ServicioCompuesto(String descripcion, Servicio ... otrosServicios) {
    super(descripcion);
    agregarServicios(otrosServicios);
  }

  public ServicioCompuesto() {

  }

  public void agregarServicios(Servicio ... serviciosNuevos){
    servicios.addAll(Arrays.stream(serviciosNuevos).toList());
  }

  public void eliminarServicios(Servicio ... serviciosASacar){
    servicios.removeAll(Arrays.stream(serviciosASacar).toList());
  }
}
