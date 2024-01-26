package controllers;

import io.javalin.http.Context;
import models.domain.main.notificaciones.mediosNotificacion.PreferenciaMedioNotificacion;
import models.domain.usuarios.Persona;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.Rol;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;
import models.repositorios.*;
import models.validadorDeContrasenias.ValidadorDeContrasenia;
import models.validadorDeContrasenias.excepciones.ExcepcionComplejidad;
import models.validadorDeContrasenias.excepciones.ExcepcionContraseniaInvalida;
import models.validadorDeContrasenias.excepciones.ExcepcionCredencial;
import models.validadorDeContrasenias.excepciones.ExcepcionLongitud;
import server.utils.ICrudViewsHandler;

import java.lang.reflect.InvocationTargetException;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static com.github.jknack.handlebars.internal.lang3.BooleanUtils.toInteger;
import static models.domain.main.localizacion.TipoLocalizacion.Departamento;
import static models.domain.usuarios.roles.TipoRol.CONSUMIDOR;

public class UsuariosController extends Controller implements ICrudViewsHandler {
    private UsuarioRepository usuarioRepository;
    private PersonaRepository personaRepository;
    private ValidadorDeContrasenia validadorDeContrasenia;
    private RolRepository rolRepository;
    private MenuRepository menuRepository;

    public UsuariosController(UsuarioRepository usuarioRepository, PersonaRepository personaRepository, ValidadorDeContrasenia validadorDeContrasenia, RolRepository rolRepository, MenuRepository menuRepository) {
        this.usuarioRepository = usuarioRepository;
        this.personaRepository = personaRepository;
        this.validadorDeContrasenia = validadorDeContrasenia;
        this.rolRepository = rolRepository;
        this.menuRepository = menuRepository;
    }

    //CERRAR SESION
    public void logout(Context context) {

        context.consumeSessionAttribute("usuario_id");
        context.redirect("/login");
        return;
    }
    //LOGIN

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


    // INICIO
    @Override
    public void show(Context context) {
        Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
        TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
        List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
        menus.forEach(m -> m.setActivo(m.getNombre().equals("Inicio")));
        Map<String, Object> model = new HashMap<>();
        model.put("usuario", usuario);
        model.put("menus", menus);


        context.render("inicio.hbs", model);
    }

    //SIGNUP
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


    //NADA
    @Override
    public void edit(Context context) {}

    @Override
    public void update(Context context) {}

    @Override
    public void delete(Context context) {}
}
