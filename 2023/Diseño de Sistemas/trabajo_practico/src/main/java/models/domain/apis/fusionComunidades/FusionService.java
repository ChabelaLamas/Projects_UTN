package models.domain.apis.fusionComunidades;

import models.domain.apis.fusionComunidades.entities.PayloadDTO;
import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.POST;

public interface FusionService {
  @POST
  Call<PayloadDTO> fusionarYSugerirFusiones(@Body PayloadDTO payloadDTO);
}