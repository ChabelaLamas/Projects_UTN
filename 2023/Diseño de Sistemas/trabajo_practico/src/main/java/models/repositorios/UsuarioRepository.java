package models.repositorios;

import models.domain.usuarios.Usuario;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.usuarios.roles.Rol;
import models.domain.usuarios.roles.TipoRol;

import javax.persistence.EntityManager;
import javax.persistence.NoResultException;
import javax.persistence.TypedQuery;
import java.util.List;

public class UsuarioRepository implements WithSimplePersistenceUnit {

  public void registrar(Usuario usuario) {
    EntityManager em = entityManager();
    em.getTransaction().begin();
    em.persist(usuario);
    em.getTransaction().commit();
    em.close();
  }

  public List<Usuario> todos() {
    EntityManager em = entityManager();
    List<Usuario> usuarios = em.createQuery("from Usuario").getResultList();
    em.close();
    return usuarios;
  }

  public Usuario buscarPorID(Long id) {
    EntityManager em = entityManager();
    Usuario usuario = em.find(Usuario.class, id);
    em.close();
    return usuario;
  }

  public Usuario buscarPorNombreUsuario(String name) {
    EntityManager em = entityManager();
    try {
      TypedQuery<Usuario> query = em.createQuery("SELECT u FROM Usuario u WHERE u.nombre = :nombre", Usuario.class);
      query.setParameter("nombre", name);
      return query.getSingleResult();
    } catch (NoResultException e) {
      // Handle the case where no user with the given name is found
      return null;
    } finally {
      em.close();
    }


  }

  public boolean existeUsuarioConNombre(String nombre) {
    String jpql = "SELECT count(u) FROM Usuario u WHERE u.nombre = :nombre";
    TypedQuery<Long> query = entityManager().createQuery(jpql, Long.class);
    query.setParameter("nombre", nombre);
    return query.getSingleResult() > 0;
  }
}




