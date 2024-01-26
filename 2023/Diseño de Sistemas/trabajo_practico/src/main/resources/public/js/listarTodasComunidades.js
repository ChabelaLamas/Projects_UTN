document.addEventListener('DOMContentLoaded', function () {
// Selecciona el enlace de eliminación
    var eliminarComunidadLink = document.getElementById('eliminarComunidad');

// Agrega un evento clic al enlace
    eliminarComunidadLink.addEventListener('click', function (event) {
// Pregunta al usuario si realmente desea eliminar la comunidad
        var confirmacion = confirm('¿Estás seguro/a de que deseas eliminar esta comunidad?');

// Si el usuario cancela la acción, detén el enlace
        if (!confirmacion) {
            event.preventDefault();
        }
    });
});
