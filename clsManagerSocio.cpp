#include <iostream>
#include"clsManagerSocio.h"
#include "estetico.h"
#include "funciones.h"
using namespace std;
void menuSocios()
{
    int opc;
    while(true)
    {
        system("cls");
        blanco();
        cout<<"MENU SOCIOS"<<endl;
        negro();
        cout<<"============================="<<endl;
        blanco();
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"5 - LISTADO: SOCIOS POR APELLIDO"<<endl;
        cout<<"6 - LISTADO: SOCIOS POR TIPO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        negro();
        cout<<"============================="<<endl;
        blanco();
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
        case 5:
            listadoSociosApellido();
            break;
        case 6:
            listadoSociosTipo();
            break;
        case 0:
            return;
        }
        pausa();
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
    amarillo();
    cout<<"SOCIO CARGADO CORRECTAMENTE"<<endl;
    blanco();
}
void bajaSocio()
{
    archivoSocio arc;
    int id ;
    cout<<"INGRESE ID DE SOCIO: ";
    cin>>id;
    int pos= arc.buscarRegistros(id);
    if(pos < 0)
    {   rojo();
        cout<<"ERROR: EL ID NO EXISTE EN EL SISTEMA"<<endl;
        blanco();
        return;
    }
    socio obj =arc.leerRegistros(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj,pos);
    amarillo();
    cout<<"SOCIO DADO DE BAJA CORRECTAMENTE "<<endl;
    blanco();
}

void modificarSocio()
{
    int id;
    cout << "INGRESE EL ID DEL SOCIO A MODIFICAR: ";
    cin >> id;

    archivoSocio arc;
    int pos = arc.buscarRegistros(id);

    if (pos < 0)
    {   rojo();
        cout << "ERROR: EL ID NO EXISTE EN EL SISTEMA." << endl;
        blanco();
        return;
    }

    socio obj = arc.leerRegistros(pos);

    // REACTIVACION SOCIO DADO DE BAJA
    if (obj.getEstado() == false)
    {
        char opcion;
        amarillo();
        cout << "EL SOCIO ESTA DADO DE BAJA" << endl;
        blanco();
        cout << "DESEA REACTIVARLO? (S/N): ";
        cin >> opcion;

        if (opcion == 'S' || opcion == 's')
        {
            obj.setEstado(true);
            arc.modificarRegistro(obj, pos);
            amarillo();
            cout << "SOCIO REACTIVADO CORRECTAMENTE" << endl;
            blanco();
        }
        return;
    }


    cout << "DATOS ACTUALES DEL SOCIO:" << endl;
    negro();
    cout << "==================================" << endl;
    blanco();
    obj.mostrar();
    negro();
    cout << "==================================" << endl;
    blanco();

    char confirmar;
    amarillo();
    cout << "DESEA MODIFICAR ESTE SOCIO? (S/N): ";
    blanco();
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 's')
    {
        return;
    }

    // Submenú
    int opcCampo;
    amarillo();
    cout << "SELECCIONE EL CAMPO A MODIFICAR:" << endl;
    negro();
    cout << "==================================" << endl;
    blanco();;
    cout << "1 - NOMBRE" << endl;
    cout << "2 - APELLIDO" << endl;
    cout << "3 - TELEFONO" << endl;
    cout << "4 - EMAIL" << endl;
    cout << "5 - FECHA DE NACIMIENTO" << endl;
    cout << "6 - TIPO DE SOCIO" << endl;
    cout << "0 - CANCELAR" << endl;
    negro();
    cout << "==================================" << endl;
    blanco();
    cout<<"INGRESE UNA OPCION: ";
    cin >> opcCampo;

    cin.ignore();

        amarillo();
    switch (opcCampo)
    {
    case 1:
        {
            char nuevoNombre[20];
            cout << "INGRESE NUEVO NOMBRE: ";
            blanco();
            cin.getline(nuevoNombre, 20);
            obj.setNombre(nuevoNombre);
        }
        break;

    case 2:
        {
            char nuevoApellido[20];
            cout << "INGRESE NUEVO APELLIDO: ";
            blanco();
            cin.getline(nuevoApellido, 20);
            obj.setApellido(nuevoApellido);
        }
        break;

    case 3:
        {
            char nuevoTelefono[15];
            cout << "INGRESE NUEVO TELEFONO: ";
            blanco();
            cin.getline(nuevoTelefono, 15);
            obj.setTelefono(nuevoTelefono);
        }
        break;

    case 4:
        {
            char nuevoEmail[50];

            while(true)
            {
                cout << "INGRESE NUEVO EMAIL: ";
                blanco();
                cin.getline(nuevoEmail, 50);

                bool tieneArroba = false;
                for(int i = 0; nuevoEmail[i] != '\0'; i++)
                {
                    if(nuevoEmail[i] == '@')
                    {
                        tieneArroba = true;
                    }
                }

                if(tieneArroba)
                {
                    break;
                }
                rojo();
                cout << "ERROR: EL EMAIL DEBE CONTENER @. REINGRESE MAIL." << endl;
                blanco();
            }

            obj.setEmail(nuevoEmail);
        }
        break;

    case 5:
        {
            Fecha nuevaFecha;
            amarillo();
            cout << "INGRESE NUEVA FECHA DE NACIMIENTO:" << endl;
            blanco();
            nuevaFecha.Cargar();
            obj.setFechaNacimiento(nuevaFecha);
        }
        break;

    case 6:
        {
            int nuevoTipo;
            amarillo();
            cout << "INGRESE NUEVO TIPO DE SOCIO (1: Basico, 2: Intermedio, 3: Premium): ";
            blanco();
            cin >> nuevoTipo;

            if (nuevoTipo >= 1 && nuevoTipo <= 3) {
                obj.setTipoSocio(nuevoTipo);
            } else {
                rojo();
                cout << "ERROR: TIPO DE SOCIO INVALIDO. NO SE REALIZARON CAMBIOS." << endl;
                blanco();
                return;
            }
        }
        break;

    case 0:
        amarillo();
        cout << "MODIFICACION CANCELADA." << endl;
        blanco();
        return;

    default:
        rojo();
        cout << "ERROR: OPCION INVALIDA." << endl;
        blanco();
        return;
    }

    // Guardar los cambios sobreescribiendo
    if (arc.modificarRegistro(obj, pos))
    {   amarillo();
        cout << "SOCIO MODIFICADO CORRECTAMENTE EN EL SISTEMA." << endl;
        blanco();
    }
    else
    {   rojo();
        cout << "ERROR: AL INTENTAR GUARDAR LOS CAMBIOS EN EL ARCHIVO." << endl;
        blanco();
    }
}

void listarSocio()
{
    archivoSocio arc;
    int cant = arc.contarRegistros();
    if (cant<=0)
    {
        amarillo();
        cout<<"NO HAY SOCIOS INGRESADOS"<<endl;
        blanco();
        return;
    }
    for(int i =0; i<cant; i++)
    {
        blanco();
        socio obj=arc.leerRegistros(i);
        if(obj.getEstado()==true)
        {
            obj.mostrar();
            cout<<endl;
            negro();
            cout << "==================================" << endl;
            blanco();
            cout<<endl;
        }
    }

}
