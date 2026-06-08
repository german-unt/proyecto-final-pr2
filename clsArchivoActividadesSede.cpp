#include <iostream>
#include <cstring>
#include "clsArchivoActividadesSede.h"
using namespace std;

archivoActividadesSede::archivoActividadesSede(const char*n){
strcpy(nombre,n);
}
actividadSede archivoActividadesSede::leerRegistro(int pos){
FILE *p = fopen(nombre, "rb");
 actividadSede obj;
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

bool archivoActividadesSede::modificarRegistro(actividadSede obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) return false;
    fseek(p, sizeof obj * pos, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool archivoActividadesSede::grabarRegistro(actividadSede obj){
 FILE *p = fopen(nombre, "ab");
 if(p == nullptr) return false;
 bool escribio = fwrite(&obj, sizeof obj, 1, p);
 fclose(p);
 return escribio;
}

int archivoActividadesSede::contarRegistros(){
 FILE *p = fopen(nombre, "rb");
 if(p == nullptr) return -1;
 fseek(p, 0, 2);
 int cant = ftell(p)/sizeof(actividadSede);
 fclose(p);
 return cant;
}

int archivoActividadesSede::buscarRegistro(int legajo){
int cantReg = contarRegistros();
for(int i=0; i<cantReg; i++){
    actividadSede obj = leerRegistro(i);
    if(obj.getIdactividad()==legajo){
        return i;
    }
}
return -1;
}

void archivoActividadesSede::listarRegistros(){
int cantReg = contarRegistros();
for(int i=0; i<cantReg; i++){
    actividadSede obj = leerRegistro(i);
    if(obj.getEliminado()){
        obj.mostrar();
        cout<<endl;
    }
}
}
