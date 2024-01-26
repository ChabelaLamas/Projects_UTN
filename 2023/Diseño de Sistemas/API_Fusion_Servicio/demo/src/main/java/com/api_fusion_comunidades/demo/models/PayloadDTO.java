package com.api_fusion_comunidades.demo.models;

import lombok.Getter;

import java.util.List;

@Getter
public class PayloadDTO {
  private List<Comunidad> comunidades;
  private List<Fusion> fusiones;

  public PayloadDTO(List<Comunidad> comunidades, List<Fusion> fusiones) {
    this.comunidades = comunidades;
    this.fusiones = fusiones;
  }
}