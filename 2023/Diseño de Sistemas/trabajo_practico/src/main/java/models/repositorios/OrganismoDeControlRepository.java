package models.repositorios;

import models.domain.main.OrganismoDeControl;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;

import java.util.List;

public class OrganismoDeControlRepository implements WithSimplePersistenceUnit {

  public void registrar(OrganismoDeControl organismoDeControl)
  {
    entityManager().persist(organismoDeControl);
  }

  public List<OrganismoDeControl> todos() {
    return entityManager()
        .createQuery("from OrganismoDeControl")
        .getResultList();
  }

  public OrganismoDeControl buscarPorID(Long id) {
    return entityManager().find(OrganismoDeControl.class, id);
  }
}
