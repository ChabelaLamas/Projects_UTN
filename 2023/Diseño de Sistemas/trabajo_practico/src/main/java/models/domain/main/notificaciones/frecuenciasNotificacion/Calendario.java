package models.domain.main.notificaciones.frecuenciasNotificacion;

import org.quartz.*;
import org.quartz.impl.StdSchedulerFactory;

public class Calendario {
  public static void iniciarCalendar() throws SchedulerException {
    Scheduler scheduler = StdSchedulerFactory.getDefaultScheduler();
    scheduler.start();

    JobDetail job = JobBuilder.newJob(NotificacionSinApuros.class)
        .withIdentity("miNotificacion", "group")
        .build();

    Trigger trigger = TriggerBuilder.newTrigger()
        .withIdentity("myTrigger", "group")
        .withSchedule(CronScheduleBuilder.cronSchedule("*/15 * * * *"))
        .build();

    // Schedule the job with the trigger
    scheduler.scheduleJob(job, trigger);
  }

  public static void borrarJob() {
    try {
      Scheduler scheduler = StdSchedulerFactory.getDefaultScheduler();
      scheduler.start();
      scheduler.deleteJob(new JobKey("miNotificacion"));
    } catch (SchedulerException e) {
      e.printStackTrace();
    }
  }
}