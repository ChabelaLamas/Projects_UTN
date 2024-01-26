package models.domain.main.notificaciones.mediosNotificacion.Email;

import models.config.Config;
import models.domain.main.notificaciones.frecuenciasNotificacion.Notificacion;
import jakarta.mail.*;
import jakarta.mail.internet.InternetAddress;
import jakarta.mail.internet.MimeMessage;

import java.util.Properties;

public class JavaxMail implements EmailAdapter{
  public void mandar(Notificacion notificacion) {
    String host = Config.obtenerInstancia().obtenerDelConfig("host_javax"); // Host del servidor de correo
    int port = Integer.parseInt(Config.obtenerInstancia().obtenerDelConfig("puerto_javax")); // Puerto del servidor de correo
    String username = Config.obtenerInstancia().obtenerDelConfig("usuario_javax"); // Nombre de usuario del correo
    String password = Config.obtenerInstancia().obtenerDelConfig("contrasenia_javax"); // Contraseña del correo
    String from = "jcarriquirycastro@frba.utn.edu.ar"; // remitente
    String subject = "Sistema de Apoyo a Comunidades con Movilidad Reducida";

    Properties props = new Properties();
    props.put("mail.smtp.auth", "true");
    props.put("mail.smtp.starttls.enable", "true");
    props.put("mail.smtp.host", host);
    props.put("mail.smtp.port", port);

    Authenticator auth = new Authenticator() {
      protected PasswordAuthentication getPasswordAuthentication() {
        return new PasswordAuthentication(username, password);
      }
    };

    Session session = Session.getInstance(props, auth);

    try {
      MimeMessage message = new MimeMessage(session);
      message.setFrom(new InternetAddress(from));
      message.setRecipients(Message.RecipientType.TO, InternetAddress.parse(notificacion.getDestinatario().getEmail()));
      message.setSubject(subject);
      message.setText(notificacion.getMensaje());

      Transport.send(message);
      System.out.println("Se mando el email exitosamente.");
      notificacion.cambiarEstadoAEnviado();
    } catch (MessagingException e) {
      e.printStackTrace();
    }
  }
}
