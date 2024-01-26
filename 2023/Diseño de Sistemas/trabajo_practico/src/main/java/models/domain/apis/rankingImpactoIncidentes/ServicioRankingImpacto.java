package models.domain.apis.rankingImpactoIncidentes;

import lombok.Getter;
import models.domain.apis.rankingImpactoIncidentes.adapters.RankingImpactoAdapter;
import models.domain.apis.rankingImpactoIncidentes.entities.RequestEntidadDTO;
import models.domain.apis.rankingImpactoIncidentes.entities.ResponseEntidadDTO;

import java.io.IOException;
import java.util.List;

public class ServicioRankingImpacto {
  private static ServicioRankingImpacto instancia = null;
  private RankingImpactoAdapter adapter;

  public void setAdapter(RankingImpactoAdapter adapter) {
    this.adapter = adapter;
  }

  public static ServicioRankingImpacto instancia() {
    if(instancia== null){
      instancia = new ServicioRankingImpacto();
    }
    return instancia;
  }

  public List<ResponseEntidadDTO> generarRankingImpacto(List<RequestEntidadDTO> requestsEntidadDTO) throws IOException {
    return this.adapter.generarRankingImpacto(requestsEntidadDTO);
  }
}
