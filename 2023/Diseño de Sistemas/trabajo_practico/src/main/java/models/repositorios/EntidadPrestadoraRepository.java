package models.repositorios;

import models.domain.main.EntidadPrestadora;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;

import java.util.List;

public class EntidadPrestadoraRepository implements WithSimplePersistenceUnit {

  public void registrar(EntidadPrestadora entidadPrestadora) {entityManager().persist(entidadPrestadora);}

  public List<EntidadPrestadora> todos() {
    return entityManager()
        .createQuery("from EntidadPrestadora")
        .getResultList();
  }

  public EntidadPrestadora buscarPorID(Long id) {
    return entityManager().find(EntidadPrestadora.class, id);
  }
}
