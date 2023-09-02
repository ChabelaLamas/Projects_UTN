module TP where
import Text.Show.Functions

--------------------------------------
-- DEFINICION DE LOS TIPOS DE DATOS
--------------------------------------

data Auto = UnAuto {
  color :: Color,
  velocidad :: Int,
  distancia :: Int
} deriving (Show, Eq)

data PowerUp = UnPowerUp {
  criterioACumplir :: Auto -> Auto -> Bool,
  modificacionAuto :: Auto -> Auto
} deriving (Show)

type Color = String
type TablaDePosiciones = [(Int, Color)]
type Carrera = [Auto]
type Evento = Carrera -> Carrera

--------------------------------------
-- FUNCIONES DISPONIBLES
--------------------------------------

ordenarPor :: Ord a => (b -> a) -> [b] -> [b]
ordenarPor ponderacion =
  foldl (\ordenada elemento -> filter ((< ponderacion elemento) . ponderacion) ordenada
                                  ++ [elemento] ++ filter ((>= ponderacion elemento) . ponderacion) ordenada) []

afectarALosQueCumplen :: (a -> Bool) -> (a -> a) -> [a] -> [a]
afectarALosQueCumplen criterio efecto lista
  = (map efecto . filter criterio) lista ++ filter (not.criterio) lista

--------------------------------------
-- FUNCIONES DE ORDEN SUPERIOR
--------------------------------------

elementoCumpleCriterioEnLista :: (a -> Bool) -> [a] -> Bool
elementoCumpleCriterioEnLista criterio = all criterio

--------------------------------------
-- FUNCIONES GENERALES
--------------------------------------

distanciaEntreAutos :: Auto -> Auto -> Int
distanciaEntreAutos auto1 = abs . (distancia auto1 -) . distancia

vaGanando :: Auto -> Carrera -> Bool
vaGanando auto = elementoCumpleCriterioEnLista (masAdelantado auto)

estaEnCarrera :: Auto -> Carrera -> Bool
estaEnCarrera auto = elem (color auto) . (map color)

masAdelantado :: Auto -> Auto -> Bool
masAdelantado auto = (distancia auto >) . distancia

distanciaARecorrer :: Auto -> Int -> Int
distanciaARecorrer auto tiempo = ((distancia auto +) . (tiempo *) . velocidad) auto

-- Ya sabemos que el color indicado va a estar en la carrera pero pusimos la guarda para dejar una logica correcta
buscarAutoEnCarrera :: Color -> Carrera -> Auto
buscarAutoEnCarrera colorIngresado = head . filter ((colorIngresado ==) . color)

--------------------------------------
-- RESOLUCION DE EJERCICIOS
--------------------------------------

-- 1A
estaCerca :: Auto -> Auto -> Bool
estaCerca auto1 auto2 = auto1 /= auto2 && ((< 10) . distanciaEntreAutos auto1) auto2

-- 1B
vaTranquilo :: Auto -> Carrera -> Bool
vaTranquilo auto = elementoCumpleCriterioEnLista (\x -> ((masAdelantado auto x) && not(estaCerca auto x)) || (auto == x))

-- 1C
definirPuesto :: Auto -> Carrera -> Int
definirPuesto auto = (+ 1) . length . filter (`masAdelantado` auto)

--2A
correrAuto :: Auto -> Int -> Auto
correrAuto auto tiempo = auto {distancia = distanciaARecorrer auto tiempo}

--2B
calcularVelocidad :: Int -> Int
calcularVelocidad =  max 0

bajarVelocidadAuto :: Int -> Auto -> Auto
bajarVelocidadAuto alteracion auto = auto {velocidad = calcularVelocidad (velocidad auto - alteracion)}

--3
terremoto :: Color -> Evento
terremoto = usarPowerUp (UnPowerUp estaCerca $ bajarVelocidadAuto 50)

miguelitos :: Int -> Color -> Evento
miguelitos tiempo = usarPowerUp (UnPowerUp masAdelantado (bajarVelocidadAuto tiempo))

jetPack :: Int -> Color -> Evento
jetPack tiempo = usarPowerUp (UnPowerUp (==) $ efectojetPack tiempo)

efectojetPack :: Int -> Auto -> Auto
efectojetPack tiempo auto = (bajarVelocidadAuto (velocidad auto) . (`correrAuto` tiempo) . (bajarVelocidadAuto (- velocidad auto))) auto
 
--4A
simularCarrera :: Carrera -> [Evento] -> TablaDePosiciones
simularCarrera carrera = crearTablaDePosiciones . foldl (\carrera evento  -> evento carrera) carrera --PUNTO 5 . agregarEvento (misilTeledirigido "blanco" "rojo")

crearTablaDePosiciones :: Carrera -> TablaDePosiciones
crearTablaDePosiciones carrera = (map (\auto -> (definirPuesto auto carrera, color auto)) . reverse . ordenarPor distancia) carrera

--4B
correnTodos :: Int -> Carrera -> Carrera
correnTodos tiempo = map $ flip correrAuto tiempo

usarPowerUp :: PowerUp -> Color -> Carrera -> Carrera
usarPowerUp power color carrera = afectarALosQueCumplen (criterioACumplir power (buscarAutoEnCarrera color carrera)) (modificacionAuto power) carrera

--4C
carreraInicial :: Carrera
carreraInicial = [UnAuto "azul" 120 0, 
                  UnAuto "blanco" 120 0, 
                  UnAuto "negro" 120 0, 
                  UnAuto "rojo" 120 0]

eventosAEjecutar :: [Evento]
eventosAEjecutar = [correnTodos 30,
                    jetPack 3 "azul",
                    terremoto "blanco",
                    correnTodos 40,
                    miguelitos 20 "blanco",
                    jetPack 6 "negro",
                    correnTodos 10,
                    misilTeledirigido "negro" "negro"]
                    
--5A
{-
  La solucion desarrollada hasta este punto permite agregar el nuevo power up ya que estos implican un criterio a cumplir y un
  efecto a realizar en los autos de la carrera que cumplen el criterio. Si bien el power up de misil teledirigido implica
  dos criterios distintos con sus dos efectos respectivamente, pudimos crear un nuevo evento para el misil teledirigido que se 
  base en dos power ups distintos pero ejecutados en conjunto y consecutivamente
-}

--5B
agregarEvento :: Evento -> [Evento] -> [Evento]
agregarEvento evento = (evento :)

misilTeledirigido :: Color -> Color -> Evento
misilTeledirigido colorEmisor colorAfectar carrera =
    usarPowerUp (UnPowerUp (\x y -> x == y) (efectoMisilTeledirigido (buscarAutoEnCarrera colorEmisor carrera))) colorAfectar carrera

efectoMisilTeledirigido :: Auto -> Auto -> Auto
efectoMisilTeledirigido autoEmisor autoAfectar
  | velocidadMenor50 autoAfectar && masAdelantado autoAfectar autoEmisor = autoAfectar {velocidad = 10, distancia = distancia autoAfectar + 5 }
  | velocidadMenor50 autoAfectar = autoAfectar {velocidad = 10} 
  | masAdelantado autoAfectar autoEmisor = autoAfectar {distancia = distancia autoAfectar + 5}
  | otherwise = autoAfectar 

velocidadMenor50 :: Auto -> Bool
velocidadMenor50 = (< 50) . velocidad