#include <iostream>
#include <string.h>
using namespace std;


struct Usuario
{
    int ID;
    int FechaCreacion;
    bool activo =true;
    float TotalImporteCompras;
    char eMail[26];

};

struct ListaUsuarios
{
    Usuario usuarioact;

    ListaUsuarios *sigUs;
};

struct Compra
{
    int CompraID;
    char FechaHora[14];
    float Monto;
    int UsuarioID;
    int NroArticulo;

};

struct ListaCompras
{
    Compra compra;
    ListaCompras *sigCompra;
};

void insertarOrdenado(ListaUsuarios *&lista,  ListaUsuarios p2aux)
{
    ListaUsuarios *paux = lista;
    ListaUsuarios *anterior =NULL;
    while (paux && paux->usuarioact.TotalImporteCompras <p2aux.usuarioact.TotalImporteCompras)
    {
        anterior = paux;
        paux = paux->sigUs;
    }
    if ( paux!= lista)
    {
        anterior->sigUs = new ListaUsuarios();
        anterior->sigUs->usuarioact.ID=p2aux.usuarioact.ID;
        anterior->sigUs->usuarioact.TotalImporteCompras = p2aux.usuarioact.TotalImporteCompras;
        strcpy(anterior->sigUs->usuarioact.eMail,p2aux.usuarioact.eMail);
        anterior->sigUs->usuarioact.FechaCreacion=p2aux.usuarioact.FechaCreacion;
        anterior->sigUs->sigUs= paux;

    }
    else
    {
        cout<<"primer elemento"<<endl;
        lista= new ListaUsuarios();
        lista->sigUs =paux;
        lista->usuarioact.ID = p2aux.usuarioact.ID;
        lista->usuarioact.FechaCreacion = p2aux.usuarioact.FechaCreacion;
        lista->usuarioact.TotalImporteCompras = p2aux.usuarioact.TotalImporteCompras;
         strcpy(lista->usuarioact.eMail,p2aux.usuarioact.eMail);

    }
    return;
}

void CargarArchivoUsuarios(ListaUsuarios *&inicio)
{
    FILE *archLU;
    archLU=fopen("clientes.bin","rb+");
    if(archLU!=NULL)
    {
        ListaUsuarios *paux=NULL;
        ListaUsuarios *panterior=NULL;
        inicio=NULL;
        fseek(archLU,0,SEEK_END);

        int TamArchivoLista=ftell(archLU);
        int numElementos=TamArchivoLista/sizeof(ListaUsuarios);

        cout<<"la cant de elementos es "<<numElementos<<endl;
        fseek(archLU,0,SEEK_SET);
        if(numElementos>0)
        {

            cout<<"Leyendo datos..."<<endl;
            int loop=0;
            paux=inicio;
            ListaUsuarios *panterior=NULL;
            ListaUsuarios p2aux;
            for(loop;loop<numElementos; loop++)
            {

                fread(&p2aux,sizeof(ListaUsuarios),1,archLU);
                 cout<<"p2aux.usuarioact.ID "<<p2aux.usuarioact.ID<<endl;

                  insertarOrdenado(inicio,p2aux);

        }
        fclose(archLU);
        return ;
    }
    else
    {
        cout<<"Lista vacia ,agregue elementos"<<endl;
        return;
    }
}
else
{
    cout<<"fallo apertura del archivo lista usuarios"<<endl;
}

}

void EscribirListaArchivoClientes(ListaUsuarios* inicioListaUsuarios)
{
    FILE *archLU;
    archLU=fopen("clientes.bin","wb+");

    ListaUsuarios* usuario=inicioListaUsuarios;

    if(archLU!=NULL)
    {

        while(usuario!=NULL)
        {
            ListaUsuarios *psiguiente;
            psiguiente=usuario->sigUs;
            usuario->sigUs=NULL;
            fwrite(usuario,sizeof(ListaUsuarios),1,archLU);
            usuario->sigUs=psiguiente;
            usuario=usuario->sigUs;
        }
        cout<<"archivo escrito exitosamente"<<endl;


    }
    fclose(archLU);
}

