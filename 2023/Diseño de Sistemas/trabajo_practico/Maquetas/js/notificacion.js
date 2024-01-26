document.addEventListener("DOMContentLoaded", function() {

    // Obtener los elementos del DOM
    const notificationPopup = document.getElementById('notificationPopup');
    const closeNotificationBtn = document.getElementById('closeNotification');
    const showNotificationBtn = document.getElementById('showNotification');

    // Variable para almacenar el ID del setTimeout
    let hideTimeout;

    // Función para mostrar la notificación
    showNotificationBtn.addEventListener('click', function() {
        notificationPopup.classList.add('show');

        // Clear previous timeout
        clearTimeout(hideTimeout);

        // Hacer que la notificación desaparezca después de 5 segundos
        hideTimeout = setTimeout(() => {
            notificationPopup.classList.remove('show');
        }, 5000);
    });

    // Función para cerrar la notificación
    closeNotificationBtn.addEventListener('click', function() {
        notificationPopup.classList.remove('show');
        
        // Clear the timeout
        clearTimeout(hideTimeout);
    });

    });