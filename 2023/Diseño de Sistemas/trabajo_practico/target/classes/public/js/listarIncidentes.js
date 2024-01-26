function Incidente(id, denominacion, prestacion, fechaApertura, observaciones, estado, comunidad) {
    this.id = id;
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
        const id = incidenteDiv.getAttribute("data-incidente-id")

        const incidente = new Incidente(id, denominacion, prestacion, fechaApertura, observaciones, estado, comunidad);
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

        const btnCerrar = document.createElement("a");
        btnCerrar.classList.add("btn-close");
        btnCerrar.textContent = "X";
        btnCerrar.setAttribute("href", `/incidentes/cerrar/${incidente.id}`);

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

    crearEventsListenersClose()
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

function crearEventsListenersClose() {
    const btnsCerrarIncidente = document.querySelectorAll(".btn-close")

    btnsCerrarIncidente.forEach(btnCerrarIncidente => {
        btnCerrarIncidente.addEventListener('click', function (event) {
            const confirmacion = confirm('¿Estás seguro/a de que deseas cerrar este incidente?');

            if (!confirmacion) {
                event.preventDefault();
            }
        });
    })
}

crearEventsListenersClose()




