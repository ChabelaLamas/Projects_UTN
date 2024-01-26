package controllers;

import io.javalin.http.Context;
import models.domain.main.Establecimiento;
import models.domain.main.entidades.Entidad;
import models.domain.main.entidades.TipoEntidad;
import models.domain.main.servicio.Servicio;
import models.domain.main.servicio.ServicioBase;
import models.domain.usuarios.*;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;
import models.json.JsonComunidad;
import models.repositorios.*;
import org.jetbrains.annotations.NotNull;
import server.exceptions.AccessDeniedException;
import server.utils.ICrudViewsHandler;

import javax.transaction.Transactional;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class ComunidadesController extends Controller implements ICrudViewsHandler {

  private ComunidadRepository comunidadRepository;
  private UsuarioRepository usuarioRepository;
  private MiembroRepository miembroRepository;
  private PersonaRepository personaRepository;
  private EstablecimientoRepository establecimientoRepository;
  private ServicioRepository servicioRepository;
  private RolRepository rolRepository;
  private MenuRepository menuRepository;

  public ComunidadesController(ComunidadRepository comunidadRepository, UsuarioRepository usuarioRepository, MiembroRepository miembroRepository, PersonaRepository personaRepository, EstablecimientoRepository establecimientoRepository, ServicioRepository servicioRepository, RolRepository rolRepository, MenuRepository menuRepository) {
    this.comunidadRepository = comunidadRepository;
    this.usuarioRepository = usuarioRepository;
    this.miembroRepository = miembroRepository;
    this.personaRepository = personaRepository;
    this.establecimientoRepository = establecimientoRepository;
    this.servicioRepository = servicioRepository;
    this.rolRepository = rolRepository;
    this.menuRepository = menuRepository;
  }
  @Override
  public void index(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "ver_mis_comunidades")) {
      throw new AccessDeniedException();
    }
    List<Miembro> miembros = miembroRepository.buscarMiembrosDeUsuario(usuario.getId()).stream().filter(x->x.getComunidad().getEstaActivo() && x.getEstaActivo()).toList();

    Map<String, Object> model = new HashMap<>();

    model.put("usuario", usuario);
    model.put("miembros", miembros);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Comunidades")));
    model.put("menus", menus);
    //
    context.render("listarComunidades.hbs", model);
  }


  @Override
  public void show(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "ver_todas_comunidades")) {
      throw new AccessDeniedException();
    }

    // Obtener todas las comunidades
    List<Comunidad> comunidades = comunidadRepository.todos().stream().filter(x->x.getEstaActivo()).toList();


    Map<String, Object> modelo = new HashMap<>();
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    modelo.put("menus", menus);
    //
    modelo.put("comunidades", comunidades);
    modelo.put("usuario", usuario);
    context.render("listarTodasComunidades.hbs", modelo);
  }


  @Override
  public void create(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<Establecimiento> establecimientos = establecimientoRepository.todos().stream().filter(x->"true".equals(String.valueOf(x.getEstaActivo()))).toList();
    List<Servicio> servicios = servicioRepository.todos();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("establecimientos", establecimientos);
    model.put("servicios", servicios);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("crearComunidad.hbs", model);

  }


