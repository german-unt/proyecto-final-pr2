#include <iostream>
#include<cstring>
#include"funciones.h"
#include "clsActividad.h"
#include "clsSocio.h"
#include "clsSede.h"
#include "clsCuota.h"
#include "clsActividadSocio.h"
#include "cargarCadena.h"
#include "clsFecha.h"
//---------------------------
#include "clsArchivoSocio.h"
#include"clsArchivoSede.h"
#include"clsArchivoCuota.h"
#include"clsArchivoActividadesSocio.h"
#include"clsArchivoActividades.h"

using namespace std;

void menuPrincipal()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - SOCIOS"<<endl;
        cout<<"2 - ACTIVIDADES"<<endl;
        cout<<"3 - SEDES"<<endl;
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
            menuSedes();
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


void menuSocios()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU SOCIOS"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            altaSocio();
            break;
        case 2:
            bajaSocio();
            break;
        case 3:
            modificarSocio();
            break;
        case 4:
            listarSocio();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}

void menuActividades()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU ACTIVIDADES"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            altaActividad();
            break;
        case 2:
            bajaActividad();
            break;
        case 3:
            modificarActividad();
            break;
        case 4:
            listarActividad();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}

void menuSedes()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU SEDES"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            altaSede();
            break;
        case 2:
            bajaSede();
            break;
        case 3:
            modificarSede();
            break;
        case 4:
            listarSede();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}
void menuCuota()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU CUOTA"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            altaCuota();
            break;
        case 2:
            bajaCuota();
            break;
        case 3:
            modificarCuota();
            break;
        case 4:
            listarCuota();
            break;
        case 0:
            return;
        }
        system("pause");
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
        cout<<"3 - Cuotas por ID de socio"<<endl;
        cout<<"4 - Cuotas por monto"<<endl;
        cout<<"5 - Sedes por ID"<<endl;
        cout<<"6 - Actividades por ID"<<endl;
        cout<<"7 - Participaciones por ID de socio"<<endl;
        cout<<"8 - Participaciones por ID de actividad"<<endl;
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
            listadoCuotaSocio();
            break;

        case 4:
            listadoCuotaMonto();
            break;

        case 5:
            listadoSedeXid();
            break;

        case 6:
            listadoActividadXid();
            break;

        case 7:
            listadoParticipacionesSocio();
            break;

        case 8:
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
            break;
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
            break;
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
            ///recuadacion mensual total (de todo el club).
            break;

        case 0:
            break;
            return;
        }
        system("pause");
    }
}

///////////////////////////////////
int generarIdSocio(){
archivoSocio arc;
int cant = arc.contarRegistros();
if(cant<=0){
    return 1;
}
socio obj = arc.leerRegistros(cant-1);
    return obj.getIdsocio()+1;
}

void altaSocio()
{
    int id = generarIdSocio();

    cout<<"ID ASIGNADO: "<<id<<endl;
    archivoSocio arc;
    int pos = arc.buscarRegistros(id);
   if(pos >= 0){

    socio obj = arc.leerRegistros(pos);

    if(obj.getEstado()){

        cout<<"EL ID INGRESADO YA EXISTE"<<endl;
        return;
    }

    char opcion;

    cout<<"EL SOCIO ESTA DADO DE BAJA"<<endl;
    cout<<"DESEA REACTIVARLO? (S/N): ";
    cin>>opcion;

    if(opcion=='S' || opcion=='s'){

        obj.setEstado(true);

        arc.modificarRegistro(obj,pos);

        cout<<"SOCIO REACTIVADO CORRECTAMENTE"<<endl;
    }

    return;
}
    socio obj;
    obj.cargar(id);
    arc.grabarRegistros(obj);
}

