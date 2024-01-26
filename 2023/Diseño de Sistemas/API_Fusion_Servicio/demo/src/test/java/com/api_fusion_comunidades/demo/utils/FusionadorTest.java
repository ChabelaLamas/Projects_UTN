package com.api_fusion_comunidades.demo.utils;

import com.api_fusion_comunidades.demo.models.Comunidad;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class FusionadorTest {

  private Comunidad comunidad1;
  private Comunidad comunidad2;

  @BeforeEach
  public void init() {
    List<Integer> establecimientos1 = new ArrayList<>();
    List<Integer> establecimientos2 = new ArrayList<>();
    List<Integer> servicios1 = new ArrayList<>();
    List<Integer> servicios2 = new ArrayList<>();
    List<Integer> miembros1 = new ArrayList<>();
    List<Integer> miembros2 = new ArrayList<>();

    establecimientos1.add(1);
    establecimientos1.add(2);
    establecimientos2.add(3);

    servicios1.add(5);
    servicios2.add(4);
    servicios2.add(6);
    servicios2.add(7);

    miembros1.add(10);
    miembros2.add(10);

    comunidad1 = new Comunidad(1, establecimientos1,servicios1, 1, miembros1);
    comunidad2 = new Comunidad(2, establecimientos2,servicios2, 1, miembros2);
  }

  @Test
  @DisplayName("Se fusionan 2 comunidades correctamente")
  public void crearComunidadFusionada() {
    Comunidad comunidadFusionada = new Fusionador().crearComunidadFusionada(comunidad1, comunidad2);

    List<Integer> establecimientosEsperados = new ArrayList<>();
    establecimientosEsperados.add(1);
    establecimientosEsperados.add(2);
    establecimientosEsperados.add(3);

    List<Integer> serviciosEsperados = new ArrayList<>();
    serviciosEsperados.add(4);
    serviciosEsperados.add(5);
    serviciosEsperados.add(6);
    serviciosEsperados.add(7);

    List<Integer> miembrosEsperados = new ArrayList<>();
    miembrosEsperados.add(10);

    assertEquals(1, comunidadFusionada.getId());
    assertEquals(establecimientosEsperados, comunidadFusionada.getIdEstablecimientoObservados());
    assertEquals(0, comunidadFusionada.getGradoDeConfianza());
    assertEquals(serviciosEsperados, comunidadFusionada.getIdServiciosObservados());
    assertEquals(miembrosEsperados, comunidadFusionada.getIdMiembros());

  }
}
