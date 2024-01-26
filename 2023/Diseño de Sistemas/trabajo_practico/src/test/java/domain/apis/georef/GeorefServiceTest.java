package domain.apis.georef;

import models.domain.apis.georef.ServicioGeoref;
import models.domain.apis.georef.adapters.GeorefAdapter;
import models.domain.apis.georef.entities.ListadoDeMunicipios;
import models.domain.apis.georef.entities.ListadoDeProvincias;
import models.domain.main.localizacion.Localizacion;
import models.domain.main.localizacion.Provincia;
import models.domain.main.localizacion.TipoLocalizacion;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static org.mockito.Mockito.*;

public class GeorefServiceTest {
    private ServicioGeoref servicioGeoref;
    private GeorefAdapter adapterMock;

    @BeforeEach
    public void init() {
        this.adapterMock = mock(GeorefAdapter.class);
        this.servicioGeoref = ServicioGeoref.instancia();
        this.servicioGeoref.setAdapter(this.adapterMock);
    }

    @Test
    public void ServicioGeorefProveeListadoDeProvinciasTest() throws IOException {
        ListadoDeProvincias listadoDeProvinciasMock = mock(ListadoDeProvincias.class);
        List<Provincia> provinciasMock = this.provinciasMock();

        when(listadoDeProvinciasMock.getProvincias()).thenReturn(provinciasMock);
        when(this.adapterMock.listadoDeProvincias()).thenReturn(listadoDeProvinciasMock);

        Assertions.assertEquals(2, this.servicioGeoref.listadoDeProvincias().getProvincias().size());
    }

    private List<Provincia> provinciasMock() {
        List<Provincia> provincias = new ArrayList<>();
        provincias.add(new Provincia("Buenos Aires"));
        provincias.add(new Provincia("Cordoba"));
        return provincias;
    }

    @Test
    public void ServicioGeorefProveeMunicipiosDeBuenosAiresTest() throws IOException {
        Provincia buenosAires = new Provincia("Buenos Aires");

        ListadoDeMunicipios listadoDeMunicipiosMock = mock(ListadoDeMunicipios.class);
        List<Localizacion> municipiosMock = this.municipiosMock();


        when(listadoDeMunicipiosMock.getMunicipios()).thenReturn(municipiosMock);
        when(this.adapterMock.listadoDeMunicipiosDeProvincia(Math.toIntExact(buenosAires.getId()))).thenReturn(listadoDeMunicipiosMock);

        Assertions.assertEquals(3, this.servicioGeoref.listadoDeMunicipiosDeProvincia(Math.toIntExact(buenosAires.getId())).getMunicipios().size());
    }

    private List<Localizacion> municipiosMock() {
        List<Localizacion> municipios = new ArrayList<>();
        Provincia buenosAires = new Provincia("Buenos Aires");
        municipios.add(new Localizacion("Pilar", buenosAires , TipoLocalizacion.Municipio));
        municipios.add(new Localizacion("Bahia Blanca", buenosAires, TipoLocalizacion.Municipio));
        municipios.add(new Localizacion("Ezeiza", buenosAires, TipoLocalizacion.Municipio));
        return municipios;
    }

}
