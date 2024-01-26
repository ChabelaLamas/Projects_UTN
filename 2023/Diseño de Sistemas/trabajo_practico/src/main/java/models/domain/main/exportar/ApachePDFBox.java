package models.domain.main.exportar;

import lombok.Setter;
import models.config.Config;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.PDPageContentStream;
import org.apache.pdfbox.pdmodel.common.PDRectangle;
import org.apache.pdfbox.pdmodel.font.PDType1Font;
import java.time.LocalDateTime;
import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.time.format.DateTimeFormatter;

public class ApachePDFBox implements PDFAdapter {

  private String nombreDeArchivo;

  public String generarInforme(Exportable exportable) {
    this.nombreDeArchivo = exportable.descripcion();
    PDDocument doc = new PDDocument();
    PDPage myPage = new PDPage();
    doc.addPage(myPage);
    try {
      PDPageContentStream cont = new PDPageContentStream(doc, myPage);
      cont.beginText();
      cont.setFont(PDType1Font.TIMES_ROMAN, 12);
      cont.setLeading(14.5f);
      cont.newLineAtOffset(25, 700);
      this.agregarDatos(cont, exportable.getDatos());

      cont.endText();
      cont.close();
      doc.save(this.rutaCompletaDelArchivo(exportable));
      doc.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
    return this.rutaCompletaDelArchivo(exportable);
  }

  private String rutaCompletaDelArchivo(Exportable exportable){

    return models.config.Config.RUTA_EXPORTACION + this.nombre_archivo(exportable);
  }

  public String nombre_archivo(Exportable exportable)
  {
    String fechaHoraActual = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMdd_HHmmss"));
    String nombre = fechaHoraActual + "_" + this.nombreDeArchivo + ".pdf";
    exportable.setNombre(nombre);
    return nombre;
  }
  private void agregarDatos(PDPageContentStream pagina, Map<String, List<String>> datos) throws IOException {
    for (Map.Entry<String, List<String>> entry : datos.entrySet()) {
      pagina.newLine();
      String posicion = entry.getValue().get(0);
      String nombre = entry.getValue().get(1);
      String puntaje = entry.getValue().get(2);

      String datosDeLaFila = posicion + "   " + nombre + "   " + puntaje;

      pagina.showText(datosDeLaFila);
    }
  }

  /*public PDDocument generarInforme(String denominacionEntidadPrestadora, List<String> rankingPromedioCierre, List<String> rankingCantidadIncidentes, List<String> rankingMayorImpacto) {
    int i = 1;
    try {
      // Create a new empty document
      PDDocument document = new PDDocument();

      // Create a blank page
      PDPage page = new PDPage(PDRectangle.A4);
      document.addPage(page);

      // Create a new content stream for the page
      PDPageContentStream contentStream = new PDPageContentStream(document, page);

      // Begin the content stream
      contentStream.beginText();

      // Set the font and font size
      contentStream.setFont(PDType1Font.HELVETICA_BOLD, 16);

      // Set the position on the page for the text
      contentStream.newLineAtOffset(20, 750);

      // Write the text to the content stream
      contentStream.showText(denominacionEntidadPrestadora);
      contentStream.newLineAtOffset(10, -50);


      contentStream.setFont(PDType1Font.HELVETICA_BOLD, 14);
      contentStream.showText("- Entidades con mayor promedio de tiempo de cierre de incidentes: ");

      contentStream.newLineAtOffset(10, -20);
      contentStream.setFont(PDType1Font.HELVETICA, 14);
      // Write the list items for the first subtitle
      for(String entidad : rankingPromedioCierre) {
        contentStream.newLineAtOffset(0, -15);
        contentStream.showText(i + ". " + entidad);
        i++;
      }
      contentStream.newLineAtOffset(-10, -30);

      contentStream.setFont(PDType1Font.HELVETICA_BOLD, 14);
      contentStream.showText("- Entidades con mayor cantidad de incidentes reportados: ");

      i = 1;
      contentStream.newLineAtOffset(10, -20);
      contentStream.setFont(PDType1Font.HELVETICA, 14);
      for(String entidad : rankingCantidadIncidentes) {
        contentStream.newLineAtOffset(0, -15);
        contentStream.showText(i + ". " + entidad);
        i++;
      }
      contentStream.newLineAtOffset(-10, -30);

      contentStream.setFont(PDType1Font.HELVETICA_BOLD, 14);
      contentStream.showText("- Incidentes con mayor grado de impacto: ");

      i = 1;
      contentStream.newLineAtOffset(10, -20);
      contentStream.setFont(PDType1Font.HELVETICA, 14);
      for(String entidad : rankingMayorImpacto) {
        contentStream.newLineAtOffset(0, -15);
        contentStream.showText(i + ". " + entidad);
        i++;
      }

      // End the content stream for the first page
      contentStream.endText();
      contentStream.close();

      // Save the document to a file
      document.save("example.pdf");

      // Close the document
      document.close();

      System.out.println("PDF created successfully.");

      return document;

    } catch (IOException e) {
      System.err.println("Error creating PDF: " + e.getMessage());
    }
    return null;
  }*/

}
