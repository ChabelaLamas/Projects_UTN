package com.api_fusion_comunidades.demo.utils;

import com.api_fusion_comunidades.demo.models.Comunidad;
import com.api_fusion_comunidades.demo.models.Fusion;

import java.util.*;

public class Fusionador {

  public List<Comunidad> ejecutar(List<Comunidad> comunidades, List<Fusion> fusiones) {
    List<Comunidad> nuevasComunidades = new ArrayList<>(comunidades);

    for(Fusion fusion : fusiones) {
      Comunidad nuevaComunidad = this.crearComunidadFusionada(fusion.getComunidad1(), fusion.getComunidad2());

      desactivarComunidad(comunidades, fusion.getComunidad1().getId());
      desactivarComunidad(comunidades, fusion.getComunidad2().getId());
      nuevasComunidades.add(nuevaComunidad);
    }

    return nuevasComunidades;
  }

  private void desactivarComunidad(List<Comunidad> comunidades, Integer id) {
    for (Comunidad comunidad : comunidades) {
      if (Objects.equals(comunidad.getId(), id)) {
        comunidad.setEstado(Comunidad.EstadoComunidad.DESACTIVADA);
        break;
      }
    }
  }

  public Comunidad crearComunidadFusionada (Comunidad comunidad1, Comunidad comunidad2) {
    Set<Integer> nuevosEstablecimientosObservados = new HashSet<>();
    nuevosEstablecimientosObservados.addAll(comunidad1.getIdEstablecimientoObservados());
    nuevosEstablecimientosObservados.addAll(comunidad2.getIdEstablecimientoObservados());

    Set<Integer> nuevosServiciosObservados = new HashSet<>();
    nuevosServiciosObservados.addAll(comunidad1.getIdServiciosObservados());
    nuevosServiciosObservados.addAll(comunidad2.getIdServiciosObservados());

    Set<Integer> nuevosMiembros = new HashSet<>();
    nuevosMiembros.addAll(comunidad1.getIdMiembros());
    nuevosMiembros.addAll(comunidad2.getIdMiembros());

    return new Comunidad( nuevosEstablecimientosObservados.stream().toList(), nuevosServiciosObservados.stream().toList(), nuevosMiembros.stream().toList());
  }

}
