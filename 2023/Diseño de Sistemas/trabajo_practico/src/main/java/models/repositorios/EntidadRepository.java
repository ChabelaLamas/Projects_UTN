package models.repositorios;

import models.domain.main.Establecimiento;
import models.domain.main.entidades.Entidad;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;

import javax.persistence.EntityTransaction;
import java.util.ArrayList;
import java.util.List;

public class EntidadRepository implements WithSimplePersistenceUnit {

  public void registrar(Entidad entidad) {
    entityManager().getTransaction().begin();
    entityManager().persist(entidad);
    entityManager().getTransaction().commit();
  }


  public Entidad buscarPorID(Long id) {
    return entityManager().find(Entidad.class, id);
  }

  public void actualizar(Entidad entidad) {
    entityManager().getTransaction().begin();
    entityManager().merge(entidad);
    entityManager().getTransaction().commit();
  }

  public void remove(Entidad entidad) {
    entidad.setEstaActivo(false);
    actualizar(entidad);
  }

  public List<Entidad> todos() {
    try {
      return entityManager()
              .createQuery("SELECT e FROM Entidad e WHERE e.estaActivo = true", Entidad.class)
              .getResultList();
    } catch (Exception e) {
      e.printStackTrace();
      return new ArrayList<>();
    }
  }

}
