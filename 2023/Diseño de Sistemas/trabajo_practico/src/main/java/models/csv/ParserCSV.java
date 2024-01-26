package models.csv;

import models.domain.usuarios.Delegado;
import models.domain.main.EntidadPrestadora;
import models.domain.main.OrganismoDeControl;

public class ParserCSV {

  public EntidadPrestadora instanciarEntidadPrestadora(LineaCSV linea) {
    return new EntidadPrestadora(linea.getDenominacion(), new Delegado(linea.getNombreDelegado(),linea.getEmailDelegado()));
  }

  public OrganismoDeControl instanciarOrganismoDeControl(LineaCSV linea) {
    return new OrganismoDeControl(linea.getDenominacion(), new Delegado(linea.getNombreDelegado(),linea.getEmailDelegado()));
  }
}
