package models.domain.main.servicio;

import javax.persistence.*;

@Entity
@DiscriminatorValue("Base")
public class ServicioBase extends Servicio {
  public ServicioBase(String descripcion) {
    super(descripcion);
  }

  public ServicioBase() {

  }
}
