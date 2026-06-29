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
        cout<<"======================="<<endl;
        cout<<"1 - INSCRIBIR SOCIO"<<endl;
        cout<<"2 - DAR DE BAJA INSCRIPCION"<<endl;
        cout<<"3 - MODIFICAR INSCRIPCION"<<endl;
        cout<<"4 - LISTAR INSCRIPCIONES"<<endl;
        cout<<"0 - VOLVER"<<endl;
        cout<<"======================="<<endl;
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

        system("pause");
    }
}
void altaActividadSocio() {
    int idSocio;
    cout << "INGRESE ID SOCIO: ";
    cin >> idSocio;

    // 1. Validar existencia y estado del socio
    archivoSocio arcSocio;
    int posSocio = arcSocio.buscarRegistros(idSocio);
    if(posSocio < 0) {
        cout << "Socio no existe." << endl;
        return;
    }
    socio objSocio = arcSocio.leerRegistros(posSocio);

    if (!objSocio.getEstado()) {
        cout << "ERROR: El socio se encuentra inactivo." << endl;
        return;
    }

    // 2. Determinar el límite por plan
    int limite;
    if (objSocio.getTipoSocio() == 1) {
        limite = 2;
    } else if (objSocio.getTipoSocio() == 2) {
        limite = 3;
    } else {
        limite = 99;
    }

    // 3. Validar límite de actividades
    if(contarActividadesSocio(idSocio) >= limite) {
        cout << "Limite de actividades alcanzado para este plan." << endl;
        return;
    }

    // 4. Listar actividades disponibles
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

    // 5. Validar que el ID de actividad ingresado exista de verdad
    while(!actividadValida) {
        cout << "\nINGRESE ID ACTIVIDAD: ";
        cin >> idAct;

        if(arcAct.estadoActividad(idAct)) {
            actividadValida = true;
        } else {
            cout << "ERROR: El ID de actividad no existe o no esta activo. Intente nuevamente." << endl;
        }
    }

    // 6. Validar si ya está inscrito a esa actividad específica
    archivoActividadesSocio arcInscripciones;
    if(arcInscripciones.buscarActividadSocio(idSocio, idAct) != -1) {
        cout << "El socio ya se encuentra inscripto en esta actividad." << endl;
        return;
    }

    // 7. Preparación de la inscripción y carga con objeto auxiliar Fecha
    actividadSocio nueva;
    nueva.setIdSocio(idSocio);
    nueva.setIdactividad(idAct);
    nueva.setEstado(true);

    // Limpiamos el buffer del cin anterior antes de llamar a la carga de la fecha
    cin.ignore();

    cout << "\nINGRESE LA FECHA DE INSCRIPCION (ALTA):" << endl;
    Fecha fAlta; // Creamos el objeto auxiliar de tipo Fecha
    fAlta.Cargar(); // Invocamos el método Cargar propio de la clase Fecha
    nueva.setFechaAlta(fAlta); // Pasamos la fecha cargada al objeto inscripción

    // 8. Grabar nueva inscripción en el archivo binario
    if(arcInscripciones.grabarRegistro(nueva)) {
        cout << "\nInscripcion realizada con exito." << endl;
    } else {
        cout << "\nError al grabar la inscripcion." << endl;
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
archivoActividadesSocio arcInscripciones;
    archivoSocio arcSocio;
    int cantInscripciones = arcInscripciones.contarRegistros();

    cout << "--- LISTADO DE ACTIVIDADES POR SOCIO (SOLO SOCIOS ACTIVOS) ---" << endl;

    // Recorremos socios para agrupar
    for(int i = 0; i < arcSocio.contarRegistros(); i++) {
        socio objSocio = arcSocio.leerRegistros(i);

        // VALIDACIÓN: Solo procesamos socios que estén activos
        if (!objSocio.getEstado()) {
            continue; // Si el socio está dado de baja, saltamos al siguiente
        }

        bool tieneActividades = false;

        // Buscamos actividades para este socio
        for(int j = 0; j < cantInscripciones; j++) {
            actividadSocio objInscripcion = arcInscripciones.leerRegistro(j);

            // Verificamos que sea el socio, que la inscripción esté activa y el socio activo
            if(objInscripcion.getIdSocio() == objSocio.getIdsocio() && objInscripcion.getEstado()) {

                if(!tieneActividades) {
                    cout << "\nSOCIO: " << objSocio.getNombre() << " " << objSocio.getApellido()
                         << " (ID: " << objSocio.getIdsocio() << ")" << endl;
                    tieneActividades = true;
                }

                objInscripcion.mostrar(); // Muestra la actividad del socio activo
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
