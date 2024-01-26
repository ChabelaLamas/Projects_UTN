package com.api_fusion_comunidades.demo.utils;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class Calculador {
    private static Calculador instancia;

    private Calculador() {
    }

    public static Calculador obtenerInstancia() { // Singleton
        if (instancia == null){
            instancia = new Calculador();
        }
        return instancia;
    }

    public float calcularPorcentajeEnComun(List<Integer> lista1, List<Integer> lista2) {
        List<Integer> interseccionDeListas = new ArrayList<>(lista1);
        interseccionDeListas.retainAll(lista2);

        float cantidadDeElementosTotal = (float) Math.min(lista1.size(), lista2.size());
        float elementosEnComun = (float) interseccionDeListas.size();

        return (elementosEnComun/cantidadDeElementosTotal);
    }
}
