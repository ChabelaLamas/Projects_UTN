function Prestacion(id, servicio, establecimiento, establecimiento_id) {
    this.id = id;
    this.servicio = servicio;
    this.establecimiento = establecimiento;
    this.establecimiento_id = establecimiento_id;
}

function Establecimiento(id, comunidad) {
    this.id = id;
    this.comunidad = comunidad;
}

function leerPrestaciones() {
    const opcionesPrestacion = document.querySelectorAll(".prestacion-option");
    const prestacionesLeidas = [];

    for (const prestacionOption of opcionesPrestacion) {
        const id = prestacionOption.value;

        const textContent = prestacionOption.textContent.trim();

        const servicio = textContent.split(" en ")[0];
        const establecimiento = textContent.split(" en ")[1];

        const establecimiento_id = prestacionOption.getAttribute("data-establecimiento");

        const prestacion = new Prestacion(id, servicio, establecimiento, establecimiento_id);
        prestacionesLeidas.push(prestacion);
    }

    return prestacionesLeidas;
}

function leerEstablecimientos() {
    const divsEstablecimientos = document.querySelectorAll(".establecimientos-de-comunidad");
    const establecimientosLeidos = [];

    for (const divEstablecimiento of divsEstablecimientos) {
        const id = divEstablecimiento.getAttribute("data-establecimiento")
        const comunidad = divEstablecimiento.getAttribute("data-comunidad")

        const establecimiento = new Establecimiento(id, comunidad)
        establecimientosLeidos.push(establecimiento)
    }

    return establecimientosLeidos;
}

const establecimientos = leerEstablecimientos();
let establecimientosSeleccionados = [];
const prestaciones = leerPrestaciones();
const selectComunidad = document.querySelector(".comunidad-selector")
const selectPrestacion = document.querySelector(".prestacion-selector");
const textoComunidad = document.querySelector("#comunidadSeleccionadaTexto");

init();

function init() {
    if (selectComunidad.options.length > 0) {
        selectComunidad.options[0].selected = true;
        textoComunidad.textContent = selectComunidad.options[selectComunidad.selectedIndex].text;

        establecimientosSeleccionados = establecimientos.filter(establecimiento => establecimiento.comunidad === selectComunidad.value).map(establecimiento => establecimiento.id);
        mostrarPrestaciones();

        if (selectPrestacion.options.length > 0) {
            selectPrestacion.options[0].selected = true;
        }
    }
}

selectComunidad.addEventListener("change", () => {
    const comunidadSeleccionada = selectComunidad.options[selectComunidad.selectedIndex];
    textoComunidad.textContent = comunidadSeleccionada.text;
    establecimientosSeleccionados = establecimientos.filter(establecimiento => establecimiento.comunidad === comunidadSeleccionada.value).map(establecimiento => establecimiento.id)

    mostrarPrestaciones();
});

function mostrarPrestaciones() {
    selectPrestacion.innerHTML = "";

    if(selectComunidad.options.length > 0) {
        const comunidadSeleccionada = selectComunidad.options[selectComunidad.selectedIndex].value;
        const prestacionesAMostrar = new Array();

        for (const p of prestaciones) {
            const existePrestacion = prestacionesAMostrar.some(
                (existingP) => existingP.id === p.id
            );

            if (
                establecimientosSeleccionados.includes(p.establecimiento_id) &&
                !existePrestacion
            ) {
                prestacionesAMostrar.push(p);
            }
        }

        for(const prestacionAMostrar of prestacionesAMostrar) {
            const option = document.createElement('option');
            option.classList.add("prestacion-option");
            option.value = prestacionAMostrar.id;
            option.textContent = prestacionAMostrar.servicio + " en " + prestacionAMostrar.establecimiento; // Esto muestra la descripción del servicio
            option.setAttribute("data-establecimiento_id", prestacionAMostrar.establecimiento_id);

            selectPrestacion.appendChild(option);
        }
    }
}

const botonCrear = document.querySelector("#botonCrear");

botonCrear.addEventListener("click", () => {
    crearIncidente();
});

function crearIncidente() {
    const prestacion_id = selectPrestacion.options[selectPrestacion.selectedIndex].value;
    const denominacion = document.querySelector("#denominacion").value;
    const observaciones = document.querySelector("#observaciones").value;
    const comunidad_id = selectComunidad.options[selectComunidad.selectedIndex].value;

    if (denominacion.trim() === "") {
        alert("La denominación no puede estar vacía. Por favor, ingrese una denominación válida.");
        return false; // Evitar que el formulario se envíe si hay un error
    }

    // Confirmar con el usuario
    const confirmacion = confirm(`¿Está seguro/a de crear el incidente?`);

    // Guardar datos si se confirma
    if (confirmacion) {

    const data = {
        prestacion_id: prestacion_id,
        incidente_denominacion: denominacion,
        incidente_observaciones: observaciones,
        comunidad_id: comunidad_id,
    };

    fetch(`../../incidentes/crear`, {
        method: "POST",
        headers: {
            'Content-Type': 'application/json' // Puedes ajustar el encabezado según sea necesario
        },
        body: JSON.stringify(data) // Convierte los datos a JSON
    })
        .
        then(response => response.json())
        .then(data => {
            // Mostrar el mensaje recibido del servidor
            alert(data.mensaje);
            // Redirigir al usuario a otra página (por ejemplo, 'otra-pagina.hbs')
            window.location.href = '/incidentes';
        })
        .catch(error => {
            console.error('Error al enviar la solicitud:', error);
            alert('Error al enviar la solicitud');
        });

}
}