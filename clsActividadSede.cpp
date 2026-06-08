#include<iostream>
#include"clsActividadSede.h"
#include"funciones.h"
using namespace std;

void actividadSede::cargar(){
cout<<"INGRESE EL ID DE ACTIVIDAD: ";
cin>>idActividad;
cout<<"INGRESE EL ID DE SEDE: ";
cin>>idSede;
cout<<"INGRESE LA POSICION DE JUEGO: ";
cin>>posicionDeJuego;
cout<<"INGRESE LA FECHA DE ALTA: ";
fechaAlta.Cargar();
cout<<"INGRESE LA FECHA DE BAJA: ";
fechaBaja.Cargar();
eliminado=true;
}

void actividadSede::mostrar(){
cout<<"ID ACTIVIDAD: "<<idActividad<<endl;
cout<<"ID SEDE: "<<idSede<<endl;
cout<<"POSICION DE JUEGO: "<<posicionDeJuego<<endl;
cout<<"FECHA ALTA: ";
fechaAlta.Mostrar();
cout<<"FECHA BAJA: ";
fechaBaja.Mostrar();
}
void actividadSede::setIdactividad(int id){idActividad=id;}
void actividadSede::setIdsede(int s){idSede=s;}
void actividadSede::setPosicion(int p){posicionDeJuego=p;}
void actividadSede::setFechaAlta(Fecha a){fechaAlta=a;}
void actividadSede::setFechaBaja(Fecha b){fechaBaja=b;}
void actividadSede::setEliminado(bool e){eliminado=e;}

int actividadSede::getIdactividad(){return idActividad;}
int actividadSede::getIdsede(){return idSede;}
int actividadSede::getPosicion(){return posicionDeJuego;}
Fecha actividadSede::getFechaAlta(){return fechaAlta;}
Fecha actividadSede::getFechaBaja(){return fechaBaja;}
bool actividadSede::getEliminado(){return eliminado;}
