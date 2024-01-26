package server.utils;

import models.domain.apis.georef.ServicioGeoref;
import models.domain.apis.georef.adapters.ServicioGeorefRetrofitAdapter;
import models.domain.main.incidentes.CronSugerenciaRevisionIncidente;
import models.domain.main.informes.CronGeneradorReportes;
import models.domain.main.localizacion.Localidad;
import models.domain.main.localizacion.Localizacion;
import models.domain.main.localizacion.Provincia;
import models.domain.main.localizacion.TipoLocalizacion;
import models.domain.usuarios.roles.Permiso;
import models.domain.usuarios.roles.Rol;
import models.domain.usuarios.roles.TipoRol;
import models.indice.Menu;
import models.repositorios.LocalizacionRepository;
import models.repositorios.MenuRepository;
import models.repositorios.PermisoRepository;
import models.repositorios.RolRepository;

import java.io.File;
import java.io.IOException;
import java.util.*;

public class Inicializador {

  public LocalizacionRepository localizacionRepository;
  public ServicioGeoref servicioGeoref;
  public MenuRepository menuRepository;
  public RolRepository rolRepository;
  public PermisoRepository permisoRepository;

  public Inicializador()
  {

    this.localizacionRepository = new LocalizacionRepository();
    this.servicioGeoref = new ServicioGeoref();
    this.servicioGeoref.setAdapter(new ServicioGeorefRetrofitAdapter());
    this.menuRepository = new MenuRepository();
    this.rolRepository = new RolRepository();
    this.permisoRepository = new PermisoRepository();
  }

  public void inicializar() throws IOException {
    //this.localizacionRepository.cargarTodo();
    //List<Provincia> provincias = this.inicializarProvincias();
    //List<Localizacion> localizaciones = this.inicializarLocalizaciones(provincias);
    //this.inicializarLocalidades(localizaciones);
    inicializarMenus();
    inicializarPermisos();
    inicializarRoles();
    String currentDirectory = System.getProperty("user.dir");
    System.out.println("El directorio actual es: " + currentDirectory);
    cronRanking();
    //cronSugerenciaCierreIncidente();
  }

