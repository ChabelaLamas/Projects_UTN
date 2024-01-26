package controllers;

import io.javalin.http.Context;
import models.domain.main.EntidadPrestadora;
import models.domain.main.Establecimiento;
import models.domain.main.PrestacionDeServicio;
import models.domain.main.entidades.Entidad;
import models.domain.main.entidades.TipoEntidad;
import models.domain.main.incidentes.Incidente;
import models.domain.main.localizacion.Localidad;
import models.domain.main.notificaciones.mediosNotificacion.PreferenciaMedioNotificacion;
import models.domain.main.servicio.Servicio;
import models.domain.usuarios.Comunidad;
import models.domain.usuarios.Miembro;
import models.domain.usuarios.Persona;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.Rol;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;
import models.json.JsonComunidad;
import models.json.JsonEntidad;
import models.json.JsonEstablecimiento;
import models.json.JsonPrestacion;
import models.repositorios.*;
import models.validadorDeContrasenias.ValidadorDeContrasenia;
import models.validadorDeContrasenias.excepciones.ExcepcionComplejidad;
import models.validadorDeContrasenias.excepciones.ExcepcionContraseniaInvalida;
import models.validadorDeContrasenias.excepciones.ExcepcionLongitud;
import org.jetbrains.annotations.NotNull;
import server.exceptions.AccessDeniedException;
import server.utils.ICrudViewsHandler;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.security.NoSuchAlgorithmException;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static models.domain.usuarios.roles.TipoRol.ADMINISTRADOR;
import static models.domain.usuarios.roles.TipoRol.CONSUMIDOR;

public class AdministrarController  extends Controller implements ICrudViewsHandler {
  private ValidadorDeContrasenia validadorDeContrasenia;
  private UsuarioRepository usuarioRepository;
  private MenuRepository menuRepository;
  private IncidenteRepository incidenteRepository;
  private RolRepository rolRepository;
  private EstablecimientoRepository establecimientoRepository;
  private PrestacionDeServicioRepository prestacionDeServicioRepository;
  private LocalizacionRepository localizacionRepository;
  private EntidadRepository entidadRepository;
  private EntidadPrestadoraRepository entidadPrestadoraRepository;
  private ServicioRepository servicioRepository;
  private PersonaRepository personaRepository;

  private ComunidadRepository comunidadRepository;

  public AdministrarController(UsuarioRepository usuarioRepository, MenuRepository menuRepository, RolRepository rolRepository, EstablecimientoRepository establecimientoRepository,
                               PrestacionDeServicioRepository prestacionDeServicioRepository, LocalizacionRepository localizacionRepository, EntidadRepository entidadRepository,
                               EntidadPrestadoraRepository entidadPrestadoraRepository, ServicioRepository servicioRepository, ValidadorDeContrasenia validadorDeContrasenia,
                               PersonaRepository personaRepository, IncidenteRepository incidenteRepository, ComunidadRepository comunidadRepository) {
    this.usuarioRepository = usuarioRepository;
    this.rolRepository = rolRepository;
    this.menuRepository = menuRepository;
    this.establecimientoRepository = establecimientoRepository;
    this.prestacionDeServicioRepository = prestacionDeServicioRepository;
    this.localizacionRepository = localizacionRepository;
    this.entidadRepository = entidadRepository;
    this.entidadPrestadoraRepository = entidadPrestadoraRepository;
    this.validadorDeContrasenia = validadorDeContrasenia;
    this.servicioRepository = servicioRepository;
    this.personaRepository = personaRepository;
    this.incidenteRepository = incidenteRepository;
    this.comunidadRepository = comunidadRepository;

  }

  @Override
  public void index (Context context){
    Long usuarioId = context.sessionAttribute("usuario_id");
    Usuario usuario = usuarioRepository.buscarPorID(usuarioId);

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    Map<String, Object> model = new HashMap<>();
    model.put("menus", menus);
    //
    context.render("administrar.hbs", model);
  }

  @Override
  public void show(Context context) throws IOException {

  }

  @Override
  public void create(Context context) {

  }

  @Override
  public void save(Context context) {

  }

  @Override
  public void edit(Context context) {

  }

  @Override
  public void update(Context context) {

  }

  @Override
  public void delete(Context context) {

  }

  public void indexEst( Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<Establecimiento> establecimientos = establecimientoRepository.todos();
    establecimientos.stream().filter(x->x.getEstaActivo());
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("establecimientos", establecimientos);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("listarEstablecimientos.hbs", model);
  }

  public void crearEst(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<Localidad> localidades = localizacionRepository.todasLasLocalidades().stream().sorted(Comparator.comparing(Localidad::getNombre)).toList();
    List<Entidad> entidades = entidadRepository.todos().stream().filter(x->x.getEstaActivo()).toList();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("localidades", localidades);
    model.put("entidades", entidades);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("crearEstablecimiento.hbs", model);
  }