public void add (Context context) {
  Long usuarioId = context.sessionAttribute("usuario_id");
  Usuario usuario = usuarioRepository.buscarPorID(usuarioId);

  if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "sumar_a_comunidad")) {
    throw new AccessDeniedException();
  }

  Persona persona = personaRepository.buscarPorIDUsuario(usuarioId);

  // Obtener todas las comunidades
  List<Comunidad> todasComunidades = comunidadRepository.todos();
  List<Comunidad> comunidadesSinMiembro = new ArrayList<>();
  // Cargar los establecimientos y servicios para todas las comunidades
  for (Comunidad comunidad : todasComunidades) {
    if (!miembroRepository.existePersonaEnComunidad(persona.getId(),comunidad.getId()) && comunidad.getEstaActivo()){
      cargarEstablecimientosEnComunidad(comunidad.getId());
      cargarServiciosEnComunidad(comunidad.getId());
      comunidadesSinMiembro.add(comunidad);
    }
  }
  List<ComunidadView> comunidadesView = new ArrayList<>();

  for (Comunidad comunidad : comunidadesSinMiembro) {
    ComunidadView cv = new ComunidadView();
    cv.setId(comunidad.getId());
    cv.setNombre(comunidad.getNombre());

    String servicios = comunidad.getServiciosObservados()
        .stream()
        .map(servicio -> servicio.getDescripcion())
        .collect(Collectors.joining(", "));
    cv.setServicios(servicios);

    String establecimientos = comunidad.getEstablecimientosObservados()
        .stream()
        .map(establecimiento -> establecimiento.getDenominacion())
        .collect(Collectors.joining(", "));
    cv.setEstablecimientos(establecimientos);

    comunidadesView.add(cv);
  }

  Map<String, Object> modelo = new HashMap<>();
  // MENU
  TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
  List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
  menus.forEach(m -> m.setActivo(m.getNombre().equals("Comunidades")));
  modelo.put("menus", menus);
  //
  modelo.put("comunidades", comunidadesView);
  modelo.put("usuario", usuario);
  context.render("sumarAComunidad.hbs", modelo);
}



  @Override
  public void save(Context context) {
    Long comunidadId = Long.valueOf(context.formParam("comunidad_id"));
    String tipoMiembro = context.formParam("tipo"); // Esto te devuelve "observador" o "afectado".
    Long usuarioId = context.sessionAttribute("usuario_id");
    Usuario usuario = usuarioRepository.buscarPorID(usuarioId);

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "ver_incidentes_de_mis_comunidades")) {
      throw new AccessDeniedException();
    }


    Persona persona = this.personaRepository.buscarPorIDUsuario(usuarioId);
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidadId);

    Miembro miembro = comunidadRepository.agregarPersonaAComunidad(persona, comunidad, tipoMiembro);
    miembroRepository.registrar(miembro);

    context.redirect("/comunidades"); // Redirigir al listado de comunidades
  }


  @Override
  public void edit(Context context) {
    Long comunidadId = Long.valueOf(context.formParam("selectedComunidad"));
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidadId);
    Long usuarioId = context.sessionAttribute("usuario_id");
    Usuario usuario = usuarioRepository.buscarPorID(usuarioId);

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "editar_comunidad")) {
      throw new AccessDeniedException();
    }

    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    Map<String, Object> model = new HashMap<>();
    model.put("menus", menus);
    //
    List<Servicio> servicios = comunidad.getServiciosObservados();
    List<Servicio> ser = new ArrayList<>();
    ser.add(new ServicioBase("pep"));
    List<Establecimiento> es = new ArrayList<>();
    TipoEntidad t = new TipoEntidad("jij", "joj");

    es.add(new Establecimiento(new Entidad(t,"lol"), "cha"));
    model.put("servicios", ser);
    List<Establecimiento> establecimientos = comunidad.getEstablecimientosObservados();
    model.put("establecimientos", es);
    model.put("comunidad", comunidad);
    context.render("editarComunidad.hbs", model);

  }

  @Override
  public void update(Context context) {
    //TODO
  }

  @Override
  public void delete(Context context) {
    Long comunidadId = Long.parseLong(context.pathParam("comunidad_id"));
    Long usuarioId = Long.parseLong(context.pathParam("usuario_id"));
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "ver_mis_comunidades")) {
      throw new AccessDeniedException();
    }

    Persona persona = personaRepository.buscarPorIDUsuario(usuarioId);
    Miembro miembro = miembroRepository.buscarMiembroPorPersonaId(persona.getId(), comunidadId);
    miembroRepository.removeMiembro(miembro);
    // MENU

    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Inicio")));
    Map<String, Object> model = new HashMap<>();
    model.put("menus", menus);
    //
    context.redirect("/comunidades"); // Redirige a la lista de comunidades u otra página

  }

  @Transactional
  public void cargarEstablecimientosEnComunidad(Long comunidadId) {
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidadId); // Obtén la comunidad por su ID
    if (comunidad != null) {
      // Limpia la lista actual de establecimientos (si es necesario)
      //comunidad.limpiarEstablecimientosObservados();

      // Obtén los establecimientos relacionados a través de la tabla intermedia
      List<Establecimiento> establecimientos = establecimientoRepository.obtenerEstablecimientosAsociados(comunidadId);

      // Agrega los establecimientos a la lista de la comunidad
      comunidad.setEstablecimientosObservados(establecimientos);

      // Guarda la comunidad actualizada en la base de datos
      comunidadRepository.actualizar(comunidad);
    }
  }

  @Transactional
  public void cargarServiciosEnComunidad(Long comunidadId) {
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidadId); // Obtén la comunidad por su ID
    if (comunidad != null) {
      // Limpia la lista actual de establecimientos (si es necesario)
      comunidad.getServiciosObservados().clear();

      // Obtén los establecimientos relacionados a través de la tabla intermedia
      List<Servicio> servicios = servicioRepository.obtenerServiciosAsociados(comunidadId);

      // Agrega los establecimientos a la lista de la comunidad
      comunidad.getServiciosObservados().addAll(servicios);

      // Guarda la comunidad actualizada en la base de datos
      comunidadRepository.actualizar(comunidad);
    }
  }


  public void guardar(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonComunidad data = context.bodyAsClass(JsonComunidad.class);

    String nombre = data.getNombre();
    String denominacion = data.getDenominacion();
    List<Long> establecimientosId = data.getEstablecimientos();
    List<Establecimiento> establecimientos = establecimientosId.stream().map(x->establecimientoRepository.buscarPorID(x)).toList();
    List<Long> serviciosId = data.getServicios();
    List<Servicio> servicios = serviciosId.stream().map(x->servicioRepository.buscarPorID(x)).toList();

    Comunidad comunidad = new Comunidad(nombre, denominacion, servicios, establecimientos);
    comunidadRepository.registrar(comunidad);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Comunidad guardada exitosamente");
    context.json(respuesta);
  }

  public void deleteComunidad( Context context) {
    Long comunidad_id = Long.parseLong(context.pathParam("comunidad_id"));
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidad_id);
    comunidadRepository.remove(comunidad);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<Comunidad> comunidades = comunidadRepository.todos().stream().filter(x->x.getEstaActivo()).toList();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("comunidades", comunidades);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.redirect("/todas-comunidades");
  }

  public void ver(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long comunidad_id = Long.parseLong(context.pathParam("comunidad_id"));
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidad_id);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<Establecimiento> establecimientos = establecimientoRepository.obtenerEstablecimientosAsociados(comunidad_id).stream().filter(x->x.getEstaActivo()).toList();
    List<Servicio> servicios = servicioRepository.obtenerServiciosAsociados(comunidad_id);
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("comunidad", comunidad);
    model.put("establecimientos", establecimientos);
    model.put("servicios", servicios);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("mostrarComunidad.hbs", model);
  }


  public void editar(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long comunidad_id = Long.parseLong(context.pathParam("comunidad_id"));
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidad_id);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<Establecimiento> establecimientos = establecimientoRepository.todos().stream().filter(x->x.getEstaActivo()).toList();
    establecimientos.forEach(x->
        {
          x.setPertenece(comunidad.getEstablecimientosObservados().contains(x));
        }
    );
    List<Servicio> servicios = servicioRepository.todos();
    servicios.forEach(x->
        {
          x.setPertenece(
              comunidad.getServiciosObservados().contains(x));
        }
    );
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("comunidad", comunidad);
    model.put("establecimientos", establecimientos);
    model.put("servicios", servicios);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("editarComunidad.hbs", model);

  }

  public void guardarEdit(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long comunidad_id = Long.parseLong(context.pathParam("comunidad_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonComunidad data = context.bodyAsClass(JsonComunidad.class);

    String nombre = data.getNombre();
    String denominacion = data.getDenominacion();
    List<Long> establecimientosId = data.getEstablecimientos();
    List<Establecimiento> establecimientos = establecimientosId.stream().map(x->establecimientoRepository.buscarPorID(x)).toList();
    List<Long> serviciosId = data.getServicios();
    List<Servicio> servicios = serviciosId.stream().map(x->servicioRepository.buscarPorID(x)).toList();
    Comunidad comunidad = comunidadRepository.buscarPorID(comunidad_id);
    comunidad.editar(nombre, denominacion, servicios, establecimientos);
    comunidadRepository.actualizar(comunidad);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Comunidad editada exitosamente");
    context.json(respuesta);
  }

  public void modificarTipoMiembro(Context context) {
    Long miembroId = Long.parseLong(context.pathParam("miembro_id"));
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Miembro miembro = miembroRepository.buscarPorID(miembroId);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "ver_mis_comunidades")) {
      throw new AccessDeniedException();
    }

    miembroRepository.modificarTipo(miembro);
    // MENU

    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Inicio")));
    Map<String, Object> model = new HashMap<>();
    model.put("menus", menus);
    //
    context.redirect("/comunidades"); // Redirige a la lista de comunidades u otra página


  }
}
