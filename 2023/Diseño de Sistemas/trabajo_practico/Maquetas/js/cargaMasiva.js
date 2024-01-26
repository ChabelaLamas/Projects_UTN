document.getElementById('csvfile').addEventListener('change', function() {
    const file = this.files[0];
    const fileName = file.name;
    const fileExtension = fileName.split('.').pop().toLowerCase();

    if (fileExtension !== 'csv') {
        // Muestra el mensaje de error
        document.getElementById('error-message').style.display = 'block';
        // Limpia el input para que el usuario no pueda enviar un archivo no válido
        this.value = '';
        // Restablece el nombre del archivo a "ejemplo.csv"
        document.getElementById('csv-filename').textContent = 'ejemplo.csv';
    } else {
        // Oculta el mensaje de error si previamente se mostró
        document.getElementById('error-message').style.display = 'none';
        // Muestra el nombre del archivo
        document.getElementById('csv-filename').textContent = fileName;
    }
});






