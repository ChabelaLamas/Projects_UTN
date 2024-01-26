package models.domain.main;

import models.domain.main.entidades.Entidad;
import models.domain.main.servicio.Servicio;
import models.domain.usuarios.Delegado;
import lombok.Getter;

import javax.persistence.*;
import java.util.List;

@Entity
@Table(name="organismoDeControl")
public class OrganismoDeControl {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Getter
    @Column(name="denominacion")
    private String denominacion;

    @ManyToOne
    @JoinColumn(name = "delegado_id", referencedColumnName = "id")
    private Delegado delegado;

    @ManyToMany(mappedBy = "organismosDeControl")
    private List<Entidad> entidades;

    @OneToMany(mappedBy = "organismoDeControl", cascade = CascadeType.ALL, orphanRemoval = true)
    private List<Servicio> serviciosControlados;

    public OrganismoDeControl(String denominacion, Delegado delegado) {
        this.denominacion = denominacion;
        this.delegado = delegado;
    }

    public OrganismoDeControl() {

    }

    //public void notificarProblematicasDelegado() = new Notificador().notificarProblematicas(delegado);
}
