document.addEventListener('DOMContentLoaded', function () {
// Selecciona el enlace de eliminación
    var eliminarEstablecimientoLink = document.getElementById('eliminarEstablecimiento');

// Agrega un evento clic al enlace
    eliminarEstablecimientoLink.addEventListener('click', function (event) {
// Pregunta al usuario si realmente desea eliminar la comunidad
        var confirmacion = confirm('¿Estás seguro/a de que deseas eliminar este establecimiento?');

// Si el usuario cancela la acción, detén el enlace
        if (!confirmacion) {
            event.preventDefault();
        }
    });
});
