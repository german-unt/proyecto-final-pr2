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
    int id;
    cout << "INGRESE EL ID DEL SOCIO A MODIFICAR: ";
    cin >> id;

    archivoSocio arc;
    int pos = arc.buscarRegistros(id);

    if (pos < 0)
    {
        cout << "EL ID NO EXISTE EN EL SISTEMA." << endl;
        return;
    }

    socio obj = arc.leerRegistros(pos);

    // 1. Manejo de socio dado de baja
    if (obj.getEstado() == false)
    {
        char opcion;
        cout << "EL SOCIO ESTA DADO DE BAJA" << endl;
        cout << "DESEA REACTIVARLO? (S/N): ";
        cin >> opcion;

        if (opcion == 'S' || opcion == 's')
        {
            obj.setEstado(true);
            arc.modificarRegistro(obj, pos);
            cout << "SOCIO REACTIVADO CORRECTAMENTE" << endl;
        }
        return;
    }

    // 2. Mostrar datos actuales
    cout << "\nDATOS ACTUALES DEL SOCIO:" << endl;
    cout << "=========================" << endl;
    obj.mostrar();
    cout << "=========================" << endl;

    char confirmar;
    cout << "DESEA MODIFICAR ESTE SOCIO? (S/N): ";
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 's')
    {
        return;
    }

    // 3. Submenú interactivo con todos los campos de la clase socio
    int opcCampo;
    cout << "\nSELECCIONE EL CAMPO A MODIFICAR:" << endl;
    cout << "1 - NOMBRE" << endl;
    cout << "2 - APELLIDO" << endl;
    cout << "3 - TELEFONO" << endl;
    cout << "4 - EMAIL" << endl;
    cout << "5 - FECHA DE NACIMIENTO" << endl;
    cout << "6 - TIPO DE SOCIO" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << "OPCION: ";
    cin >> opcCampo;

    cin.ignore(); // Limpia el residuo del enter en el buffer

    switch (opcCampo)
    {
    case 1:
        {
            char nuevoNombre[20]; // Tamaño exacto de la propiedad en la clase
            cout << "INGRESE NUEVO NOMBRE: ";
            cin.getline(nuevoNombre, 20);
            obj.setNombre(nuevoNombre);
        }
        break;

    case 2:
        {
            char nuevoApellido[20]; // Tamaño exacto de la propiedad en la clase
            cout << "INGRESE NUEVO APELLIDO: ";
            cin.getline(nuevoApellido, 20);
            obj.setApellido(nuevoApellido);
        }
        break;

    case 3:
        {
            char nuevoTelefono[15]; // Tamaño exacto de la propiedad en la clase
            cout << "INGRESE NUEVO TELEFONO: ";
            cin.getline(nuevoTelefono, 15);
            obj.setTelefono(nuevoTelefono);
        }
        break;

    case 4:
        {
            char nuevoEmail[50]; // Tamaño exacto de la propiedad en la clase

            while(true)
            {
                cout << "INGRESE NUEVO EMAIL: ";
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
                    break; // Corta el bucle while porque el mail es válido
                }

                cout << "ERROR: EL EMAIL DEBE CONTENER @. Intente nuevamente." << endl;
            }

            obj.setEmail(nuevoEmail); // Guarda el email validado en el objeto
        }
        break;

    case 5:
        {
            Fecha nuevaFecha;
            cout << "INGRESE NUEVA FECHA DE NACIMIENTO:" << endl;
            nuevaFecha.Cargar(); // Reutiliza el método de validación de fechas de tu clase
            obj.setFechaNacimiento(nuevaFecha);
        }
        break;

    case 6:
        {
            int nuevoTipo;
            cout << "INGRESE NUEVO TIPO DE SOCIO (1: Basico, 2: Intermedio, 3: Premium): ";
            cin >> nuevoTipo;

            if (nuevoTipo >= 1 && nuevoTipo <= 3) {
                obj.setTipoSocio(nuevoTipo);
            } else {
                cout << "TIPO DE SOCIO INVALIDO. NO SE REALIZARON CAMBIOS." << endl;
                return;
            }
        }
        break;

    case 0:
        cout << "MODIFICACION CANCELADA." << endl;
        return;

    default:
        cout << "OPCION INVALIDA." << endl;
        return;
    }

    // 4. Guardar los cambios sobreescribiendo en el archivo binario
    if (arc.modificarRegistro(obj, pos))
    {
        cout << "\nSOCIO MODIFICADO CORRECTAMENTE EN EL SISTEMA." << endl;
    }
    else
    {
        cout << "\nERROR AL INTENTAR GUARDAR LOS CAMBIOS EN EL ARCHIVO." << endl;
    }
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
            cout<<endl;
            cout<<"============================"<<endl;
        }
    }

}
