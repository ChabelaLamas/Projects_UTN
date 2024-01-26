package controllers;
import io.javalin.http.Context;
import models.domain.main.entidades.Entidad;
import models.domain.main.exportar.ApachePDFBox;
import models.domain.main.exportar.Informe;
import models.domain.main.informes.PosicionRanking;
import models.domain.main.informes.rankings.CantidadIncidentesReportados;
import models.domain.main.informes.rankings.GradoImpactoProblematicas;
import models.domain.main.informes.rankings.InformeExportable;
import models.domain.main.informes.rankings.PromedioCierre;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;
import models.repositorios.*;
import server.utils.ICrudViewsHandler;
import services.RankingsService;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.nio.file.Paths;
import java.text.SimpleDateFormat;
import java.util.*;

import static org.hibernate.type.LocalTimeType.FORMATTER;

public class RankingsController extends Controller implements ICrudViewsHandler {

  private CantidadIncidentesReportados cantidadIncidentesReportados;
  private GradoImpactoProblematicas gradoImpactoProblematicas;
  private PromedioCierre promedioCierre;
  private EntidadRepository entidadRepository;
  private UsuarioRepository usuarioRepository;
  private RolRepository rolRepository;
  private MenuRepository menuRepository;
  private RankingsService rankingsService;

  public RankingsController(CantidadIncidentesReportados cantidadIncidentesReportados,
                            GradoImpactoProblematicas    gradoImpactoProblematicas,
                            PromedioCierre               promedioCierre,
                            EntidadRepository            entidadRepository,
                            MenuRepository               menuRepository,
                            UsuarioRepository            usuarioRepository,
                            RolRepository                rolRepository,
                            RankingsService              servicioRanking
  ) {
    this.promedioCierre               = promedioCierre;
    this.cantidadIncidentesReportados = cantidadIncidentesReportados;
    this.gradoImpactoProblematicas    = gradoImpactoProblematicas;
    this.entidadRepository            = entidadRepository;
    this.usuarioRepository            = usuarioRepository;
    this.rolRepository                = rolRepository;
    this.menuRepository               = menuRepository;
    this.rankingsService              = servicioRanking;
  }

  @Override
  public void index (Context context){
    // MENU
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Rankings")));
    Map<String, Object> model = new HashMap<>();
    model.put("menus", menus);
    //
    context.render("rankings.hbs", model);
  }

  @Override
  public void show (Context context) throws IOException {
    Map<String, Object> model = new HashMap<>();
    List<String> ranking = null;
    String descripcion = "";
    List<Entidad> entidades = this.entidadRepository.todos();
    String id = context.pathParam("id");
    switch(id) {
      case "1":
        ranking = this.rankingsService.pasarRankingAString(this.promedioCierre.elaborarRanking(entidades));
        descripcion = "Entidades con mayor promedio de tiempo de cierre de incidentes";
        break;
      case "2":
        ranking = this.rankingsService.pasarRankingAString(this.cantidadIncidentesReportados.elaborarRanking(entidades));
        descripcion = "Entidades con mayor cantidad de incidentes reportados en la semana";
        break;
      case "3":
        //ranking = this.rankingsService.pasarRankingAString(posicionesRanking);
        ranking = new ArrayList<>();
        descripcion = "Incidentes con mayor grado de impacto de las problemáticas";
        break;
    }
    // MENU
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    //InformeExportable informeExportable = new InformeExportable("Descripción del Informe", informe.procesoDatosEntrantes());
    ApachePDFBox pdfBox = new ApachePDFBox();
    //String rutaCompleta = pdfBox.generarInforme(informeExportable);
    //String nombreArchivo = buscarArchivoUltimaSemana(rutaCompleta, id);

    //model.put("nombreArchivo", nombreArchivo);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Rankings")));
    model.put("menus", menus);
    //
    model.put("ranking", ranking);
    model.put("id", id);
    model.put("descripcion", descripcion);

    // Imprime el ranking en la consola
    System.out.println("Ranking: " + ranking);
    context.result(entidades.get(0).getDenominacion());
    context.render("rankingPuntual.hbs", model);
  }

  private String buscarArchivoUltimaSemana(String rutaCompleta, String id) {
    try {
      // Extraer la fecha del nombre del archivo
      String[] partes = rutaCompleta.split("/");
      String nombreArchivo = partes[partes.length - 1];

      SimpleDateFormat formatter = new SimpleDateFormat("yyyyMMdd");
      Date fechaArchivo = formatter.parse(nombreArchivo.substring(0, 8));

      // Obtener el inicio y fin de la semana
      Calendar calendar = Calendar.getInstance();
      calendar.setTime(fechaArchivo);
      int weekYear = calendar.get(Calendar.WEEK_OF_YEAR);
      int year = calendar.get(Calendar.YEAR);

      // Filtro para archivos de la misma semana
      FilenameFilter filter = (dir, name) -> {
        try {
          Date fecha = formatter.parse(nombreArchivo.substring(0, 8));
          calendar.setTime(fecha);
          return calendar.get(Calendar.WEEK_OF_YEAR) == weekYear && calendar.get(Calendar.YEAR) == year;
        } catch (Exception e) {
          return false;
        }
      };

      // Listar archivos en el directorio
      File dir = new File(Paths.get("/2023-tpa-mama-grupo-04/src/main/resources/public/exportados/").toUri());

      File[] archivosSemana = dir.listFiles(filter);

      if (archivosSemana != null && archivosSemana.length > 0) {
        // Ordenar los archivos por fecha de modificación
        Arrays.sort(archivosSemana, Comparator.comparingLong(File::lastModified));

        // Lógica para seleccionar el archivo basado en el ID
        String sufijo = id.equals("1") ? "PROMEDIO_CIERRE_INCIDENTES" : "MAYOR_CANTIDAD_INCIDENTES.pdf";
        for (int i = archivosSemana.length - 1; i >= 0; i--) {
          if (archivosSemana[i].getName().endsWith(sufijo)) {
            return archivosSemana[i].getName();
          }
        }
      }
    } catch (Exception e) {
      e.printStackTrace();
    }

    return "No encontrado";
  }

  private Map<String, List<String>> convertirDatos(List<PosicionRanking> posiciones) {
    Map<String, List<String>> datos = new HashMap<>();
    int posicion = 1; // Para llevar la cuenta de la posición en el ranking

    for (PosicionRanking entrada : posiciones) {
      // Suponiendo que PosicionRanking tiene métodos getEntidad() y getPuntaje()
      String nombreEntidad = entrada.getEntidad().getDenominacion();
      String tipoEntidad = entrada.getEntidad().getTipo().getTipoEntidad();
      String puntaje = String.valueOf(entrada.getPuntaje());

      List<String> detalles = Arrays.asList(String.valueOf(posicion), nombreEntidad, tipoEntidad, puntaje);
      datos.put(String.valueOf(posicion), detalles);
      posicion++;
    }

    return datos;
  }


  // NADA
  public void create (Context context){
  }

  @Override
  public void save (Context context){
  }

  @Override
  public void edit (Context context){
  }

  @Override
  public void update (Context context){
  }

  @Override
  public void delete (Context context){
  }
}