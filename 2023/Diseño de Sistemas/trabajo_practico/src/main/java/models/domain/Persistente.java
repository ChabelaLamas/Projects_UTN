package models.domain;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.MappedSuperclass;


//@MappedSuperclass
@Getter @Setter
public class Persistente {
    @Id
    private Long id;
}
