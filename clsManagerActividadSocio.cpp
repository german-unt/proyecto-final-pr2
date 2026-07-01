#include <iostream>
#include "funciones.h"
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
        blanco();
        cout<<"MENU INSCRIPCIONES"<<endl;
        negro();
        cout<<"======================="<<endl;
        blanco();
        cout<<"1 - INSCRIBIR SOCIO"<<endl;
        cout<<"2 - DAR DE BAJA INSCRIPCION"<<endl;
        cout<<"3 - MODIFICAR INSCRIPCION"<<endl;
        cout<<"4 - LISTAR INSCRIPCIONES"<<endl;
        cout<<"0 - VOLVER"<<endl;
        negro();
        cout<<"======================="<<endl;
        blanco();
        cout<<"INGRESE UNA OPCION: ";

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
        pausa();
    }
}
void altaActividadSocio() {
    int idSocio;
    blanco();
    cout << "INGRESE ID SOCIO: ";
    cin >> idSocio;

    // VALIDAR EXISTENCIA Y ESTADO DEL SOCIO
    archivoSocio arcSocio;
    int posSocio = arcSocio.buscarRegistros(idSocio);
    if(posSocio < 0) {
        rojo();
        cout << "ERROR: SOCIO NO EXISTE." << endl;
        blanco();
        return;
    }
    socio objSocio = arcSocio.leerRegistros(posSocio);

    if (!objSocio.getEstado()) {
        rojo();
        cout << "ERROR: EL SOCIO ESTA INACTIVO" << endl;
        blanco();
        return;
    }

    // LIMITE DE TIPO DE SOCIO
    int limite;
    if (objSocio.getTipoSocio() == 1) {
        limite = 2;
    } else if (objSocio.getTipoSocio() == 2) {
        limite = 3;
    } else {
        limite = 99;
    }

    // VALIDAR LIMITE
    if(contarActividadesSocio(idSocio) >= limite) {
        amarillo();
        cout << "LIMITE ALCANZADO" << endl;
        blanco();
        return;
    }

    // LISTADO
    amarillo();
    cout << "--- ACTIVIDADES DISPONIBLES ---" << endl;
    blanco();
    archivoActividades arcAct;
    int cantAct = arcAct.contarRegistros();

    for(int i = 0; i < cantAct; i++) {
        actividad aux = arcAct.leerRegistros(i);
        if(aux.getEstado()) {
            negro();
            cout << "ID: ";
            blanco();
            cout << aux.getIdactividad();
            negro();
            cout << " | ";
            blanco();
            cout << "NOMBRE: " << aux.getNombreActividad() << endl;
        }
    }

    int idAct;
    bool actividadValida = false;

    // VALIDAR QUE EL ID DE ACTIVIDAD INGRESADO EXISTA DE VERDAD
    while(!actividadValida) {
        blanco();
        cout << "INGRESE ID ACTIVIDAD: ";
        cin >> idAct;

        if(arcAct.estadoActividad(idAct)) {
            actividadValida = true;
        } else {
            rojo();
            cout << "ERROR: EL ID DE ACTIVIDAD NO EXISTE O ESTA INACTIVO. VUELVA A INGRESAR" << endl;
            blanco();
        }
    }

    // VALIDAR SI YA ESTA INSCRIPTO A ESA ACTIVIDAD
    archivoActividadesSocio arcInscripciones;
    if(arcInscripciones.buscarActividadSocio(idSocio, idAct) != -1) {
        amarillo();
        cout << "EL SOCIO YA SE ENCUENTRA INSCRIPTO A ESTA ACTIVIDAD" << endl;
        blanco();
        return;
    }

    // PREPARACION DE LA INSCRIPCION
    actividadSocio nueva;
    nueva.setIdSocio(idSocio);
    nueva.setIdactividad(idAct);
    nueva.setEstado(true);

    cin.ignore();

    blanco();
    cout << "INGRESE LA FECHA DE INSCRIPCION (ALTA):" << endl;
    Fecha fAlta;
    fAlta.Cargar();
    nueva.setFechaAlta(fAlta);

    // GRABAR NUEVA INSCRIPCION EN EL ARCHIVO
    if(arcInscripciones.grabarRegistro(nueva)) {
        amarillo();
        cout << "INSCRIPCION REALIZADA CORRECTAMENTE" << endl;
        blanco();
    } else {
        rojo();
        cout << "ERROR: AL GRABAR INSCRIPCION" << endl;
        blanco();
    }
}

void bajaActividadSocio() {
    int idSocio;
    cout << "ID SOCIO: "; cin >> idSocio;

    archivoActividadesSocio arc;
    int cant = arc.contarRegistros();

    cout << "ACTIVIDADES INSCRIPTAS:" << endl;
    for(int i=0; i<cant; i++) {
        actividadSocio aux = arc.leerRegistro(i);
        if(aux.getIdSocio() == idSocio && aux.getEstado()) {
            cout << "POS: ";

            cout<< i ;
            negro();
            cout<< " |";
            blanco();
            cout<<" ID Actividad: " << aux.getIdactividad() << endl;
        }
    }

    int pos;
    cout << "INGRESE POSICION A DAR DE BAJA: "; cin >> pos;
    actividadSocio obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}

