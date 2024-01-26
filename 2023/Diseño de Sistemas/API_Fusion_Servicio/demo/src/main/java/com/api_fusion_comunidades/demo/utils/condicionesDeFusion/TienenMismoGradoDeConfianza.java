package com.api_fusion_comunidades.demo.utils.condicionesDeFusion;

import com.api_fusion_comunidades.demo.models.Comunidad;
import com.api_fusion_comunidades.demo.models.Fusion;

import java.util.List;


public class TienenMismoGradoDeConfianza implements CondicionDeFusion {
    public Boolean cumpleCondicionDeFusion(Comunidad comunidad1, Comunidad comunidad2, List<Fusion> fusiones) {
        return comunidad1.getGradoDeConfianza() == comunidad2.getGradoDeConfianza();
    }
}
