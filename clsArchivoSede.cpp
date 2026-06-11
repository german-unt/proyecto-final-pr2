#include <iostream>
#include <cstring>
#include"clsArchivoSede.h"

using namespace std;

archivoSede::archivoSede(const char *n){
strcpy(nombre,n);
}
sede archivoSede::leerRegistro(int pos){
  FILE *p = fopen(nombre, "rb");
  sede obj;
  if(p == nullptr){
    obj.setIdsede(-2);
    return obj;
}
obj.setIdsede(-1);
fseek(p, sizeof obj * pos, 0);
fread(&obj, sizeof obj, 1, p);
fclose(p);
return obj;

}

bool archivoSede::modificarRegistro(sede obj, int pos){
 FILE *p = fopen(nombre, "rb+");
 if(p == nullptr) return false;
 fseek(p, sizeof obj * pos, 0);
 bool escribio = fwrite(&obj, sizeof obj, 1, p);
 fclose(p);
 return escribio;
}

bool archivoSede::grabarRegistro(sede obj){
FILE *p = fopen(nombre, "ab");
if(p == nullptr) return false;
bool escribio = fwrite(&obj, sizeof obj, 1, p);
fclose(p);
return escribio;

}
int archivoSede::contarRegistro(){
FILE *p = fopen(nombre, "rb");
if(p == nullptr) return -1;
fseek(p, 0, 2);
int cant = ftell(p)/sizeof(sede);
fclose(p);
return cant;
}
int  archivoSede::buscarRegistro(int legajo){
int cantReg = contarRegistro();
for(int i=0; i<cantReg; i++){
    sede obj = leerRegistro(i);
    if(obj.getIdsede()==legajo){
        return i;
    }
}
return -1;
}

void archivoSede::listarRegistro(){
int cantReg = contarRegistro();
for(int i=0; i<cantReg; i++){
    sede obj = leerRegistro(i);
    if(obj.getEstado()){
        obj.mostrar();
        cout<<endl;
    }
}

}
