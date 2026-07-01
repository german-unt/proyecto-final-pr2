#include<iostream>
#include"clsSocio.h"
#include <cstring>
#include "funciones.h"
#include "cargarCadena.h"
using namespace std;
void socio::cargar(int id){
blanco();
    if(id == -1){
        cout<<"INGRESE EL ID DE SOCIO: ";
        cin>>idSocio;
    }else{
        idSocio = id;
    }
cout<<"INGRESE EL NOMBRE: ";
cargarCadena(nombre,20);
cout<<"INGRESE EL APELLIDO: ";
cargarCadena(apellido,20);
while(true){
cout<<"INGRESE EL TELEFONO: ";
cargarCadena(telefono,15);

bool valido=true;

for(int i=0; telefono[i]!='\0'; i++){

if(telefono[i]<'0' || telefono[i]>'9'){
    valido=false;
    }
}
if(valido){
    break;
    }
amarillo();
cout<<"EL TELEFONO SOLO PUEDE CONTENER NUMEROS"<<endl;
blanco();
}
cout<<"INGRESE LA FECHA DE NACIMIENTO: "<<endl;
fechaNacimiento.Cargar();
cout<<"TIPOS DE SOCIO"<<endl;
cout<<"1 - BASICO"<<endl;
cout<<"2 - INTERMEDIO"<<endl;
cout<<"3 - PREMIUM"<<endl;

while(true){
cout<<"INGRESE EL TIPO DE SOCIO: ";
cin>>tipoSocio;

if(tipoSocio>=1 && tipoSocio<=3){
    break;
    }
rojo();
cout<<"ERROR: TIPO DE SOCIO INVALIDO"<<endl;
blanco();
}
while(true){

cout<<"INGRESE EL EMAIL: ";
cargarCadena(email,50);

bool tieneArroba=false;

for(int i=0; email[i]!='\0'; i++){

if(email[i]=='@'){
    tieneArroba=true;
    }
}

if(tieneArroba){
    break;
}
amarillo();
cout<<"EL EMAIL DEBE CONTENER @. REINGRESE MAIL"<<endl;
blanco();
}
estado=true;
}

void socio::mostrar(){
blanco();
cout<<"ID DEL SOCIO: "<<idSocio<<endl<<endl;
cout<<"NOMBRE: "<<nombre<<endl<<endl;
cout<<"APELLIDO: "<<apellido<<endl;
cout<<endl;
cout<<"TELEFONO: "<<telefono<<endl;
cout<<endl;
cout<<"FECHA DE NACIMIENTO: ";
cout<<endl;
fechaNacimiento.Mostrar();
cout<<endl;
cout<<endl;
cout<<"TIPO DE SOCIO: ";
cout<<endl;

if(tipoSocio==1){
cout<<"BASICO";
}
else if(tipoSocio==2){
cout<<"INTERMEDIO";
}
else{
cout<<"PREMIUM";
}
cout<<endl;
cout<<endl;

cout<<"EMAIL: "<<email<<endl;
}


void socio::setIdSocio(int id){
idSocio=id;
}
void socio::setNombre(char* n){
strcpy(nombre,n);
}
void socio::setApellido(char*a){
strcpy(apellido,a);
}
void socio::setTelefono(char*t){
strcpy(telefono,t);
}
void socio::setFechaNacimiento(Fecha f){
fechaNacimiento=f;
}
void socio::setEstado(bool e ){
estado=e;
}
void socio::setTipoSocio(int Ts){

tipoSocio=Ts;}
void socio::setEmail(char* em ){
strcpy(email,em);}
int socio::getIdsocio(){
return idSocio;}

char* socio::getNombre(){return nombre;}

char* socio::getApellido(){return apellido;
}

char* socio::getTelefono(){return telefono;}

Fecha socio::getFechaNacimiento(){return fechaNacimiento;}

bool socio::getEstado(){return estado;}

int socio::getTipoSocio(){return tipoSocio;}

char* socio::getEmail(){return email;}
