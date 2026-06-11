#include <iostream>
#include <cstring>
#include"clsArchivoSocio.h"

using namespace std;

archivoSocio::archivoSocio(const char *n){
strcpy(nombre,n);

}

socio archivoSocio::leerRegistros(int pos){
FILE *p=fopen(nombre,"rb");
socio obj;
if(p==nullptr){obj.setIdSocio(-2);
    return obj;
  }
obj.setIdSocio(-1);
fseek(p,sizeof obj * pos, 0);
fread(&obj,sizeof obj, 1,p);
fclose(p);
return obj;
}

bool archivoSocio::modificarRegistro(socio obj, int pos){
FILE *p=fopen(nombre,"rb+");
if(p==nullptr){return false;}
fseek(p, sizeof obj * pos, 0);
bool escribio = fwrite(&obj, sizeof obj, 1, p);
fclose(p);
return escribio;
}

bool archivoSocio::grabarRegistros(socio obj){
 FILE *p = fopen(nombre, "ab");
 if(p == nullptr) return false;
 bool escribio = fwrite(&obj, sizeof obj, 1, p);
 fclose(p);
 return escribio;
}

int archivoSocio::contarRegistros(){
FILE *p = fopen(nombre, "rb");
if(p == nullptr) return -1;
fseek(p, 0, 2);
int cant = ftell(p)/sizeof(socio);
fclose(p);
return cant;
}

int archivoSocio::buscarRegistros(int legajo){
 int cantReg = contarRegistros();
 for(int i=0; i<cantReg; i++){
     socio obj = leerRegistros(i);
     if(obj.getIdsocio()==legajo){
         return i;
     }
 }
 return -1;

}

void archivoSocio::listarRegistros(){

 int cantReg = contarRegistros();
 for(int i=0; i<cantReg; i++){
     socio obj = leerRegistros(i);
     if(obj.getEstado()){
         obj.mostrar();
         cout<<endl;
     }
 }
}
