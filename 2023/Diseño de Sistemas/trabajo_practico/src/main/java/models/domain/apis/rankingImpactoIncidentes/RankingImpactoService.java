package models.domain.apis.rankingImpactoIncidentes;

import models.domain.apis.fusionComunidades.entities.PayloadDTO;
import models.domain.apis.rankingImpactoIncidentes.entities.RequestEntidadDTO;
import models.domain.apis.rankingImpactoIncidentes.entities.ResponseEntidadDTO;
import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.POST;

import java.util.List;

public interface RankingImpactoService {
  @POST
  Call<List<ResponseEntidadDTO>> generarRankingImpacto(@Body List<RequestEntidadDTO> requestsEntidadDTO);
}
