package models.domain.main.exportar;

import java.util.List;
import java.util.Map;

public interface Exportable {

    public Map<String, List<String>> getDatos();

    public String descripcion();

    public void setNombre(String nombre);
}
