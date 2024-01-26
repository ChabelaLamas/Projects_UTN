package models.repositorios;

import models.domain.usuarios.Miembro;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.usuarios.Persona;
import org.apache.commons.lang3.ObjectUtils;

import javax.persistence.*;
import java.util.List;

public class MiembroRepository implements WithSimplePersistenceUnit {

  public void registrar(Miembro miembro)
  {
    entityManager().getTransaction().begin();
    entityManager().persist(miembro);
    entityManager().getTransaction().commit();

  }
  public List<Miembro> todos() {
    return entityManager()
        .createQuery("from Miembro")
        .getResultList();
  }

  public Miembro buscarPorID(Long id) {
    return entityManager().find(Miembro.class, id);
  }

  public Miembro buscarMiembroPorPersonaId(Long idPersona, Long idComunidad) {
    try {
      return entityManager()
          .createQuery(
              "SELECT m FROM Miembro m WHERE m.persona.id = :personaId AND m.comunidad.id = :comunidadId",
              Miembro.class
          )
          .setParameter("personaId", idPersona)
          .setParameter("comunidadId", idComunidad)
          .getSingleResult();
    } catch (NoResultException e) {
      // En caso de que no se encuentre ningún resultado, puedes manejarlo aquí
      return null; // O puedes lanzar una excepción personalizada si es necesario
    }
  }

  public List<Miembro> buscarMiembrosDeUsuario(Long idUsuario) {
      return entityManager()
          .createQuery(
              "SELECT m FROM Miembro m JOIN m.persona p WHERE p.usuario.id = :usuarioId",
              Miembro.class
          )
          .setParameter("usuarioId", idUsuario)
          .getResultList();

  }


  public void removeMiembro(Miembro miembro) {
    EntityTransaction tx = entityManager().getTransaction();
    tx.begin();
    miembro.desactivar();
    entityManager().merge(miembro);
    tx.commit();
  }

  public boolean existePersonaEnComunidad(Long idPersona, Long idComunidad) {
    return buscarMiembroPorPersonaId(idPersona, idComunidad) != null;
  }

  public void modificarTipo(Miembro miembro) {
    EntityTransaction tx = entityManager().getTransaction();
    tx.begin();
    miembro.modificarTipoMiembro();
    entityManager().merge(miembro);
    tx.commit();
  }
}
