#include<iostream>
#include"clsActividad.h"
#include"cargarCadena.h"
#include<cstring>
using namespace std;

void actividad::cargar(int id){
    if(id == -1){
        cout << "INGRESE EL ID de Actividad: ";
        cin >> idActividad;
        cin.ignore();
    } else {
        idActividad = id;
    }

    while(true) {
        cout << "INGRESE EL NOMBRE DE LA ACTIVIDAD: ";
        cargarCadena(nombreActividad, 20);

        bool tieneNumeros = false;

        // Recorremos la cadena buscando dígitos numéricos
        for(int i = 0; nombreActividad[i] != '\0'; i++) {
            if(nombreActividad[i] >= '0' && nombreActividad[i] <= '9') {
                tieneNumeros = true;
            }
        }

        // Si no se encontraron números y la cadena no está vacía, es válida
        if(!tieneNumeros && nombreActividad[0] != '\0') {
            break; // Rompe el while e ingresa con éxito
        }

        cout << "ERROR: EL NOMBRE DE LA ACTIVIDAD NO PUEDE TENER NUMEROS O ESTAR VACIO " << endl;
    }

    estado = true;
}

void actividad::mostrar(){
cout<<"ID DE ACTIVIDAD: "<<idActividad<<endl;
cout<<"ACTIVIDAD: "<<nombreActividad<<endl;
}

void actividad::setIdactividad(int a){idActividad=a;}
void actividad::setNombreactividad(char* n){strcpy(nombreActividad,n);}
void actividad::setEstado(bool e){estado=e;}

int actividad::getIdactividad(){return idActividad;}
char* actividad::getNombreActividad(){return nombreActividad;}
bool actividad::getEstado(){return estado;}
