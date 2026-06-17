#include<iostream>
#include"clsActividadSocio.h"
#include"funciones.h"
#include "clsArchivoSocio.h"
using namespace std;

void actividadSocio::cargar(){
cout<<"INGRESE EL ID DE SOCIO: ";
cin>>idSocio;
archivoSocio arcSocio;
int pos = arcSocio.buscarRegistros(idSocio);
if(pos<0){
cout<<"SOCIO NO ENCONTRADO"<<endl;
    return;
}
socio obj = arcSocio.leerRegistros(pos);
if(obj.getTipoSocio()==1){

cout<<"ACTIVIDADES DISPONIBLES"<<endl;
cout<<"1 - FUTBOL"<<endl;
cout<<"2 - VOLEY"<<endl;

while(true){

cout<<"INGRESE EL ID DE ACTIVIDAD: ";
cin>>idActividad;

if(idActividad==1 || idActividad==2){
            break;
        }

cout<<"ESA ACTIVIDAD NO ESTA DISPONIBLE PARA SU PLAN"<<endl;
    }
}
else if(obj.getTipoSocio()==2){
 cout<<"ACTIVIDADES DISPONIBLES"<<endl;
 cout<<"1 - FUTBOL"<<endl;
 cout<<"2 - VOLEY"<<endl;
 cout<<"3 - HOCKEY"<<endl;
 cout<<"4 - RUGBY"<<endl;

while(true){
cout<<"INGRESE EL ID DE ACTIVIDAD: ";
cin>>idActividad;
if(idActividad>=1 && idActividad<=4){
    break;
}
    cout<<"ESA ACTIVIDAD NO ESTA DISPONIBLE PARA SU PLAN"<<endl;
    }
}
else if(obj.getTipoSocio()==3){
cout<<"ACTIVIDADES DISPONIBLES"<<endl;
cout<<"1 - FUTBOL"<<endl;
cout<<"2 - VOLEY"<<endl;
cout<<"3 - HOCKEY"<<endl;
cout<<"4 - RUGBY"<<endl;
cout<<"5 - NATACION"<<endl;

while(true){
cout<<"INGRESE EL ID DE ACTIVIDAD: ";
cin>>idActividad;

if(idActividad>=1 && idActividad<=5){
    break;
}

cout<<"ID DE ACTIVIDAD INVALIDO"<<endl;
    }
}
cout<<"INGRESE LA FECHA DE ALTA: ";
fechaAlta.Cargar();
cout<<"INGRESE LA FECHA DE BAJA: ";
fechaBaja.Cargar();
estado=true;
}

void actividadSocio::mostrar(){
cout<<"ID ACTIVIDAD: "<<idActividad<<endl;
cout<<"ID SOCIO: "<<idSocio<<endl;
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
