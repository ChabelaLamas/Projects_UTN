package domain.main;
import models.domain.main.Establecimiento;
import models.domain.main.PrestacionDeServicio;
import models.domain.main.entidades.Entidad;
import models.domain.main.entidades.TipoEntidad;
import models.domain.main.incidentes.Incidente;
import models.domain.main.notificaciones.Notificador;
import models.domain.main.notificaciones.frecuenciasNotificacion.NotificacionSinApuros;
import models.domain.main.notificaciones.mediosNotificacion.PreferenciaMedioNotificacion;
import models.domain.main.servicio.Servicio;
import models.domain.main.servicio.ServicioBase;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Miembro;
import models.domain.usuarios.Persona;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.Rol;
import org.junit.jupiter.api.Test;
import org.quartz.*;

import java.time.LocalDateTime;
import java.time.Month;
import java.util.ArrayList;
import java.util.List;

class NotificacionesTest {
  Notificador notificador = Notificador.obtenerInstancia();

  @Test
  void notificarIncidentes() throws SchedulerException, InterruptedException {
    NotificacionSinApuros notificacionSinApuros = new NotificacionSinApuros();
    Comunidad comunidad = new Comunidad();
    Usuario usuario = new Usuario("pepe", "argento", new Rol());
    List<LocalDateTime> listaHorarios = new ArrayList<>();

    LocalDateTime horarioEspecifico1 = LocalDateTime.of(2023, Month.JULY, 10, 13, 15);
    LocalDateTime horarioEspecifico2 = LocalDateTime.of(2023, Month.JULY, 10, 13, 16);

    listaHorarios.add(horarioEspecifico1);
    listaHorarios.add(horarioEspecifico2);
    Persona persona1 = new Persona(usuario, "ej1@gmail.com", "1234");
    Persona persona2 = new Persona(usuario, "ej2@gmail.com", "1234");
    Servicio servicio = new ServicioBase("baño sin genero");
    TipoEntidad tipoEntidad = new TipoEntidad();
    Entidad entidad = new Entidad(tipoEntidad, "entidad");
    Establecimiento establecimiento1 = new Establecimiento(entidad, "Banco Nacion");
    PrestacionDeServicio prestacion = new PrestacionDeServicio(establecimiento1, servicio);

    Miembro miembro1 = new Miembro(persona1, comunidad);

    LocalDateTime now = LocalDateTime.now();
    String observaciones = "";
    String denominacion = " ";
    Incidente incidente1 = new Incidente(observaciones, denominacion, comunidad, prestacion, miembro1);
    incidente1.setFechaApertura(now.minusHours(23)); // menos de 24 hs

    Incidente incidente2 = new Incidente(observaciones, denominacion, comunidad, prestacion, miembro1);
    incidente2.setFechaApertura(now.minusHours(23)); // mas de 24 hs

    Incidente incidente3 = new Incidente(observaciones, denominacion, comunidad, prestacion, miembro1);
    incidente3.setFechaApertura(now.minusHours(25)); // entre las 24 hs

    notificacionSinApuros.gestionarInicidente(persona1, incidente1);
    notificacionSinApuros.gestionarInicidente(persona2, incidente3);

    System.out.println("Esperando mensajes");

    Thread.sleep(60000);
    notificacionSinApuros.gestionarInicidente(persona1, incidente2);
    Thread.sleep(100000);
  }
}
