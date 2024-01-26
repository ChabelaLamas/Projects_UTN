function guardarEntidad() {
    // Obtener valores del formulario
    const denominacion = document.getElementById('denominacion').value;

    const tipoEntidad = document.getElementById('tipoEntidad').value;

    const tipoEstablecimiento = document.getElementById('tipoEstablecimiento').value;

    const entidadPrestadoraElement = document.getElementById('entidadPrestadora');
    const entidadPrestadoraId = entidadPrestadoraElement.options[entidadPrestadoraElement.selectedIndex].value;


    // Confirmar datos ingresados
    if (denominacion.trim() === "") {
        alert("La denominación no puede estar vacía. Por favor, ingrese una denominación válida.");
        return false; // Evitar que el formulario se envíe si hay un error
    }

    // Confirmar con el usuario
    const confirmacion = confirm(`¿Está seguro/a de guardar los datos de la nueva entidad?`);

    // Guardar datos si se confirma
    if (confirmacion) {
        const datos = {
            denominacion: denominacion,
            tipoEntidad: tipoEntidad,
            tipoEstablecimiento: tipoEstablecimiento,
            entidadPrestadoraId: entidadPrestadoraId,
        };

        // Realizar solicitud POST al servidor sin manejar la respuesta
        fetch('/crear-entidad', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(datos)
        })
            .
            then(response => response.json())
            .then(data => {
                // Mostrar el mensaje recibido del servidor
                alert(data.mensaje);
                // Redirigir al usuario a otra página (por ejemplo, 'otra-pagina.hbs')
                window.location.href = '/todas-entidades';
            })
            .catch(error => {
                console.error('Error al enviar la solicitud:', error);
                alert('Error al enviar la solicitud');
            });
    }
}
