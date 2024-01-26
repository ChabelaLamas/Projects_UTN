document.addEventListener("DOMContentLoaded", function() {
    const selected = document.querySelector(".selected");
    const optionsContainer = document.querySelector(".options-container");
    const optionsList = document.querySelectorAll(".option");


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

function actualizarComunidadSeleccionada(comunidadId) {
    const comunidadInput = document.querySelector("#selectedComunidad");
    comunidadInput.value = comunidadId;
}


document.addEventListener("DOMContentLoaded", function() {
    const optionsList = document.querySelectorAll(".option");
    const comunidadInput = document.querySelector("#selectedComunidad");
    const form = document.getElementById("joinForm");

    optionsList.forEach((option) => {
        option.addEventListener("click", () => {
            const comunidadId = option.getAttribute("data-comunidad-id");
            comunidadInput.value = comunidadId;
        });
    });

    form.addEventListener("submit", function(event) {
        if (comunidadInput.value === "") {
            event.preventDefault(); // Evita el envío del formulario
            alert("Por favor, seleccione una comunidad para editar.");
        }
    });
});

