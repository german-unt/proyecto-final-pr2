#include <iostream>
#include<cstring>
#include"funciones.h"
#include "clsActividad.h"
#include "clsSocio.h"
#include "clsCuota.h"
#include "clsActividadSocio.h"
#include "cargarCadena.h"
#include "clsFecha.h"
#include"clsManagerSocio.h"
#include"clsManagerActividad.h"
#include"clsManagerCouta.h"
#include"clsManagerInformes.h"
#include "clsArchivoSocio.h"
#include"clsArchivoCuota.h"
#include"clsArchivoActividadesSocio.h"
#include"clsArchivoActividades.h"
#include "clsManagerActividadSocio.h"

using namespace std;

void menuPrincipal()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"*BIENVENIDO A FC-CODE*"<<endl;
        cout<<"   MENU PRINCIPAL   "<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - SOCIOS"<<endl;
        cout<<"2 - ACTIVIDADES"<<endl;
        cout<<"3 - INSCRIPCION A ACTIVIDADES"<<endl;
        cout<<"4 - CUOTA"<<endl;
        cout<<"5 - LISTADOS "<<endl;
        cout<<"6 - INFORMES"<<endl;
        cout<<"7 - CONSULTAS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            menuSocios();
            break;
        case 2:
            menuActividades();
            break;
        case 3:
            menuActividadSocio();
            break;
        case 4:
            menuCuota();
            break;
        case 5:
            listados();
            break;
        case 6:
            informes();
            break;
        case 7:
            consultas();
            break;
        case 0:
            return;
        }
    }
}
void listados()
{
    int opc;

    while(true)
    {
        system("cls");

        cout<<"MENU LISTADOS"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - Socios por apellido"<<endl;
        cout<<"2 - Socios por tipo"<<endl;
        cout<<"4 - Cuotas por monto"<<endl;
        cout<<"7-  Participaciones por ID de actividad"<<endl;
        cout<<"0 - Volver"<<endl;
        cout<<"=========================="<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
        {
        case 1:
            listadoSociosApellido();
            break;

        case 2:
            listadoSociosTipo();
            break;

        case 3:
           // listadoCuotaSocio();
            break;

        case 4:
            listadoCuotaMonto();
            break;

        case 5:
           // listadoActividadXid();
            break;

        case 6:
            //listadoParticipacionesSocio();
            break;

        case 7:
            listadoParticipacionesActividad();
            break;

        case 0:
            return;
        }

        system("pause");
    }
}
void consultas()
{
    int opc;

    while(true)
    {
        system("cls");

        cout<<"MENU CONSULTAS"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - CONSULTA DE SOCIOS"<<endl;
        cout<<"2 - CONSULTA DE ACTIVIDADES"<<endl;
        cout<<"3 - CONSULTA DE ESTADO"<<endl;
        cout<<"0 - SALIR"<<endl;

        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            consultasSocios();
            break;

        case 2:
            menuConsultaActividades();
            break;

        case 3:
            consultasDeEstado();
            break;

        case 0:
            return;
        }
        system("pause");
    }
}
void consultasSocios()
{

    int opc;
    while(true)
    {
        system("cls");

        cout<<"CONSULTAS SOCIOS"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - CONSULTA POR RANGO DE FECHAS"<<endl;
        cout<<"2 - CONSULTA POR ID DE SOCIO"<<endl;
        cout<<"0 - SALIR"<<endl;

        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            rangoDeFechas();
            break;

        case 2:
            consultaXSocio();
            break;

        case 0:
            return;
        }
        system("pause");

    }
}
void menuConsultaActividades()

{

    int opc;
    while(true)
    {
        system("cls");

        cout<<"CONSULTAS DE ACTIVIDADES"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - CONSULTA POR ACTIVIDAD"<<endl;
        cout<<"2 - CONSULTA POR RESUMEN"<<endl;
        cout<<"0 - SALIR"<<endl;

        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            consultaXActividad();
            break;

        case 2:
            consultaResumen();
            break;

        case 0:
            return;
        }
        system("pause");
    }
}

