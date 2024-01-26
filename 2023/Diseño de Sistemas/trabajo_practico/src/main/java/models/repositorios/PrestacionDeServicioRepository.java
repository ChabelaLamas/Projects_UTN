package models.repositorios;

import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.main.Establecimiento;
import models.domain.main.PrestacionDeServicio;
import models.domain.main.entidades.Entidad;
import models.domain.main.servicio.Servicio;
import models.domain.usuarios.Comunidad;

import javax.persistence.EntityTransaction;
import java.util.List;

public class PrestacionDeServicioRepository implements WithSimplePersistenceUnit {
  public void registrar(PrestacionDeServicio prestacionDeServicio) {
    entityManager().getTransaction().begin();
    entityManager().persist(prestacionDeServicio);
    entityManager().getTransaction().commit();
  }

  public PrestacionDeServicio buscarPorID(Long id) {
    return entityManager().find(PrestacionDeServicio.class, id);
  }


  public void actualizar(PrestacionDeServicio prestacionDeServicio) {
    entityManager().getTransaction().begin();
    entityManager().merge(prestacionDeServicio);
    entityManager().getTransaction().commit();
  }

  public void remove (PrestacionDeServicio prestacionDeServicio) {
    prestacionDeServicio.setEstaActivo(false);
    actualizar(prestacionDeServicio);
  }

  public List<PrestacionDeServicio> todos() {
    return entityManager()
        .createQuery("from PrestacionDeServicio E where E.estaActivo=true")
        .getResultList();
  }
}



/*
  public List<PrestacionDeServicio> prestacionesDeUnServicio (Servicio servicio) {




}
*/