void EscribirListaArchivoClientesActivos(ListaUsuarios* inicioListaUsuarios)
{
    FILE *archLU;
    archLU=fopen("clientes.bin","wb+");

    ListaUsuarios* usuario=inicioListaUsuarios;

    if(archLU!=NULL)
    {

        while(usuario!=NULL)
        {
   if(usuario->usuarioact.activo){
            ListaUsuarios *psiguiente;
            psiguiente=usuario->sigUs;
            usuario->sigUs=NULL;
            fwrite(usuario,sizeof(ListaUsuarios),1,archLU);
            usuario->sigUs=psiguiente;
            usuario=usuario->sigUs;
   }
   else{
    usuario=usuario->sigUs;
   }
        }

        cout<<"archivo escrito exitosamente"<<endl;


    }
    fclose(archLU);
}




void EscribirListaArchivoCompras(ListaCompras* inicioListaCompras)
{
    FILE *archLC;
    archLC=fopen("comprasprueba.bin","wb+");

    ListaCompras* compra=inicioListaCompras;

    if(archLC!=NULL)
    {

        while(compra!=NULL)
        {
            ListaCompras *psiguiente;
            psiguiente=compra->sigCompra;
            compra->sigCompra=NULL;
            fwrite(compra,sizeof(ListaCompras),1,archLC);
            compra->sigCompra=psiguiente;
            compra=compra->sigCompra;
        }
        cout<<"archivo escrito exitosamente"<<endl;


    }
    fclose(archLC);
}

void EscribirLotedeCompras(ListaCompras* inicioListaCompras)
{
    FILE *archLC;
    archLC=fopen("procesados.bin","wb+");

    ListaCompras* compra=inicioListaCompras;

    if(archLC!=NULL)
    {

        while(compra!=NULL)
        {
            ListaCompras *psiguiente;
            psiguiente=compra->sigCompra;
            compra->sigCompra=NULL;
            fwrite(compra,sizeof(ListaCompras),1,archLC);
            compra->sigCompra=psiguiente;
            compra=compra->sigCompra;
        }
        cout<<"archivo escrito exitosamente"<<endl;


    }
    fclose(archLC);
}

void CargarArchivoComprasPrueba(ListaCompras  *&inicioListaCompras)
{
 FILE *archLC;
    archLC=fopen("comprasprueba.bin","rb");
    if(archLC!=NULL)
    {
        ListaCompras*paux=NULL;
        ListaCompras *panterior=NULL;
        ListaCompras *&inicio=inicioListaCompras;
        fseek(archLC,0,SEEK_END);


        int TamArchivoLista=ftell(archLC);
        int numElementos=TamArchivoLista/sizeof(ListaCompras);

        cout<<"la cant de elementos es "<<numElementos<<endl;
        fseek(archLC,0,SEEK_SET);

          if(numElementos>0)
        {

            cout<<"Leyendo datos..."<<endl;
            int loop=0;
            paux=inicio;
            ListaCompras *panterior=NULL;
            ListaCompras *p2aux;
            for(loop;loop<numElementos; loop++)
            {
                fseek(archLC,sizeof(ListaCompras)*loop,SEEK_SET);
                if(loop==0)
                              {

                                  inicio=new ListaCompras();
                                  inicio->sigCompra=NULL;
                                  fread(inicio,sizeof(ListaCompras),1,archLC);
                                  panterior=inicio;

                              }
                              else{

                                       panterior->sigCompra= new ListaCompras();
                                       paux=panterior->sigCompra;
                                       fread(panterior->sigCompra,sizeof(ListaCompras),1,archLC);
                                       panterior->sigCompra->sigCompra=NULL;
                                       panterior=paux;
                                 }

             }
             fclose(archLC);
           return;
        }
             else
                 {
                   cout<<"Lista vacia ,agregue elementos"<<endl;
                   return;
                  }

    }
    else
      {
    cout<<"fallo apertura del archivo lista usuarios"<<endl;
       }

}