void modificarActividadSocio() {
    int idSocio;
    blanco();
    cout << "INGRESE ID DEL SOCIO A MODIFICAR: ";
    cin >> idSocio;

    archivoActividadesSocio arc;
    int cant = arc.contarRegistros();
    bool tieneActividades = false;

    // MOSTRAR ACTIVIDADES ACTUALES

    for(int i = 0; i < cant; i++) {
        actividadSocio aux = arc.leerRegistro(i);
        if(aux.getIdSocio() == idSocio && aux.getEstado()) {
            amarillo();
            cout<<endl;
            cout << "ACTIVIDADES ACTUALES DEL SOCIO:" << endl;
            negro();
            cout << "===========================================" << endl<<endl;
            blanco();
            cout << "[";
            negro();
            cout << i;
            blanco();
            cout << "] ID ACTIVIDAD: " << aux.getIdactividad() << endl;
            tieneActividades = true;
        }
    }

    if(!tieneActividades) {
        rojo();
        cout << "ERROR: EL SOCIO NO TIENE ACTIVIDADES ACTIVAS O NO EXISTE." << endl;
        blanco();
        return;
    }

    cout << endl;
    char confirmar;
    amarillo();
    cout << "DESEA MODIFICAR ESTA ACTIVIDAD? (S/N): ";
    blanco();
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 's')
    {
        return;
    }

    //ELEGIR ACTIVIDAD
    int pos;
    blanco();
    cout << "INGRESE LA POSICION DE LA ACTIVIDAD A MODIFICAR: ";
    cin >> pos;

    actividadSocio obj = arc.leerRegistro(pos);

    //BAJA LOGICA
    if(obj.getIdSocio() == idSocio && obj.getEstado()) {
        obj.setEstado(false);
        arc.modificarRegistro(obj, pos);

        amarillo();
        cout << "ACTIVIDAD DADA DE BAJA. AHORA SELECCIONE LA NUEVA:" << endl;
        blanco();

        // LLAMAR AL ALTA PARA QUE EL USUARIO ELIJA LA NUEVA
        altaActividadSocio();
    } else {
        rojo();
        cout << "ERROR: POSICION INVALIDA O NO ENCONTRADA." << endl;
        blanco();
    }
}
void listarActividadSocio() {
    archivoActividadesSocio arcInscripciones;
    archivoSocio arcSocio;
    int cantInscripciones = arcInscripciones.contarRegistros();

    negro();
    cout << "--- ";
    amarillo();
    cout << "LISTADO DE ACTIVIDADES POR SOCIO";
    negro();
    cout << " ---" << endl;
    cout << endl;

    // RECORREMOS SOCIOS PARA AGRUPAR
    for(int i = 0; i < arcSocio.contarRegistros(); i++) {
        socio objSocio = arcSocio.leerRegistros(i);

        // VALIDACION: SOLO PROCESAMOS SOCIOS QUE ESTEN ACTIVOS
        if (!objSocio.getEstado()) {
            continue; // SI EL SOCIO ESTA DADO DE BAJA, SALTAMOS AL SIGUIENTE
        }

        bool tieneActividades = false;

        // BUSCAMOS ACTIVIDADES PARA ESTE SOCIO
        for(int j = 0; j < cantInscripciones; j++) {
            actividadSocio objInscripcion = arcInscripciones.leerRegistro(j);

            // VERIFICAMOS QUE SEA EL SOCIO, QUE LA INSCRIPCION ESTE ACTIVA Y EL SOCIO ACTIVO
            if(objInscripcion.getIdSocio() == objSocio.getIdsocio() && objInscripcion.getEstado()) {

                if(!tieneActividades) {
                    negro();
                    cout << "SOCIO: ";
                    amarillo();
                    cout<< objSocio.getNombre() << " " << objSocio.getApellido();
                    negro();
                    cout << " ID: ";
                    blanco();
                    cout << objSocio.getIdsocio();
                    cout<<endl<<endl;
                    tieneActividades = true;
                }

                objInscripcion.mostrar(); // MUESTRA LA ACTIVIDAD DEL SOCIO ACTIVO
            }
        }
    if(tieneActividades==true){
        negro();
        cout << "--------------------------------------------------------" << endl;
    }
    }
    blanco();
}

int contarActividadesSocio(int idSocio) {
    archivoActividadesSocio arc;
    int cant = arc.contarRegistros();
    int contador = 0;
    for(int i=0; i<cant; i++) {
        actividadSocio aux = arc.leerRegistro(i);
        if(aux.getIdSocio() == idSocio && aux.getEstado()) contador++;
    }
    return contador;
}
