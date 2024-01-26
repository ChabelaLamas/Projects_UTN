package models.domain.apis.rankingImpactoIncidentes.adapters;

import models.domain.apis.rankingImpactoIncidentes.entities.RequestEntidadDTO;
import models.domain.apis.rankingImpactoIncidentes.entities.ResponseEntidadDTO;

import java.io.IOException;
import java.util.List;

public interface RankingImpactoAdapter {
  List<ResponseEntidadDTO> generarRankingImpacto(List<RequestEntidadDTO> requestsEntidadDTO) throws IOException;
}
