function guardarPrestacion() {
    const prestacionId = document.getElementById('prestacionId').value;

    const servicioElement = document.getElementById('servicio');
    const servicioId = servicioElement.options[servicioElement.selectedIndex].value;

    const establecimientoElement = document.getElementById('establecimiento');
    const establecimientoId = establecimientoElement.options[establecimientoElement.selectedIndex].value;


    // Confirmar con el usuario
    const confirmacion = confirm(`¿Está seguro/a de guardar los datos de la nueva prestación de servicio?`);

    // Guardar datos si se confirma
    if (confirmacion) {
        const datos = {
            servicio: servicioId,
            establecimiento: establecimientoId,
        };
        const url = '/editar-prestacion/' + prestacionId;
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
                window.location.href = '/todas-prestaciones';
            })
            .catch(error => {
                console.error('Error al enviar la solicitud:', error);
                alert('Error al enviar la solicitud');
            });
    }
}
