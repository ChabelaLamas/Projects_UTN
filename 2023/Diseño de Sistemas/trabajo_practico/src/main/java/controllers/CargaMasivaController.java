package controllers;

import io.javalin.http.Context;
import io.javalin.http.UploadedFile;
import models.domain.main.EntidadPrestadora;
import models.domain.main.OrganismoDeControl;
import models.domain.usuarios.Delegado;
import models.domain.usuarios.Usuario;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;
import models.repositorios.*;
import server.exceptions.AccessDeniedException;
import server.utils.ICrudViewsHandler;

import javax.persistence.EntityManager;
import javax.persistence.NoResultException;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CargaMasivaController extends Controller implements ICrudViewsHandler {

  private EntidadPrestadoraRepository entidadPrestadoraRepository;
  private OrganismoDeControlRepository organismoDeControlRepository;
  private UsuarioRepository usuarioRepository;
  private RolRepository rolRepository;
  private MenuRepository menuRepository;

  public CargaMasivaController(EntidadPrestadoraRepository entidadPrestadoraRepository,
                               OrganismoDeControlRepository organismoDeControlRepository,
                               UsuarioRepository usuarioRepository, RolRepository rolRepository,
                               MenuRepository menuRepository) {
    this.entidadPrestadoraRepository = entidadPrestadoraRepository;
    this.organismoDeControlRepository = organismoDeControlRepository;
    this.usuarioRepository = usuarioRepository;
    this.rolRepository = rolRepository;
    this.menuRepository = menuRepository;
  }
  @Override
  public void index(Context context) {
    Long usuarioId = context.sessionAttribute("usuario_id");
    Usuario usuarioLogueado = usuarioRepository.buscarPorID(usuarioId);

    if(usuarioLogueado == null || !rolRepository.tienePermiso(usuarioLogueado.getRol().getId(), "carga_masiva")) {
      throw new AccessDeniedException();
    }
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuarioLogueado.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Carga Masiva")));
    Map<String, Object> model = new HashMap<>();
    model.put("usuario", usuarioLogueado);
    model.put("menus", menus);
    context.render("cargaMasiva.hbs", model);
  }

  @Override
  public void show(Context context) {
    //TODO
  }

  // basicamente llama al importador csv para q cree las entidades correspondientes
  public void create(Context context) {
    //TODO
  }

  @Override
  public void save(Context context) {
    Map<String, Object> model = new HashMap<>();
    EntityManager entityManager;
    entityManager = entidadPrestadoraRepository.entityManager();

    try {
      entityManager.getTransaction().begin();

      // Aquí es donde manejas la subida del archivo
      UploadedFile uploadedFile = context.uploadedFile("csvfile"); // "csvfile" debe ser el nombre del campo input en tu formulario
      String csvContent = new String(uploadedFile.content().readAllBytes(), StandardCharsets.UTF_8);

      System.out.println("Primeras líneas del CSV:\n" + csvContent.substring(0, Math.min(500, csvContent.length())));
      String[] lines = csvContent.split("\r?\n");

      for (int i = 1; i < lines.length; i++) {
        String line = lines[i];
        String[] values = line.split(";"); // Cambio a ; como delimitador

        System.out.println("Línea: " + line);
        System.out.println("Número de valores: " + values.length);

        if (values.length < 4) {
          continue;
        }

        String denominacion = values[0].trim();
        String tipo = values[1].trim();
        String nombreDelegado = values[2].trim();
        String emailDelegado = values[3].trim();

        Delegado delegado = getOrCreateDelegado(entityManager, nombreDelegado, emailDelegado);

        if ("Entidad prestadora".equalsIgnoreCase(tipo)) {
          EntidadPrestadora entidadPrestadora = new EntidadPrestadora(denominacion, delegado);
          entityManager.persist(entidadPrestadora);
        } else if ("Organismo de control".equalsIgnoreCase(tipo)) {
          OrganismoDeControl organismoDeControl = new OrganismoDeControl(denominacion, delegado);
          entityManager.persist(organismoDeControl);
        } else {
          model.put("errorMessage", "Hubo un un tipo desconocido al procesar el archivo.");
          // Tipo desconocido, manejar o regist

        }

      }

      entityManager.getTransaction().commit();
      model.put("happyMessage", "Archivo procesado y datos guardados correctamente.");

    } catch (Exception e) {
      if (entityManager.getTransaction().isActive()) {
        entityManager.getTransaction().rollback();
      }
      e.printStackTrace();
      model.put("errorMessage", "Hubo un error al procesar el archivo.");

    } finally {
      if (entityManager != null) {
        entityManager.close();
      }
    }


    // MENU
    Usuario usuario = this.usuarioRepository.buscarPorID(context.sessionAttribute("usuario_id"));
    TipoRol tipoRol = this.rolRepository.buscarTipoRol(usuario.getRol().getId());
    List<Menu> menus = menuRepository.hacerListaMenu(tipoRol);
    menus.forEach(m -> m.setActivo(m.getNombre().equals("Carga Masiva")));
    model.put("menus", menus);
    //

    context.render("cargaMasiva.hbs", model);


  }








  private Delegado getOrCreateDelegado(EntityManager entityManager, String nombre, String email) {
    try {
      // Intentar buscar un Delegado existente por email
      Delegado delegado = entityManager.createQuery("SELECT d FROM Delegado d WHERE d.email = :email", Delegado.class)
          .setParameter("email", email)
          .getSingleResult();
      return delegado;
    } catch (NoResultException nre) {
      // Si no hay un Delegado con ese email, crear uno nuevo
      Delegado newDelegado = new Delegado(nombre, email);
      entityManager.persist(newDelegado);
      return newDelegado;
    }
  }



  @Override
  public void edit(Context context) {
    //TODO
  }

  @Override
  public void update(Context context) {
    //TODO
  }

  @Override
  public void delete(Context context) {
    //TODO
  }

}