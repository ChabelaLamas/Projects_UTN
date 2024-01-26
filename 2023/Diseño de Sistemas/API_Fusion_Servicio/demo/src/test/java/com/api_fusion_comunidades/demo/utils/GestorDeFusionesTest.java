package com.api_fusion_comunidades.demo.utils;

import com.api_fusion_comunidades.demo.models.Comunidad;
import com.api_fusion_comunidades.demo.models.Fusion;
import com.api_fusion_comunidades.demo.models.PayloadDTO;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class GestorDeFusionesTest {

  private Comunidad comunidad1;
  private Comunidad comunidad2;
  private List<Fusion> fusiones = new ArrayList<>();
  private List<Comunidad> comunidades = new ArrayList<>();

  @BeforeEach
  public void init() {
    List<Integer> i = new ArrayList<>();
    i.add(1);
    comunidad1 = new Comunidad(1, i,i, 1, i);
    comunidad2 = new Comunidad(2, i,i, 1, i);

    comunidades.add(comunidad1);
    comunidades.add(comunidad2);

    Fusion fusion = new Fusion(comunidad1, comunidad2);
    fusion.setEstado(Fusion.EstadoFusion.ACEPTADA);
    fusiones.add(fusion);
  }

  @Test
  @DisplayName("Se ejecutan las fusiones y tiene que volver el payload correctamente")
  public void devolverPayloadPostFucion() {
    PayloadDTO payload = new GestorDeFusiones().ejecutarFusiones(comunidades, fusiones);
    assertEquals(0, payload.getFusiones().size());
    assertEquals(1, payload.getComunidades().size());
  }
}
