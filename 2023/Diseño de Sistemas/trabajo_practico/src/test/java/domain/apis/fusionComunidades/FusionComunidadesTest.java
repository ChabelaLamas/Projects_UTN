package domain.apis.fusionComunidades;

import models.domain.apis.fusionComunidades.ServicioFusion;
import models.domain.apis.fusionComunidades.adapters.FusionAdapter;
import models.domain.apis.fusionComunidades.entities.ComunidadMolde;
import models.domain.apis.fusionComunidades.entities.FusionMolde;
import models.domain.apis.fusionComunidades.entities.PayloadDTO;

import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Miembro;
import org.checkerframework.checker.units.qual.C;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class FusionComunidadesTest {
  private ServicioFusion servicioFusion;
  private FusionAdapter adapterMock;
  private PayloadDTO payloadDTO;
  private ComunidadMolde comunidad1;
  private ComunidadMolde comunidad2;
  private final List<Integer> id1 = new ArrayList<>();
  private final List<Integer> id2 = new ArrayList<>();
  private LocalDateTime fecha;

  @BeforeEach
  public void init() {
    this.adapterMock = mock(FusionAdapter.class);
    this.servicioFusion = ServicioFusion.instancia();
    this.servicioFusion.setAdapter(this.adapterMock);

    id1.add(1);
    id1.add(2);
    id1.add(3);
    id1.add(4);

    id2.add(1);
    id2.add(2);
    id2.add(3);
    id2.add(5);

    comunidad1 = new ComunidadMolde(1, id1, id1, 3, id1);
    comunidad2 = new ComunidadMolde(2, id2, id2, 3, id2);

    payloadDTO = new PayloadDTO();
    payloadDTO.comunidades = new ArrayList<>();
    payloadDTO.comunidades.add(comunidad1);
    payloadDTO.comunidades.add(comunidad2);
    payloadDTO.fusiones = new ArrayList<>();

    fecha = LocalDateTime.now();
  }

  @Test
  public void ServicioFusionDevuelveSugerenciasTest() throws IOException {
    PayloadDTO payloadDTOMock = mock(PayloadDTO.class);
    List<FusionMolde> fusionesMock = this.fusionesMock();

    when(payloadDTOMock.getFusiones()).thenReturn(fusionesMock);
    when(this.adapterMock.fusionarYSugerirFusiones(payloadDTO)).thenReturn(payloadDTOMock);

    Assertions.assertEquals(comunidad1, this.servicioFusion.fusionarYSugerirFusiones(payloadDTO).getFusiones().stream().findFirst().get().comunidad1);
    Assertions.assertEquals(comunidad2, this.servicioFusion.fusionarYSugerirFusiones(payloadDTO).getFusiones().stream().findFirst().get().comunidad2);
  }

  private List<FusionMolde> fusionesMock() {
    List<FusionMolde> fusiones = new ArrayList<>();

    FusionMolde fusion = new FusionMolde();
    fusion.comunidad1= comunidad1;
    fusion.comunidad2 = comunidad2;
    fusion.estado = FusionMolde.EstadoFusion.PROPUESTA;
    fusion.fechaCreada = fecha;

    fusiones.add(fusion);

    return fusiones;
  }
}