void CargarArchivoProcesados(ListaCompras  *&inicioListaCompras)
{
 FILE *archLC;
    archLC=fopen("procesados.bin","rb");
    if(archLC!=NULL)
    {
        ListaCompras*paux=NULL;
        ListaCompras *panterior=NULL;
        ListaCompras *&inicio=inicioListaCompras;
        fseek(archLC,0,SEEK_END);


        int TamArchivoLista=ftell(archLC);
        int numElementos=TamArchivoLista/sizeof(ListaCompras);

        cout<<"la cant de elementos es "<<numElementos<<endl;
        fseek(archLC,0,SEEK_SET);

          if(numElementos>0)
        {

            cout<<"Leyendo datos..."<<endl;
            int loop=0;
            paux=inicio;
            ListaCompras *panterior=NULL;
            ListaCompras *p2aux;
            for(loop;loop<numElementos; loop++)
            {
                fseek(archLC,sizeof(ListaCompras)*loop,SEEK_SET);

                  if(loop==0)
                              {
                                  cout<<" PRIMER ELEMENTO "<<endl;
                                  inicio=new ListaCompras();

                                inicio->sigCompra=NULL;
                                  fread(inicio,sizeof(ListaCompras),1,archLC);
                                  panterior=inicio;

                              }
                              else{
                                    cout<<"loop "<<loop<<endl;
                                       panterior->sigCompra= new ListaCompras();
                                       paux=panterior->sigCompra;
                                       fread(panterior->sigCompra,sizeof(ListaCompras),1,archLC);
                                       panterior->sigCompra->sigCompra=NULL;
                                       panterior=paux;
                                 }

             }
             fclose(archLC);
           return;
        }
             else
                 {
                   cout<<"Lista vacia ,agregue elementos"<<endl;
                   return;
                  }

    }
    else
      {
    cout<<"fallo apertura del archivo lista usuarios"<<endl;
       }

}

void ListarComprasPrueba (ListaCompras *indx)
{


    if(indx!=NULL)
    {
        while(indx!=NULL)
        {
            cout<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"dir actual: "<<indx<<endl;
            cout<<"id de Compra"<<indx->compra.CompraID<<endl;
            cout<<"fecha Hora de usuario "<<indx->compra.FechaHora<<endl;
            cout<<"Monto :"<<indx->compra.Monto<<endl;
            cout<<"Nro articulo"<<indx->compra.NroArticulo<<endl;
            cout<<"Usuario ID: "<<indx->compra.UsuarioID<<endl;
            cout<<"sig usuario en dir"<<indx->sigCompra<<endl;
            if(indx->sigCompra==NULL)
            cout<<"elemento siguiente nulo"<<endl;
            indx=indx->sigCompra;
            cout<<"ahora indx vale: "<<indx<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<" "<<endl;
        }
    }
    else
    {
        cout<<"Lista vacia "<<endl;
    }
}

void ListarUsuarios (ListaUsuarios *indx)
{

    cout<<"listando usuarios"<<endl;
    if(indx!=NULL)
    {
        cout<<endl<<endl;
        cout<<"----------------------------------------------------"<<endl;

        while(indx!=NULL)
        {
            if (indx->usuarioact.activo){
            cout<<"dir actual: "<<indx<<endl;

            cout<<"id de usuario "<<indx->usuarioact.ID<<endl;

            cout<<"email de usuario "<<indx->usuarioact.eMail<<endl;

            cout<<"estado de actividad :"<<indx->usuarioact.activo<<endl;

            cout<<"importe actual: "<<indx->usuarioact.TotalImporteCompras<<endl;

            cout<<"fecha de creacion: "<<indx->usuarioact.FechaCreacion<<endl;

            cout<<"sig usuario en dir"<<indx->sigUs<<endl;

            if(indx->sigUs==NULL)
            cout<<"elemento siguiente nulo"<<endl;
            indx=indx->sigUs;
            cout<<"ahora indx vale: "<<indx<<endl;
            cout<<" "<<endl;
            cout<<"----------------------------------------------------"<<endl;
            cout<<endl<<endl;
        }
        else
            indx=indx->sigUs;
        }
    }
    else
    {
        cout<<"Lista vacia "<<endl;
    }
}

