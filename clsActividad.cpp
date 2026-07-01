#include<iostream>
#include"clsActividad.h"
#include"cargarCadena.h"
#include<cstring>
#include"estetico.h"
using namespace std;

void actividad::cargar(int id){
    if(id == -1){
        blanco();
        cout << "INGRESE EL ID DE ACTIVIDAD: ";
        cin >> idActividad;
        cin.ignore();
    } else {
        idActividad = id;
    }

    while(true) {
        blanco();
        cout << "INGRESE EL NOMBRE DE LA ACTIVIDAD: ";
        cargarCadena(nombreActividad, 20);

        bool tieneNumeros = false;

        // RECORREMOS LA CADENA BUSCANDO DIGITOS NUMERICOS
        for(int i = 0; nombreActividad[i] != '\0'; i++) {
            if(nombreActividad[i] >= '0' && nombreActividad[i] <= '9') {
                tieneNumeros = true;
            }
        }

        // SI NO SE ENCONTRARON NUMEROS Y LA CADENA NO ESTA VACIA, ES VALIDA
        if(!tieneNumeros && nombreActividad[0] != '\0') {
            break; // ROMPE EL WHILE E INGRESA CON EXITO
        }

        rojo();
        cout << "ERROR: EL NOMBRE DE LA ACTIVIDAD NO PUEDE TENER NUMEROS O ESTAR VACIO" << endl;
        blanco();
    }

    estado = true;
}

void actividad::mostrar(){
    blanco();
    cout << "ID DE ACTIVIDAD: ";
    amarillo();
    cout << idActividad << endl;

    blanco();
    cout << "ACTIVIDAD: " << nombreActividad << endl;
}

void actividad::setIdactividad(int a){idActividad=a;}
void actividad::setNombreactividad(char* n){strcpy(nombreActividad,n);}
void actividad::setEstado(bool e){estado=e;}

int actividad::getIdactividad(){return idActividad;}
char* actividad::getNombreActividad(){return nombreActividad;}
bool actividad::getEstado(){return estado;}
