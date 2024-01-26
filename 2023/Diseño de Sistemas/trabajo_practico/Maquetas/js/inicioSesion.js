function seleccionarTipo(tipo) {
  const botonCorreo = document.getElementById("botonCorreo");
  const botonTelefono = document.getElementById("botonTelefono");
  const campo = document.getElementById("campoTelefonoYMail");

  // Aplica la clase "activo" al botón seleccionado
  if (botonTelefono.classList.contains("activo") && tipo == "correo") {
    botonTelefono.classList.remove("activo");
    botonCorreo.classList.add("activo");
    campo.placeholder = "Correo Electrónico";
  } else if (botonCorreo.classList.contains("activo") && tipo == "telefono") {
    botonCorreo.classList.remove("activo");
    botonTelefono.classList.add("activo");
    campo.placeholder = "Teléfono";
  }
}


function validarFormulario() {
  var nombreUsuario = document.getElementById('campoNombreUsuario');
  var contrasena = document.getElementById('campoContrasena');
  var campoTelefonoYMail = document.getElementById('campoTelefonoYMail');

  if (!nombreUsuario.value || !contrasena.value || !campoTelefonoYMail.value) {
    alert('Por favor, complete todos los campos.');
    return false;
  }

  return true;
} 

function validarFormularioInicio() {
  var nombreUsuario = document.getElementById('usuarioInput');
  var contrasena = document.getElementById('contraseniaInput');
  
  if (!nombreUsuario.value || !contrasena.value) {
      alert('Por favor, complete los campos de nombre de usuario y contraseña.');
      return false;
  }
  

  return true;
}