#include<iostream>
#include"clsCuota.h"
#include"funciones.h"
#include "clsFecha.h"
using namespace std;
void cuota::cargar(int id){
    if(id == -1){
        cout<<"INGRESE EL ID de socio: ";
        cin>>idSocio;
    }else{
        idSocio = id;
    }
cout<<"INGRESE EL VALOR DE LA CUOTA: ";
cin>>cuota;
cout<<"INGRESE LA DEUDA DEL SOCIO: ";
cin>>deuda;
estado=true;
cout<<"INGRESE FECHA DE PAGO: ";
FechaPago.Cargar;
}
void cuota::mostrar(){
cout<<"ID SOCIO:"<<idSocio<<endl;
cout<<"VALOR DE LA CUOTA: "<<cuota<<endl;
cout<<"DEUDA TOTAL: "<<deuda<<endl;
}

void cuota::setIdsocio(int id){
idSocio=id;
}
void cuota::setCuota(float c){
cuota=c;
}void cuota::setDeuda(float d){
deuda=d;
}
void cuota::setEstado(bool e){
estado=e;
}
void cuota::setFechaPago(fecha f){
fechaPago=f; }
int cuota::getIdsocio(){return idSocio;}
float cuota::getCuota(){return cuota;}
float cuota::getDeuda(){return deuda;}
bool cuota::getEstado(){return estado;}
fecha cuota::getFechaPago(){return fechaPago; }

