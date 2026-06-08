#include<iostream>
#include"cargarCadena.h"
#include<cstring>
#include"clsSede.h"
using namespace std;

void sede::cargar(int id){
    if(id == -1){
        cout<<"INGRESE EL ID de sede: ";
        cin>>idSede;
    }else{
        idSede = id;
    }
cout<<"INGRESE EL NOMBRE DE LA SEDE: ";
cargarCadena(nombreSede,50);
cout<<"INGRESE LA DIRECCION DE LA SEDE: ";
cargarCadena(direccion,100);
cout<<"INGRESE EL TIPO DE ACTIVIDAD";
cin>>tipoActividad;
eliminado=true;
}

void sede::mostrar(){
cout<<"ID SEDE: "<<idSede<<endl;
cout<<"SEDE: "<<nombreSede<<endl;
cout<<"DIRECCION: "<<direccion<<endl;
cout<<"TIPO ACTIVIDAD: "<<tipoActividad<<endl;

}

void sede::setIdsede(int s){idSede=s;}
void sede::setNombresede(char* n){strcpy(nombreSede,n);}
void sede::setDireccion(char* d){strcpy(direccion,d);}
void sede::setTipoactividad(int t){tipoActividad=t;}
void sede::setEliminado(bool e){eliminado=e;}

int sede::getIdsede(){return idSede;}
char* sede::getNombresede(){return nombreSede;}
char*sede::getDireccion(){return direccion;}
int sede::getTipoactividad(){return tipoActividad;}
bool sede::getEliminado(){return eliminado;}