  public void guardarEst( Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonEstablecimiento data = context.bodyAsClass(JsonEstablecimiento.class);

    // Ahora 'data' contiene tus datos del JSON
    String denominacion = data.getDenominacion();
    Long entidad_id = data.getEntidad();
    Long localidad_id = data.getLocalidad();

    Localidad localidad = localizacionRepository.buscarLocalidadPorId(localidad_id);
    Entidad entidad = entidadRepository.buscarPorID(entidad_id);

    Establecimiento establecimiento = new Establecimiento(denominacion, entidad, localidad);
    establecimientoRepository.registrar(establecimiento);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Establecimiento guardado exitosamente");
    context.json(respuesta);
  }

  public void deleteEstablecimiento(Context context) {
    Long establecimiento_id = Long.parseLong(context.pathParam("establecimiento_id"));
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Establecimiento establecimiento = establecimientoRepository.buscarPorID(establecimiento_id);
    establecimientoRepository.remove(establecimiento);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<Establecimiento> establecimientos = establecimientoRepository.todos();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("establecimientos", establecimientos);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.redirect("/todos-establecimientos");

  }

  public void indexIncidentes( Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<Incidente> incidentes = incidenteRepository.todos();
    List<Comunidad> comunidades = comunidadRepository.todos();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("incidentes", incidentes);
    model.put("comunidades", comunidades);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("listarTodosIncidentes.hbs", model);
  }

  public void indexEnt(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<Entidad> entidades = entidadRepository.todos();
    entidades.stream().filter(x->x.getEstaActivo());
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("entidades", entidades);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("listarEntidades.hbs", model);
  }

  public void crearEnt(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<EntidadPrestadora> entidadesPrestadoras = entidadPrestadoraRepository.todos();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("entidadesPrestadoras", entidadesPrestadoras);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("crearEntidad.hbs", model);
  }

  public void guardarEnt( Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonEntidad data = context.bodyAsClass(JsonEntidad.class);

    String denominacion = data.getDenominacion() ;
    String tipoEntidad = data.getTipoEntidad() ;
    String tipoEstablecimiento = data.getTipoEstablecimiento();
    Long entidadPrestadoraId = data.getEntidadPrestadoraId();


    EntidadPrestadora entidadPrestadora = entidadPrestadoraRepository.buscarPorID(entidadPrestadoraId);
    TipoEntidad tipoEntidadClase = new TipoEntidad(tipoEntidad, tipoEstablecimiento);

    Entidad entidad = new Entidad(tipoEntidadClase, denominacion, entidadPrestadora);
    entidadRepository.registrar(entidad);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Entidad guardada exitosamente");
    context.json(respuesta);
  }

  public void deleteEntidad(Context context) {

    Long entidad_id = Long.parseLong(context.pathParam("entidad_id"));
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Entidad entidad = entidadRepository.buscarPorID(entidad_id);
    entidadRepository.remove(entidad);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<Entidad> entidades = entidadRepository.todos();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("entidades", entidades);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.redirect("/todas-entidades");
  }

  public void indexPrest(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<PrestacionDeServicio> prestacionesDeServicios = prestacionDeServicioRepository.todos().stream().filter(x->x.getEstaActivo()).toList();

    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("prestacionesDeServicios", prestacionesDeServicios);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("listarPrestaciones.hbs", model);
  }

  public void crearPrest(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<Establecimiento> establecimientos = establecimientoRepository.todos().stream().filter(x->x.getEstaActivo()).toList();
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
    context.render("crearPrestacion.hbs", model);
  }

  public void guardarPrest(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonPrestacion data = context.bodyAsClass(JsonPrestacion.class);

    Long establecimientoId = data.getEstablecimiento() ;
    Establecimiento establecimiento = establecimientoRepository.buscarPorID(establecimientoId);
    Long servicioId = data.getServicio();
    Servicio servicio = servicioRepository.buscarPorID(servicioId);
    PrestacionDeServicio prestacionDeServicio = new PrestacionDeServicio(establecimiento, servicio);

    prestacionDeServicioRepository.registrar(prestacionDeServicio);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Prestación de Servicio guardada exitosamente");
    context.json(respuesta);
  }

  public void deletePrestacion(Context context) {
    Long prestacion_id = Long.parseLong(context.pathParam("prestacion_id"));
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    PrestacionDeServicio prestacionDeServicio = prestacionDeServicioRepository.buscarPorID(prestacion_id);
    prestacionDeServicioRepository.remove(prestacionDeServicio);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<PrestacionDeServicio> prestacionDeServicios = prestacionDeServicioRepository.todos();
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("prestaciones", prestacionDeServicios);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.redirect("/todas-prestaciones");
  }

