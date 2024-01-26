function Incidente(denominacion, prestacion, fechaApertura, observaciones, estado, comunidad) {
    this.denominacion = denominacion;
    this.prestacion = prestacion;
    this.fechaApertura = fechaApertura;
    this.observaciones = observaciones;
    this.estado = estado;
    this.comunidad = comunidad;
}

function leerIncidentes() {
    const incidentesDivs = document.querySelectorAll(".incidente");
    const incidentesLeidos = [];

    for (const incidenteDiv of incidentesDivs) {
        const denominacionElement = incidenteDiv.querySelector(".denominacion");
        const denominacion = denominacionElement.textContent.trim();

        const prestacionElement = incidenteDiv.querySelector(".prestacion");
        const prestacion = prestacionElement.textContent.trim();

        const fechaAperturaElement = incidenteDiv.querySelector(".fechaApertura");
        const fechaApertura = fechaAperturaElement.textContent.trim();

        const observacionesElement = incidenteDiv.querySelector(".observaciones");
        const observaciones = observacionesElement.textContent.trim();

        const estadoElement = incidenteDiv.querySelector(".estado");
        const estado = estadoElement.textContent.trim();

        const comunidad = incidenteDiv.getAttribute("data-comunidad");

        const incidente = new Incidente(denominacion, prestacion, fechaApertura, observaciones, estado, comunidad);
        incidentesLeidos.push(incidente);
    }

    return incidentesLeidos;
}

const incidentes = leerIncidentes();
let comunidadSeleccionada = "todas";
let estadoSeleccionado = "AMBOS";

function mostrarIncidentes() {
    const seccionTarjetas = document.querySelector(".seccion-tarjetas");
    seccionTarjetas.innerHTML = "";
    const incidentesAMostrar = incidentes.filter(incidente => hayQueMostrar(incidente));

    for (const incidente of incidentesAMostrar) {
        const tarjeta = document.createElement("div");
        tarjeta.classList.add("incidente");

        const denominacion = document.createElement("span");
        denominacion.classList.add("denominacion");
        denominacion.textContent = incidente.denominacion;

        const prestacion = document.createElement("span");
        prestacion.classList.add("prestacion");
        prestacion.textContent = incidente.prestacion;

        const horario = document.createElement("span");
        horario.textContent = "Horario de publicación: " + incidente.fechaApertura;

        const observaciones = document.createElement("span");
        observaciones.textContent = "Observaciones: " + incidente.observaciones;

        const estado = document.createElement("span");
        estado.textContent = "Estado: " + incidente.estado

        const btnCerrar = document.createElement("button");
        btnCerrar.classList.add("btn-close");
        btnCerrar.textContent = "X";

        tarjeta.appendChild(document.createTextNode("Denominación: "));
        tarjeta.appendChild(denominacion);
        tarjeta.appendChild(document.createElement("br"));
        tarjeta.appendChild(document.createTextNode("Prestación: "));
        tarjeta.appendChild(prestacion);
        tarjeta.appendChild(document.createElement("br"));
        tarjeta.appendChild(horario);
        tarjeta.appendChild(document.createElement("br"));
        tarjeta.appendChild(observaciones);
        tarjeta.appendChild(document.createElement("br"));
        tarjeta.appendChild(estado);
        tarjeta.appendChild(document.createElement("br"));
        tarjeta.appendChild(btnCerrar);

        seccionTarjetas.appendChild(tarjeta);
    }
}

function hayQueMostrar(incidente) {
    return (incidente.comunidad === comunidadSeleccionada || comunidadSeleccionada === "todas") && (estadoSeleccionado === "AMBOS" || estadoSeleccionado === incidente.estado);
}

const selectEstado = document.querySelector("#estado-selector");
const selectComunidad = document.querySelector(".comunidad-selector");

selectEstado.addEventListener("change", () => {
    estadoSeleccionado = selectEstado.value;
    mostrarIncidentes();
});

selectComunidad.addEventListener("change", () => {
    const textoComunidad = document.querySelector("#comunidadSeleccionadaTexto");

    if (selectComunidad.value === "todas") {
        textoComunidad.textContent = "Todas las comunidades";
    } else {
        textoComunidad.textContent = selectComunidad.value;
    }

    comunidadSeleccionada = selectComunidad.value;
    mostrarIncidentes();
});

const buttonsClose = document.querySelectorAll(".btn-close");

buttonsClose.forEach(button => {
    button.addEventListener("click", () => {
        const incidenteId = obtenerIncidenteIdDesdeBoton(button);
        cerrarIncidente(incidenteId);
    });
});

function obtenerIncidenteIdDesdeBoton(button) {
    // Obtiene el valor del atributo data-incidente-id del botón
    const incidenteId = button.getAttribute("data-incidente-id");
    // Asegúrate de que el valor no sea nulo y sea válido antes de devolverlo
    if (incidenteId !== null && incidenteId !== "") {
        return incidenteId;
    } else {
        // En caso de que el atributo no esté definido o sea inválido
        console.error("El atributo data-incidente-id no está definido o es inválido en el botón.");
        return null; // O maneja el error de la manera que consideres adecuada
    }
    console
}

function cerrarIncidente(incidenteId) {
    fetch(`incidente/${incidenteId}/cerrar`, {
        method: "POST",
        // Puedes agregar otros encabezados o datos en el cuerpo de la solicitud si es necesario
    })
        .catch(error => {
            console.error("Error en la solicitud POST:", error);
        });
}
