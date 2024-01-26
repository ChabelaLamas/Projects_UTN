package models.domain.apis.georef.adapters;

import models.domain.apis.georef.entities.ListadoDeDepartamentos;
import models.domain.apis.georef.entities.ListadoDeLocalidades;
import models.domain.apis.georef.entities.ListadoDeMunicipios;
import models.domain.apis.georef.entities.ListadoDeProvincias;
import models.domain.main.localizacion.TipoLocalizacion;

import java.io.IOException;

public interface GeorefAdapter {

    ListadoDeProvincias listadoDeProvincias() throws IOException;
    ListadoDeMunicipios listadoDeMunicipiosDeProvincia(int idProvincia) throws IOException;
    ListadoDeDepartamentos listadoDeDepartamentosDeProvincia(int idProvincia) throws IOException;

    ListadoDeLocalidades listadoDeLocalidades(int idLocalizacion, TipoLocalizacion tipoLocalizacion) throws IOException;
}
