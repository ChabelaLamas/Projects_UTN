package controllers;


import models.domain.main.incidentes.Incidente;
import models.domain.main.informes.rankings.CantidadIncidentesReportados;
import models.domain.main.informes.rankings.GradoImpactoProblematicas;
import models.domain.main.informes.rankings.PromedioCierre;
import models.repositorios.*;
import models.validadorDeContrasenias.ValidadorDeContrasenia;
import services.RankingsService;

public class FactoryController extends Controller{

  public static Object controller(String nombre) {
    Object controller = null;
    switch (nombre) {
      case "Incidentes": controller = new IncidentesController(new IncidenteRepository(), new UsuarioRepository(),
          new ComunidadRepository(), new ServicioRepository(), new RolRepository(), new MenuRepository(), new MiembroRepository(), new PersonaRepository(), new PrestacionDeServicioRepository()); break;
      case "Comunidades": controller = new ComunidadesController(new ComunidadRepository(), new UsuarioRepository(), new MiembroRepository(), new PersonaRepository(), new EstablecimientoRepository(),
          new ServicioRepository(), new RolRepository(), new MenuRepository()); break;
      case "Usuarios": controller = new UsuariosController(new UsuarioRepository(), new PersonaRepository(), new ValidadorDeContrasenia(), new RolRepository(), new MenuRepository()); break;
      case "Signup": controller = new SignUpController(new UsuarioRepository(), new PersonaRepository(), new ValidadorDeContrasenia(), new RolRepository()); break;
      case "Login": controller = new LoginController(new UsuarioRepository(), new ValidadorDeContrasenia()); break;
      case "Miembros": controller = new MiembrosController(new MiembroRepository()); break;
      case "Personas": controller = new PersonasController(new PersonaRepository(), new LocalizacionRepository(), new RolRepository(), new UsuarioRepository(), new MenuRepository()); break;
      case "OrganismoDeControl": controller = new OrganismoDeControlController(new OrganismoDeControlRepository()); break;
      case "EntidadPrestadora": controller = new EntidadPrestadoraController(new EntidadPrestadoraRepository()); break;
      case "Rankings": controller = new RankingsController(new CantidadIncidentesReportados(), new GradoImpactoProblematicas(), new PromedioCierre(), new EntidadRepository(), new MenuRepository(), new UsuarioRepository(), new RolRepository(), new RankingsService()); break;
      case "CargaMasiva": controller = new CargaMasivaController(new EntidadPrestadoraRepository(), new OrganismoDeControlRepository(), new UsuarioRepository(), new RolRepository(), new MenuRepository()); break;
      case "Administrar": controller = new AdministrarController(new UsuarioRepository(), new MenuRepository(), new RolRepository(), new EstablecimientoRepository(), new PrestacionDeServicioRepository(),
          new LocalizacionRepository(), new EntidadRepository(), new EntidadPrestadoraRepository(), new ServicioRepository(), new ValidadorDeContrasenia(),
          new PersonaRepository(), new IncidenteRepository(), new ComunidadRepository()); break;
    }

    return controller;
  }
}