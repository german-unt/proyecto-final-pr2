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
    actividad obj;
    obj.cargar(id);
    arc.grabarRegistros(obj);
    cout<<"ACTIVIDAD CARGADA CORRECTAMENTE"<<endl;
}

void bajaActividad()
{
    int id;
    archivoActividades arc;

    cout<<"INGRESE EL ID DE LA ACTIVIDAD: ";
    cin>>id;

    int pos = arc.buscarRegistros(id);
    if(pos < 0)
    {
        cout<<"EL ID NO EXISTE"<<endl;
        return;
    }
    actividad obj = arc.leerRegistros(pos);
    obj.setEstado(false);
    arc.modificarRegistros(obj,pos);

    cout<<"LA ACTIVIDAD HA SIDO DADA DE BAJA CORRECTAMENTE"<<endl;
}
void modificarActividad()
{
    int id;
    cout<<"INGRESE EL ID DE LA ACTIVIDAD: ";
    cin>>id;
    archivoActividades arc;
    int pos = arc.buscarRegistros(id);
    if(pos<0)
    {
        cout<<"EL ID NO EXISTE"<<endl;
        return;
    }
    actividad obj = arc.leerRegistros(pos);
    if(obj.getEstado()==false)
    {
        char opcion;

        cout<<"LA ACTIVIDAD ESTA DADA DE BAJA"<<endl;
        cout<<"DESEA REACTIVARLA? (S/N): ";
        cin>>opcion;

    if(opcion=='S' || opcion=='s')
        {
    obj.setEstado(true);
    arc.modificarRegistros(obj,pos);
    cout<<"ACTIVIDAD REACTIVADA CORRECTAMENTE"<<endl;
        }
        return;
    }
    obj.mostrar();
    char opcion;

    cout<<"DESEA MODIFICAR ESTA ACTIVIDAD? (S/N): ";
    cin>>opcion;

    if(opcion!='S' && opcion!='s')
    {
        return;
    }
    cout<<"INGRESE LOS DATOS NUEVOS"<<endl;
    obj.cargar(id);
    arc.modificarRegistros(obj,pos);
    cout<<"ACTIVIDAD MODIFICADA CORRECTAMENTE"<<endl;
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
             cout<<endl;
            cout<<"============================"<<endl;
        }
    }
}
