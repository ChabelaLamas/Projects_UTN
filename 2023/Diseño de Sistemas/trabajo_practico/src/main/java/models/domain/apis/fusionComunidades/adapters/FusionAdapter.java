package models.domain.apis.fusionComunidades.adapters;

import models.domain.apis.fusionComunidades.entities.PayloadDTO;

import java.io.IOException;

public interface FusionAdapter {
  PayloadDTO fusionarYSugerirFusiones(PayloadDTO payloadDTO) throws IOException;
}