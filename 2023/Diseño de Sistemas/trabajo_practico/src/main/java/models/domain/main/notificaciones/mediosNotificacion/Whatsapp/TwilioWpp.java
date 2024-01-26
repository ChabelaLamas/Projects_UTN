package models.domain.main.notificaciones.mediosNotificacion.Whatsapp;

import com.twilio.Twilio;
import com.twilio.rest.api.v2010.account.Message;
import models.config.Config;
import models.domain.main.notificaciones.frecuenciasNotificacion.Notificacion;

public class TwilioWpp implements WhatsappAdapter {

  public static final String ACCOUNT_SID = Config.obtenerInstancia().obtenerDelConfig("account_sid");
  public static final String AUTH_TOKEN = Config.obtenerInstancia().obtenerDelConfig("auth_token");

  public void mandar (Notificacion notificacion) {
    Twilio.init(ACCOUNT_SID, AUTH_TOKEN);
    Message message = Message.creator(
        new com.twilio.type.PhoneNumber("whatsapp:+5491134099892"),
        new com.twilio.type.PhoneNumber("whatsapp:+14155238886"),
        notificacion.getMensaje()).create();

    System.out.println(message.getSid());
    notificacion.cambiarEstadoAEnviado();
  }
}
