#include <iostream>
#include"clsManagerSocio.h"

using namespace std;
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

    socio obj;

    obj.cargar(id);

    arc.grabarRegistros(obj);

    cout<<"SOCIO CARGADO CORRECTAMENTE"<<endl;
}
void bajaSocio()
{
    archivoSocio arc;
    int id ;
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
        char opcion;

    cout<<"EL SOCIO ESTA DADO DE BAJA"<<endl;
    cout<<"DESEA REACTIVARLO? (S/N): ";
    cin>>opcion;

        if(opcion=='S' || opcion=='s')
        {
            obj.setEstado(true);
            arc.modificarRegistro(obj,pos);

    cout<<"SOCIO REACTIVADO CORRECTAMENTE"<<endl;
        }
        return;
    }
    obj.mostrar();

    char opcion;

    cout<<"DESEA MODIFICAR ESTE SOCIO? (S/N): ";
    cin>>opcion;

    if(opcion!='S' && opcion!='s')
    {
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
