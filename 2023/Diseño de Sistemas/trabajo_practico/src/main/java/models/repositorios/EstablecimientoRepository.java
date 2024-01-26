package models.repositorios;

import models.domain.main.Establecimiento;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Miembro;

import javax.persistence.EntityTransaction;
import javax.persistence.NoResultException;
import javax.persistence.PersistenceException;
import java.util.ArrayList;
import java.util.List;

public class EstablecimientoRepository implements WithSimplePersistenceUnit {

  public void registrar(Establecimiento establecimiento) {
    entityManager().getTransaction().begin();
    entityManager().persist(establecimiento);
    entityManager().getTransaction().commit();
  }

  public void actualizar(Establecimiento establecimiento) {
    entityManager().getTransaction().begin();
    entityManager().merge(establecimiento);
    entityManager().getTransaction().commit();
  }

  public void remove (Establecimiento establecimiento) {
    establecimiento.setEstaActivo(false);
    actualizar(establecimiento);
  }

  public List<Establecimiento> todos() {
    return entityManager()
        .createQuery("from Establecimiento E where E.estaActivo=true")
        .getResultList();
  }

  public Establecimiento buscarPorID(Long id) {
    return entityManager().find(Establecimiento.class, id);
  }

  public List<Establecimiento> obtenerEstablecimientosAsociados(Long comunidadId) {

      String jpql = "SELECT e FROM Establecimiento e " +
          "JOIN e.comunidadesAsociadas c " +
          "WHERE c.id = :comunidadId";

      return entityManager().createQuery(jpql, Establecimiento.class)
          .setParameter("comunidadId", comunidadId)
          .getResultList();

    }

}
