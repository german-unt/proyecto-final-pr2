#include<iostream>
#include"clsActividad.h"
#include"cargarCadena.h"
#include<cstring>
using namespace std;

void actividad::cargar(int id){
    if(id == -1){
        cout<<"INGRESE EL ID de Actividad: ";
        cin>>idActividad;
    }else{
        idActividad = id;
    }
cout<<"INGRESE EL ID DE SEDE: ";
cin>>idSede;
cout<<"INGRESE EL NOMBRE DE LA ACTIVIDAD: ";
cargarCadena(nombreActividad,20);
eliminado=true;
}

void actividad::mostrar(){
cout<<"ID DE ACTIVIDAD: "<<idActividad<<endl;
cout<<"ID DE SEDE: "<<idSede<<endl;
cout<<"ACTIVIDAD: "<<nombreActividad<<endl;
}

void actividad::setIdactividad(int a){idActividad=a;}
void actividad::setIdsede(int s){idSede=s;}
void actividad::setNombreactividad(char* n){strcpy(nombreActividad,n);}
void actividad::setEliminado(bool e){eliminado=e;}

int actividad::getIdactividad(){return idActividad;}
int actividad::getIdSede(){return idSede;}
char* actividad::getNombreActividad(){return nombreActividad;}
bool actividad::getEliminado(){return eliminado;}
