%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Código Inicial
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% popularidad(Personaje, Popularidad)
popularidad(kitty, 5).
popularidad(keroppi, 2).
popularidad(melody, 3).
popularidad(cinnamoroll, 4).
popularidad(pompompurin, 4).
popularidad(littleTwinStars, 2).
popularidad(badtzMaru, 2).
popularidad(gudetama, 1).

% consiguio(Persona, NroFigurita, Medio)
consiguio(andy, 2, paquete(1)).
consiguio(andy, 4, paquete(1)).
consiguio(andy, 7, paquete(2)).
consiguio(andy, 6, paquete(2)).
consiguio(andy, 6, paquete(3)).
consiguio(andy, 1, paquete(3)).
consiguio(andy, 4, paquete(3)).

consiguio(flor, 5, paquete(1)).
consiguio(flor, 5, paquete(2)).

consiguio(bobby, 3, paquete(1)).
consiguio(bobby, 5, paquete(1)).
consiguio(bobby, 7, paquete(2)).
consiguio(bobby, 5, paquete(2)).

consiguio(pepe, 5, paquete(1)).
consiguio(pepe, 2, paquete(1)).
consiguio(pepe, 4, paquete(1)).
consiguio(pepe, 7, paquete(2)).
consiguio(pepe, 6, paquete(2)).
consiguio(pepe, 10, paquete(2)).
consiguio(pepe, 11, paquete(2)).
consiguio(pepe, 6, paquete(3)).
consiguio(pepe, 1, paquete(3)).
consiguio(pepe, 4, paquete(3)).
consiguio(pepe, 8, paquete(3)).
consiguio(pepe, 9, paquete(3)).


consiguio(lolo, 5, paquete(1)).
consiguio(lolo, 5, paquete(1)).
consiguio(lolo, 7, paquete(1)).
consiguio(lolo, 9, paquete(2)).
consiguio(lolo, 9, paquete(3)).

consiguio(mimi, 4, paquete(2)).
consiguio(mimi, 10, paquete(3)).


consiguio(Persona, Figurita, canje(Canjeante, ACambio)):-
  cambiaron(Persona, ACambio, Canjeante, FiguritasQueRecibio), 
  member(Figurita, FiguritasQueRecibio).
consiguio(Persona, Figurita, canje(Canjeante, ACambio)):-
  cambiaron(Canjeante, FiguritasQueRecibio, Persona, ACambio), 
  member(Figurita, FiguritasQueRecibio).

cambiaron(andy, [4,7], flor, [1]).
cambiaron(bobby, [2], flor, [4, 6]).
cambiaron(lolo, [7], mimi, [8]).
cambiaron(lolo, [4], mimi, [11]).

%% persona que haya dado una valiosa y haya recibido valiosa


%% PUNTO 1
%% repetida(Persona, NroFigurita).
repetida(Persona, Numero) :-
  consiguio(Persona, Numero, Medio1),
  consiguio(Persona, Numero, Medio2),
  Medio1 \= Medio2.


%% PUNTO 2
%% figurita(NroFigurita, Imagen).
figurita(1, basica).
figurita(2, brillante).
figurita(3, brillante).
figurita(4, basica).
figurita(5, rompecabeza).
figurita(6, rompecabeza).
figurita(7, rompecabeza).
figurita(8, basica).
figurita(9, basica).
figurita(10,rompecabeza).
figurita(11,rompecabeza).


%% apareceEn(Personaje, NroFigurita).
apareceEn(kitty, 1).
apareceEn(keroppi, 1).
apareceEn(kitty, 2).
apareceEn(melody, 3).
apareceEn(Personaje, 8) :- popularidad(Personaje, _).
apareceEn(badtzMaru, 9).
apareceEn(pompompurin, 9).
apareceEn(cinnamoroll, 9).

%% rompecabezaContiene(Rompecabezas, NroFigurita).
rompecabezaContiene(kittyYCompania, 5).
rompecabezaContiene(kittyYCompania, 6).
rompecabezaContiene(kittyYCompania, 7).
rompecabezaContiene(kittyYCars, 10).
rompecabezaContiene(kittyYCars, 11).

