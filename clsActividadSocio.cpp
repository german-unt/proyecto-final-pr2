#include<iostream>
#include"clsActividadSocio.h"
#include"funciones.h"
#include "clsArchivoSocio.h"
using namespace std;

void actividadSocio::cargar() {
    cout << "INGRESE EL ID DE SOCIO: ";
    cin >> idSocio;

    // Aquí el Manager ya debería haber validado que el socio existe.
    // Solo pedimos el ID de la actividad (la validación de si puede inscribirse
    // se hace en el Manager ANTES de llamar a este cargar).
    cout << "INGRESE EL ID DE ACTIVIDAD: ";
    cin >> idActividad;

    cout << "INGRESE LA FECHA DE ALTA: " << endl;
    fechaAlta.Cargar();

    // La fecha de baja usualmente empieza vacía o nula al dar el alta
    estado = true;
}

void actividadSocio::mostrar() {
    // Para mostrar el nombre de la actividad, necesitamos el archivo de actividades
    archivoActividades arcAct;
    int pos = arcAct.buscarRegistros(idActividad); // Asumiendo que tu clase tiene este método
    actividad act = arcAct.leerRegistros(pos);

    cout << "ID ACTIVIDAD: " << idActividad << " | NOMBRE: " << act.getNombreActividad() << endl;
}
void actividadSocio::setIdactividad(int id){idActividad=id;}
void actividadSocio::setIdSocio(int s){idSocio=s;}
void actividadSocio::setFechaAlta(Fecha a){fechaAlta=a;}
void actividadSocio::setFechaBaja(Fecha b){fechaBaja=b;}
void actividadSocio::setEstado(bool e){estado=e;}

int actividadSocio::getIdactividad(){return idActividad;}
int actividadSocio::getIdSocio(){return idSocio;}
Fecha actividadSocio::getFechaAlta(){return fechaAlta;}
Fecha actividadSocio::getFechaBaja(){return fechaBaja;}
bool actividadSocio::getEstado(){return estado;}
