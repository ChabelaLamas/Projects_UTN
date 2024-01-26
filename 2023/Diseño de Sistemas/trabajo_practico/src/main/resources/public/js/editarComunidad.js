function guardarComunidad() {
    // Obtener valores del formulario
    const comunidadId = document.getElementById('comunidadId').value;

    const nombre = document.getElementById('nombre').value;
    const descripcion = document.getElementById('descripcion').value;

    const selectServicio = document.getElementById('servicio');
    const opcionesSeleccionadasServicio = Array.from(selectServicio.selectedOptions).map(option => option.value);

    const selectEstablecimiento = document.getElementById('establecimiento');
    const opcionesSeleccionadasEstablecimiento = Array.from(selectEstablecimiento.selectedOptions).map(option => option.value);


    // Confirmar datos ingresados
    if (nombre.trim() === "") {
        alert("El nombre no puede estar vacío. Por favor, ingrese un nombre válido.");
        return false; // Evitar que el formulario se envíe si hay un error
    }

    // Confirmar con el usuario
    const confirmacion = confirm(`¿Está seguro/a de guardar los datos de la nueva comunidad?`);

    // Guardar datos si se confirma
    if (confirmacion) {
        const datos = {
            nombre: nombre,
            denominacion: descripcion,
            servicios: opcionesSeleccionadasServicio,
            establecimientos: opcionesSeleccionadasEstablecimiento,
        };
        const url = '/editar-comunidad/' + comunidadId;

        // Realizar solicitud POST al servidor sin manejar la respuesta
        fetch(url, {
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
                window.location.href = '/todas-comunidades';
            })
            .catch(error => {
                console.error('Error al enviar la solicitud:', error);
                alert('Error al enviar la solicitud');
            });
    }
}