///ordenar socios por apellido (ARREGLAR ES TEMA DE LA MAYUSCULAS QUE AFECTAN EL ORDEN).
void listadoSociosApellido()
{
    archivoSocio arc;

    int cant = arc.contarRegistros();

    socio *vec = new socio[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistros(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(strcmp(vec[i].getApellido(),
                      vec[j].getApellido())>0)
            {

                socio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {

        if(vec[i].getEstado())
        {

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}

///ordenar  por tipo de socios
void listadoSociosTipo()
{

    archivoSocio arc;

    int cant=arc.contarRegistros();

    socio *vec=new socio[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistros(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(vec[i].getTipoSocio()>
                    vec[j].getTipoSocio())
            {

                socio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {

        if(vec[i].getEstado())
        {

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}
///ordenar cuota por id de socio.
/*
void listadoCuotaSocio()
{

    archivoCuota arc;

    int cant=arc.contarRegistros();

    cuota *vec=new cuota[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(vec[i].getIdsocio()>
                    vec[j].getIdsocio())
            {

                cuota aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {

        if(vec[i].getEstado())
        {

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}

*/
///ordenar por monto PAGADO

void listadoCuotaMonto()
{

    archivoCuota arc;

    int cant=arc.contarRegistros();

    cuota *vec=new cuota[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(vec[i].getImportePagado()>
                    vec[j].getImportePagado())
            {

                cuota aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {

        if(vec[i].getEstado())
        {

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}
/*
void listadoParticipacionesSocio()
{

    archivoActividadesSocio arc;

    int cant=arc.contarRegistros();

    actividadSocio *vec=new actividadSocio[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(vec[i].getIdSocio()>
                    vec[j].getIdSocio())
            {

                actividadSocio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {

        if(vec[i].getEstado())
        {

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}

*/

void listadoParticipacionesActividad()
{

    archivoActividadesSocio arc;

    int cant=arc.contarRegistros();

    actividadSocio *vec=new actividadSocio[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(vec[i].getIdactividad()>
                    vec[j].getIdactividad())
            {

                actividadSocio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {

        if(vec[i].getEstado())
        {

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}
/*
void listadoActividadXid()
{

    archivoActividades arc;

    int cant = arc.contarRegistros();

    actividad *vec = new actividad[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistros(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(vec[i].getIdactividad() >
                    vec[j].getIdactividad())
            {

                actividad aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {

        if(vec[i].getEstado())
        {

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}
*/

///consulta rango de fechas (no anda)
void rangoDeFechas()
{
    archivoActividadesSocio arc;
    actividadSocio obj;

    Fecha primeraFecha;
    Fecha segundaFecha;

    cout << "INGRESE LA PRIMER FECHA: ";
    primeraFecha.Cargar();

    cout << "INGRESE LA SEGUNDA FECHA: ";
    segundaFecha.Cargar();

    int cantidad = 0;

    int cant = arc.contarRegistros();

    for(int i = 0; i < cant; i++)
    {

        obj = arc.leerRegistro(i);

        if(obj.getFechaAlta() >= primeraFecha &&
                obj.getFechaAlta() <= segundaFecha)
        {
            cantidad++;
        }
    }

    cout << "La cantidad de socios ingresados en ese rango de fechas es: "
         << cantidad << endl;
}
///consultaXSocio
void consultaXSocio()
{
    socio obj;
    archivoSocio arc;
    bool encontrado=false;
    int cant=arc.contarRegistros();
    int id;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>id;

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);


        if((obj.getIdsocio()==id) && (obj.getEstado()==true))
        {
            obj.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado)
    {
        cout << "NO EXISTE NINGUN SOCIO CON ESE ID." << endl;
    }
}
void consultaXActividad()
{
    actividad obj;
    archivoActividades arc;
    bool encontrado=false;
    int cant=arc.contarRegistros();
    int id;
    cout<<"INGRESE EL ID DE LA ACTIVIDAD: ";
    cin>>id;

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);

    if((obj.getIdactividad()==id) && (obj.getEstado()==true))
        {
            obj.mostrar();
            encontrado=true;
        }

    }

    if(!encontrado)
    {
        cout << "NO SE ENCONTRO NINGUNA ACTIVIDAD " << endl;
    }

}
///(no anda) agregar con importe de pago
void consultaResumen()
{
    cuota obj;
    archivoCuota arc;
    int mes;
    cout << "INGRESE EL MES A RESUMIR: ";
    cin >> mes;
    float total = 0;
    int cant = arc.contarRegistros();
    for(int i=0; i<cant; i++)
    {
        obj = arc.leerRegistro(i);
        if(obj.getFechaPago().getMes()== mes)
        {
            total += obj.getMontoEsperado();
        }
    }
    cout << "RECAUDACION TOTAL DEL MES: $" << total << endl;
}

void consultasDeEstado()
{
    socio obj;
    archivoSocio arc;
    bool encontrado=false;
    int cant= arc.contarRegistros();
    int id;
    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>id;

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);


        if((obj.getIdsocio()==id) && (obj.getEstado()==true))
        {
            cout<<"EL SOCIO ESTA ACTIVO"<<endl;
            encontrado=true;
            return;
        }
        else if((obj.getIdsocio()==id) && (obj.getEstado()==false))
        {
            cout<<"EL SOCIO ESTA INACTIVO"<<endl;

            return;
        }
    }
    if(!encontrado)
    {
        cout << "NO EXISTE NINGUN SOCIO." << endl;
    }
}
