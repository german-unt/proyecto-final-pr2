#include <iostream>
#include"clsManagerCouta.h"

using namespace std;

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
{   int id ;
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
