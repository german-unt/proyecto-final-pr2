#include<iostream>
#include"clsCuota.h"
#include"funciones.h"
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
eliminado=true;
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
}void cuota::setDeuda(bool d){
deuda=d;
}
void cuota::setEliminado(bool e){
eliminado=e;
}
int cuota::getIdsocio(){return idSocio;}
float cuota::getCuota(){return cuota;}
bool cuota::getDeuda(){return deuda;}
bool cuota::getEliminado(){return eliminado;}
