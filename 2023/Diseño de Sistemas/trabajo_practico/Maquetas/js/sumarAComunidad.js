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
        
        // Combina las dos descripciones con un elemento <br> para el salto de línea
        const combinedDescription = descriptionServicios + '<br>' + descriptionEstablecimientos;
    
        const descriptionElement = document.querySelector(".description");
        if (descriptionElement) {
          descriptionElement.innerHTML = combinedDescription; // Usamos innerHTML para permitir el uso de HTML en el contenido
        }
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
  console.log(selected.textContent);
  if (selected.textContent == "Seleccione una comunidad para sumarse") {
    console.log("AAAA");
  } else {
    console.log("bbbb");
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
  }
  
