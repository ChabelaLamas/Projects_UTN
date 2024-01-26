package models.domain.apis.georef;

import models.domain.apis.georef.entities.ListadoDeDepartamentos;
import models.domain.apis.georef.entities.ListadoDeLocalidades;
import models.domain.apis.georef.entities.ListadoDeMunicipios;
import models.domain.apis.georef.entities.ListadoDeProvincias;
import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Query;

public interface GeorefService {
  @GET("provincias")
  Call<ListadoDeProvincias> provincias(@Query("campos") String campos);

  @GET("municipios")
  Call<ListadoDeMunicipios> municipios(@Query("provincia") int idProvincia, @Query("campos") String campos);

  @GET("departamentos")
  Call<ListadoDeDepartamentos> departamentos(@Query("provincia") int idProvincia, @Query("campos") String campos);

  @GET("localidades")
  Call<ListadoDeLocalidades> localidadesDepartamento(@Query("departamento") int idLocalizacion, @Query("campos") String campos);

  @GET("localidades")
  Call<ListadoDeLocalidades> localidadesMunicipio(@Query("municipio") int idLocalizacion, @Query("campos") String campos);
}