void AgregarnuevoUSuario(ListaUsuarios *&inicio)
{

    ListaUsuarios *nuevoUsuario;
    nuevoUsuario= new ListaUsuarios;

    if(inicio)
    {
        cout<<"anadir nuevo elemento"<<endl;
        nuevoUsuario->sigUs=inicio;
        cout<<"Ingrese  ID usuario"<<endl;
        cin>>nuevoUsuario->usuarioact.ID;
        cout<<"email: "<<endl;
        cin>>nuevoUsuario->usuarioact.eMail;
        cout<<"Ingrese Fecha Creacion :"<<endl;
        cin>>nuevoUsuario->usuarioact.FechaCreacion;
        nuevoUsuario->usuarioact.activo=true;
        inicio=nuevoUsuario;
    }
    else
    {
        //lista vacia
        cout<<"lista vacia"<<endl;
         cout<<"Ingrese  ID usuario"<<endl;
        cin>>nuevoUsuario->usuarioact.ID;
        cout<<"email: "<<endl;
        cin>>nuevoUsuario->usuarioact.eMail;
        cout<<"Ingrese Fecha Creacion :"<<endl;
        cin>>nuevoUsuario->usuarioact.FechaCreacion;
        nuevoUsuario->usuarioact.activo=true;

        nuevoUsuario->usuarioact.activo=true;
        inicio=nuevoUsuario;
        nuevoUsuario->sigUs=NULL;
    }

}

void DesactivarUsuarioExistente( ListaUsuarios *&inicio)
{
    int idbuscada;
    cout<<"ingrese id del usuario"<<endl;
    ListaUsuarios *paux=inicio;
    cin>>idbuscada;
    if(idbuscada<0)
    {
        cout<<"ID no valida. Vuelva a ingresar : "<<endl;
        cin>>idbuscada;
    }
    else
    {
        while(paux&&paux->usuarioact.ID!=idbuscada)
        {
            paux=paux->sigUs;
        }
        if(paux==NULL)
        {
            cout<<"no se encontro el ID"<<endl;
        }
        paux->usuarioact.activo=false;
        cout<<"usuario "<<paux->usuarioact.ID<<"  fue desactivado"<<endl;
    }

}

void OrdenarListaPorImporte(ListaUsuarios *&inicio)
{

    ListaUsuarios *anterior=NULL;
    ListaUsuarios *paux=NULL;
    paux=inicio;
    ListaUsuarios* psiguiente=NULL;
    ListaUsuarios *p2aux;
    while(paux)
    {
        if(paux->sigUs!=NULL)
        {
            if((paux->usuarioact.TotalImporteCompras  < paux->sigUs->usuarioact.TotalImporteCompras))
            {

                if(!anterior)
                {
                    p2aux=psiguiente;
                    paux->sigUs=psiguiente->sigUs;

                    psiguiente=paux->sigUs;


                    psiguiente=p2aux;
                    anterior=paux;
                    paux=paux->sigUs;
                }
                else
                {
                    anterior->sigUs=psiguiente;
                    p2aux=psiguiente;
                    paux->sigUs=psiguiente->sigUs;

                    psiguiente=paux->sigUs;


                    psiguiente=p2aux;
                     anterior=paux;
                     paux=paux->sigUs;

                }
            }



        }
        else{
            paux=NULL;
        }
    }

}


void BorrarListaProcesado(ListaCompras *&indx)
{
        ListaCompras *paux;
        ListaCompras *pactual;
        paux=indx;

        while(paux!=NULL)
        {

            pactual=paux;
            paux=paux->sigCompra;
            cout<<"sig compra "<<paux<<endl;
            delete pactual;
        }
        cout<<"lista Compras procesadas borrada satisfactoriamente "<<endl;
    }


void BorrarListaUs(ListaUsuarios *&inicio)
{
        ListaUsuarios* paux;



        while(inicio)
        {
            paux=inicio;
            if(paux->sigUs != NULL){
            cout<<"borrando usuario "<<paux->usuarioact.ID<<endl;
               inicio=inicio->sigUs;
            cout<<"paux->sig es : "<<paux->sigUs<<endl;
            delete paux;
            }
            else
            {
                delete inicio;
                inicio=NULL;
            }
        }
        cout<<"lista borrada satisfactoriamente "<<endl;
    }

void BorrarListaCompras(ListaCompras *&indx)
{
        ListaCompras* paux;
        ListaCompras *pactual;
        paux=indx;

        while(paux!=NULL)
        {

            pactual=paux;
            paux=paux->sigCompra;
            cout<<"sig compra "<<paux<<endl;
            delete pactual;
        }
        cout<<"lista Compras borrada satisfactoriamente "<<endl;
    }

