package com.api_fusion_comunidades.demo.utils.condicionesDeFusion;

import com.api_fusion_comunidades.demo.conifg.Config;
import com.api_fusion_comunidades.demo.models.Comunidad;
import com.api_fusion_comunidades.demo.models.Fusion;

import java.time.LocalDateTime;
import java.util.List;

public class NoSePropusoHacePoco implements CondicionDeFusion {
  @Override
  public Boolean cumpleCondicionDeFusion(Comunidad comunidad1, Comunidad comunidad2, List<Fusion> fusiones) {
    List<Fusion> propuestasRecientes = fusiones.stream().filter(fusion -> fusion.esUnaPropuestaPara(comunidad1, comunidad2) && this.sePropusoHacePoco(fusion)).toList();

    return propuestasRecientes.size() == 0;
  }

  private boolean sePropusoHacePoco(Fusion fusion) {
    int cantidadMesesDiferencia = Integer.parseInt(Config.obtenerInstancia().obtenerDelConfig("mesesDeDiferenciaEntrePropuestas"));

    LocalDateTime fechaLimite = LocalDateTime.now().minusMonths(cantidadMesesDiferencia);

    return fusion.getFechaCreada().isAfter(fechaLimite);
  }
}
