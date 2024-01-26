package controllers;

    import com.fasterxml.jackson.databind.ObjectMapper;
    import com.mysql.cj.protocol.x.CompressionAlgorithm;
    import models.domain.main.Establecimiento;
    import models.domain.main.PrestacionDeServicio;
    import models.domain.main.entidades.Entidad;
    import models.domain.main.incidentes.Incidente;
    import models.domain.main.servicio.Servicio;
    import models.domain.main.servicio.ServicioBase;
    import models.domain.usuarios.Comunidad;
    import models.domain.usuarios.Miembro;
    import models.domain.usuarios.Persona;
    import models.domain.usuarios.Usuario;
    import models.domain.usuarios.roles.TipoRol;
    import models.indice.Menu;
    import models.json.JsonComunidad;
    import models.json.JsonIncidente;
    import models.repositorios.*;
    import io.javalin.http.Context;
    import net.bytebuddy.asm.Advice;
    import org.jetbrains.annotations.NotNull;
    import server.exceptions.AccessDeniedException;
    import server.utils.ICrudViewsHandler;

    import java.time.LocalDateTime;
    import java.util.ArrayList;
    import java.util.HashMap;
    import java.util.List;
    import java.util.Map;

public class IncidentesController extends Controller implements ICrudViewsHandler {
  private IncidenteRepository incidenteRepository;
  private UsuarioRepository usuarioRepository;
  private ComunidadRepository comunidadRepository;
  private ServicioRepository servicioRepository;
  private MenuRepository menuRepository;
  private RolRepository rolRepository;
  private MiembroRepository miembroRepository;
  private PersonaRepository personaRepository;
  private PrestacionDeServicioRepository prestacionDeServicioRepository;

  public IncidentesController(IncidenteRepository incidenteRepository, UsuarioRepository usuarioRepository,
                              ComunidadRepository comunidadRepository, ServicioRepository servicioRepository,
                              RolRepository rolRepository, MenuRepository menuRepository, MiembroRepository miembroRepository, PersonaRepository personaRepository, PrestacionDeServicioRepository prestacionRepository) {
    this.incidenteRepository = incidenteRepository;
    this.usuarioRepository = usuarioRepository;
    this.comunidadRepository = comunidadRepository;
    this.servicioRepository = servicioRepository;
    this.rolRepository = rolRepository;
    this.menuRepository = menuRepository;
    this.miembroRepository = miembroRepository;
    this.personaRepository = personaRepository;
    this.prestacionDeServicioRepository = prestacionRepository;
  }

  @Override
  public void index(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "sumar_a_comunidad")) {
      throw new AccessDeniedException();
    }
    List<Comunidad> comunidades = this.comunidadRepository.buscarComunidadesUsuario(usuario).stream().filter(x->x.getEstaActivo()).toList();
    List<Incidente> incidentes = new ArrayList<>();

    for (Comunidad comunidad : comunidades) {
        List<Incidente> incidentesComunidad = comunidad.getIncidentes();
        if (!incidentesComunidad.isEmpty()) {
            incidentes.addAll(incidentesComunidad);
        }
    }

    Map<String, Object> model = new HashMap<>();

    model.put("comunidades", comunidades);
    model.put("incidentes", incidentes);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Incidentes")));
    model.put("menus", menus);
    //
    context.render("listarIncidentes.hbs", model);
  }

  @Override
  public void show(Context context) {
    //TODO
  }

  @Override
  public void create(Context context) {
      Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "crear_incidente")) {
      throw new AccessDeniedException();
    }

      List<Comunidad> comunidades = this.comunidadRepository.buscarComunidadesUsuario(usuario).stream().filter(x->x.getEstaActivo()).toList();
      List<PrestacionDeServicio> prestaciones = new ArrayList<>();

      for(Comunidad comunidad: comunidades) {
          for(Establecimiento establecimiento : comunidad.getEstablecimientosObservados()) {
              prestaciones.addAll(establecimiento.getPrestaciones().stream().filter(x->x.getEstaActivo()).toList());
          }
      }

      Map<String, Object> model = new HashMap<>();
      model.put("comunidades", comunidades);
      model.put("prestaciones", prestaciones);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Incidentes")));
    model.put("menus", menus);
    //
        context.render("crearIncidente.hbs", model);
  }

  @Override
  public void save(Context context) {

    JsonIncidente incidenteDTO = context.bodyAsClass(JsonIncidente.class);
    Persona p = personaRepository.buscarPorIDUsuario(context.sessionAttribute("usuario_id"));
    Miembro creador = miembroRepository.buscarMiembroPorPersonaId(p.getId(),incidenteDTO.getComunidad_id());
    Incidente nuevoIncidente = new Incidente();
    nuevoIncidente.setCreador(creador);
    PrestacionDeServicio ps= prestacionDeServicioRepository.buscarPorID(incidenteDTO.getPrestacion_id());
    nuevoIncidente.setPrestacion(ps);
    nuevoIncidente.setDenominacion(incidenteDTO.getIncidente_denominacion());
    nuevoIncidente.setObservaciones(incidenteDTO.getIncidente_observaciones());
    nuevoIncidente.setFechaApertura(LocalDateTime.now());
    nuevoIncidente.setFechaCierre(null);
    nuevoIncidente.setAbierto(true);
    nuevoIncidente.setComunidad(comunidadRepository.buscarPorID(incidenteDTO.getComunidad_id()));

    // Registra el nuevo incidente
    this.incidenteRepository.registrar(nuevoIncidente);
    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Incidente creado exitosamente");
    context.json(respuesta);
  }

  @Override
  public void edit(Context context) {
    //TODO
  }

  @Override
  public void update(Context context) {
    String id = context.pathParam("id");
    this.incidenteRepository.cerrarIncidente(incidenteRepository.buscarPorID(Long.valueOf(id)));

    context.redirect("../../incidentes");
  }

  @Override
  public void delete(Context context) {
    //TODO
  }


}