void BuscarClientePorID(ListaUsuarios* inicio)
{
     int idbuscada;
        cout<<"ingrese id del usuario"<<endl;
        ListaUsuarios *paux;
        paux=inicio;
        cin>>idbuscada;
        if(idbuscada<0)
        {
            cout<<"id no valida"<<endl;
            cin>>idbuscada;
        }
        else
        {
            while(paux&&paux->usuarioact.ID!=idbuscada)
            {
                paux=paux->sigUs;
            }
            if(paux==NULL)
            {
                cout<<"no se encontro el ID"<<endl;
            }
            else
            {
                if (paux->usuarioact.activo){
             cout<<endl;
             cout<<"Usuario ID: "<<paux->usuarioact.ID<<endl;
             cout<<"email: "<<paux->usuarioact.eMail<<endl;
             cout<<"Fecha creacion: "<<paux->usuarioact.FechaCreacion<<endl;
             cout<<"Importe "<<paux->usuarioact.TotalImporteCompras<<endl;
                }
                else{
            cout<<endl;
            cout<<"--El usuario ya no se encuentra activo. Sus datos son los siguientes:--"<<endl;
            cout<<endl;
             cout<<"Usuario ID: "<<paux->usuarioact.ID<<endl;
             cout<<"email: "<<paux->usuarioact.eMail<<endl;
             cout<<"Fecha creacion: "<<paux->usuarioact.FechaCreacion<<endl;
             cout<<"Importe "<<paux->usuarioact.TotalImporteCompras<<endl;
                }
            }
        }
    }

void BuscarClientePorMail(ListaUsuarios* inicio)
{
        char mailingresado[20];

        cout<<"ingrese Mail del usuario"<<endl;

        ListaUsuarios *paux;
        paux=inicio;
        cin>>mailingresado;

        while(paux && strcmp(paux->usuarioact.eMail,mailingresado) )
            {
                paux=paux->sigUs;
            }
            if(paux==NULL)
            {
                cout<<"no se encontro el usuario"<<endl;
            }
            else
            {
                if (paux->usuarioact.activo){
             cout<<endl;
             cout<<"Usuario ID: "<<paux->usuarioact.ID<<endl;
             cout<<"email: "<<paux->usuarioact.eMail<<endl;
             cout<<"Fecha creacion: "<<paux->usuarioact.FechaCreacion<<endl;
             cout<<"Importe "<<paux->usuarioact.TotalImporteCompras<<endl;
                }
                else{
            cout<<endl;
            cout<<"--El usuario ya no se encuentra activo. Sus datos son los siguientes:--"<<endl;
            cout<<endl;
            cout<<"Usuario ID: "<<paux->usuarioact.ID<<endl;
             cout<<"email: "<<paux->usuarioact.eMail<<endl;
             cout<<"Fecha creacion: "<<paux->usuarioact.FechaCreacion<<endl;
             cout<<"Importe "<<paux->usuarioact.TotalImporteCompras<<endl;
                }
            }
        }

void BuscarClientePorIDoMail(ListaUsuarios *inicio)
{
    int opcion;
    cout<<"Para buscar por ID ingrese 1"<<endl;
    cout<<"para buscar por email, ingrese 2"<<endl;
    cin>>opcion;
    switch(opcion)
    {
    case 1: BuscarClientePorID(inicio);
    break;
    case 2:BuscarClientePorMail(inicio);
  break;
    }
}

void ListarClientesImportes (ListaUsuarios *indx)
{

    cout<<"listando clientes segun importes, si esta activo"<<endl;
    ListaUsuarios *paux=indx;//ver si es inicio o indx
    if(indx!=NULL)
    {
        while(indx!=NULL)
        {
            if (paux->usuarioact.activo=true){
            cout<<"dir actual: "<<indx<<endl;
            cout<<" "<<endl;
            cout<<"id de usuario "<<indx->usuarioact.ID<<endl;
            cout<<" "<<endl;
            cout<<"email de usuario "<<indx->usuarioact.eMail<<endl;
            cout<<" "<<endl;
            cout<<"estado de actividad :"<<indx->usuarioact.activo<<endl;
            cout<<" "<<endl;
            cout<<"importe actual: "<<indx->usuarioact.TotalImporteCompras<<endl;
            cout<<" "<<endl;
            cout<<"fecha de creacion: "<<indx->usuarioact.FechaCreacion<<endl;
            cout<<" "<<endl;
            cout<<"sig usuario en dir"<<indx->sigUs<<endl;
            cout<<" "<<endl;
            if(indx->sigUs==NULL)
            cout<<"elemento siguiente nulo"<<endl;
            indx=indx->sigUs;
            cout<<"ahora indx vale: "<<indx<<endl;
            cout<<" "<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<endl;
            }

        }
    }
    else
    {
        cout<<"Lista vacia "<<endl;
    }
    }

