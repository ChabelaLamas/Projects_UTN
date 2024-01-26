package models.domain.apis.fusionComunidades;

import models.domain.apis.fusionComunidades.adapters.FusionAdapter;
import models.domain.apis.fusionComunidades.entities.PayloadDTO;

import java.io.IOException;

public class ServicioFusion {
  private static ServicioFusion instancia = null;
  private FusionAdapter adapter;

  public void setAdapter(FusionAdapter adapter) {
    this.adapter = adapter;
  }

  public static ServicioFusion instancia() {
    if(instancia== null){
      instancia = new ServicioFusion();
    }
    return instancia;
  }

  public PayloadDTO fusionarYSugerirFusiones(PayloadDTO payloadDTO) throws IOException {
    return this.adapter.fusionarYSugerirFusiones(payloadDTO);
  }
}
