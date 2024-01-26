package server;



import server.utils.Inicializador;

import java.io.IOException;
import java.net.URI;
import java.util.HashMap;
import java.util.Map;

public class App {

  public static void main(String[] args) throws IOException {
    Server.init();
    Inicializador inicializador = new Inicializador();
    inicializador.inicializar();
  }
}