void ProcesarLoteCompras(ListaCompras *inicioLC,ListaUsuarios *&inicioListaUsuarios)
{
   ListaUsuarios *pauxLU=inicioListaUsuarios;
EscribirLotedeCompras(inicioLC);
    while(inicioLC!=NULL)
    {


        while(pauxLU&&inicioLC->compra.UsuarioID!=pauxLU->usuarioact.ID)
        {
            pauxLU=pauxLU->sigUs;
        }
        if(pauxLU){
        pauxLU->usuarioact.TotalImporteCompras+=inicioLC->compra.Monto;
        }
        cout<<"procesando sig compra"<<endl;
        inicioLC=inicioLC->sigCompra;
    }
}

void escribirReporteHTML(ListaCompras *paux)
{
    char fecha1[14];
    char fecha2[14];
    cout<<"Ingresa las fechas en numeros, con el siguiente formato: anomesdiahora:minutos . Por ejemplo:2021090213:30"<<endl;
    cout<<"Primero ingrese la fecha mas temprana"<<endl;
    cin>>fecha1;
    cout<<"Ahora ingrese la fecha mas tardia"<<endl;
    cin>>fecha2;
    FILE *f;
    f = fopen("salidahtml.html", "wt");
    fprintf(f,"<html><body>\n");
    fprintf(f,"<h1>Reporte de compras de usuraios</h1>\n");
    fprintf(f,"<table border=1>\n");
    fprintf(f,"<th>Compra ID</th><th>Fecha y Hora</th><th>Monto</th><th>Usuario ID</th><th>Nro de Articulo</th>\n");
    while (paux !=NULL)
    {
        if ( strcmp(paux->compra.FechaHora,fecha1 )&&  strcmp(fecha2,paux->compra.FechaHora)){
        fprintf(f,"<tr>\n");
        fprintf(f,"<td>%d</td><td>%s</td><td>%f</td><td>%d</td><td>%d</td>\n",paux->compra.CompraID, paux->compra.FechaHora,paux->compra.Monto,paux->compra.UsuarioID,paux->compra.NroArticulo);
        fprintf(f,"</tr>\n");
        }
        paux=paux->sigCompra;
    }
    fprintf(f, "</table>");
    fprintf(f, "</body>");
    fprintf(f, "</html>");
    fclose(f);
    return;
}

void escribirReporteCSV(ListaCompras *paux)
{
    char fecha1[14];
    char fecha2[14];
    cout<<"Ingresa las fechas en numeros, con el siguiente formato: anomesdiahora:minutos . Por ejemplo:2021090213:30"<<endl;
    cout<<"Primero ingrese la fecha mas temprana"<<endl;
    cin>>fecha1;
    cout<<"Ahora ingrese la fecha mas tardia"<<endl;
    cin>>fecha2;
    FILE *f;
    f = fopen("salidaexcel.csv", "wt");
    fprintf(f,"Compra ID;Fecha y Hora;Monto;Usuario ID;Nro de Articulo\n");

    while (paux !=NULL) //ver si es srtlen
    {
        if ( strcmp(paux->compra.FechaHora,fecha1)&&  strcmp(fecha2,paux->compra.FechaHora))
    {
        fprintf(f,"%d;%s;%f;%d;%d\n",paux->compra.CompraID,paux->compra.FechaHora,paux->compra.Monto,paux->compra.UsuarioID,paux->compra.NroArticulo);
    }
    paux=paux->sigCompra;
    }
    fclose(f);
    return;
}