  public void verPres(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long prestacion_id = Long.parseLong(context.pathParam("prestacion_id"));
    PrestacionDeServicio prestacion = prestacionDeServicioRepository.buscarPorID(prestacion_id);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("prestacion", prestacion);

    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("mostrarPrestacion.hbs", model);
  }

  public void verEnti(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long entidad_id = Long.parseLong(context.pathParam("entidad_id"));
    Entidad entidad = entidadRepository.buscarPorID(entidad_id);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("entidad", entidad);

    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("mostrarEntidad.hbs", model);
  }
  public void verEnta(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long establecimiento_id = Long.parseLong(context.pathParam("establecimiento_id"));
    Establecimiento establecimiento = establecimientoRepository.buscarPorID(establecimiento_id);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("establecimiento", establecimiento);

    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("mostrarEstablecimiento.hbs", model);
  }


  public void crearAdmin(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "crear_administrador")) {
      throw new AccessDeniedException();
    }

    Map<String, Object> model = new HashMap<>();

    String errorType = context.queryParam("error");
    if (errorType != null) {
      switch (errorType) {
        case "complexity":
          model.put("errorMessage", "La contraseña debe tener mayúsculas, minúsculas, números y símbolos.");
          break;
        case "length":
          model.put("errorMessage", "La contraseña no cumple con la longitud requerida.");
          break;
        case "invalid_password":
          model.put("errorMessage", "Contraseña inválida.");
          break;
        case "registration_error":
          model.put("errorMessage", "Error al intentar registrar al usuario. Inténtelo nuevamente.");
          break;
        case "username_exists":
          model.put("errorMessage", "El nombre de usuario ya está en uso.");
          break;
        case "email_exists":
          model.put("errorMessage", "El correo electrónico/ o teléfono ya está en uso.");
          break;
        default:
          model.put("errorMessage", "Ocurrió un error al intentar registrarse.");
          break;
      }
    }

    context.render("signupAdmin.hbs", model);
  }

  public void guardarAdmin( Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "crear_administrador")) {
      throw new AccessDeniedException();
    }

    String nombre = context.formParam("nombre");
    String contrasenia = context.formParam("contrasenia");
    String valorMedio = context.formParam("valor-medio");
    String telefonoYMail = context.formParam("telefonoYMail");
    String tipoSeleccionado = context.formParam("tipoSeleccionado");
    String contraseniaEncriptada = " ";

    // Verificar si el nombre de usuario ya está en uso
    if (usuarioRepository.existeUsuarioConNombre(nombre)) {
      context.redirect("/crear-administrador?error=username_exists");
      return;
    }
    try {
      validadorDeContrasenia.verificarValidez(nombre, contrasenia);
    } catch (ExcepcionComplejidad e) {
      context.redirect("/crear-administrador?error=complexity");
      return;
    } catch (ExcepcionLongitud e) {
      context.redirect("/crear-administrador?error=length");
      return;
    } catch (ExcepcionContraseniaInvalida e) {
      context.redirect("/crear-administrador?error=invalid_password");
      return;
    }

    try {
      Rol rol = rolRepository.buscarPorTipoRol(ADMINISTRADOR);
      contraseniaEncriptada = validadorDeContrasenia.encriptarContrasenia(contrasenia);
      Usuario usuarioNuevo = new Usuario(nombre, contraseniaEncriptada, rol);
      usuarioRepository.registrar(usuarioNuevo);

      Persona persona;
      if (tipoSeleccionado.equals("correo")) {
        persona = new Persona(usuarioNuevo, telefonoYMail, "");
      } else {
        persona = new Persona(usuarioNuevo, "", telefonoYMail);
      }
      PreferenciaMedioNotificacion medio = PreferenciaMedioNotificacion.valueOf(valorMedio);
      persona.setPreferenciaMedioNotificacion(medio);
      personaRepository.registrar(persona);

      context.redirect("/perfil");
    } catch (NoSuchAlgorithmException | ClassNotFoundException | NoSuchMethodException | InvocationTargetException | InstantiationException | IllegalAccessException e) {
      e.printStackTrace();
      context.redirect("/crear-administrador?error=registration_error");
    }


  }

  public void editarPrest(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long prestacion_id = Long.parseLong(context.pathParam("prestacion_id"));
    PrestacionDeServicio prestacion = prestacionDeServicioRepository.buscarPorID(prestacion_id);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<Establecimiento> establecimientos = establecimientoRepository.todos().stream().filter(x->x.getEstaActivo()).toList();
    establecimientos.forEach(x->
        {
          x.setPertenece(prestacion.getEstablecimiento().equals(x));
        }
    );
    List<Servicio> servicios = servicioRepository.todos();
    servicios.forEach(x->
        {
          x.setPertenece(prestacion.getServicio().equals(x));
        }
    );
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("prestacion", prestacion);
    model.put("establecimientos", establecimientos);
    model.put("servicios", servicios);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("editarPrestacion.hbs", model);
  }

  public void guardarEditPrest(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long prestacion_id = Long.parseLong(context.pathParam("prestacion_id"));
    PrestacionDeServicio prestacion = prestacionDeServicioRepository.buscarPorID(prestacion_id);
    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonPrestacion data = context.bodyAsClass(JsonPrestacion.class);

    Long establecimientoId = data.getEstablecimiento() ;
    Establecimiento establecimiento = establecimientoRepository.buscarPorID(establecimientoId);
    Long servicioId = data.getServicio();
    Servicio servicio = servicioRepository.buscarPorID(servicioId);
    prestacion.editar(establecimiento, servicio);

    prestacionDeServicioRepository.actualizar(prestacion);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Prestación de Servicio guardada exitosamente");
    context.json(respuesta);
  }


  public void editarEnti(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long entidad_id = Long.parseLong(context.pathParam("entidad_id"));
    Entidad entidad = entidadRepository.buscarPorID(entidad_id);

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    List<EntidadPrestadora> entidadesPrestadoras = entidadPrestadoraRepository.todos();
    entidadesPrestadoras.forEach(x->
        {
          x.setPertenece(entidad.getEntidadPrestadora().equals(x));
        }
    );
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("entidadesPrestadoras", entidadesPrestadoras);
    model.put("entidad", entidad);
    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("editarEntidad.hbs", model);
  }

  public void guardarEditEnti(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long entidad_id = Long.parseLong(context.pathParam("entidad_id"));
    Entidad entidad = entidadRepository.buscarPorID(entidad_id);

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonEntidad data = context.bodyAsClass(JsonEntidad.class);

    String denominacion = data.getDenominacion() ;
    String tipoEntidad = data.getTipoEntidad() ;
    String tipoEstablecimiento = data.getTipoEstablecimiento();
    Long entidadPrestadoraId = data.getEntidadPrestadoraId();


    EntidadPrestadora entidadPrestadora = entidadPrestadoraRepository.buscarPorID(entidadPrestadoraId);
    TipoEntidad tipoEntidadClase = new TipoEntidad(tipoEntidad, tipoEstablecimiento);

    entidad.editar(tipoEntidadClase, denominacion, entidadPrestadora);
    entidadRepository.actualizar(entidad);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Entidad guardada exitosamente");
    context.json(respuesta);
  }


  public void editarEsta(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long establecimiento_id = Long.parseLong(context.pathParam("establecimiento_id"));
    Establecimiento establecimiento = establecimientoRepository.buscarPorID(establecimiento_id);

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }
    List<Localidad> localidades = localizacionRepository.todasLasLocalidades();
    List<Entidad> entidades = entidadRepository.todos().stream().filter(x->x.getEstaActivo()).toList();

    localidades.forEach(x->
        {
          x.setPertenece(establecimiento.getLocalidad().equals(x));
        }
    );
    Entidad e = establecimiento.getEntidad();
    entidades.forEach(x->
        {
          x.setPertenece(e.equals(x));
        }
    );
    entidades.stream().filter(x->x.getEstaActivo());

    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuario);
    model.put("localidades", localidades);
    model.put("entidades", entidades);
    model.put("establecimiento", establecimiento);

    // MENU
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Administrar")));
    model.put("menus", menus);
    //
    context.render("editarEstablecimiento.hbs", model);
  }

  public void guardarEditEsta(Context context) {
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    Long establecimiento_id = Long.parseLong(context.pathParam("establecimiento_id"));
    Establecimiento establecimiento = establecimientoRepository.buscarPorID(establecimiento_id);

    if(usuario == null || !rolRepository.tienePermiso(usuario.getRol().getId(), "administrar_recursos")) {
      throw new AccessDeniedException();
    }

    JsonEstablecimiento data = context.bodyAsClass(JsonEstablecimiento.class);

    // Ahora 'data' contiene tus datos del JSON
    String denominacion = data.getDenominacion();
    Long entidad_id = data.getEntidad();
    Long localidad_id = data.getLocalidad();

    Localidad localidad = localizacionRepository.buscarLocalidadPorId(localidad_id);
    Entidad entidad = entidadRepository.buscarPorID(entidad_id);

    establecimiento.editar(denominacion, entidad, localidad);
    establecimientoRepository.actualizar(establecimiento);

    Map<String, String> respuesta = new HashMap<>();

    respuesta.put("mensaje", "Establecimiento guardado exitosamente");
    context.json(respuesta);
  }






}
