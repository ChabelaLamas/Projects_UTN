package models.repositorios;

import models.domain.usuarios.Persona;
import io.github.flbulgarelli.jpa.extras.simple.WithSimplePersistenceUnit;
import models.domain.usuarios.Usuario;

import javax.persistence.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.stream.Collectors;

public class PersonaRepository implements WithSimplePersistenceUnit {

    public void registrar(Persona persona) {
        EntityManager em = entityManager();
        EntityTransaction tx = null;

        try {
            tx = em.getTransaction();
            tx.begin();
            em.persist(persona);
            tx.commit();
        } catch (PersistenceException pe) {
            System.out.println("Error de persistencia: " + pe.getMessage());
            pe.printStackTrace();
            if (tx != null && tx.isActive()) tx.rollback();
        } catch (IllegalStateException ise) {
            System.out.println("Estado ilegal: " + ise.getMessage());
            ise.printStackTrace();
            if (tx != null && tx.isActive()) tx.rollback();
        } catch (Exception e) {
            System.out.println("Excepción general: " + e.getMessage());
            e.printStackTrace();
            if (tx != null && tx.isActive()) tx.rollback();
        } finally {
            em.close();
        }
    }


    public List<Persona> todos() {
        EntityManager em = entityManager();
        List<Persona> personas = em.createQuery("from Persona", Persona.class).getResultList();
        em.close();
        return personas;
    }

    public Persona buscarPorID(Long id) {
        EntityManager em = entityManager();
        Persona persona = em.find(Persona.class, id);
        em.close();
        return persona;
    }

    public Persona buscarPorUsuario(Usuario usuario) {
        EntityManager em = entityManager();
        try {
            Persona persona = em.createQuery(
                            "SELECT p FROM Persona p WHERE p.usuario = :usuario",
                            Persona.class)
                    .setParameter("usuario", usuario)
                    .getSingleResult();
            return persona;
        } catch (NoResultException e) {
            return null;  // No se encontró una Persona para el Usuario dado
        } finally {
            em.close();
        }
    }

    public Persona buscarPorIDUsuario(Long usuarioId) {
        EntityManager em = entityManager();
        try {
            Persona persona = em.createQuery(
                            "SELECT p FROM Persona p WHERE p.usuario.id = :usuarioId",
                            Persona.class)
                    .setParameter("usuarioId", usuarioId)
                    .getSingleResult();
            return persona;
        } catch (NoResultException e) {
            return null;  // No se encontró una Persona para el ID de Usuario dado
        } finally {
            em.close();
        }
    }

    public boolean existePersonaConCorreo(String correo) {
        EntityManager em = entityManager();
        try {
            Long count = em.createQuery(
                            "SELECT count(p) FROM Persona p WHERE p.email = :correo OR p.telefono = :correo",
                            Long.class)
                    .setParameter("correo", correo)
                    .getSingleResult();
            return count > 0;
        } catch (NoResultException e) {
            return false;  // No se encontró una Persona con el correo dado
        } finally {
            em.close();
        }
    }


    public List<LocalDateTime> buscarHorariosPorPersonaId(Long personaId) {
        EntityManager em = entityManager();
        try {
            List<LocalDateTime> horarios = em.createQuery(
                            "SELECT horario FROM Persona p JOIN p.horariosDeNotificaciones horario WHERE p.id = :personaId",
                            LocalDateTime.class)
                    .setParameter("personaId", personaId)
                    .getResultList();
            return horarios;
        } finally {
            em.close();
        }
    }

    public String convertirHorariosAStringHorasYMinutos(List<LocalDateTime> horarios) {

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm");

        String horariosConcatenados = horarios.stream()
                .map(horario -> horario.format(formatter))
                .collect(Collectors.joining(" "));

        return horariosConcatenados;
    }



}