void MostrarComprasCliente(ListaCompras*inicioLP)
{
 int id;
 cout<<"Ingrese ID del usuario"<<endl;
 cin>>id;
 ListaCompras *indx=inicioLP;
    if(indx!=NULL)
    {
        while(indx!=NULL)
        {
            if(indx->compra.CompraID==id){
            cout<<endl;
            cout<<"dir actual: "<<indx<<endl;
            cout<<"id de Compra"<<indx->compra.CompraID<<endl;
            cout<<"fecha Hora de usuario "<<indx->compra.FechaHora<<endl;
            cout<<"Monto :"<<indx->compra.Monto<<endl;
            cout<<"Nro articulo"<<indx->compra.NroArticulo<<endl;
            cout<<"Usuario ID: "<<indx->compra.UsuarioID<<endl;
            cout<<"sig usuario en dir"<<indx->sigCompra<<endl;
            cout<<" "<<endl;
            }
        indx=indx->sigCompra;
        }
}
}

void FinalizarJornada(ListaUsuarios *&inicioLU,ListaCompras *&inicioLC,ListaCompras *& inicioLP)
{

cout<<"Borrando Listas"<<endl;
EscribirListaArchivoClientesActivos(inicioLU);
 BorrarListaUs(inicioLU);
 BorrarListaCompras(inicioLC);
 BorrarListaProcesado(inicioLP);
//agregar borrar lista procesados
}

int OpcionesMenu()
{
        int opcion;
        cout<<"INGRESE OPCION"<<endl ;
        cout<<"1--- Cargar usuarios "<<endl;
        cout<<"2--- Listar Usuario "<<endl;
        cout<<"3--- Escribir Lista Usuarios Archivo (funcion de prueba)"<<endl;
        cout<<"4--- Agregar nuevo usuario "<<endl;
        cout<<"5--- Desactivar usuario Existente"<<endl;
        cout<<"6--- Buscar cliente por ID o por mail "<<endl;
        cout<<"7--- Listar clientes ordenados por importe "<<endl;
        cout<<"8--- Procesar lote de compras "<<endl;
        cout<<"9--- Mostrar compras realizadas de un cliente dado "<<endl;
        cout<<"10-- Generar reporte HTML de compras realizadas en dos fechas "<<endl;
        cout<<"11-- Generar reporte CSV de compras realizadas en dos fechas " <<endl;
        cout<<"12-- Borrar lista "<<endl;
        cout<<"13-- Finalizar jornada "<<endl;

        cin>>opcion;
        return opcion;
    }

