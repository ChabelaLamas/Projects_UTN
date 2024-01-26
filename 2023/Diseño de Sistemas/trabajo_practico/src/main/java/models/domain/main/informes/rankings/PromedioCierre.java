package models.domain.main.informes.rankings;

import models.domain.main.Establecimiento;
import models.domain.main.PrestacionDeServicio;
import models.domain.main.entidades.Entidad;
import models.domain.main.incidentes.Incidente;
import models.domain.main.informes.PosicionRanking;

import java.time.DayOfWeek;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.time.temporal.TemporalAdjusters;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class PromedioCierre implements Ranking {

  public PromedioCierre() {
  }

  /*
    * Entidades con mayor promedio de tiempo de cierre de incidentes (diferencia entre horario de cierre
      de incidente y horario de apertura) en la semana.
  */

  public List<PosicionRanking> elaborarRanking(List<Entidad> entidades) {
    List<PosicionRanking> posiciones = new ArrayList<>();

    for (Entidad entidad : entidades) {
      double promedioEntidad = this.calcularPromedioTiempoCierreSemana(entidad);
      PosicionRanking posicion = new PosicionRanking((int)promedioEntidad, entidad);
      posiciones.add(posicion);
    }

    posiciones.sort(new Comparator<PosicionRanking>() {
      public int compare(PosicionRanking o1, PosicionRanking o2) {
          // Coloca todos los elementos con puntaje 0 al final
          if (o1.getPuntaje() == 0 && o2.getPuntaje() != 0) {
              return 1; // o1 es mayor ya que queremos que vaya al final
          } else if (o1.getPuntaje() != 0 && o2.getPuntaje() == 0) {
              return -1; // o1 es menor ya que no queremos que vaya al final
          }

          // Ordena de menor a mayor si ninguno tiene puntaje 0
          return Integer.compare(o1.getPuntaje(), o2.getPuntaje());
      }
    });


    return posiciones;
  }

  public String getDenominacion()
  {
    return "Promedio de cierre de incidente";
  }

  public double calcularPromedioTiempoCierreSemana(Entidad entidad)
  {
      double tiempoTotalCierre = 0;
      int cantidadIncidentes = 0;

      // Obtener la fecha actual
      LocalDateTime now = LocalDateTime.now();

      // Calcular el inicio de la semana (lunes a las 0:00 h)
      LocalDateTime inicioSemana = now.with(TemporalAdjusters.previousOrSame(DayOfWeek.MONDAY))
              .truncatedTo(ChronoUnit.DAYS);

      // Calcular el fin de la semana (domingo a las 23:59 h)
      LocalDateTime finSemana = inicioSemana.plusDays(6).withHour(23).withMinute(59).withSecond(59);

      for (Incidente incidente : entidad.obtenerIncidentesSemanales()) {
            LocalDateTime fechaApertura = incidente.getFechaApertura();
            // Verificar si el incidente está dentro de la semana
            if (fechaApertura.isAfter(inicioSemana) && fechaApertura.isBefore(finSemana)) {
              if (!incidente.isAbierto()){ // Me fijo solo en los incidentes resueltos
                LocalDateTime fechaCierre = incidente.getFechaCierre();
                long tiempoCierre = ChronoUnit.SECONDS.between(fechaApertura, fechaCierre);
                tiempoTotalCierre += tiempoCierre;
                cantidadIncidentes++;
              }
            }
      }
      if (cantidadIncidentes > 0) {
        return tiempoTotalCierre / cantidadIncidentes;
      } else {
        return 0;
      }
  }
}
