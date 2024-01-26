package services;

import models.domain.main.informes.PosicionRanking;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class RankingsService {

    public List<String> pasarRankingAString(List<PosicionRanking> ranking) {
        // Ordenar la lista por puntaje

        // Crear la lista de denominaciones
        List<String> denominaciones = new ArrayList<>();
        for (PosicionRanking posicion : ranking) {
            denominaciones.add(posicion.getEntidad().getDenominacion());
        }

        return denominaciones;
    }
}
