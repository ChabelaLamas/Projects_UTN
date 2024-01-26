package controllers;

import io.javalin.http.Context;
import models.repositorios.EntidadPrestadoraRepository;
import models.repositorios.PersonaRepository;
import server.utils.ICrudViewsHandler;

public class EntidadPrestadoraController extends Controller implements ICrudViewsHandler {

  private EntidadPrestadoraRepository entidadPrestadoraRepository;

  public EntidadPrestadoraController(EntidadPrestadoraRepository personaRepository) {
    this.entidadPrestadoraRepository = entidadPrestadoraRepository;
  }
  @Override
  public void index(Context context) {
    //TODO
  }

  public void indexCargaMasiva(Context context) {
    //TODO
  }

  public void saveCargaMasiva(Context context) {
    //TODO
  }

  @Override
  public void show(Context context) {
    //TODO
  }

  public void create(Context context) {
    //TODO
  }

  @Override
  public void save(Context context) {
    //TODO
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
