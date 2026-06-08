#include<iostream>
#include"clsActividadSocio.h"
#include"funciones.h"
using namespace std;

void actividadSocio::cargar(){
cout<<"INGRESE EL ID DE ACTIVIDAD: ";
cin>>idActividad;
cout<<"INGRESE EL ID DEL SOCIO: ";
cin>>idSocio;
cout<<"INGRESE LA POSICION DE JUEGO: ";
cin>>posicionDeJuego;
cout<<"INGRESE LA FECHA DE ALTA: ";
fechaAlta.Cargar();
cout<<"INGRESE LA FECHA DE BAJA: ";
fechaBaja.Cargar();
eliminado=true;
}

void actividadSocio::mostrar(){
cout<<"ID ACTIVIDAD: "<<idActividad<<endl;
cout<<"ID SOCIO: "<<idSocio<<endl;
cout<<"POSICION DE JUEGO: "<<posicionDeJuego<<endl;
cout<<"FECHA ALTA: ";
fechaAlta.Mostrar();
cout<<"FECHA BAJA: ";
fechaBaja.Mostrar();
}
void actividadSocio::setIdactividad(int id){idActividad=id;}
void actividadSocio::setIdsocio(int s){idSocio=s;}
void actividadSocio::setPosicion(int p){posicionDeJuego=p;}
void actividadSocio::setFechaAlta(Fecha a){fechaAlta=a;}
void actividadSocio::setFechaBaja(Fecha b){fechaBaja=b;}
void actividadSocio::setEliminado(bool e){eliminado=e;}

int actividadSocio::getIdactividad(){return idActividad;}
int actividadSocio::getIdsocio(){return idSocio;}
int actividadSocio::getPosicion(){return posicionDeJuego;}
Fecha actividadSocio::getFechaAlta(){return fechaAlta;}
Fecha actividadSocio::getFechaBaja(){return fechaBaja;}
bool actividadSocio::getEliminado(){return eliminado;}
