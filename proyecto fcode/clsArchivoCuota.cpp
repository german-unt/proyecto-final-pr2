#include <iostream>
#include <cstring>
#include"clsArchivoCuota.h"

using namespace std;

archivoCuota::archivoCuota(const char *n){
strcpy(nombre,n);
}

cuota archivoCuota::leerRegistro(int pos){
FILE *p = fopen(nombre, "rb");
cuota obj;
if(p==nullptr){
    obj.setCuota(-2);
    return obj;
}
obj.setCuota(-1);
fseek(p, sizeof obj * pos, 0);
fread(&obj, sizeof obj, 1, p);
fclose(p);
return obj;
}

bool archivoCuota::modificarRegistro(cuota obj,int pos){
FILE *p = fopen(nombre, "rb+");
if(p == nullptr) return false;
fseek(p, sizeof obj * pos, 0);
bool escribio = fwrite(&obj, sizeof obj, 1, p);
fclose(p);
return escribio;
}

bool archivoCuota::grabarRegistro(cuota obj){
 FILE *p = fopen(nombre, "ab");
 if(p == nullptr) return false;
 bool escribio = fwrite(&obj, sizeof obj, 1, p);
 fclose(p);
 return escribio;

}

int archivoCuota::contarRegistros(){
FILE *p = fopen(nombre, "rb");
if(p == nullptr) return -1;
fseek(p, 0, 2);
int cant = ftell(p)/sizeof(cuota);
fclose(p);
return cant;
}

int archivoCuota::buscarRegistros(int legajo){
int cantReg = contarRegistros();
for(int i=0; i<cantReg; i++){
    cuota obj = leerRegistro(i);
    if(obj.getCuota()==legajo){
        return i;
    }
}
return -1;

}

void archivoCuota::listarRegistros(){
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        cuota obj = leerRegistro(i);
        if(obj.getEliminado()){
            obj.mostrar();
            cout<<endl;
        }
    }
}
