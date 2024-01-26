package models.domain.apis.rankingImpactoIncidentes.adapters;

import models.config.Config;
import models.domain.apis.fusionComunidades.FusionService;
import models.domain.apis.fusionComunidades.entities.PayloadDTO;
import models.domain.apis.rankingImpactoIncidentes.RankingImpactoService;
import models.domain.apis.rankingImpactoIncidentes.entities.RequestEntidadDTO;
import models.domain.apis.rankingImpactoIncidentes.entities.ResponseEntidadDTO;
import retrofit2.Call;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

import java.io.IOException;
import java.util.List;

public class RankingServiceRetrofitAdapter implements RankingImpactoAdapter {
  private static final String urlApi = Config.obtenerInstancia().obtenerDelConfig("apiRankingImpacto");
  private final Retrofit retrofit;

  public RankingServiceRetrofitAdapter() {
    this.retrofit = new Retrofit.Builder()
        .baseUrl(urlApi)
        .addConverterFactory(GsonConverterFactory.create())
        .build();
  }

  public List<ResponseEntidadDTO> generarRankingImpacto(List<RequestEntidadDTO> requestsEntidadDTO) throws IOException {
    RankingImpactoService rankingImpactoService  = this.retrofit.create(RankingImpactoService.class);
    Call<List<ResponseEntidadDTO>> requestRankingImpacto = rankingImpactoService.generarRankingImpacto(requestsEntidadDTO);
    Response<List<ResponseEntidadDTO>> responseRankingImpacto = requestRankingImpacto.execute();
    return responseRankingImpacto.body();
  }
}
