package models.config;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public class Config {
  private static final Properties prop = new Properties();
  private static Config instancia;

  public static final String RUTA_EXPORTACION = "src/main/resources/public/exportados/";

  public static final Integer TIEMPO_NOTIFICACIONES = 21600000;
  public static final Integer TIEMPO_REPORTES = 604800000;
  public static final String DOWNLOAD = "2023-tpa-mama-grupo-04/descargas/";
  //Esto cuando tengan que descargar, la ruta es /public/descargas/*nombre archivo pdf* (suponiendo que hagan una carpeta descargas para guardar los pdf)

  private Config() { //porque es un Singleton
  }

  public static Config obtenerInstancia() { // Singleton
    if (instancia == null){
      instancia = new Config();
    }
    return instancia;
  }

  public String obtenerDelConfig(String key) {
    try (InputStream input = Config.class.getResourceAsStream("/config.properties")) {
      prop.load(input);
      return prop.getProperty(key);
    } catch (IOException e) {
      e.printStackTrace();
      return null;
    }
  }
}
