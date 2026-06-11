#include<iostream>
#include"clsActividadSocio.h"
#include"funciones.h"
using namespace std;

void actividadSocio::cargar(){
cout<<"INGRESE EL ID DE ACTIVIDAD: ";
cin>>idActividad;
cout<<"INGRESE EL ID DE SOCIO: ";
cin>>idSocio;
cout<<"INGRESE LA FECHA DE ALTA: ";
fechaAlta.Cargar();
cout<<"INGRESE LA FECHA DE BAJA: ";
fechaBaja.Cargar();
estado=true;
}

void actividadSocio::mostrar(){
cout<<"ID ACTIVIDAD: "<<idActividad<<endl;
cout<<"ID SOCIO: "<<idSocio<<endl;
cout<<"FECHA ALTA: ";
fechaAlta.Mostrar();
cout<<"FECHA BAJA: ";
fechaBaja.Mostrar();
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
