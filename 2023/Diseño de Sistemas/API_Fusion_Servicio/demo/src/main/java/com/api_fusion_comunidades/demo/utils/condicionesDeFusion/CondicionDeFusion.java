package com.api_fusion_comunidades.demo.utils.condicionesDeFusion;


import com.api_fusion_comunidades.demo.models.Comunidad;
import com.api_fusion_comunidades.demo.models.Fusion;

import java.util.List;

public interface CondicionDeFusion {
    Boolean cumpleCondicionDeFusion(Comunidad comunidad1, Comunidad comunidad2, List<Fusion> fusiones);
}
