package domain.main;

import models.domain.main.Establecimiento;
import models.domain.main.PrestacionDeServicio;
import models.domain.main.entidades.Entidad;
import models.domain.main.entidades.TipoEntidad;
import models.domain.main.incidentes.Incidente;
import models.domain.main.informes.rankings.*;
import models.domain.main.notificaciones.frecuenciasNotificacion.NotificacionCuandoSucedeIncidente;
import models.domain.main.notificaciones.mediosNotificacion.PreferenciaMedioNotificacion;
import models.domain.main.servicio.Servicio;
import models.domain.main.servicio.ServicioBase;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Miembro;
import models.domain.usuarios.Persona;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.Rol;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.quartz.SchedulerException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class RankeadorTest {
  private static Incidente incidente1;
  private static Incidente incidente2;
  private static Entidad entidad1;
  private static Entidad entidad2;
  private static Comunidad comunidad1;
  private static PrestacionDeServicio prestacion1;
  private static Miembro miembro1;
  private static Persona persona1;
  private static Usuario usuario;

  private static CantidadIncidentesReportados cantidadIncidentes;
  private static GradoImpactoProblematicas gradoImpacto;
  private static PromedioCierre promedioCierre;


  @BeforeAll
  public static void init() throws SchedulerException {
    comunidad1 = new Comunidad();

    promedioCierre = new PromedioCierre();
    gradoImpacto = new GradoImpactoProblematicas();
    cantidadIncidentes = new CantidadIncidentesReportados();

    usuario = new Usuario("pepe", "argento", new Rol());
    persona1 = new Persona(usuario, "panchito@gmail.com", "1234");

    miembro1 = new Miembro(persona1,comunidad1);

    Servicio servicio = new ServicioBase("baño sin genero");
    TipoEntidad tipoEntidad = new TipoEntidad();

    entidad1 = new Entidad(tipoEntidad, "entidad1");
    entidad2 = new Entidad(tipoEntidad, "entidad2");

    Establecimiento establecimiento1 = new Establecimiento(entidad1, "Banco Nacion");
    prestacion1 = new PrestacionDeServicio(establecimiento1, servicio);
    Establecimiento establecimiento2 = new Establecimiento(entidad2, "Banco Provincia");
    PrestacionDeServicio prestacion2 = new PrestacionDeServicio(establecimiento2, servicio);

    establecimiento1.getPrestaciones().add(prestacion1);
    establecimiento2.getPrestaciones().add(prestacion2);

    entidad1.getEstablecimientos().add(establecimiento1);
    entidad2.getEstablecimientos().add(establecimiento2);

    incidente1 = new Incidente("observaciones 1", "incidente 1", comunidad1, prestacion1, miembro1);
    incidente2 = new Incidente("observaciones 2", "incidente 2", comunidad1, prestacion2, miembro1);

    prestacion1.getIncidentes().add(incidente1);
    prestacion2.getIncidentes().add(incidente2);
  }

  @Test
  @DisplayName("Ranking: Entidades con mayor promedio de tiempo de cierre de incidentes")
  public void rankingPromedioCierre() throws SchedulerException, InterruptedException {
    incidente1.cerrar();
    Thread.sleep(1000);
    incidente2.cerrar();
    List<Entidad> entidades = new ArrayList<>();
    entidades.add(entidad1);
    entidades.add(entidad2);

    List<String> ranking1 = new ArrayList<>();
    ranking1.add(entidad2.getDenominacion());
    ranking1.add(entidad1.getDenominacion());

    Optional <Ranking> resultado = Rankeador.obtenerInstancia().getRankings().stream().
        filter(ranking -> ranking.getDenominacion().equals("Promedio de cierre de incidente")).findFirst();

    Ranking rankingPromedioCierre = resultado.get();

    try {
    Assertions.assertEquals(ranking1, rankingPromedioCierre.elaborarRanking(entidades));
    } catch (IOException e) {
      // TODO ERROR MANEJAR
    }
  }

  @Test
  @DisplayName("Ranking: Entidades con mayor cantidad de incidentes reportados en la semana")
  public void rankingCantidadIncidentes() throws SchedulerException, InterruptedException {

    Incidente incidente3 = new Incidente("observaciones 3", "incidente 3", comunidad1, prestacion1, miembro1);

    prestacion1.getIncidentes().add(incidente3);

    incidente1.cerrar();
    incidente2.cerrar();
    incidente3.cerrar();

    List<Entidad> entidades = new ArrayList<>();
    entidades.add(entidad1);
    entidades.add(entidad2);

    List<String> ranking2 = new ArrayList<>();
    ranking2.add(entidad1.getDenominacion());
    ranking2.add(entidad2.getDenominacion());

    Optional <Ranking> resultado = Rankeador.obtenerInstancia().getRankings().stream().
        filter(ranking -> ranking.getDenominacion().equals("Cantidad de incidentes reportados")).findFirst();

    Ranking rankingCantidadIncidentes = resultado.get();

    try {
      Assertions.assertEquals(ranking2, rankingCantidadIncidentes.elaborarRanking(entidades));
      prestacion1.getIncidentes().remove(incidente3);
    } catch (IOException e) {
      // TODO MANEJAR ERROR
    }

  }
  @Test
  @DisplayName("Ranking: Mayor grado de impacto de las problemáticas")
  public void rankingGradoImpacto() throws SchedulerException, InterruptedException {
    Comunidad comunidad2 = new Comunidad();

    Miembro miembro1 = new Miembro(persona1, comunidad1);

    Persona persona2 = new Persona(usuario, "vivaLaPepa@gmail.com", "1234");
    Miembro miembro2 = new Miembro(persona2, comunidad1);

    Persona persona3 = new Persona(usuario, "yolo@gmail.com", "1234");
    Miembro miembro3 = new Miembro(persona3, comunidad2);

    incidente1.cerrar();
    incidente2.cerrar();

    List<Entidad> entidades = new ArrayList<>();
    entidades.add(entidad1);
    entidades.add(entidad2);

    List<String> ranking3 = new ArrayList<>();
    ranking3.add(incidente1.getDenominacion());
    ranking3.add(incidente2.getDenominacion());

    Optional <Ranking> resultado = Rankeador.obtenerInstancia().getRankings().stream().
        filter(ranking -> ranking.getDenominacion().equals("Grado de impacto de las problematicas")).findFirst();

    Ranking rankingGradoImpacto = resultado.get();

    try {
      Assertions.assertEquals(ranking3, rankingGradoImpacto.elaborarRanking(entidades));
  } catch (IOException e)
  {
    // TODO MANEJAR ERROR
  }

  }
}
