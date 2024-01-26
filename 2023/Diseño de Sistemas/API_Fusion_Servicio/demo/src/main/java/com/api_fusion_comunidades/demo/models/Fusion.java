package com.api_fusion_comunidades.demo.models;

import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;
import java.util.Date;

@Getter @Setter
public class Fusion {
    private EstadoFusion estado;
    private Comunidad comunidad1;
    private Comunidad comunidad2;
    private LocalDateTime fechaCreada;

    public Fusion(Comunidad comunidad1, Comunidad comunidad2) {
        this.comunidad1 = comunidad1;
        this.comunidad2 = comunidad2;
        this.fechaCreada = LocalDateTime.now();
        this.estado = EstadoFusion.PROPUESTA;
    }

    public enum EstadoFusion {
        PROPUESTA,
        ACEPTADA,
        RECHAZADA
    }

    public Boolean esUnaPropuestaPara (Comunidad comunidadA, Comunidad comunidadB) {
        return sonLasComunidadesDeLaFusion(comunidadA, comunidadB) && this.estado == EstadoFusion.PROPUESTA;
    }

    private Boolean sonLasComunidadesDeLaFusion(Comunidad comunidadA, Comunidad comunidadB) {
        Integer id_comunidad1 = comunidad1.getId();
        Integer id_comunidad2 = comunidad2.getId();
        Integer id_comunidadA = comunidadA.getId();
        Integer id_comunidadB = comunidadB.getId();

        return ( (id_comunidad1.equals(id_comunidadA)||id_comunidad1.equals(id_comunidadB)) && (id_comunidad2.equals(id_comunidadA)||id_comunidad2.equals(id_comunidadB)) );
    }

}