void Menu(ListaUsuarios *&inicioListaUsuarios, ListaCompras *&inicioLC,ListaCompras * inicioLP)
{
        int opcion=OpcionesMenu();
        while(opcion)
        {
            if (0<opcion && opcion<14){
            switch(opcion)
            {
            case 1: //(para verificar que se hayan cargado exitosamente los clientes en proxima ejecucion)
                CargarArchivoUsuarios(inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 2: // verificar que esten listados  correctamente
                ListarUsuarios(inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 3 ://prueba escritura  archivo USuarios
                    EscribirListaArchivoClientes(inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 4://Agregar Nuevo Usuario.
                     AgregarnuevoUSuario(inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 5:// Desactivar usuario existente;
                DesactivarUsuarioExistente(inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 6:// Buscar cliente por ID o por Mail.
                BuscarClientePorIDoMail(inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 7://ListarClientesOrdenadosPorImporte
                ListarClientesImportes (inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 8://procesar lote compras.
                ProcesarLoteCompras(inicioLC,inicioListaUsuarios);
                opcion=OpcionesMenu();
                break;
            case 9: //Mostrar por pantalla las todas las compras de un cliente dado desde el Archivo procesadfo.bin
                MostrarComprasCliente(inicioLP);
                opcion=OpcionesMenu();
                break;
            case 10: // Mostrar compras realizadas entre dos fechas en un reporte html,.Mostrando también el total de compras.
                escribirReporteHTML(inicioLP);
                  opcion=OpcionesMenu();
                break;
            case 11:// Mismo reporte de compras entre dos fechas con total en formato csv,
                escribirReporteCSV(inicioLP);
                opcion=OpcionesMenu();
                break;
            case 12:
                // borrar lista  usuariosfuncion prueba;
              BorrarListaUs(inicioListaUsuarios);
              opcion=OpcionesMenu();
              break;
            case 13: //ger tiene que modificar
                FinalizarJornada(inicioListaUsuarios,inicioLC,inicioLP);
                opcion=0;
                break;

            }

            }
            else {
            cout<< "--Opcion no valida--"<<endl;
            cout<<endl;
            opcion=OpcionesMenu();
            }

        }
    }

int main()
{
        ListaUsuarios *inicioListaUsuarios=NULL;
        ListaUsuarios *inicioListaActivosUsuarios=NULL;
        CargarArchivoUsuarios(inicioListaUsuarios);
        ListaCompras*pauxLC;
        ListaCompras *inicioListaProcesados=NULL;
        ListaCompras *inicioListaCompras=NULL;
/*
//Compra numero 1

        inicioListaCompras= new ListaCompras();
        inicioListaCompras->compra.CompraID=1;
      strcpy(inicioListaCompras->compra.FechaHora,"2021012515:23")  ;
        inicioListaCompras->compra.Monto=240000;
        inicioListaCompras->compra.NroArticulo=43;
        inicioListaCompras->compra.UsuarioID=1;
        inicioListaCompras->sigCompra=new ListaCompras();
        pauxLC=inicioListaCompras->sigCompra;





//compra numero 2
        pauxLC->compra.CompraID=2;
strcpy(pauxLC->compra.FechaHora,"2021022812:20");
            pauxLC->compra.Monto=233000;
        pauxLC->compra.NroArticulo=78;
        pauxLC->compra.UsuarioID=2;
        pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;

// compra numero 3

        pauxLC->compra.CompraID=3;
     strcpy(  pauxLC->compra.FechaHora,"2021052312:32"),
        pauxLC->compra.Monto=34000;
        pauxLC->compra.NroArticulo=10;
        pauxLC->compra.UsuarioID=3;
        pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;
// compra numero 4
        pauxLC->compra.CompraID=4;
         strcpy(pauxLC->compra.FechaHora,"2021081718:30");
        pauxLC->compra.Monto=3000;
        pauxLC->compra.NroArticulo=77;
        pauxLC->compra.UsuarioID=4;
        pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;

//compra numero 5
        pauxLC->compra.CompraID=5;
      strcpy(pauxLC->compra.FechaHora,"2021090213:30");
       pauxLC->compra.Monto=4500;
        pauxLC->compra.NroArticulo=23;
        pauxLC->compra.UsuarioID=5;
        pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;
//Compra Numero 6
     pauxLC->compra.CompraID=6;
      strcpy(pauxLC->compra.FechaHora,"2021100315:30");
       pauxLC->compra.Monto=5700;
        pauxLC->compra.NroArticulo=25;
        pauxLC->compra.UsuarioID=1;
        pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;

//Compra numero 7
     pauxLC->compra.CompraID=7;
      strcpy(pauxLC->compra.FechaHora,"2021100711:30");
       pauxLC->compra.Monto=7700;
        pauxLC->compra.NroArticulo=42;
        pauxLC->compra.UsuarioID=3;
 pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;

 // Compra numero 8
        pauxLC->compra.CompraID=8;
        strcpy(pauxLC->compra.FechaHora,"2021101018:30");
        pauxLC->compra.Monto=5900;
        pauxLC->compra.NroArticulo=34;
        pauxLC->compra.UsuarioID=2;
        pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;
        //Compra numero 9
        pauxLC->compra.CompraID=9;
        strcpy(pauxLC->compra.FechaHora,"2021112020:55");
        pauxLC->compra.Monto=6400;
        pauxLC->compra.NroArticulo=50;
        pauxLC->compra.UsuarioID=5;
        pauxLC->sigCompra=new ListaCompras();
        pauxLC=pauxLC->sigCompra;
    //compra numero 10;
    pauxLC->compra.CompraID=10;
      strcpy(pauxLC->compra.FechaHora,"2021112212:00");
       pauxLC->compra.Monto=5700;
        pauxLC->compra.NroArticulo=25;
        pauxLC->compra.UsuarioID=4;
 pauxLC->sigCompra=NULL;

 EscribirListaArchivoCompras(inicioListaCompras);
*/
    CargarArchivoComprasPrueba(inicioListaCompras);
    CargarArchivoProcesados(inicioListaProcesados);
    ListarComprasPrueba(inicioListaCompras);
    Menu(inicioListaUsuarios,inicioListaCompras,inicioListaProcesados);

        return 0;
}
