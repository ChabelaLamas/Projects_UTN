package models.repositorios;

import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.main.localizacion.Provincia;
import models.domain.usuarios.Persona;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;

import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.TypedQuery;
import java.util.List;

public class MenuRepository implements WithSimplePersistenceUnit {

  public List<Menu> hacerListaMenu (TipoRol tipoRol){
    TypedQuery<Menu> query = entityManager().createQuery(
        "SELECT m FROM Menu m WHERE m.tipo = :tipo", Menu.class);
    query.setParameter("tipo", tipoRol);
    return query.getResultList();
  }

  public List<Menu> all() {
    return entityManager().createQuery("from Menu", Menu.class).getResultList();
  }


  public void persistir(List<Menu> menus) {
    EntityTransaction tx = entityManager().getTransaction();
    tx.begin();
    for (Menu m : menus) {
      entityManager().merge(m);

    }
    tx.commit();
  }



}
