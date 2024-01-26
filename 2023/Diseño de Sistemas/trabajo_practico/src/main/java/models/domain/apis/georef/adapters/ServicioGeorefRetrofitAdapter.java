package models.domain.apis.georef.adapters;

import models.domain.apis.georef.GeorefService;
import models.domain.apis.georef.entities.ListadoDeDepartamentos;
import models.domain.apis.georef.entities.ListadoDeProvincias;
import models.domain.main.localizacion.TipoLocalizacion;
import models.domain.apis.georef.entities.ListadoDeLocalidades;
import models.domain.apis.georef.entities.ListadoDeMunicipios;
import retrofit2.Call;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;
import models.config.Config;

import java.io.IOException;

public class ServicioGeorefRetrofitAdapter implements GeorefAdapter{
    private static final String urlApi = Config.obtenerInstancia().obtenerDelConfig("apiGeoref");
    private final Retrofit retrofit;

    public ServicioGeorefRetrofitAdapter() {
        this.retrofit = new Retrofit.Builder()
                .baseUrl(urlApi)
                .addConverterFactory(GsonConverterFactory.create())
                .build();
    }

    public ListadoDeProvincias listadoDeProvincias() throws IOException {
        GeorefService georefService = this.retrofit.create(GeorefService.class);
        Call<ListadoDeProvincias> requestProvinciasArgentinas = georefService.provincias("id,nombre");
        Response<ListadoDeProvincias> responseProvinciasArgentinas = requestProvinciasArgentinas.execute();
        return responseProvinciasArgentinas.body();
    }

    public ListadoDeMunicipios listadoDeMunicipiosDeProvincia(int idProvincia) throws IOException {
        GeorefService georefService = this.retrofit.create(GeorefService.class);
        Call<ListadoDeMunicipios> requestListadoDeMunicipios = georefService.municipios(idProvincia, "id,nombre");
        Response<ListadoDeMunicipios> responseListadoDeMunicipios = requestListadoDeMunicipios.execute();
        return responseListadoDeMunicipios.body();
    }
    public ListadoDeDepartamentos listadoDeDepartamentosDeProvincia(int idProvincia) throws IOException {
        GeorefService georefService = this.retrofit.create(GeorefService.class);
        Call<ListadoDeDepartamentos> requestListadoDeDepartamentos = georefService.departamentos(idProvincia, "id,nombre");
        Response<ListadoDeDepartamentos> responseListadoDeDepartamentos = requestListadoDeDepartamentos.execute();
        return responseListadoDeDepartamentos.body();
    }

    public ListadoDeLocalidades listadoDeLocalidades(int idLocalizacion, TipoLocalizacion tipoLocalizacion) throws IOException {
        GeorefService georefService = this.retrofit.create(GeorefService.class);
        Call<ListadoDeLocalidades> requestListadoDeLocalidades = null;

        if(tipoLocalizacion.equals(TipoLocalizacion.Departamento)) {
            requestListadoDeLocalidades = georefService.localidadesDepartamento(idLocalizacion, "id,nombre");
        } else if(tipoLocalizacion.equals(TipoLocalizacion.Municipio)) {
            requestListadoDeLocalidades = georefService.localidadesMunicipio(idLocalizacion, "id,nombre");
        } else {
            System.out.println("Error al traer el listado de localidades");
        }

        Response<ListadoDeLocalidades> responseListadoDeLocalidades = requestListadoDeLocalidades.execute();
        return responseListadoDeLocalidades.body();
    }
}
