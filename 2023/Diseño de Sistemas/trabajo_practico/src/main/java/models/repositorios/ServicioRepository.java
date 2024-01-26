package models.repositorios;

import models.domain.main.Establecimiento;
import models.domain.main.servicio.Servicio;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.usuarios.Comunidad;

import java.util.List;

public class ServicioRepository implements WithSimplePersistenceUnit {

  public void registrar(Servicio servicio)
  {
    entityManager().persist(servicio);
  }

  public List<Servicio> todos() {
    return entityManager()
        .createQuery("from Servicio")
        .getResultList();
  }

  public Servicio buscarPorID(Long id) {
    return entityManager().find(Servicio.class, id);
  }




  public List<Servicio> obtenerServiciosAsociados(Long comunidadId) {
    String jpql = "SELECT e FROM Servicio e " +
        "JOIN e.comunidadesAsociadas c " +
        "WHERE c.id = :comunidadId";

    return entityManager().createQuery(jpql, Servicio.class).setParameter("comunidadId", comunidadId).getResultList();
  }
}
