package controllers;

import io.javalin.http.Context;
import models.domain.main.notificaciones.mediosNotificacion.PreferenciaMedioNotificacion;
import models.domain.usuarios.Persona;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.Rol;
import models.repositorios.PersonaRepository;
import models.repositorios.RolRepository;
import models.repositorios.UsuarioRepository;
import models.validadorDeContrasenias.ValidadorDeContrasenia;
import models.validadorDeContrasenias.excepciones.ExcepcionComplejidad;
import models.validadorDeContrasenias.excepciones.ExcepcionContraseniaInvalida;
import models.validadorDeContrasenias.excepciones.ExcepcionLongitud;
import server.utils.ICrudViewsHandler;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;

import static models.domain.usuarios.roles.TipoRol.ADMINISTRADOR;
import static models.domain.usuarios.roles.TipoRol.CONSUMIDOR;

public class SignUpController extends Controller implements ICrudViewsHandler {
  private UsuarioRepository usuarioRepository;
  private PersonaRepository personaRepository;
  private ValidadorDeContrasenia validadorDeContrasenia;
  private RolRepository rolRepository;

  public SignUpController(UsuarioRepository usuarioRepository, PersonaRepository personaRepository, ValidadorDeContrasenia validadorDeContrasenia, RolRepository rolRepository) {
    this.usuarioRepository = usuarioRepository;
    this.personaRepository = personaRepository;
    this.validadorDeContrasenia = validadorDeContrasenia;
    this.rolRepository = rolRepository;
  }

  @Override
  public void create(Context context) {
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

    context.render("signup.hbs", model);
  }



  @Override
  public void save(Context context) {
    String nombre = context.formParam("nombre");
    String contrasenia = context.formParam("contrasenia");
    String valorMedio = context.formParam("valor-medio");
    String telefonoYMail = context.formParam("telefonoYMail");
    String tipoSeleccionado = context.formParam("tipoSeleccionado");
    String contraseniaEncriptada = " ";

    // Verificar si el nombre de usuario ya está en uso
    if (usuarioRepository.existeUsuarioConNombre(nombre)) {
      context.redirect("/signup?error=username_exists");
      return;
    }

    // Verificar si el correo electrónico ya está en uso
    if (personaRepository.existePersonaConCorreo(telefonoYMail)) {
      context.redirect("/signup?error=email_exists");
      return;
    }

    try {
      validadorDeContrasenia.verificarValidez(nombre, contrasenia);
    } catch (ExcepcionComplejidad e) {
      context.redirect("/signup?error=complexity");
      return;
    } catch (ExcepcionLongitud e) {
      context.redirect("/signup?error=length");
      return;
    } catch (ExcepcionContraseniaInvalida e) {
      context.redirect("/signup?error=invalid_password");
      return;
    }

    try {
      Rol rol = rolRepository.buscarPorTipoRol(CONSUMIDOR);
      contraseniaEncriptada = validadorDeContrasenia.encriptarContrasenia(contrasenia);
      Usuario usuario = new Usuario(nombre, contraseniaEncriptada, rol);
      usuarioRepository.registrar(usuario);

      Persona persona;
      if (tipoSeleccionado.equals("correo")) {
        persona = new Persona(usuario, telefonoYMail, "");
      } else {
        persona = new Persona(usuario, "", telefonoYMail);
      }
      PreferenciaMedioNotificacion medio = PreferenciaMedioNotificacion.valueOf(valorMedio);
      persona.setPreferenciaMedioNotificacion(medio);
      personaRepository.registrar(persona);

      context.redirect("/login");
    } catch (NoSuchAlgorithmException | ClassNotFoundException | NoSuchMethodException | InvocationTargetException | InstantiationException | IllegalAccessException e) {
      e.printStackTrace();
      context.redirect("/signup?error=registration_error");
    }
  }


  // NADA
  @Override
  public void edit(Context context) {  }
  @Override
  public void index(Context context) {  }
  @Override
  public void update(Context context) {  }
  @Override
  public void delete(Context context) {  }

  @Override
  public void show(Context context) throws IOException {  }

}
