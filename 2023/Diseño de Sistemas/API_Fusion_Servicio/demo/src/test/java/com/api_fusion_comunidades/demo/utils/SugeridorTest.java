package com.api_fusion_comunidades.demo.utils;

import com.api_fusion_comunidades.demo.models.Comunidad;
import com.api_fusion_comunidades.demo.models.PayloadDTO;
import com.api_fusion_comunidades.demo.models.Fusion;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SugeridorTest {

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
  }

  @Test
  @DisplayName("Se propone una fusion")
  public void sugerirFusion() {
    PayloadDTO payload = new Sugeridor().sugerirNuevasFusiones(comunidades, fusiones);
    assertEquals(comunidad1, payload.getFusiones().get(0).getComunidad1());
  }

  @Test
  @DisplayName("Se propone una fusion y nos aseguramos que no se repita")
  public void sugerirFusiones() {
    fusiones.add(new Fusion(comunidad1, comunidad2));

    PayloadDTO payload = new Sugeridor().sugerirNuevasFusiones(comunidades, fusiones);
    assertEquals(1, payload.getFusiones().size());
  }
}
