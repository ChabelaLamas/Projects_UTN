package models.repositorios;

import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.usuarios.roles.Permiso;

import javax.persistence.EntityTransaction;
import java.util.List;

public class PermisoRepository implements WithSimplePersistenceUnit {

  public void persistir(List<Permiso> permisos) {
    EntityTransaction tx = entityManager().getTransaction();
    tx.begin();
    for (Permiso p : permisos) {
      entityManager().merge(p);
    }
    tx.commit();
  }

  public Permiso buscarPorNombreInterno(String nombreI) {
    Permiso permiso = entityManager().createQuery(
            "SELECT p FROM Permiso p WHERE p.nombreInterno = :nombreI",Permiso.class)
        .setParameter("nombreI", nombreI)
        .getSingleResult();
    return permiso;
  }

  public List<Permiso> all() {
    return entityManager()
        .createQuery("from Permiso")
        .getResultList();
  }
}
