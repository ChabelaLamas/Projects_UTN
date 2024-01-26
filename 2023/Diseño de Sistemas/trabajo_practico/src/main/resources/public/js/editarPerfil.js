function Localidad(id, nombre, provincia_id) {
    this.id = id;
    this.nombre = nombre;
    this.provincia_id = provincia_id;
}

function leerLocalidades() {
    const selectLocalidad = document.querySelector("#localidad_select");
    const localidadesLeidas = [];

    for (const opcion of selectLocalidad.options) {
        const localidad = new Localidad(opcion.value, opcion.text, opcion.getAttribute("data-provincia"));
        localidadesLeidas.push(localidad);
    }

    return localidadesLeidas;
}

let localidades = []
const selectProvincia = document.querySelector("#provincia_select");


document.addEventListener('DOMContentLoaded', function() {
    localidades = leerLocalidades();

    console.log(localidades);

    const selectLocalidad = document.querySelector("#localidad_select");

    selectLocalidad.addEventListener('change', () => {
        console.log('Localidad seleccionada:', this.text);
    });


    selectProvincia.addEventListener("change", () => {
        cargarLocalidades(selectProvincia.value);
    });

});

selectProvincia.addEventListener("change", () => {
    cargarLocalidades(selectProvincia.value);
});


function cargarLocalidades(provincia_id) {
    console.log(localidades);
    const localidadesAMostrar = localidades.filter(localidad => esDeProvincia(provincia_id, localidad));

    const selectLocalidad = document.querySelector("#localidad_select");
    selectLocalidad.innerHTML = "";

    for (const localidadAMostrar of localidadesAMostrar) {
        var opcion = document.createElement("option");
        opcion.value = localidadAMostrar.id;
        opcion.textContent = localidadAMostrar.nombre;
        selectLocalidad.appendChild(opcion);
    }
}

function esDeProvincia(provincia_id, localidad) {
    return provincia_id === localidad.provincia_id
}

document.addEventListener('DOMContentLoaded', function() {
    const preferenciaMedioNotificacion = "{{persona.preferenciaMedioNotificacion}}";

    //console.log('preferenciaMedioNotificacion:', preferenciaMedioNotificacion);

    let botonMedioNotificacion = document.querySelector(`#grupo1 .boton_seleccionador[data-valor="${preferenciaMedioNotificacion}"]`);
    if (botonMedioNotificacion) {
        botonMedioNotificacion.click();
    }

});

document.addEventListener('DOMContentLoaded', function() {
    const botonesSeleccionadores = document.querySelectorAll(".boton_seleccionador");

    botonesSeleccionadores.forEach(boton => {
        boton.addEventListener("click", function() {
            const campo = this.getAttribute('data-campo');
            const valor = this.getAttribute('data-valor');

            // Obtén el grupo al que pertenece este botón
            const grupo = this.closest('.grupo');
            const botonesDelGrupo = grupo.querySelectorAll('.boton_seleccionador');

            botonesDelGrupo.forEach(b => {
                // Quita la clase de todos los botones del grupo
                b.classList.remove('boton_seleccionado');
            });

            this.classList.add('boton_seleccionado');

            if (campo === "frecuenciaNotificacion") {
                if (valor === "CUANDO_SUCEDE") {
                    ocultarElementos();
                } else if (valor === "SIN_APURO") {
                    mostrarElementos();
                }
            }

            guardarCampo(campo, valor);
        });
    });

    // Inicialmente, hacer clic en el primer botón de "Cuando sucede"
    document.querySelector("#grupo2 .boton_seleccionador:nth-child(1)").click();
});

// Horarios
// Set para almacenar los horarios seleccionados
const selectedHorarios = new Set();

function toggleDropdown() {
    const dropdown = document.querySelector(".dropdown");
    const addBtn = document.querySelector('.add-btn');

    if (dropdown.style.display === "block") {
        // Si el menú está visible, ocultarlo y restablecer la posición del botón "+"
        dropdown.style.display = "none";
        addBtn.style.position = "static";
    } else {
        // Si el menú está oculto, mostrarlo y ajustar la posición del botón "+"
        dropdown.style.display = "block";
        addBtn.style.position = "relative";
    }
}

// Función para generar los horarios automáticamente
function generateTimes() {
    const dropdownContent = document.getElementById('dropdown-content');
    for (let i = 0; i < 24; i++) {
        const hour = i.toString().padStart(2, '0') + ':00';
        const link = document.createElement('a');
        link.href = '#';
        link.dataset.horario = hour;
        link.onclick = function () {
            selectHorario(this);
        };
        link.textContent = hour;
        dropdownContent.appendChild(link);
    }
}

// Función para manejar la selección de horarios
function selectHorario(element) {
    const horario = element.getAttribute("data-horario");
    if (!selectedHorarios.has(horario)) {
        selectedHorarios.add(horario);
        element.style.color = "#0CC0DF";
        element.style.pointerEvents = "none";

        const etiqueta = document.createElement('span');
        etiqueta.classList.add('etiqueta-horario');
        etiqueta.innerHTML = `${horario} <button class="eliminar-horario" onclick="eliminarHorario(this, '${horario}')">x</button>`;
        const container = document.querySelector('.horarios-seleccionados');
        container.appendChild(etiqueta);
    } else {
        alert("Este horario ya ha sido seleccionado.");
    }
}

// Función para eliminar horarios seleccionados
function eliminarHorario(buttonElement, horario) {
    selectedHorarios.delete(horario);
    buttonElement.parentElement.remove();
}

// Función para guardar horarios en el servidor
function guardarHorarios() {
    const horariosArray = Array.from(selectedHorarios);
    guardarCampo('horarios', JSON.stringify(horariosArray));
}

// Función para enviar datos al servidor
function guardarCampo(campo, valor) {
    $.ajax({
        url: '/perfil',
        type: 'POST',
        data: { campo: campo, valor: valor },
        success: function(response){
            //console.log('Campo actualizado exitosamente:', response);
        },
        error: function(error) {
            alert('Error al guardar campo: ' + error.responseText);
        }
    });
}

// Inicialización: generar horarios y agregar eventos
document.addEventListener("DOMContentLoaded", function() {
    generateTimes();  // Genera los horarios automáticamente

    document.querySelector('.horarios-seleccionados').addEventListener('click', function(event) {
        if (event.target.classList.contains('eliminar-horario')) {
            event.target.parentElement.remove();
        }
    });
});


function toggleBotones() {
    const cuandoSucedeButton = document.querySelector('[data-valor="CUANDO_SUCEDE"]');
    const sinApurosButton = document.querySelector('[data-valor="SIN_APURO"]');
    const guardarButton = document.querySelector('.botonsote');
    const addHorariosButton = document.querySelector('.add-btn');
    const parrafo = document.getElementById('parrafo');

    if (sinApurosButton.classList.contains('boton_seleccionado')) {
        mostrarElementos();
    } else {
        ocultarElementos();
    }
}


function ocultarElementos() {
    const parrafo = document.getElementById('parrafo');
    const guardarButton = document.querySelector('#botonGuardar');
    const addHorariosButton = document.querySelector('.add-btn');

    parrafo.style.display = 'none';
    //guardarButton.style.display = 'none';
    addHorariosButton.style.display = 'none';
}

function mostrarElementos() {
    const parrafo = document.getElementById('parrafo');
    const guardarButton = document.querySelector('.botonsote');
    const addHorariosButton = document.querySelector('.add-btn');

    parrafo.style.display = 'block';
    guardarButton.style.display = 'block';
    addHorariosButton.style.display = 'block';
}


