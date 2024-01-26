function seleccionarTipo(tipoNuevo) {
    const botonCorreo = document.getElementById("botonCorreo");
    const botonTelefono = document.getElementById("botonTelefono");
    const campo = document.getElementById("campoTelefonoYMail");
    const tipoSeleccionado = document.getElementById("tipoSeleccionado");

    // Aplica la clase "activo" al botón seleccionado
    if (tipoSeleccionado.value === "telefono" && tipoNuevo === "correo") {
        botonTelefono.classList.remove("activo");
        botonCorreo.classList.add("activo");
        campo.placeholder = "Correo Electrónico";
        tipoSeleccionado.value = "correo";
    } else if (tipoSeleccionado.value === "correo" && tipoNuevo === "telefono") {
        botonCorreo.classList.remove("activo");
        botonTelefono.classList.add("activo");
        campo.placeholder = "Teléfono";
        tipoSeleccionado.value = "telefono"
    }
}


function validarFormulario() {
    const nombreUsuario = document.getElementById('campoNombreUsuario');
    const contrasena = document.getElementById('campoContrasena');
    const campoTelefonoYMail = document.getElementById('campoTelefonoYMail');

    if (!nombreUsuario.value || !contrasena.value || !campoTelefonoYMail.value) {
        alert('Por favor, complete todos los campos.');
        return false;
    }

    var confirmacion = confirm('¿Estás seguro/a de que deseas crear este usuario?');

    // Si el usuario elige "Cancelar" en la ventana emergente, devuelve false y detiene el envío del formulario.
    if (!confirmacion) {
        return false;
    }

    return true;
}

function validarFormularioInicio() {
    const nombreUsuario = document.getElementById('usuarioInput');
    const contrasena = document.getElementById('contraseniaInput');

    if (!nombreUsuario.value || !contrasena.value) {
        alert('Por favor, complete los campos de nombre de usuario y contraseña.');
        return false;
    }

    return true;
}

function seleccionarTipo(tipoNuevo) {
    const valorMedio = (tipoNuevo === 'correo') ? 'EMAIL' : 'WHATSAPP';
    document.getElementById('campoValorMedio').value = valorMedio;

    const botonCorreo = document.getElementById("botonCorreo");
    const botonTelefono = document.getElementById("botonTelefono");
    const campo = document.getElementById("campoTelefonoYMail");
    const tipoSeleccionado = document.getElementById("tipoSeleccionado");

    // Aplica la clase "activo" al botón seleccionado
    if (tipoSeleccionado.value === "telefono" && tipoNuevo === "correo") {
        botonTelefono.classList.remove("activo");
        botonCorreo.classList.add("activo");
        campo.placeholder = "Correo Electrónico";
        tipoSeleccionado.value = "correo";
    } else if (tipoSeleccionado.value === "correo" && tipoNuevo === "telefono") {
        botonCorreo.classList.remove("activo");
        botonTelefono.classList.add("activo");
        campo.placeholder = "Teléfono";
        tipoSeleccionado.value = "telefono"
    }
}

