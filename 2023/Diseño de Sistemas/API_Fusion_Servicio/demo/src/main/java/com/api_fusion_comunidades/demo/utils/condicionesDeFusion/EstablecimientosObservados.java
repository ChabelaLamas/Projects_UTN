package com.api_fusion_comunidades.demo.utils.condicionesDeFusion;


import com.api_fusion_comunidades.demo.models.Comunidad;
import com.api_fusion_comunidades.demo.conifg.Config;
import com.api_fusion_comunidades.demo.models.Fusion;
import com.api_fusion_comunidades.demo.utils.Calculador;

import java.util.List;

public class EstablecimientosObservados implements CondicionDeFusion {

    float porcentajeRequerido = Float.parseFloat(Config.obtenerInstancia().obtenerDelConfig("porcentajeEnComunEstablecimientos"));

    public Boolean cumpleCondicionDeFusion(Comunidad comunidad1, Comunidad comunidad2, List<Fusion> fusiones) {
        float porcentajeEnComun = Calculador.obtenerInstancia().calcularPorcentajeEnComun(comunidad1.getIdEstablecimientoObservados(), comunidad2.getIdEstablecimientoObservados());

        return porcentajeEnComun >= porcentajeRequerido;
    }
}
