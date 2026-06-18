#include <iostream>

#include "clsManagerActividadSocio.h"
#include "clsActividadSocio.h"
#include "clsArchivoActividadesSocio.h"
#include "clsArchivoSocio.h"

using namespace std;
void menuActividadSocio()
{
    int opc;

    while(true)
    {
        system("cls");

        cout<<"MENU INSCRIPCIONES"<<endl;
        cout<<"=================="<<endl;
        cout<<"1 - INSCRIBIR SOCIO"<<endl;
        cout<<"2 - DAR DE BAJA INSCRIPCION"<<endl;
        cout<<"3 - MODIFICAR INSCRIPCION"<<endl;
        cout<<"4 - LISTAR INSCRIPCIONES"<<endl;
        cout<<"0 - VOLVER"<<endl;

        cin>>opc;

        system("cls");

        switch(opc)
        {
        case 1:
            altaActividadSocio();
            break;

        case 2:
            bajaActividadSocio();
            break;

        case 3:
             modificarActividadSocio();
            break;

        case 4:
            listarActividadSocio();
            break;

        case 0:
            return;
        }

        system("pause");
    }
}
void altaActividadSocio()
{
    int idSocio;
    cout<<"INGRESE ID DEL SOCIO: ";
    cin>>idSocio;

    archivoSocio arcSocio;

    int posSocio = arcSocio.buscarRegistros(idSocio);

    if(posSocio<0)
    {
        cout<<"SOCIO INEXISTENTE"<<endl;
        return;
    }

    socio objSocio = arcSocio.leerRegistros(posSocio);
    if (objSocio.getEstado()==false){cout<<"EL SOCIO ESTA DADO DE BAJA"<<endl;
    return;
    }

    int tipo = objSocio.getTipoSocio();

    cout<<"ACTIVIDADES DISPONIBLES"<<endl;
    cout<<"======================="<<endl;

    if(tipo==1)
    {
        cout<<"1 - FUTBOL"<<endl;
        cout<<"5 - HOCKEY"<<endl;
    }

    if(tipo==2)
    {
        cout<<"1 - FUTBOL"<<endl;
        cout<<"3 - NATACION"<<endl;
        cout<<"4 - VOLEY"<<endl;
        cout<<"5 - HOCKEY"<<endl;
    }

    if(tipo==3)
    {
        cout<<"1 - FUTBOL"<<endl;
        cout<<"2 - RUGBY"<<endl;
        cout<<"3 - NATACION"<<endl;
        cout<<"4 - VOLEY"<<endl;
        cout<<"5 - HOCKEY"<<endl;
    }

int idActividad;
    cout<<"======================="<<endl;
    cout<<"ELIJA UNA ACTIVIDAD: "<<endl<<endl;
    cin>>idActividad;
    actividadSocio obj;

    actividad objActividad;
    archivoActividades arcActividad;

    int pos=arcActividad.buscarRegistros(idActividad);
    objActividad=arcActividad.leerRegistros(pos);
    if (objActividad.getEstado()==false){cout<<"LA ACTIVIDAD ESTA DADA DE BAJA"<<endl;
    return;
    }
    obj.setIdactividad(idActividad);
    obj.setEstado(true);
    obj.setIdSocio(idSocio);
    archivoActividadesSocio arc;
    arc.grabarRegistro(obj);

    cout<<"INSCRIPCION REALIZADA CORRECTAMENTE"<<endl;
}
void bajaActividadSocio()
{
    int idActividad;

    cout<<"INGRESE ID DE ACTIVIDAD: ";
    cin>>idActividad;

    archivoActividadesSocio arc;

    int pos = arc.buscarRegistro(idActividad);

    if(pos<0)
    {
        cout<<"NO EXISTE"<<endl;
        return;
    }

    actividadSocio obj = arc.leerRegistro(pos);

    obj.setEstado(false);

    arc.modificarRegistro(obj,pos);

    cout<<"INSCRIPCION DADA DE BAJA"<<endl;
}
void modificarActividadSocio()
{
    int idSocio;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>idSocio;

    archivoActividadesSocio arc;

    int pos = arc.buscarRegistroSocio(idSocio);

    if(pos<0)
    {
        cout<<"NO EXISTE INSCRIPCION PARA ESE SOCIO"<<endl;
        return;
    }

    actividadSocio obj = arc.leerRegistro(pos);

    if(obj.getEstado()==false)
    {
        cout<<"LA INSCRIPCION ESTA DADA DE BAJA"<<endl;
        return;
    }

    cout<<endl;
    cout<<"INSCRIPCION ACTUAL"<<endl;
    cout<<"================="<<endl;
    obj.mostrar();

    int opcion;

    cout<<endl;
    cout<<"DESEA MODIFICAR ESTA INSCRIPCION?"<<endl;
    cout<<"1 - SI"<<endl;
    cout<<"0 - NO"<<endl;
    cin>>opcion;


while(opcion!=0 && opcion !=1){
     cout<<"ERROR, INGRESE 0 O 1"<<endl;
     cin>>opcion;
}
    archivoSocio arcSocio;

    int posSocio = arcSocio.buscarRegistros(obj.getIdSocio());

    if(posSocio<0)
    {
        cout<<"SOCIO INEXISTENTE"<<endl;
        return;
    }

    socio objSocio = arcSocio.leerRegistros(posSocio);

    int tipo = objSocio.getTipoSocio();

    cout<<endl;
    cout<<"ACTIVIDADES DISPONIBLES"<<endl;
    cout<<"======================="<<endl;

    if(tipo==1)
    {
        cout<<"1 - FUTBOL"<<endl;
        cout<<"5 - HOCKEY"<<endl;
    }

    if(tipo==2)
    {
        cout<<"1 - FUTBOL"<<endl;
        cout<<"3 - NATACION"<<endl;
        cout<<"4 - VOLEY"<<endl;
        cout<<"5 - HOCKEY"<<endl;
    }

    if(tipo==3)
    {
        cout<<"1 - FUTBOL"<<endl;
        cout<<"2 - RUGBY"<<endl;
        cout<<"3 - NATACION"<<endl;
        cout<<"4 - VOLEY"<<endl;
        cout<<"5 - HOCKEY"<<endl;
    }

    int nuevaActividad;

    cout<<endl;
    cout<<"INGRESE NUEVO ID DE ACTIVIDAD: ";
    cin>>nuevaActividad;

    if(tipo==1 &&
       nuevaActividad!=1 &&
       nuevaActividad!=5)
    {
        cout<<"ESA ACTIVIDAD NO CORRESPONDE A SU PLAN"<<endl;
        return;
    }

    if(tipo==2 &&
       nuevaActividad==2)
    {
        cout<<"ESA ACTIVIDAD NO CORRESPONDE A SU PLAN"<<endl;
        return;
    }

    obj.setIdactividad(nuevaActividad);

    arc.modificarRegistro(obj,pos);

    cout<<"INSCRIPCION MODIFICADA CORRECTAMENTE"<<endl;
}
void listarActividadSocio()
{
    archivoActividadesSocio arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++)
    {
        actividadSocio obj = arc.leerRegistro(i);

        if(obj.getEstado())
        {
            obj.mostrar();
            cout<<endl;
            cout<<"============================"<<endl;
            cout<<endl;
        }
    }
}
