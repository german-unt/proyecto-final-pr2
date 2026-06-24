#include <iostream>
#include <cstring>
#include "clsArchivoActividadesSocio.h"
using namespace std;

archivoActividadesSocio::archivoActividadesSocio(const char*n){
strcpy(nombre,n);
}
actividadSocio archivoActividadesSocio::leerRegistro(int pos){
FILE *p = fopen(nombre, "rb");
 actividadSocio obj;
if(p == nullptr){
    obj.setIdactividad(-2);
    return obj;
}
obj.setIdactividad(-1);
fseek(p, sizeof obj * pos, 0);
fread(&obj, sizeof obj, 1, p);
fclose(p);
return obj;
}

bool archivoActividadesSocio::modificarRegistro(actividadSocio obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) return false;
    fseek(p, sizeof obj * pos, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool archivoActividadesSocio::grabarRegistro(actividadSocio obj){
 FILE *p = fopen(nombre, "ab");
 if(p == nullptr) return false;
 bool escribio = fwrite(&obj, sizeof obj, 1, p);
 fclose(p);
 return escribio;
}

int archivoActividadesSocio::contarRegistros(){
 FILE *p = fopen(nombre, "rb");
 if(p == nullptr) return -1;
 fseek(p, 0, 2);
 int cant = ftell(p)/sizeof(actividadSocio);
 fclose(p);
 return cant;
}

int archivoActividadesSocio::buscarRegistro(int legajo){
int cantReg = contarRegistros();
for(int i=0; i<cantReg; i++){
    actividadSocio obj = leerRegistro(i);
    if(obj.getIdactividad()==legajo){
        return i;
    }
}
return -1;
}

void archivoActividadesSocio::listarRegistros(){
int cantReg = contarRegistros();
for(int i=0; i<cantReg; i++){
    actividadSocio obj = leerRegistro(i);
    if(obj.getEstado()){
        obj.mostrar();
        cout<<endl;
    }
}
}


int archivoActividadesSocio::buscarRegistroSocio(int idSocio){

    int cantReg = contarRegistros();

    for(int i=0;i<cantReg;i++){

        actividadSocio obj = leerRegistro(i);

        if(obj.getIdSocio()==idSocio){
            return i;
        }
    }

    return -1;
}


int archivoActividadesSocio::buscarActividadSocio(int idSocio, int idActividad) {
    int cant = contarRegistros();
    for(int i = 0; i < cant; i++) {
        actividadSocio aux = leerRegistro(i);
        if(aux.getIdSocio() == idSocio && aux.getIdactividad() == idActividad && aux.getEstado()) {
            return i; // Encontró la inscripción activa
        }
    }
    return -1;
}