%% imagen(NroFigurita, Imagen).
imagen(Numero, basica(Personajes)) :- 
  figurita(Numero, basica), 
  findall(Personaje, apareceEn(Personaje, Numero), Personajes).

imagen(Numero, brillante(fondoMetalizado, Personaje)) :- 
  figurita(Numero, brillante),
  apareceEn(Personaje, Numero).

imagen(Numero, rompecabeza(Nombre, Figuritas)) :- 
  rompecabezaContiene(Nombre, Numero),
  findall(Figurita, rompecabezaContiene(Nombre, Figurita), Figuritas).

%% PUNTO 3
%% esValiosa(NroFigurita).
esValiosa(Numero) :- esRara(Numero).
esValiosa(Numero) :- nivelDeAtractivo(Numero, Nivel), Nivel > 7.

%% esRara(NroFigurita).
esRara(Numero) :- figurita(Numero, _), not(repetida(_, Numero)).

%% nivelDeAtractivo(NroFigurita, NivelDeAtractivo).
nivelDeAtractivo(Numero, Nivel) :- figurita(Numero, _),  imagen(Numero, Imagen), nivelSegunImagen(Imagen, Nivel).

%% nivelSegunImagen(Imagen, Nivel).
nivelSegunImagen(brillante(fondoMetalizado, Personaje), Nivel) :-
  popularidad(Personaje, Popularidad),
  Nivel is 5 * Popularidad.

nivelSegunImagen(basica(Personajes), Nivel) :-
  findall(Popularidad, (member(Personaje, Personajes), popularidad(Personaje, Popularidad)), Popularidades),
  sum_list(Popularidades, Nivel).

nivelSegunImagen(rompecabeza(_, Figuritas), Nivel) :-
  length(Figuritas, Cantidad),
  partesRompecabezas(Cantidad, Nivel).

%% partesRompecabezas(CantidadPartesRompec, NivelDeAtractivo)
partesRompecabezas(Cantidad, 2) :- Cantidad < 3.
partesRompecabezas(Cantidad, 0) :- Cantidad > 2.


%% Punto 4
%% imagenMasAtractiva(Persona, Imagen).
imagenMasAtractiva(Persona, Imagen) :-
  consiguio(Persona, Numero, _),
  imagen(Numero, Imagen),
  nivelDeAtractivo(Numero, Nivel1),
  forall((
    consiguio(Persona, Num, _),
    Num \= Numero,
    nivelDeAtractivo(Num, Nivel2)),
    Nivel1 >= Nivel2).


%% Punto 5
%% hizoNegocio(Persona, Canje) 
hizoNegocio(Persona, canje(Persona2, FigsACambio)) :-
  consiguio(Persona, Figurita, canje(Persona2, FigsACambio)), 
  esValiosa(Figurita),
  not((member(FigACambio, FigsACambio), esValiosa(FigACambio))).


%% Punto 6
%% necesitaFigurita(Persona, NroFigurita).
necesitaFigurita(Persona, Numero) :-
  consiguio(Persona, _, _),
  figurita(Numero, _),
  not(consiguio(Persona, Numero, _)), 
  condicionDeNecesidad(Persona, Numero).

%% condicionDeNecesidad(Persona, NroFigurita).
condicionDeNecesidad(Persona, Numero):-
  forall((figurita(Num, _), Numero \= Num), consiguio(Persona, Num, _)).

condicionDeNecesidad(Persona, Numero1) :-
  rompecabezaContiene(Nombre, Numero1),
  rompecabezaContiene(Nombre, Numero2),
  consiguio(Persona, Numero2, _),
  Numero2 \= Numero1.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Pruebas
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Tests de ejemplo sobre código base
:- begin_tests(consiguio).

%% Testeo de consultas que esperan que sean ciertas
test(florConsiguioLa5EnSuPrimerPaquete, nondet):-
  consiguio(flor, 5, paquete(1)).
test(florConsiguioLa2EnUnCanjeConBobby, nondet):-
  consiguio(flor, 2, canje(bobby, _)).

