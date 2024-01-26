package models.domain.usuarios;

import lombok.Getter;

import javax.persistence.*;

@Getter
@Entity
@Table(name="delegado")
public class Delegado {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name="nombre", columnDefinition = "TEXT")
    private String nombre;

    @Column(name="email", columnDefinition = "TEXT")
    private String email;

    public Delegado(String nombre, String email) {
        this.nombre = nombre;
        this.email = email;
    }

    public Delegado() {

    }
}
