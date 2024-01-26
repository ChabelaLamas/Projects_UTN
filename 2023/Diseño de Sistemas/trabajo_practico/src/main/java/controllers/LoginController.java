package controllers;

import io.javalin.http.Context;
import models.domain.usuarios.Usuario;
import models.repositorios.PersonaRepository;
import models.repositorios.UsuarioRepository;
import models.validadorDeContrasenias.ValidadorDeContrasenia;
import org.jetbrains.annotations.NotNull;
import server.utils.ICrudViewsHandler;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;

public class LoginController extends Controller implements ICrudViewsHandler {
  private UsuarioRepository usuarioRepository;
  private PersonaRepository personaRepository;
  private ValidadorDeContrasenia validadorDeContrasenia;
  public LoginController(UsuarioRepository usuarioRepository, ValidadorDeContrasenia validadorDeContrasenia) {
    this.usuarioRepository = usuarioRepository;
    this.validadorDeContrasenia = validadorDeContrasenia;
  }
  @Override
  public void index(Context context) {
    Map<String, Object> model = new HashMap<>();

    String errorType = context.queryParam("error");
    if (errorType != null) {
      switch (errorType) {
        case "unregistered":
          model.put("errorMessage", "Usuario no registrado.");
          break;
        case "encryption_error":
          model.put("errorMessage", "Error al encriptar la contraseña. Inténtelo nuevamente.");
          break;
        case "invalid_password":
          model.put("errorMessage", "Contraseña inválida.");
          break;
        default:
          model.put("errorMessage", "Ocurrió un error al intentar iniciar sesión.");
          break;
      }
    }

    context.render("login.hbs", model);
  }

  public void validar(Context context) {
    String nombre = context.formParam("nombre");
    String contrasenia = context.formParam("contrasenia");
    String contraseniaEncriptadaDB = " ";
    Usuario usuario = this.usuarioRepository.buscarPorNombreUsuario(nombre);

    // Verificar si el usuario está registrado
    if(usuario == null) {
      context.redirect("/login?error=unregistered");
      return;
    }

    try {
      contraseniaEncriptadaDB = this.validadorDeContrasenia.encriptarContrasenia(contrasenia);
    } catch (NoSuchAlgorithmException | ClassNotFoundException | NoSuchMethodException | InvocationTargetException | InstantiationException | IllegalAccessException e) {
      context.redirect("/login?error=encryption_error");
      return;
    }

    if (usuario.getContraseniaEncriptada().equals(contraseniaEncriptadaDB)) {
      context.sessionAttribute("usuario_id", usuario.getId());
      context.redirect("/inicio");
    } else {
      context.redirect("/login?error=invalid_password");
    }
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

  public void redirect(Context context) {
    context.redirect("/login");
  }
}
