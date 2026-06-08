#include <iostream>
#include"funciones.h"
#include "clsActividad.h"
#include "clsSocio.h"
#include "clsSede.h"
#include "clsCuota.h"
#include "clsActividad.h"
#include "cargarCadena.h"
#include "clsFecha.h"
//---------------------------
#include "clsArchivoSocio.h"
#include"clsArchivoSede.h"
#include"clsArchivoCuota.h"
#include"clsArchivoActividadesSocio.h"
#include"clsArchivoActividades.h"

using namespace std;

void menuPrincipal(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 -SOCIOS"<<endl;
        cout<<"2 - ACTIVIDADES"<<endl;
        cout<<"3 - SEDES"<<endl;
        cout<<"4 - CUOTA"<<endl;
        cout<<"5 - LISTADOS "<<endl;
        cout<<"6 - INFORMES"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuSocios();
                break;
            case 2:
                menuActividades();
                break;
            case 3:
                menuSedes();
                break;
            case 4:
                menuCuota();
                break;
            case 5:
                listados();
                break;
            case 6:

                break;
            case 0:
                return;
        }
    }
}


void menuSocios(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU SOCIOS"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaSocio();
                break;
            case 2:
                bajaSocio();
                break;
            case 3:
                modificarSocio();
                break;
            case 4:
                listarSocio();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void menuActividades(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ACTIVIDADES"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaActividad();
                break;
            case 2:
                bajaActividad();
                break;
            case 3:
                modificarActividad();
                break;
            case 4:
                listarActividad();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void menuSedes(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU SEDES"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaSede();
                break;
            case 2:
                bajaSede();
                break;
            case 3:
                modificarSede();
                break;
            case 4:
                listarSede();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}
void menuCuota(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU CUOTA"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaCuota();
                break;
            case 2:
                bajaCuota();
                break;
            case 3:
                modificarCuota();
                break;
            case 4:
                listarCuota();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}
void listados(){
 int opc;
    while(true){
        system("cls");
        cout<<"MENU LISTADOS"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - LISTADO DE SOCIOS"<<endl;
        cout<<"2 - LISTADO DE CUOTAS"<<endl;
        cout<<"3 - LISTADO DE SEDES"<<endl;
        cout<<"4 - LISTADO DE ACTIVIDADES"<<endl;
        cout<<"5 - LISTADO DE PARTICIPACIONES DEL SOCIO POR ACTIVIDADES"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"======================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                listadoSocioXid();
                break;
            case 2:
                listadoCuotaXid();
                break;
            case 3:
                listadoSedeXid();
                break;
            case 4:
                listadoActividadXid();
                break;
            case 5:
                listadoParticipaciones();
                break;
            case 0:
                return;
}
}}
///////////////////////////////////


void altaSocio(){
 int id;
 cout<<"INGRESE EL ID DE SOCIO: ";
 cin>>id;
 archivoSocio arc;
 int pos = arc.buscarRegistros(id);
 if(pos >= 0){
     cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
     return;
 }
 socio obj;
 obj.cargar(id);
 arc.grabarRegistros(obj);
}

void bajaSocio(){
int id ;
archivoSocio arc;
cout<<"ingrese el id del socio: ";
int pos= arc.buscarRegistros(id);
if(pos < 0){
    cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
return;
}
socio obj =arc.leerRegistros(pos);
obj.setEliminado(false);
arc.modificarRegistro(obj,pos);
cout<<"el socio ha sido dado de baja correctamente "<<endl;
}

void modificarSocio(){
int id ;
cout<<"ingrese el id del socio: ";
cin>>id;

archivoSocio arc;
int pos = arc.buscarRegistros(id);
if(pos<0){
 cout<<"el id no existe "<<endl;
 return;
    }
    socio obj=arc.leerRegistros(pos);

    if(obj.getEliminado()==false){
        cout<<"el socio esta dado de baja"<<endl;
        return;
        }
cout<<"ingrese los datos nuevos ";
obj.cargar(id);
arc.modificarRegistro(obj,pos);
cout<<"socio modificado correctamente"<<endl;
}

void listarSocio(){
archivoSocio arc;
int cant = arc.contarRegistros();
if (cant<=0){

   cout<<"no hay socios ingresados: "<<endl;
   return;
}
for(int i =0;i<cant;i++){

    socio obj=arc.leerRegistros(i);
    if(obj.getEliminado()==true){
        obj.mostrar();
        }
}

}

void altaActividad(){
int id;
 cout<<"INGRESE EL ID DE ACTIVIDADES: ";
 cin>>id;
 archivoActividades arc;
 int pos = arc.buscarRegistros(id);
 if(pos >= 0){
     cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
     return;
 }
 actividad obj;
 obj.cargar(id);
 arc.grabarRegistros(obj);
}

void bajaActividad(){

int id ;
archivoActividades arc;
cout<<"ingrese el id del actividades: ";
int pos= arc.buscarRegistros(id);
if(pos < 0){
    cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
return;
}
actividad obj =arc.leerRegistros(pos);
obj.setEliminado(false);
arc.modificarRegistros(obj,pos);
cout<<"la actividad ha sido dado de baja correctamente "<<endl;
}

void modificarActividad(){
int id ;
cout<<"ingrese el id del actividad: ";
cin>>id;

archivoActividades arc;
int pos = arc.buscarRegistros(id);
if(pos<0){
 cout<<"el id no existe "<<endl;
 return;
    }
    actividad obj=arc.leerRegistros(pos);

    if(obj.getEliminado()==false){
        cout<<"el actividades esta dado de baja"<<endl;
        return;
        }
cout<<"ingrese los datos nuevos ";
obj.cargar(id);
arc.modificarRegistros(obj,pos);
cout<<"actividades modificado correctamente"<<endl;
}

void listarActividad(){
archivoActividades arc;
int cant = arc.contarRegistros();
if (cant<=0){

   cout<<"no hay actividades ingresadas: "<<endl;
   return;
}
for(int i =0;i<cant;i++){

  actividad obj=arc.leerRegistros(i);
    if(obj.getEliminado()==true){
        obj.mostrar();
        }
}
}

void altaSede(){
int id;
 cout<<"INGRESE EL ID DE SEDE: ";
 cin>>id;
 archivoSede arc;
 int pos = arc.buscarRegistro(id);
 if(pos >= 0){
     cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
     return;
 }
 sede obj;
 obj.cargar(id);
 arc.grabarRegistro(obj);
}

void bajaSede(){
int id ;
archivoSede arc;
cout<<"ingrese el id de la sede: ";
int pos= arc.buscarRegistro(id);
if(pos < 0){
    cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
return;
}
sede obj =arc.leerRegistro(pos);
obj.setEliminado(false);
arc.modificarRegistro(obj,pos);
cout<<"la sede ha sido dado de baja correctamente "<<endl;
}

void modificarSede(){
int id ;
cout<<"ingrese el id de la sede: ";
cin>>id;
archivoSede arc;
int pos = arc.buscarRegistro(id);
if(pos<0){
 cout<<"el id no existe "<<endl;
 return;
    }
    sede obj=arc.leerRegistro(pos);

    if(obj.getEliminado()==false){
        cout<<"la sede esta dada de baja"<<endl;
        return;
        }
cout<<"ingrese los datos nuevos ";
obj.cargar(id);
arc.modificarRegistro(obj,pos);
cout<<"sede modificad correctamente"<<endl;
}

void listarSede(){
archivoSede arc;
int cant = arc.contarRegistro();
if (cant<=0){

   cout<<"no hay sedes ingresadas: "<<endl;
   return;
}
for(int i =0;i<cant;i++){

  sede obj=arc.leerRegistro(i);
    if(obj.getEliminado()==true){
        obj.mostrar();
        }
}

}

void altaCuota(){
int id;
 cout<<"INGRESE EL ID DE CUOTA: ";
 cin>>id;
 archivoCuota arc;
 int pos = arc.buscarRegistros(id);
 if(pos >= 0){
     cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
     return;
 }
 cuota obj;
 obj.cargar(id);
 arc.grabarRegistro(obj);

}

void bajaCuota(){

 int id ;
 archivoCuota arc;
 cout<<"ingrese el id de la cuota: ";
 int pos= arc.buscarRegistros(id);
 if(pos < 0){
     cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
 return;
 }
 cuota obj =arc.leerRegistro(pos);
 obj.setEliminado(false);
 arc.modificarRegistro(obj,pos);
 cout<<"la couta ha sido dado de baja correctamente "<<endl;

}

void modificarCuota(){
int id ;
cout<<"ingrese el id de la couta: ";
cin>>id;
archivoCuota arc;
int pos = arc.buscarRegistros(id);
if(pos<0){
 cout<<"el id no existe "<<endl;
 return;
    }
    cuota obj=arc.leerRegistro(pos);

    if(obj.getEliminado()==false){
        cout<<"la sede esta dada de baja"<<endl;
        return;
        }
cout<<"ingrese los datos nuevos ";
obj.cargar(id);
arc.modificarRegistro(obj,pos);
cout<<"couta modificad correctamente"<<endl;

}

void listarCuota(){
archivoCuota arc;
int cant = arc.contarRegistros();
if (cant<=0){

   cout<<"no hay cuotas ingresadas: "<<endl;
   return;
}
for(int i =0;i<cant;i++){

  cuota obj=arc.leerRegistro(i);
    if(obj.getEliminado()==true){
        obj.mostrar();
        }
}
}
///ordenar socios por apellido .ordenar  por tipo de socios
void listadoSocioXid(){
archivoSocio arc("socios.dat");
arc.listarRegistros();

}
///ordenar por id de socio. ordenar por monto de deuda.
void listadoCuotaXid(){
archivoCuota arc("coutas.dat");
arc.listarRegistros();
}

///ordenar por id de sedes.


///ordenar id de actividad.


///ordenar por id de socio . ordenar por id de actividad.

