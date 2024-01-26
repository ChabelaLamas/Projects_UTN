document.addEventListener("DOMContentLoaded", function() {
    const selected = document.querySelector(".selected");
    const optionsContainer = document.querySelector(".options-container");
    const optionsList = document.querySelectorAll(".option");

    // Seleccionar tipo por defecto
    seleccionarTipo('observador');

    selected.addEventListener("click", () => {
        optionsContainer.classList.toggle("active");
    });

    optionsList.forEach((option) => {
        option.addEventListener("click", () => {
            selected.textContent = option.querySelector("label").textContent;
            const descriptionServicios = option.getAttribute("data-description");
            const descriptionEstablecimientos = option.getAttribute("data-description1");
            const combinedDescription = descriptionServicios + '<br>' + descriptionEstablecimientos;

            const descriptionElement = document.querySelector(".description");
            if (descriptionElement) {
                descriptionElement.innerHTML = combinedDescription; // Usamos innerHTML para permitir el uso de HTML en el contenido
            }
            actualizarComunidadSeleccionada(option.getAttribute("data-comunidad-id"));
            optionsContainer.classList.remove("active");
        });
    });

    // Agregamos un evento click al documento para cerrar el menú si se hace clic en cualquier otro lugar
    document.addEventListener("click", (e) => {
        if (!selected.contains(e.target) && !optionsContainer.contains(e.target)) {
            optionsContainer.classList.remove("active");
        }
    });
});

document.querySelector(".botonUnir").addEventListener("click", (e) => {
    const selected = document.querySelector(".selected");
    if (selected.textContent == "Seleccione una comunidad para sumarse") {
        console.log("Comunidad no seleccionada");
        e.preventDefault(); // Evitar el envío del formulario si no se ha seleccionado una comunidad
    } else {
        console.log("Comunidad seleccionada");
    }
});

function seleccionarTipo(tipo) {
    const botonObservador = document.getElementById("botonObservador");
    const botonAfectado = document.getElementById("botonAfectado");

    // Elimina la clase "activo" de ambos botones
    botonObservador.classList.remove("activo");
    botonAfectado.classList.remove("activo");

    if (tipo === 'observador') {
        botonObservador.classList.add("activo");
        botonAfectado.style.backgroundColor = '#BEBEBE';
        botonObservador.style.backgroundColor = '#0CC0DF';
    } else if (tipo === 'afectado') {
        botonAfectado.classList.add("activo");
        botonObservador.style.backgroundColor = '#BEBEBE';
        botonAfectado.style.backgroundColor = '#0CC0DF';
    }

    actualizarTipoSeleccionado(tipo); // Actualiza el input oculto con el tipo seleccionado
}

function actualizarTipoSeleccionado(tipo) {
    const tipoInput = document.querySelector("#selectedTipo");
    tipoInput.value = tipo;
}

function actualizarComunidadSeleccionada(comunidadId) {
    const comunidadInput = document.querySelector("#selectedComunidad");
    comunidadInput.value = comunidadId;
}