%% Testeo de consultas que esperan que sean falsas
test(florConsiguioLa5EnSuPrimerPaquete, fail):-
  consiguio(flor, 2, paquete(1)).

%% Testeo de consultas existenciales con múltiples respuestas => inversibilidad
test(figuritasQueConsiguioFlor, set(Figurita == [5, 4, 7, 2])):-
  consiguio(flor, Figurita, _).

%% Test basado en condiciones más complejas
test(cuandoDosPersonasCambianFiguritasAmbasConsiguenFiguritasPorCanjeConLaOtraIncluyendoLasQueLeDieronALaOtra, nondet):-
  consiguio(andy, _, canje(flor, [4,7])),
  consiguio(flor, _, canje(andy, [1])).

:- end_tests(consiguio).

%% Tests de requerimiento, implementar aquí...
:- begin_tests(pruebas).

% Punto 1
test(el_predicado_repetida_es_inversible_para_su_segundo_parametro, set(Numero == [5])):-
  repetida(flor, Numero).

test(el_predicado_repetida_es_inversible_para_su_primer_parametro, set(Persona == [flor, bobby])):-
  repetida(Persona, 5).

test(una_figurita_esta_repetida_si_se_consiguio_por_dos_o_mas_medios_distintos, nondet):-
  repetida(lolo, 9).

test(una_figurita_no_esta_repetida_si_se_consiguio_por_un_medio_solo, nondet):-
  not(repetida(pepe, 10)).

test(una_figurita_no_esta_repetida_si_no_se_consiguio, nondet):-
  not(repetida(flor, 8)).

% Punto 2
test(la_imagen_de_la_figurita_1_es_basica, nondet) :-
  figurita(1, basica).

test(el_predicado_figurita_es_inversible_para_su_primer_parametro, set(Numero == [5,6,7,10,11])) :-
  figurita(Numero, rompecabeza).

test(el_predicado_apareceEn_es_inversible_para_su_primer_parametro, set(Personaje == [kitty,keroppi,melody,cinnamoroll,pompompurin,littleTwinStars,badtzMaru,gudetama])) :-
  apareceEn(Personaje, 8).

test(el_predicado_apareceEn_es_inversible_para_su_segundo_parametro, set(Numero == [1,2,8])) :-
  apareceEn(kitty, Numero).

test(el_predicado_rompecabezaContiene_es_inversible_para_su_segundo_parametro, set(Numero == [5,6,7])) :-
  rompecabezaContiene(kittyYCompania, Numero).

test(una_imagen_brillante_tiene_un_unico_personaje, set(Imagen == [brillante(fondoMetalizado, melody)])) :-
  imagen(3, Imagen).

test(una_imagen_basica_puede_tener_mas_de_un_personaje, set(Imagen == [basica([badtzMaru,pompompurin,cinnamoroll])])) :-
  imagen(9, Imagen).

test(una_imagen_basica_puede_no_tener_personajes, set(Imagen == [basica([])])) :-
  imagen(4, Imagen).

test(una_imagen_rompecabezas_tiene_varias_figuritas, set(Imagen == [rompecabeza(kittyYCompania, [5,6,7])])) :-
  imagen(7, Imagen).

% Punto 3
test(el_predicado_esValiosa_es_inversible, set(Numero == [2,3,8,7,9,10,11])) :-
  esValiosa(Numero).

test(el_predicado_esRara_es_inversible, set(Numero == [2,3,8,7,10,11])) :-
  esRara(Numero).

test(una_figurita_rara_con_nivel_de_atractivo_bajo_es_valiosa, nondet) :-
  esValiosa(10).

test(una_figurita_no_rara_con_nivel_de_atractivo_alto_es_valiosa, nondet) :-
  esValiosa(9).

test(nivel_de_atractivo_de_una_figuritas_basica_es_la_suma_de_popularidades_de_sus_personajes, nondet) :-
  nivelDeAtractivo(8, 23).

test(nivel_de_atractivo_de_una_figurita_basica_sin_personajes_es_0, nondet) :-
  nivelDeAtractivo(4, 0).

