#include<iostream>
#include"clsActividadSocio.h"
#include"funciones.h"
#include "clsArchivoSocio.h"
#include "clsFecha.h"
using namespace std;

void actividadSocio::cargar() {
    blanco();
    cout << "INGRESE EL ID DE SOCIO: ";
    cin >> idSocio;

    cout << "INGRESE EL ID DE ACTIVIDAD: ";
    cin >> idActividad;

    cin.ignore();

    // Bucle de validación para la fecha de alta
    while (true) {
        cout << "INGRESE LA FECHA DE ALTA: " << endl;
        fechaAlta.Cargar();

        if (fechaAlta.getAnio() >= 2020) {
            break;
        }
        rojo();
        cout << "ERROR: LA FECHA DE ALTA NO PUEDE SER MENOR AL ANIO 2020. REINTENTE." << endl << endl;
        blanco();
    }

    estado = true;
}

void actividadSocio::mostrar() {
    blanco();
    archivoActividades arcAct;
    int pos = arcAct.buscarRegistros(idActividad);
    actividad act = arcAct.leerRegistros(pos);

    cout << "ID ACTIVIDAD: " << idActividad << " | NOMBRE: " << act.getNombreActividad() << endl;
    cout<< "FECHA DE INSCRIPCION: ";
    fechaAlta.Mostrar();
    cout<<endl;
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
