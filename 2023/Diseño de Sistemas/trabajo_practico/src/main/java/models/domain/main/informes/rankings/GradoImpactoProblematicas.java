package models.domain.main.informes.rankings;

import models.domain.apis.rankingImpactoIncidentes.ServicioRankingImpacto;
import models.domain.apis.rankingImpactoIncidentes.entities.RequestEntidadDTO;
import models.domain.apis.rankingImpactoIncidentes.entities.ResponseEntidadDTO;
import models.domain.main.entidades.Entidad;
import models.domain.main.informes.PosicionRanking;
import models.repositorios.EntidadRepository;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class GradoImpactoProblematicas implements Ranking {

  public GradoImpactoProblematicas() {}

  /*
    * Entidades con mayor cantidad de incidentes reportados en la semana. Una vez que un incidente
    sobre una prestación es reportado por algún usuario, independientemente de la comunidad de la que
    forma parte, no se consideran, para el presente ranking, ningún incidente que se genere sobre dicha
    prestación en un plazo de 24 horas siempre y cuando el mismo continúe abierto.

  */

  public List<PosicionRanking> elaborarRanking(List<Entidad> entidades) throws IOException {
    ServicioRankingImpacto servicioRankingImpacto = ServicioRankingImpacto.instancia();
    List<PosicionRanking> posicionRankings = new ArrayList<>();

    //Esta es la solicitud del ServicioRankingImpacto
    List<RequestEntidadDTO> requestsEntidadDTO = generarRequests(entidades);

    //Esta es la respuesta del ServicioRankingImpacto
    List<ResponseEntidadDTO> responseEntidadDTO = servicioRankingImpacto.generarRankingImpacto(requestsEntidadDTO);

    //Obtenemos una instancia del repositorio de entidades
    EntidadRepository entidadRepository = new EntidadRepository();

    /*
    * Por cada respuesta, obtenemos la entidad, su puntaje y generamos una posicion
    * */
    for (ResponseEntidadDTO responseEntidadDTO1 : responseEntidadDTO) {
      Entidad entidad = entidadRepository.buscarPorID(responseEntidadDTO1.idEntidad.longValue());
      PosicionRanking posicion = new PosicionRanking(responseEntidadDTO1.nivelImpactoEntidad, entidad);
      posicionRankings.add(posicion);
    }
    return posicionRankings;
  }

  private List<RequestEntidadDTO> generarRequests(List<Entidad> entidades) {
    List<RequestEntidadDTO> requests = new ArrayList<>();

    for(Entidad entidad : entidades) {
      RequestEntidadDTO request = new RequestEntidadDTO();
      request.idEntidad = entidad.getId().intValue();
      request.sumatoriaTiemposResolucion = entidad.obtenerSumatoriaTiemposResolucion();
      request.cantidadIncidentesNoResueltos = entidad.obtenerIncidentesNoResueltos();
      request.cantidadMiembrosAfectados = entidad.obtenerCantidaMiembrosAfectados();
      requests.add(request);
    }

    return requests;
  }

  public String getDenominacion()
  {
    return "Grado de impacto de las problematicas";
  }
}
