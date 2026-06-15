#include<iostream>
#include"clsSocio.h"
#include<cstring>
#include "funciones.h"
#include "cargarCadena.h"
using namespace std;
void socio::cargar(int id){
    if(id == -1){
        cout<<"INGRESE EL ID de Socio: ";
        cin>>idSocio;
    }else{
        idSocio = id;
    }
cout<<"INGRESE EL NOMBRE: ";
cargarCadena(nombre,20);
cout<<"INGRESE EL APELLIDO: ";
cargarCadena(apellido,20);
cout<<"INGRESE EL TELEFONO: ";
cargarCadena(telefono,15);
cout<<"INGRESE LA FECHA DE NACIMIENTO: ";
fechaNacimiento.Cargar();
cout<<"INGRESE EL TIPO DE SOCIO: ";
cin>>tipoSocio;
cout<<"INGRESE EL EMAIL: ";
cargarCadena(email,50);
estado=true;
}

void socio::mostrar(){
cout<<"ID DEL SOCIO: "<<idSocio<<endl;
cout<<"NOMBRE: "<<nombre<<endl;
cout<<"APELLIDO: "<<apellido<<endl;
cout<<"TELEFONO: "<<telefono<<endl;
cout<<"FECHA DE NACIMIENTO: ";
fechaNacimiento.Mostrar();
cout<<"TIPO DE SOCIO: "<<tipoSocio<<endl;
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
