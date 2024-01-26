package models.repositorios;

import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.main.informes.rankings.InformeExportable;
import models.domain.main.informes.rankings.Reporte;

import javax.persistence.EntityTransaction;
import javax.persistence.FlushModeType;
import java.util.List;

public class InformeExportableRepository implements WithSimplePersistenceUnit {

    public void guardar(InformeExportable o) {
        entityManager().setFlushMode(FlushModeType.COMMIT);
        EntityTransaction tx = entityManager().getTransaction();
        tx.begin();
        entityManager().persist(o);
        tx.commit();
    }

}
