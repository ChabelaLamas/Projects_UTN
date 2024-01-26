
document.addEventListener('DOMContentLoaded', function () {
// Selecciona el enlace de eliminación
var eliminarComunidadLink = document.getElementById('eliminarComunidad');
var cambiarTipoMiembroLink = document.getElementById('cambiarTipoMiembro');
var tipoActualMiembro = document.getElementById('tipoActualMiembro').value;



eliminarComunidadLink.addEventListener('click', function (event) {
var confirmacion = confirm('¿Estás seguro/a de que deseas eliminar esta comunidad?');

if (!confirmacion) {
event.preventDefault();
}
});

cambiarTipoMiembroLink.addEventListener('click', function (event) {
    var confirmacion = confirm('¿Estás seguro/a de que deseas cambiar tu rol '+ tipoActualMiembro + ' de esta comunidad?');

    if (!confirmacion) {
        event.preventDefault();
    }
});

});

