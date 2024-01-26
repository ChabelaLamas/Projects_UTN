package models.domain.main.informes;

import lombok.Getter;
import models.domain.main.entidades.Entidad;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

@Getter
public class PosicionRanking {

    private int puntaje;
    private Entidad entidad;

    public PosicionRanking(int puntaje, Entidad entidad) {
        this.puntaje = puntaje;
        this.entidad = entidad;
    }




}
