package models.domain.main.incidentes;

import models.config.Config;
import models.domain.main.notificaciones.Notificador;
import models.domain.main.notificaciones.frecuenciasNotificacion.Notificacion;
import models.domain.usuarios.Persona;
import models.repositorios.IncidenteRepository;
import models.repositorios.PersonaRepository;

import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

public class CronSugerenciaRevisionIncidente extends TimerTask {


    public CronSugerenciaRevisionIncidente() {
        Timer t = new Timer();
        t.scheduleAtFixedRate(this, 0, Config.TIEMPO_NOTIFICACIONES);
    }

    @Override
    public void run() {
        PersonaRepository personaRepository = new PersonaRepository();
        List<Persona> personas = personaRepository.todos();

        IncidenteRepository incidenteRepository = new IncidenteRepository();
        List<Incidente> incidentes = incidenteRepository.todos();

        for (Persona persona : personas) {
            for(Incidente incidente : incidentes) {
                if (persona.getLocalidad().getId().equals(incidente.getLocalidad().getId())) {
                    System.out.println(incidente.getId());
                    Notificador notificador = Notificador.obtenerInstancia();
                    notificador.enviarNotificacion(new Notificacion(persona, incidente, true));
                }
            }
        }


    }
}
