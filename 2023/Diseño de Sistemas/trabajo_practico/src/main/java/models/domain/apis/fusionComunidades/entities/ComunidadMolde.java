package models.domain.apis.fusionComunidades.entities;

import lombok.Setter;
import models.domain.usuarios.Comunidad;

import java.util.List;

public class ComunidadMolde {
    public Integer id;
    public List<Integer> idEstablecimientoObservados;
    public List<Integer> idServiciosObservados;
    public int gradoDeConfianza;
    public List<Integer> idMiembros;
    public EstadoComunidad estado;

    public ComunidadMolde(Integer id1, List<Integer> idEstablecimientoObservados1, List<Integer> idServiciosObservados1, int gradoDeConfianza1, List<Integer> idMiembros1) {
      id=id1;
      idEstablecimientoObservados=idEstablecimientoObservados1;
      idServiciosObservados=idServiciosObservados1;
      gradoDeConfianza=gradoDeConfianza1;
      idMiembros=idMiembros1;
      estado=EstadoComunidad.ACTIVADA;
    }

    public ComunidadMolde(Comunidad comunidad) {
      this.id = Math.toIntExact(comunidad.getId());
      this.idEstablecimientoObservados = comunidad.getEstablecimientosObservados().stream().map(x -> Math.toIntExact(x.getId())).toList();
      this.idServiciosObservados = comunidad.getServiciosObservados().stream().map(x -> Math.toIntExact(x.getId())).toList();
      this.gradoDeConfianza = 0;
      this.idMiembros = comunidad.getMiembros().stream().map(x -> Math.toIntExact(x.getId())).toList();
      this.estado = this.getEstado(comunidad);
    }

    private EstadoComunidad getEstado(Comunidad comunidad) {
      if (comunidad.getEstaActivo()) {
        return EstadoComunidad.ACTIVADA;
      } else {
        return EstadoComunidad.DESACTIVADA;
      }
    }

    public enum EstadoComunidad {
      ACTIVADA,
      DESACTIVADA
    }
}



