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
void altaActividadSocio() {
    int idSocio;
    cout << "INGRESE ID SOCIO: ";
    cin >> idSocio;

    // 1. Validar existencia socio
    archivoSocio arcSocio;
    int posSocio = arcSocio.buscarRegistros(idSocio);
    if(posSocio < 0) {
        cout << "Socio no existe." << endl;
        return;
    }
    socio s = arcSocio.leerRegistros(posSocio);

    // 2. Determinar el límite usando IF-ELSE normal
    int limite;
    if (s.getTipoSocio() == 1) {
        limite = 2;
    } else if (s.getTipoSocio() == 2) {
        limite = 3;
    } else {
        limite = 99; // Para Premium o cualquier otro plan
    }

    // 3. Validar límite de actividades
    if(contarActividadesSocio(idSocio) >= limite) {
        cout << "Limite de actividades alcanzado para este plan." << endl;
        return;
    }

    cout << "\n--- ACTIVIDADES DISPONIBLES ---" << endl;
    archivoActividades arcAct;
    int cantAct = arcAct.contarRegistros();
    for(int i = 0; i < cantAct; i++) {
        actividad aux = arcAct.leerRegistros(i);
        if(aux.getEstado()) {
            cout << "ID: " << aux.getIdactividad() << " | Nombre: " << aux.getNombreActividad() << endl;
        }
    }

    int idAct;
    bool actividadValida = false;

    // Bucle de validación para que el usuario no pueda seguir hasta poner un ID real
    while(!actividadValida) {
        cout << "\nINGRESE ID ACTIVIDAD: ";
        cin >> idAct;

        if(arcAct.estadoActividad(idAct)) {
            actividadValida = true;
        } else {
            cout << "ERROR: El ID de actividad no existe o no está activo. Intente nuevamente." << endl;
        }
    }

    // Validar si ya está inscrito
    archivoActividadesSocio arc;
    if(arc.buscarActividadSocio(idSocio, idAct) != -1) {
        cout << "El socio ya se encuentra inscripto en esta actividad." << endl;
        return;
    }

    // Grabar
    actividadSocio nueva;
    nueva.setIdSocio(idSocio);
    nueva.setIdactividad(idAct);
    nueva.setEstado(true);

    if(arc.grabarRegistro(nueva)) {
        cout << "Inscripcion realizada con exito." << endl;
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
            cout << "Pos: " << i << " | ID Actividad: " << aux.getIdactividad() << endl;
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
    cout << "INGRESE ID DEL SOCIO A MODIFICAR: ";
    cin >> idSocio;

    archivoActividadesSocio arc;
    int cant = arc.contarRegistros();
    bool tieneActividades = false;

    // 1. Mostrar actividades actuales
    cout << "\nACTIVIDADES ACTUALES DEL SOCIO:" << endl;
    for(int i = 0; i < cant; i++) {
        actividadSocio aux = arc.leerRegistro(i);
        if(aux.getIdSocio() == idSocio && aux.getEstado()) {
            cout << "[" << i << "] ID Actividad: " << aux.getIdactividad() << endl;
            tieneActividades = true;
        }
    }

    if(!tieneActividades) {
        cout << "EL SOCIO NO TIENE ACTIVIDADES ACTIVAS." << endl;
        return;
    }

    // 2. Elegir actividad
    int pos;
    cout << "\nINGRESE LA POSICION DE LA ACTIVIDAD A MODIFICAR: ";
    cin >> pos;

    actividadSocio obj = arc.leerRegistro(pos);

    // 3. Baja lógica
    if(obj.getIdSocio() == idSocio && obj.getEstado()) {
        obj.setEstado(false);
        arc.modificarRegistro(obj, pos);

        cout << "ACTIVIDAD DADA DE BAJA. AHORA SELECCIONE LA NUEVA:" << endl;

        // 4. Llamar al alta para que el usuario elija la nueva
        altaActividadSocio();
    } else {
        cout << "POSICION INVALIDA O NO ENCONTRADA." << endl;
    }
}
void listarActividadSocio() {

    archivoActividadesSocio arc;
    archivoSocio arcSocio;
    int cant = arc.contarRegistros();

    cout << "--- LISTADO DE ACTIVIDADES POR SOCIO ---" << endl;

    // Recorremos socios para agrupar
    for(int i = 0; i < arcSocio.contarRegistros(); i++) {
        socio s = arcSocio.leerRegistros(i);
        bool tieneActividades = false;

        // Buscamos actividades para este socio
        for(int j = 0; j < cant; j++) {
            actividadSocio ins = arc.leerRegistro(j);
            if(ins.getIdSocio() == s.getIdsocio() && ins.getEstado()) {
                if(!tieneActividades) {
                    cout << "\nSOCIO: " << s.getNombre() << " " << s.getApellido() << " (ID: " << s.getIdsocio() << ")" << endl;
                    tieneActividades = true;
                }
                ins.mostrar(); // Esto mostrará el ID y el nombre de la actividad
            }
        }
    }
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
