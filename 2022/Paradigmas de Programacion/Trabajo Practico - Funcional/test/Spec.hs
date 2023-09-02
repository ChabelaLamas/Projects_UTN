--import Library
import Test.Hspec
import TP

main :: IO ()
main = hspec $ do
  describe "TP integrador" $ do
    -- Autos
    let autoAzul = UnAuto "azul" 120 28
    let autoBlanco = UnAuto "blanco" 120 19
    let autoNegro = UnAuto "negro" 120 5
    let autoRojo = UnAuto "rojo" 120 42

    -- Carreras
    let carrera1 = [autoAzul, 
                    autoBlanco, 
                    autoNegro, 
                    autoRojo]
    let carrera2 = [autoAzul, 
                    autoBlanco, 
                    autoNegro, 
                    autoRojo {distancia = 22}]
    let carrera3 = [autoAzul {velocidad = 30},
                    autoBlanco,
                    autoNegro,
                    autoRojo]
    let eventos1 = [correnTodos 30,
                    jetPack 3 "azul",
                    terremoto "blanco",
                    correnTodos 40,
                    miguelitos 30 "blanco",
                    jetPack 6 "negro",
                    jetPack 25 "rojo"]
    
    -- Punto 1
    it "autos que estan a menos de 10 metros, estan cerca" $ do
      estaCerca autoAzul autoBlanco `shouldBe` True
    it "autos que estan a mas de 10 metros, no estan cerca" $ do
      estaCerca autoAzul autoNegro `shouldBe` False

    it "auto que va ganando y no tiene a nadie cerca, va tranquilo" $ do
       vaTranquilo autoRojo carrera1 `shouldBe` True
    it "auto que va primero y tiene a alguien cerca, no va tranquilo" $ do
       vaTranquilo autoAzul carrera2 `shouldBe` False
    it "auto que no va primero y no tiene a nadie cerca, no va tranquilo" $ do
       vaTranquilo autoNegro carrera1 `shouldBe` False

    it "la posicion de un auto que va primero" $ do
       definirPuesto autoRojo carrera1 `shouldBe` 1
    it "la posicion de un auto que va tercero" $ do
       definirPuesto autoBlanco carrera1 `shouldBe` 3

    -- Punto 2
    it "auto que corre durante 10 segundos a 120 de velocidad, avanza 1200" $ do
      correrAuto autoAzul 10 `shouldBe` autoAzul {distancia = distancia autoAzul + 1200}

    it "auto que disminuye su velocidad en 5 unidades" $ do
      bajarVelocidadAuto 5 autoAzul `shouldBe` autoAzul {velocidad = velocidad autoAzul -5}

    -- Punto 3
    it "Terremoto" $ do
      ordenarPor distancia (terremoto "azul" carrera1) `shouldBe` ordenarPor distancia [autoAzul, autoBlanco {velocidad = 70}, autoNegro, autoRojo]
    it "Miguelito" $ do
      ordenarPor distancia (miguelitos 40 "azul" carrera1) `shouldBe` ordenarPor distancia [autoAzul, autoBlanco {velocidad = 80}, autoNegro {velocidad = 80}, autoRojo]
    it "JetPack" $ do
      ordenarPor distancia (jetPack 4 "azul" carrera1) `shouldBe` ordenarPor distancia [autoAzul {distancia = distancia autoAzul + velocidad autoAzul * 2 * 4 }, autoBlanco, autoNegro, autoRojo]

    -- Punto 4
    it "Simulamos la carrera" $ do
      simularCarrera carrera2 eventos1 `shouldBe` [(1,"negro"),(2,"azul"),(3,"rojo"),(4,"blanco")]

    -- Punto 5
    it "Misil teledirigido" $ do
      misilTeledirigido "blanco" "azul" carrera3 `shouldBe` [autoAzul {distancia = 33, velocidad = 10 }, autoBlanco, autoNegro, autoRojo]

    -- prueba de integracion
    it "Simulamos la carrera con misil teledirigido" $ do
      simularCarrera carrera3 
        ((agregarEvento (correnTodos 10) . (agregarEvento (misilTeledirigido "blanco" "rojo"))) eventos1)
        `shouldBe` [(1,"rojo"),(2,"negro"),(3,"blanco"),(4,"azul")]