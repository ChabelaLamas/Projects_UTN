package com.api_fusion_comunidades.demo.controllers;

import com.api_fusion_comunidades.demo.models.PayloadDTO;
import com.api_fusion_comunidades.demo.services.APIService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController @RequestMapping
public class APIController {
  @Autowired
  private APIService apiService;

  @PostMapping
  public ResponseEntity<PayloadDTO> fusionarYSugerir(@RequestBody PayloadDTO solicitud){
    PayloadDTO payload = apiService.fusionarYSugerir(solicitud.getComunidades(), solicitud.getFusiones());
    return ResponseEntity.ok(payload);
  }

}



