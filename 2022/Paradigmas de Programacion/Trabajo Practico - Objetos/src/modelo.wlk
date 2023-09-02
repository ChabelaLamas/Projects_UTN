
// ACADEMIA
class Academia {
	var property cocineros 
	var property recetario
	var property experienciaMaxima
	method entrenarCocineros () {
		cocineros.forEach({cocinero => cocinero.prepararRecetaQueAportaMas(recetario)})
	}
}

class Cocinero {
	const academia
	const property preparaciones 
	var property nivelDeAprendizaje = principiante
	
	method experiencia () = self.experienciasDePreparaciones().sum()
	method experienciasDePreparaciones () = preparaciones.map({comida => comida.experiencia(academia)})
	method recetasPreparadas () = preparaciones.map({comida => comida.receta()}) 
	method comidasConRecetasSimilaresA (receta) = preparaciones.filter({comida => comida.tieneRecetaSimilarA(receta)})
	method tieneRecetaSimilarA (receta) = self.comidasConRecetasSimilaresA(receta).size() > 0
	method expComidasConRecetasSimilarA (receta) = self.comidasConRecetasSimilaresA (receta).map({comida => comida.experiencia(self)}).sum()
	method convertirseEnExperto () {
		nivelDeAprendizaje = experimentado
	} 
	method convertirseEnChef () {
		nivelDeAprendizaje = chef
	}
	method superarNivel () {
		nivelDeAprendizaje.verificarSuperarNivel(self)
	} 
	method calcularPlus (receta) = self.comidasConRecetasSimilaresA(receta).size() / 10
	method recetaQueAportaMas (recetas) = recetas.max({receta => receta.experienciaAportada()})
	method preparar (receta) {
		if (!nivelDeAprendizaje.puedePreparar(self, receta)) {
			throw new NoPuedePrepararComida(message = "Debido a su nivel, no puede preparar esta comida")
		}
		self.sumarPreparacion(receta)
		self.superarNivel()
	}
	method recetasQuePuedePreparar (recetas) = recetas.filter{receta => nivelDeAprendizaje.puedePreparar(self, receta)}
	method prepararRecetaQueAportaMas (recetas) {
		
		const receta = self.recetaQueAportaMas(self.recetasQuePuedePreparar (recetas))
		self.preparar(receta)
	}
	method sumarPreparacion(receta) {
		const comida = new Comida (receta = receta, calidad = nivelDeAprendizaje.calidadComida(self, receta))
		preparaciones.add(comida)
	}
	
}


// NIVEL DE APRENDIZAJE
const experimentado = new Experimentado ()
const principiante = new Principiante ()

class Principiante {
	method puedePreparar (cocinero, receta) = !receta.esDificil()
	method verificarSuperarNivel (cocinero) {
		if (cocinero.experiencia () > 100) cocinero.convertirseEnExperto() 
	}
	method calidadComida (cocinero, receta) {
		if (receta.cantidadDeIngredientes() < 4) return normal
		return pobre
	}
}

class Experimentado inherits Principiante {
	override method puedePreparar (cocinero, receta) = super(cocinero,receta) || cocinero.tieneRecetaSimilarA(receta)
	override method verificarSuperarNivel (cocinero) {
		const recetasDificiles = cocinero.recetasPreparadas().filter({receta => receta.esDificil()})
		if (recetasDificiles.size() > 5) cocinero.convertirseEnChef() 
	}
	override method calidadComida (cocinero, receta) {
	if (receta.perfeccionarReceta(cocinero)) {
		return new Superior (plus = cocinero.calcularPlus(receta))
		}
		return normal
	}
}

object chef inherits Experimentado {
	override method puedePreparar (cocinero, receta) = true
	override method verificarSuperarNivel (cocinero) {}
}

class NoPuedePrepararComida inherits DomainException {}


// PRODUCCIONES
class Receta {
	const property nivelDificultad
	const property ingredientes
	method cantidadDeIngredientes () = ingredientes.size()
 	method experienciaAportada () = self.cantidadDeIngredientes() * nivelDificultad
	method dificultadesSimilares (recetita) = (nivelDificultad - recetita.nivelDificultad()).abs() >= 1 
	method esSimilar (otraReceta) = ingredientes == otraReceta.ingredientes() || self.dificultadesSimilares(otraReceta)
	method esDificil () = nivelDificultad > 5 || ingredientes.size() > 10
	method perfeccionarReceta (cocinero) = cocinero.expComidasConRecetasSimilarA(self) == 3 * self.experienciaAportada()
}

class RecetaGourmet inherits Receta {
	override method experienciaAportada () = super() * 2
	override method esDificil () = true
}

class Comida {
	var property calidad
	const property receta
	method experiencia (academia) = calidad.experienciaAportada (receta, academia)
	method tieneRecetaSimilarA (otraReceta) = receta.esSimilar(otraReceta)
}


// CALIDAD
object pobre {
	method experienciaAportada (receta, academia) = academia.experienciaMaxima().min(receta.experienciaAportada()) 
}

object normal {
	method experienciaAportada (receta, academia) = receta.experienciaAportada()
}

class Superior {
	const plus 
	method experienciaAportada (receta, academia) = receta.experienciaAportada() + plus
}