  public List<Provincia> inicializarProvincias() {
    List<Provincia> provincias = this.localizacionRepository.todasLasProvincias();
    if (provincias.isEmpty()) {
      try {
        provincias = this.servicioGeoref.listadoDeProvincias().getProvincias();
        localizacionRepository.persistirProvincias(provincias);
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    return provincias;
  }

  public List<Localizacion> inicializarLocalizaciones(List<Provincia> provincias) throws IOException {
    List <Localizacion> localizaciones = this.localizacionRepository.todasLasLocalizaciones();
    if (localizaciones.isEmpty()) {
      for (Provincia provincia : provincias) {
        List<Localizacion> municipiosNuevos = (this.servicioGeoref.listadoDeMunicipiosDeProvincia(provincia.getId().intValue())).getMunicipios();
        municipiosNuevos.forEach(municipioNuevo -> {
          municipioNuevo.setTipoLocalizacion(TipoLocalizacion.Municipio);
          municipioNuevo.setProvincia(provincia);
        });
        List<Localizacion> departamentosNuevos = this.servicioGeoref.listadoDeDepartamentosDeProvincia(provincia.getId().intValue()).getDepartamentos();

        departamentosNuevos.forEach(departamentoNuevo -> {
          departamentoNuevo.setTipoLocalizacion(TipoLocalizacion.Departamento);
          departamentoNuevo.setProvincia(provincia);
        });

        localizaciones.addAll(municipiosNuevos);
        localizaciones.addAll(departamentosNuevos);
      }
      localizacionRepository.persistirLocalizaciones(localizaciones);
    }
    return localizaciones;
  }
  public List<Localidad> inicializarLocalidades(List<Localizacion> localizaciones) throws IOException {
    List <Localidad> localidades = this.localizacionRepository.todasLasLocalidades();
    if (localidades.isEmpty()) {
      for (Localizacion localizacion : localizaciones) {
        List<Localidad> localidadesNuevas =this.servicioGeoref.listadoDeLocalidades(localizacion.getId().intValue(),
                localizacion.getTipoLocalizacion()).getLocalidades();

        for (Localidad localidadNueva : localidadesNuevas) {
          localidadNueva.setLocalizacion(localizacion);
        }

        localidades.addAll(localidadesNuevas);
      }

      localizacionRepository.persistirLocalidades(localidades);
    }
    return localidades;
  }

  public void inicializarMenus() {
    List<Menu> menus = this.menuRepository.all();
    if (menus.isEmpty()) {

        menus.add(new Menu("/inicio", "Inicio", TipoRol.CONSUMIDOR));
        menus.add(new Menu("/inicio", "Inicio", TipoRol.ADMINISTRADOR));

        menus.add(new Menu("/perfil", "Perfil", TipoRol.CONSUMIDOR));
        menus.add(new Menu("/perfil", "Perfil", TipoRol.ADMINISTRADOR));

        menus.add(new Menu("/administrar", "Administrar", TipoRol.ADMINISTRADOR));

        menus.add(new Menu("/comunidades", "Comunidades", TipoRol.CONSUMIDOR));
        menus.add(new Menu("/incidentes", "Incidentes", TipoRol.CONSUMIDOR));

        menus.add(new Menu("/rankings", "Rankings", TipoRol.CONSUMIDOR));
        menus.add(new Menu("/rankings", "Rankings", TipoRol.ADMINISTRADOR));

        menus.add(new Menu("/carga-masiva", "Carga Masiva", TipoRol.ADMINISTRADOR));


        menuRepository.persistir(menus);
    }
  }


  public void inicializarRoles() {
    List<Rol> roles = this.rolRepository.all();
    if(!(roles.stream().anyMatch(x->x.getTipo().equals(TipoRol.ADMINISTRADOR))&&roles.stream().anyMatch(x->x.getTipo().equals(TipoRol.CONSUMIDOR)))){
      Set<Permiso> permisosAdmin = new HashSet<>();
      Set<Permiso> permisosCons = new HashSet<>();
      permisosAdmin.add(permisoRepository.buscarPorNombreInterno("crear_comunidad"));
      permisosAdmin.add(permisoRepository.buscarPorNombreInterno("carga_masiva"));
      permisosCons.add(permisoRepository.buscarPorNombreInterno("ver_mis_comunidades"));
      permisosCons.add(permisoRepository.buscarPorNombreInterno("ver_incidentes_de_mis_comunidades"));
      permisosCons.add(permisoRepository.buscarPorNombreInterno("sumar_a_comunidad"));
      permisosCons.add(permisoRepository.buscarPorNombreInterno("salir_de_comunidad"));
      permisosCons.add(permisoRepository.buscarPorNombreInterno("crear_incidente"));
      permisosAdmin.add(permisoRepository.buscarPorNombreInterno("administrar_recursos"));
      permisosAdmin.add(permisoRepository.buscarPorNombreInterno("ver_todas_comunidades"));
      permisosAdmin.add(permisoRepository.buscarPorNombreInterno("editar_comunidad"));
      permisosAdmin.add(permisoRepository.buscarPorNombreInterno("crear_administrador"));

      roles.add(new Rol("consumidor", TipoRol.CONSUMIDOR, permisosCons));
      roles.add(new Rol("administrador", TipoRol.ADMINISTRADOR, permisosAdmin));

      rolRepository.persistir(roles);
    }
  }

  public void inicializarPermisos (){
    List<Permiso> permisos = this.permisoRepository.all();
    if(permisos.isEmpty()){

      permisos.add(new Permiso("crear_comunidad","crear_comunidad"));
      permisos.add(new Permiso("carga_masiva","carga_masiva"));
      permisos.add(new Permiso("ver_mis_comunidades", "ver_mis_comunidades"));
      permisos.add(new Permiso("ver_incidentes_de_mis_comunidades", "ver_incidentes_de_mis_comunidades"));
      permisos.add(new Permiso("sumar_a_comunidad", "sumar_a_comunidad"));
      permisos.add(new Permiso("salir_de_comunidad", "salir_de_comunidad"));
      permisos.add(new Permiso("crear_incidente", "crear_incidente"));
      permisos.add(new Permiso("administrar_recursos", "administrar_recursos"));
      permisos.add(new Permiso("ver_todas_comunidades", "ver_todas_comunidades"));
      permisos.add(new Permiso("editar_comunidad", "editar_comunidad"));
      permisos.add(new Permiso("crear_administrador", "crear_administrador"));

      permisoRepository.persistir(permisos);
    }
  }


  public void cronRanking() {
    CronGeneradorReportes cronGeneradorReportes = new CronGeneradorReportes();
    //cronGeneradorReportes.run();
  }

  public void cronSugerenciaCierreIncidente() {
    CronSugerenciaRevisionIncidente cronSugerenciaRevisionIncidente = new CronSugerenciaRevisionIncidente();
    cronSugerenciaRevisionIncidente.run();
  }




}
