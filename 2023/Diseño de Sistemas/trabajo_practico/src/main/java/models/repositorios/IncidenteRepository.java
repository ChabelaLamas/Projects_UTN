package models.repositorios;

import models.domain.main.incidentes.Incidente;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.usuarios.Comunidad;
import org.apache.http.conn.util.PublicSuffixList;

import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.TypedQuery;
import java.time.LocalDateTime;
import java.util.Date;
import java.util.List;

import static org.hsqldb.Tokens.CURRENT_TIMESTAMP;

public class IncidenteRepository implements WithSimplePersistenceUnit {

  public void registrar(Incidente incidente)
  {
    EntityManager em = entityManager();
    EntityTransaction tx = em.getTransaction();

    try {
      tx.begin(); // Iniciar la transacción
      em.persist(incidente); // Realizar la operación de persistencia
      tx.commit(); // Confirmar la transacción si todo va bien
    } catch (Exception e) {
      if (tx != null && tx.isActive()) {
        tx.rollback(); // Revertir la transacción en caso de error
      }
      e.printStackTrace(); // Manejar la excepción apropiadamente
    } finally {
      em.close(); // Cerrar el EntityManager cuando hayas terminado
    }
  }

  public List<Incidente> todos() {
    return entityManager()
        .createQuery("SELECT i FROM Incidente i", Incidente.class)
        .getResultList();
  }
  public Incidente buscarPorID(Long id) {
    return entityManager().find(Incidente.class, id);
  }

  //TODO: buscarIncidentesDeTodasLasComunidades
  //public List<Incidente> buscarIncidentesDeTodasLasComunidades (Long comunidadId)

  public void cerrarIncidente(Incidente incidente) {
    incidente.cerrar();
    entityManager().getTransaction().begin();
    entityManager().merge(incidente);
    entityManager().getTransaction().commit();

  }

  public void borrarTodos() {
    entityManager()
        .createQuery("DELETE FROM Incidente")
        .executeUpdate();
  }
}