test(nivel_de_atractivo_de_una_figuritas_rompecabeza_grande_es_0, nondet) :-
  nivelDeAtractivo(5, 0).

test(nivel_de_atractivo_de_una_figuritas_rompecabeza_chico_es_2, nondet) :-
  nivelDeAtractivo(10, 2).

test(nivel_de_atractivo_de_una_figuritas_brillante_es_la_popularidad_de_su_personaje_por_5, nondet) :-
  nivelDeAtractivo(3, 15).

test(nivel_de_atractivo_de_un_rompecabezas_con_menos_de_tres_partes_es_2, nondet) :-
  partesRompecabezas(2, 2).

test(nivel_de_atractivo_de_un_rompecabezas_con_mas_de_dos_partes_es_0, nondet) :-
  partesRompecabezas(3, 0).

% Punto 4
test(el_predicado_imagenMasAtractiva_es_inversible_para_su_segundo_parametro, set(Imagen == [basica([kitty,keroppi,melody,cinnamoroll,pompompurin,littleTwinStars,badtzMaru,gudetama])])) :-
  imagenMasAtractiva(lolo, Imagen).

test(el_predicado_imagenMasAtractiva_es_inversible_para_su_primer_parametro, set(Persona == [andy, bobby, pepe, flor])) :-
  imagenMasAtractiva(Persona, brillante(fondoMetalizado, _)).

test(la_imagen_mas_atractiva_de_pepe_es_brillante_fondoMetalizado_kitty, nondet) :-
  imagenMasAtractiva(pepe, brillante(fondoMetalizado, kitty)).

test(la_imagen_mas_atractiva_de_mimi_es_rompecabezas_kittyYCars_10_11, nondet) :-
  imagenMasAtractiva(mimi, rompecabeza(kittyYCars, [10, 11])).

% Punto 5
test(el_predicado_hizoNegocio_es_inversible_para_su_primer_parametro, set(Persona == [flor])) :-
  hizoNegocio(Persona, canje(bobby, [4, 6])).

test(el_predicado_hizoNegocio_es_inversible_para_su_segundo_parametro, set(Canje== [(canje(andy, [1])),canje(bobby, [4, 6])])) :-
  hizoNegocio(flor, Canje).

test(el_predicado_hizoNegocio_es_inversible_para_los_dos_parametros, set(Persona == [flor]), set(Canje = [(canje(andy, [1])),canje(bobby, [4, 6])])) :-
  hizoNegocio(Persona, Canje).

test(una_persona_que_dio_no_valiosas_y_recibio_una_valiosa_hizo_negocio, nondet) :-
  hizoNegocio(flor, canje(bobby, [4, 6])).

test(una_persona_que_dio_alguna_valiosa_y_recibio_valiosa_no_hizo_negocio, nondet) :-
  not(hizoNegocio(bobby, _)).

test(una_persona_que_no_dio_valiosa_y_no_recibio_valiosa_no_hizo_negocio, nondet) :-
  not(hizoNegocio(bobby, _)).

% Punto 6
test(el_predicado_necesitaFigurita_es_inversible_para_su_primer_parametro, set(Persona == [flor, lolo, mimi])) :-
  necesitaFigurita(Persona, 6).

test(el_predicado_necesitaFigurita_es_inversible_para_su_segundo_parametro, set(Numero == [3])) :-
  necesitaFigurita(pepe, Numero).

test(una_persona_que_ya_consiguio_todas_las_otras_figuritas_del_album_necesita_la_restante, nondet) :-
  necesitaFigurita(pepe, 3).

test(una_persona_que_ya_consiguio_una_o_mas_figuritas_de_un_rompecabeza_necesita_alguna_de_las_restante, nondet) :-
  necesitaFigurita(mimi, 11).

test(una_persona_que_le_falta_mas_de_una_figurita_y_no_le_faltan_figuritas_para_llenar_un_rompecabezas_no_necesita_ninguna, nondet) :-
  not(necesitaFigurita(bobby, _)).



:- end_tests(pruebas).