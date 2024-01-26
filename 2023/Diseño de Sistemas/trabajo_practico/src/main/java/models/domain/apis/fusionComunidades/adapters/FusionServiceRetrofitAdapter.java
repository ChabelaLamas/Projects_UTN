package models.domain.apis.fusionComunidades.adapters;

import models.config.Config;
import models.domain.apis.fusionComunidades.FusionService;
import models.domain.apis.fusionComunidades.entities.PayloadDTO;
import retrofit2.Call;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

import java.io.IOException;

public class FusionServiceRetrofitAdapter implements FusionAdapter {
  private static final String urlApi = Config.obtenerInstancia().obtenerDelConfig("apiFusionComunidades");
  private final Retrofit retrofit;

  public FusionServiceRetrofitAdapter() {
    this.retrofit = new Retrofit.Builder()
        .baseUrl(urlApi)
        .addConverterFactory(GsonConverterFactory.create())
        .build();
  }

  public PayloadDTO fusionarYSugerirFusiones(PayloadDTO payloadDTO) throws IOException {
    FusionService fusionService = this.retrofit.create(FusionService.class);
    Call<PayloadDTO> requestFusionesYSugerencias = fusionService.fusionarYSugerirFusiones(payloadDTO);
    Response<PayloadDTO> responseFusionesYSugerencias = requestFusionesYSugerencias.execute();
    return responseFusionesYSugerencias.body();
  }
}
