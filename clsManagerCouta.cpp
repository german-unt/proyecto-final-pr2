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
    int idSocio;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>idSocio;

    archivoCuota arc;

    int pos = arc.buscarRegistros(idSocio);

    if(pos >= 0)
    {
        cout<<"EL SOCIO YA TIENE UNA CUOTA REGISTRADA"<<endl;
        return;
    }

    cuota obj;

    obj.cargar(idSocio);

    arc.grabarRegistro(obj);

    cout<<"CUOTA REGISTRADA CORRECTAMENTE"<<endl;
}
void bajaCuota()
{
    int idSocio;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>idSocio;

    archivoCuota arc;

    int pos = arc.buscarRegistros(idSocio);

    if(pos < 0)
    {
        cout<<"NO EXISTE LA CUOTA"<<endl;
        return;
    }

    cuota obj = arc.leerRegistro(pos);

    obj.setEstado(false);

    arc.modificarRegistro(obj,pos);

    cout<<"LA CUOTA FUE DADA DE BAJA"<<endl;
}
void modificarCuota()
{
    int idSocio;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>idSocio;

    archivoCuota arc;

    int pos = arc.buscarRegistros(idSocio);

    if(pos<0)
    {
        cout<<"NO EXISTE LA CUOTA"<<endl;
        return;
    }

    cuota obj = arc.leerRegistro(pos);

    if(obj.getEstado()==false)
    {
        cout<<"LA CUOTA ESTA DADA DE BAJA"<<endl;
        return;
    }

    obj.mostrar();

    char opcion;

    cout<<"DESEA MODIFICAR ESTA CUOTA? (S/N): ";
    cin>>opcion;

    if(opcion!='S' && opcion!='s')
    {
        return;
    }

    obj.cargar(idSocio);

    arc.modificarRegistro(obj,pos);

    cout<<"CUOTA MODIFICADA CORRECTAMENTE"<<endl;
}

void listarCuota()
{
    archivoCuota arc;

    int cant = arc.contarRegistros();

    if(cant<=0)
    {
        cout<<"NO HAY CUOTAS INGRESADAS"<<endl;
        return;
    }

    for(int i=0; i<cant; i++)
    {
        cuota obj = arc.leerRegistro(i);

        if(obj.getEstado())
        {
            obj.mostrar();
        }
    }
}
