package controllers;

import io.javalin.http.Context;
import models.repositorios.OrganismoDeControlRepository;
import models.repositorios.PersonaRepository;
import server.utils.ICrudViewsHandler;

public class OrganismoDeControlController extends Controller implements ICrudViewsHandler {

  private OrganismoDeControlRepository organismoDeControlRepository;

  public OrganismoDeControlController(OrganismoDeControlRepository organismoDeControlRepository) {
    this.organismoDeControlRepository = organismoDeControlRepository;
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
