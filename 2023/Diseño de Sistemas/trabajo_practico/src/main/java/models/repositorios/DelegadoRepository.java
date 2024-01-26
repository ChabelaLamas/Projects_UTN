package models.repositorios;

import models.domain.usuarios.Delegado;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;

import java.util.List;

public class DelegadoRepository implements WithSimplePersistenceUnit {

  public void registrar(Delegado delegado) {entityManager().persist(delegado);}

  public List<Delegado> todos() {
    return entityManager()
        .createQuery("from Delegado")
        .getResultList();
  }

  public Delegado buscarPorID(Long id) {
    return entityManager().find(Delegado.class, id);
  }
}
