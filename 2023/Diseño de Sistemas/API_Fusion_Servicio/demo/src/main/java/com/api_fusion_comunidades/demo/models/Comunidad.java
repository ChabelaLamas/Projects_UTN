package com.api_fusion_comunidades.demo.models;

import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

@Getter @Setter
public class Comunidad {

    private Integer id;
    private List<Integer> idEstablecimientoObservados;
    private List<Integer> idServiciosObservados;
    private int gradoDeConfianza;
    private List<Integer> idMiembros;
    private EstadoComunidad estado;

    public Comunidad(List<Integer> idEstablecimientoObservados, List<Integer> idServiciosObservados, List<Integer> idMiembros) {
        this.id = null;
        this.idEstablecimientoObservados = idEstablecimientoObservados;
        this.idServiciosObservados = idServiciosObservados;
        this.gradoDeConfianza = 0;
        this.idMiembros = idMiembros;
        this.estado = EstadoComunidad.ACTIVADA;
    }

    public enum EstadoComunidad {
        ACTIVADA,
        DESACTIVADA
    }
}

