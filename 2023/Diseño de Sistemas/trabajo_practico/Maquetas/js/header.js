// Función para cargar y mostrar el encabezado
function cargarEncabezado() {
    // Crea un objeto XMLHttpRequest para cargar el contenido del encabezado
    var xhr = new XMLHttpRequest();
    xhr.open('GET', '../headers/headerInterno.html', true);
  
    // Define la función que se ejecutará cuando se complete la solicitud
    xhr.onload = function() {
      if (xhr.status === 200) {
        // Éxito: inserta el contenido del encabezado en el elemento <div>
        document.getElementById('header-container').innerHTML = xhr.responseText;
      } else {
        // Error: muestra un mensaje de error o maneja la situación de otra manera
        console.error('Error al cargar el encabezado');
      }
    };
  
    // Envía la solicitud
    xhr.send();
  }
  
  // Llama a la función para cargar el encabezado cuando la página se carga completamente
  document.addEventListener('DOMContentLoaded', function() {
    cargarEncabezado();
  });
  