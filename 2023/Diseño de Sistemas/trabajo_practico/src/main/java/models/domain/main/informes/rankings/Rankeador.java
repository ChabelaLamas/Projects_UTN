package models.domain.main.informes.rankings;

import models.config.Config;
import lombok.Getter;

import java.util.ArrayList;
import java.util.List;

public class Rankeador {

  private static Rankeador instancia;
  @Getter
  public final List<Ranking> rankings = new ArrayList<>();

  private Rankeador() {
  }
  public static Rankeador obtenerInstancia() { // Singleton
    if (instancia == null){
      instancia = new Rankeador();
      instancia.agregarRankings();
    }
    return instancia;
  }

  // Levanta rankings del config
  public void agregarRankings() {
    String[] rankingsPorAgregar = Config.obtenerInstancia().obtenerDelConfig("rankings").split(",");

    for (String ranking : rankingsPorAgregar) {
      try {
        Class<? extends Ranking> clazz = Class.forName("domain.main.informes.rankings." + ranking).asSubclass(Ranking.class);
        Ranking instancia = clazz.getDeclaredConstructor().newInstance();
        rankings.add(instancia);
      } catch (ClassNotFoundException | IllegalAccessException
               | InstantiationException | NoSuchMethodException
               | java.lang.reflect.InvocationTargetException e) {
        e.printStackTrace();
      }
    }
  }
}
