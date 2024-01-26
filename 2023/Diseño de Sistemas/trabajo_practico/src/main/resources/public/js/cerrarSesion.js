document.addEventListener("DOMContentLoaded", function() {
    const cerrarSesionLink = document.getElementById("cerrarSesionLink");

    cerrarSesionLink.addEventListener("click", function(event) {
        event.preventDefault(); // Evita que el enlace se siga al hacer clic

        const confirmacion = confirm("¿Seguro/a que deseas cerrar la sesión?");

        if (confirmacion) {
            window.location.href = "/logout";
        }
    });
});

const atras = document.getElementById('atrasLink')

if(atras) {
    atras.addEventListener('click', function() {
        // Navegar hacia atrás en la historia del navegador
        window.history.back();
    });
}
