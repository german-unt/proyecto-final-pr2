#include <iostream>
#include <cstring>
#include "clsArchivoActividades.h"
#include"funciones.h"

using namespace std;

archivoActividades::archivoActividades(const char *n){
strcpy(nombre,n);
}

 actividad archivoActividades::leerRegistros(int pos){
  FILE *p = fopen(nombre, "rb");
  actividad obj;
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

 bool archivoActividades::modificarRegistros(actividad obj,int pos){
 FILE *p = fopen(nombre, "rb+");
if(p == nullptr) return false;
fseek(p, sizeof obj * pos, 0);
bool escribio = fwrite(&obj, sizeof obj, 1, p);
fclose(p);
return escribio;

 }

 bool archivoActividades::grabarRegistros(actividad obj){
  FILE *p = fopen(nombre, "ab");
 if(p == nullptr) return false;
 bool escribio = fwrite(&obj, sizeof obj, 1, p);
 fclose(p);
 return escribio;
 }

 int archivoActividades::contarRegistros(){
  FILE *p = fopen(nombre, "rb");
 if(p == nullptr) return -1;
 fseek(p, 0, 2);
 int cant = ftell(p)/sizeof(actividad);
 fclose(p);
 return cant;
 }

 int archivoActividades::buscarRegistros(int legajo){
  int cantReg = contarRegistros();
 for(int i=0; i<cantReg; i++){
     actividad obj = leerRegistros(i);
     if(obj.getIdactividad()==legajo){
         return i;
     }
 }
 return -1;

 }
 void archivoActividades::listarRegistros(){
 int cantReg = contarRegistros();
for(int i=0; i<cantReg; i++){
    actividad obj = leerRegistros(i);
    if(obj.getEliminado()){
        obj.mostrar();
        cout<<endl;
    }
}
 }
