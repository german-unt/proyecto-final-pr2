#include <iostream>
#include"clsManagerActividad.h"

using namespace std;

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
