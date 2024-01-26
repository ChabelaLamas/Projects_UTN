package models.domain.apis.georef;

import models.domain.apis.georef.adapters.GeorefAdapter;
import models.domain.apis.georef.entities.ListadoDeDepartamentos;
import models.domain.apis.georef.entities.ListadoDeLocalidades;
import models.domain.apis.georef.entities.ListadoDeMunicipios;
import models.domain.apis.georef.entities.ListadoDeProvincias;
import models.domain.main.localizacion.TipoLocalizacion;

import java.io.IOException;

public class ServicioGeoref {
  private static ServicioGeoref instancia = null;
  private GeorefAdapter adapter;

  public void setAdapter(GeorefAdapter adapter) {
    this.adapter = adapter;
  }

  public static ServicioGeoref instancia() {
    if(instancia== null){
      instancia = new ServicioGeoref();
    }
    return instancia;
  }

  public ListadoDeProvincias listadoDeProvincias() throws IOException {
    return this.adapter.listadoDeProvincias();
  }

  public ListadoDeMunicipios listadoDeMunicipiosDeProvincia(int idProvincia) throws IOException {
    return this.adapter.listadoDeMunicipiosDeProvincia(idProvincia);
  }
  public ListadoDeDepartamentos listadoDeDepartamentosDeProvincia(int idProvincia) throws IOException {
    return this.adapter.listadoDeDepartamentosDeProvincia(idProvincia);
  }

  public ListadoDeLocalidades listadoDeLocalidades(int idLocalizacion, TipoLocalizacion tipoLocalizacion) throws IOException {
    return this.adapter.listadoDeLocalidades(idLocalizacion, tipoLocalizacion);
  }
}