void bajaSocio()
{
    int id ;
    archivoSocio arc;
    cout<<"ingrese el id del socio: ";
    cin>>id;
    int pos= arc.buscarRegistros(id);
    if(pos < 0)
    {
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    socio obj =arc.leerRegistros(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj,pos);
    cout<<"el socio ha sido dado de baja correctamente "<<endl;
}

void modificarSocio()
{
    int id ;
    cout<<"ingrese el id del socio: ";
    cin>>id;

    archivoSocio arc;
    int pos = arc.buscarRegistros(id);
    if(pos<0)
    {
        cout<<"el id no existe "<<endl;
        return;
    }
    socio obj=arc.leerRegistros(pos);

    if(obj.getEstado()==false)
    {
        cout<<"el socio esta dado de baja"<<endl;
        return;
    }
    obj.mostrar();
char opcion;
cout<<"DESEA MODIFICAR ESTE SOCIO? (S/N): ";
cin>>opcion;
    if(opcion!='S' && opcion!='s'){
    return;
}
    cout<<"ingrese los datos nuevos ";
    obj.cargar(id);
    arc.modificarRegistro(obj,pos);
    cout<<"socio modificado correctamente"<<endl;
}

void listarSocio()
{
    archivoSocio arc;
    int cant = arc.contarRegistros();
    if (cant<=0)
    {

        cout<<"no hay socios ingresados: "<<endl;
        return;
    }
    for(int i =0; i<cant; i++)
    {

        socio obj=arc.leerRegistros(i);
        if(obj.getEstado()==true)
        {
            obj.mostrar();
        }
    }

}
int generarIdActividad(){
archivoActividades arc;
int cant = arc.contarRegistros();
    if(cant<=0){
        return 1;
    }
actividad obj = arc.leerRegistros(cant-1);
return obj.getIdactividad()+1;
}
void altaActividad()
{
   int id = generarIdActividad();
    cout<<"ID ASIGNADO: "<<id<<endl;
    archivoActividades arc;
    int pos = arc.buscarRegistros(id);
    if(pos >= 0)
    {
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    actividad obj;
    obj.cargar(id);
    arc.grabarRegistros(obj);
}

void bajaActividad()
{

    int id ;
    archivoActividades arc;
    cout<<"ingrese el id del actividades: ";
    cin>>id;
    int pos= arc.buscarRegistros(id);
    if(pos < 0)
    {
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    actividad obj =arc.leerRegistros(pos);
    obj.setEstado(false);
    arc.modificarRegistros(obj,pos);
    cout<<"la actividad ha sido dado de baja correctamente "<<endl;
}

void modificarActividad()
{
    int id ;
    cout<<"ingrese el id del actividad: ";
    cin>>id;

    archivoActividades arc;
    int pos = arc.buscarRegistros(id);
    if(pos<0)
    {
        cout<<"el id no existe "<<endl;
        return;
    }
    actividad obj=arc.leerRegistros(pos);

    if(obj.getEstado()==false)
    {
        cout<<"el actividades esta dado de baja"<<endl;
        return;
    }
    cout<<"ingrese los datos nuevos ";
    obj.cargar(id);
    arc.modificarRegistros(obj,pos);
    cout<<"actividades modificado correctamente"<<endl;
}

void listarActividad()
{
    archivoActividades arc;
    int cant = arc.contarRegistros();
    if (cant<=0)
    {

        cout<<"no hay actividades ingresadas: "<<endl;
        return;
    }
    for(int i =0; i<cant; i++)
    {

        actividad obj=arc.leerRegistros(i);
        if(obj.getEstado()==true)
        {
            obj.mostrar();
        }
    }
}
int generarIdSede(){
    archivoSede arc;
    int cant = arc.contarRegistro();
    if(cant<=0){
        return 1;
    }
    sede obj = arc.leerRegistro(cant-1);
    return obj.getIdsede()+1;
}
void altaSede()
{
    int id = generarIdSede();

    cout<<"ID ASIGNADO: "<<id<<endl;
    archivoSede arc;
    int pos = arc.buscarRegistro(id);
    if(pos >= 0)
    {
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    sede obj;
    obj.cargar(id);
    arc.grabarRegistro(obj);
}

void bajaSede()
{
    int id ;
    archivoSede arc;
    cout<<"ingrese el id de la sede: ";
    cin>>id;
    int pos= arc.buscarRegistro(id);
    if(pos < 0)
    {
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    sede obj =arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj,pos);
    cout<<"la sede ha sido dado de baja correctamente "<<endl;
}

void modificarSede()
{
    int id ;
    cout<<"ingrese el id de la sede: ";
    cin>>id;
    archivoSede arc;
    int pos = arc.buscarRegistro(id);
    if(pos<0)
    {
        cout<<"el id no existe "<<endl;
        return;
    }
    sede obj=arc.leerRegistro(pos);

    if(obj.getEstado()==false)
    {
        cout<<"la sede esta dada de baja"<<endl;
        return;
    }
    cout<<"ingrese los datos nuevos ";
    obj.cargar(id);
    arc.modificarRegistro(obj,pos);
    cout<<"sede modificad correctamente"<<endl;
}

void listarSede()
{
    archivoSede arc;
    int cant = arc.contarRegistro();
    if (cant<=0)
    {

        cout<<"no hay sedes ingresadas: "<<endl;
        return;
    }
    for(int i =0; i<cant; i++)
    {

        sede obj=arc.leerRegistro(i);
        if(obj.getEstado()==true)
        {
            obj.mostrar();
        }
    }

}

void altaCuota()
{
    int id;
    cout<<"INGRESE EL ID DE CUOTA: ";
    cin>>id;
    archivoCuota arc;
    int pos = arc.buscarRegistros(id);
    if(pos >= 0)
    {
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    cuota obj;
    obj.cargar(id);
    arc.grabarRegistro(obj);

}

void bajaCuota()
{

    int id ;
    archivoCuota arc;
    cout<<"ingrese el id de la cuota: ";
    cin>>id;
    int pos= arc.buscarRegistros(id);
    if(pos < 0)
    {
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    cuota obj =arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj,pos);
    cout<<"la couta ha sido dado de baja correctamente "<<endl;

}

void modificarCuota()
{
    int id ;
    cout<<"ingrese el id de la couta: ";
    cin>>id;
    archivoCuota arc;
    int pos = arc.buscarRegistros(id);
    if(pos<0)
    {
        cout<<"el id no existe "<<endl;
        return;
    }
    cuota obj=arc.leerRegistro(pos);

    if(obj.getEstado()==false)
    {
        cout<<"la sede esta dada de baja"<<endl;
        return;
    }
    cout<<"ingrese los datos nuevos ";
    obj.cargar(id);
    arc.modificarRegistro(obj,pos);
    cout<<"couta modificad correctamente"<<endl;

}

void listarCuota()
{
    archivoCuota arc;
    int cant = arc.contarRegistros();
    if (cant<=0)
    {

        cout<<"no hay cuotas ingresadas: "<<endl;
        return;
    }
    for(int i =0; i<cant; i++)
    {

        cuota obj=arc.leerRegistro(i);
        if(obj.getEstado()==true)
        {
            obj.mostrar();
        }
    }
}
///ordenar socios por apellido .
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


///ordenar por monto de deuda.

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

            if(vec[i].getCuota()>
                    vec[j].getCuota())
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

///ordenar por id de sedes.

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


void listadoSedeXid()
{

    archivoSede arc;

    int cant = arc.contarRegistro();

    sede *vec = new sede[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0; i<cant-1; i++)
    {

        for(int j=i+1; j<cant; j++)
        {

            if(vec[i].getIdsede() >
                    vec[j].getIdsede())
            {

                sede aux=vec[i];
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

///INFORMES


actividad buscarActividadPorId(int idActividad)
{

    archivoActividades arc;

    int cant = arc.contarRegistros();

    for(int i=0; i<cant; i++)
    {

        actividad obj = arc.leerRegistros(i);

        if(obj.getIdactividad()==idActividad)
        {
            return obj;
        }
    }

    actividad aux;
    aux.setIdactividad(-1);

    return aux;
}


void listarActividadesDeSocio()
{

    int idSocio;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>idSocio;

    archivoActividadesSocio arc;

    int cant = arc.contarRegistros();

    bool encontro=false;

    for(int i=0; i<cant; i++)
    {

        actividadSocio reg = arc.leerRegistro(i);

        if(reg.getIdSocio()==idSocio &&
                reg.getEstado())
        {

            actividad act =
                buscarActividadPorId(reg.getIdactividad());

            if(act.getIdactividad()!=-1)
            {

                act.mostrar();
                cout<<endl;

                encontro=true;
            }
        }
    }

    if(!encontro)
    {
        cout<<"EL SOCIO NO TIENE ACTIVIDADES REGISTRADAS"<<endl;
    }
}




void recaudacionAnual()
{

    archivoCuota arc;

    int cant = arc.contarRegistros();

    float total=0;

    for(int i=0; i<cant; i++)
    {

        cuota obj = arc.leerRegistro(i);

        if(obj.getEstado())
        {

            total += obj.getCuota();
        }
    }

    cout<<"RECAUDACION ANUAL: $"<<total<<endl;
}

///informe
void recaudacionXActividad(){

    archivoActividades arcAct;
    archivoActividadesSocio arcSocio;
    archivoCuota arcCuota;

    int cantAct=arcAct.contarRegistros();
    int cantSoc=arcSocio.contarRegistros();
    int cantCuo=arcCuota.contarRegistros();

    for(int i=0;i<cantAct;i++){

        actividad act=arcAct.leerRegistros(i);

        float total=0;

        for(int j=0;j<cantSoc;j++){

            actividadSocio as=arcSocio.leerRegistro(j);

            if(as.getIdactividad()==act.getIdactividad()){

                for(int k=0;k<cantCuo;k++){

                    cuota c=arcCuota.leerRegistro(k);

                    if(c.getIdsocio()==as.getIdSocio()){

                        total+=c.getCuota();
                    }
                }
            }
        }

        cout<<"ACTIVIDAD: "<<act.getNombreActividad()<<endl;
        cout<<"RECAUDACION: $"<<total<<endl<<endl;
    }
}

void porcentajeInscripciones(){

    archivoActividades arcAct;
    archivoActividadesSocio arc;

    int cantAct = arcAct.contarRegistros();
    int cant = arc.contarRegistros();

    int total = 0;

    for(int i=0; i<cant; i++){

        actividadSocio obj = arc.leerRegistro(i);

        if(obj.getEstado()==true){
            total++;
        }
    }

    for(int i=0; i<cantAct; i++){

        actividad act = arcAct.leerRegistros(i);

        int cantidad = 0;

        for(int j=0; j<cant; j++){

            actividadSocio obj = arc.leerRegistro(j);

            if(obj.getEstado()==true){

                if(obj.getIdactividad()==act.getIdactividad()){
                    cantidad++;
                }
            }
        }

        float porcentaje = 0;

        if(total>0){
            porcentaje = cantidad * 100.0 / total;
        }

        cout<<"ACTIVIDAD: "<<act.getNombreActividad()<<endl;
        cout<<"PORCENTAJE DE INSCRIPCIONES: "<<porcentaje<<"%"<<endl;
        cout<<endl;
    }
}

///INFORME RANKING
void ranking(){
    archivoActividadesSocio arcActiviXSocio;
    archivoActividades arcActivida;

    int cantAxS= arcActiviXSocio.contarRegistros();
    int cantActi= arcActivida.contarRegistros();

if(cantActi<=0) {cout<< "ERROR: NO HAY ACTIVIDADES REGISTRADAS"<<endl; return;} /// VALIDACION DE REGISTROS

    int *VcontarActividad= new int[cantActi]();
    actividad *VranquearActividad = new actividad[cantActi];
    actividadSocio registro;
    actividad auxActi;
    int aux;

for(int i= 0; i<cantActi; i++){
    VranquearActividad[i]= arcActivida.leerRegistros(i);
    }

    for(int i= 0; i<cantAxS; i++){
    registro= arcActiviXSocio.leerRegistro(i);

    if (registro.getEstado()==true){///VALIDA QUE LOS REGISTROS ESTEN ACTIVOS
        for(int j=0; j<cantActi; j++){
            if(registro.getIdactividad()==VranquearActividad[j].getIdactividad()){
            VcontarActividad[j]++;
            break;
            }
        }
      }
    }
    for(int a=0; a<cantActi-1; a++){

        for(int b=0; b<cantActi-a-1; b++){

            if(VcontarActividad[b]<VcontarActividad[b+1]){
            aux= VcontarActividad[b];
            VcontarActividad[b]= VcontarActividad[b+1];
            VcontarActividad[b+1]= aux;
            ///ORDENAMOS EL CONTADOR Y EL REGISTRO TAMBIEN
            auxActi= VranquearActividad[b];
            VranquearActividad[b]= VranquearActividad[b+1];
            VranquearActividad[b+1]= auxActi;
        }
        }
    }
    for(int i=0; i<cantActi; i++){
    if (VcontarActividad[i]>0){
    cout<< "#"<<i+1<<" : "<<VranquearActividad[i].getNombreActividad()<<". TOTAL INSCRIPTOS: "<<VcontarActividad[i]<<endl;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    }
    }


    delete[] VranquearActividad;
    delete[] VcontarActividad;
    }

///INFORME DEUDORES
void deudores(){
archivoCuota arc;
cuota deudor;
archivoSocio arcSocio;
int pos;
socio obj;
int contDeudores=0;
int cant=arc.contarRegistros();

cout<<"SOCIOS CON DEUDAS PENDIENTES: "<<endl;
for(int i =0; i<cant; i++){
    deudor= arc.leerRegistro(i);
    if(deudor.calcularDeuda()>0){
        if(deudor.getEstado()){
            pos=arcSocio.buscarRegistros(deudor.getIdsocio());
            obj=arcSocio.leerRegistros(pos);
            if(pos>=0){
                cout<<"ID: "<<deudor.getIdsocio()<<" | APELLIDO Y NOMBRE: "<<obj.getApellido()<<" "<<obj.getNombre()
                <<" | DEUDA TOTAL: "<<deudor.calcularDeuda()<<endl;
                contDeudores++;
            }
        }
    }

}
cout<<"CANTIDAD TOTAL DE SOCIOS CON DEUDA: "<<contDeudores;
}



void informes()
{
    int opc;

    while(true)
    {
        system("cls");

        cout<<"MENU INFORMES"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - Recaudacion anual"<<endl;
        cout<<"2 - Recaudacion por actividad"<<endl;
        cout<<"3 - Porcentaje de inscripciones por cada actividad"<<endl;
        cout<<"4 - Listar todas las actividades de un socio"<<endl;
        cout<<"5 - Ranking de actividades"<<endl;
        cout<<"6 - Listar socios con deudas pendientes"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=========================="<<endl;

        cin>>opc;

        system("cls");

        switch(opc)
        {
        case 1:
            recaudacionAnual();
            break;

        case 2:
            recaudacionXActividad();
            break;

        case 3:
            porcentajeInscripciones();
            break;

        case 4:
            listarActividadesDeSocio();
            break;

        case 5:
            ranking();
            break;

        case 6:
            deudores();
            break;

        case 0:
            return;
        }

        system("pause");
    }
}
///consulta rango de fechas
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
    char apellido [20];

    cout<<"INGRESE EL APELLIDO DEL SOCIO: ";

    cargarCadena(apellido,20);

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);


        if(strcmp(obj.getApellido(),apellido)==0)
        {
            obj.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado)
    {
        cout << "NO EXISTE NINGUN SOCIO CON ESE APELLIDO." << endl;
    }
}




void consultaXActividad()
{
    actividad obj;
    archivoActividades arc;
    bool encontrado=false;
    int cant=arc.contarRegistros();
    char nombre[20];
    cout<<"INGRESE EL NOMBRE DE LA ACTIVIDAD: ";
    cargarCadena(nombre,20);

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);


        if(strcmp(obj.getNombreActividad(),nombre)==0)
        {
            obj.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado)
    {
        cout << "NO SE ENCONTRO NINGUNA ACTIVIDAD   " << endl;
    }

}

void consultaResumen(){

    cuota obj;
    archivoCuota arc;

    int mes;

    cout << "INGRESE EL MES A RESUMIR: ";
    cin >> mes;
    float total = 0;
    int cant = arc.contarRegistros();
    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(obj.getFechaPago().getMes()== mes){
            total += obj.getCuota();
        }
    }
    cout << "RECAUDACION TOTAL DEL MES: $" << total << endl;
}

void consultasDeEstado(){
socio obj;
    archivoSocio arc;
    bool encontrado=false;
    int cant= arc.contarRegistros();
    char apellido [20];

    cout<<"INGRESE EL APELLIDO DEL SOCIO: ";

    cargarCadena(apellido,20);

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);


        if((strcmp(obj.getApellido(),apellido)==0) && (obj.getEstado()==true))
        {
            cout<<"EL SOCIO ESTA ACTIVO"<<endl;
            encontrado=true;
        }
        else {cout<<"EL SOCIO ESTA INACTIVO"<<endl;}
    }
    if(!encontrado)
    {
        cout << "NO EXISTE NINGUN SOCIO CON ESE APELLIDO." << endl;
    }
}


