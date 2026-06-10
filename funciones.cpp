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
#include"clsArchivoActividadesSede.h"
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
        cout<<"7 - CONSULTAS"<<endl;
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
                informes();
                break;
            case 7:
                consultas();
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
        cout<<"=========================="<<endl;
        cout<<"1 - Socios por apellido"<<endl;
        cout<<"2 - Socios por tipo"<<endl;
        cout<<"3 - Cuotas por ID de socio"<<endl;
        cout<<"4 - Cuotas por monto"<<endl;
        cout<<"5 - Sedes por ID"<<endl;
        cout<<"6 - Actividades por ID"<<endl;
        cout<<"7 - Participaciones por ID de socio"<<endl;
        cout<<"8 - Participaciones por ID de actividad"<<endl;
        cout<<"0 - Volver"<<endl;
        cout<<"=========================="<<endl;

        cin>>opc;

        system("cls");

        switch(opc){
        case 1:
            listadoSociosApellido();
            break;

        case 2:
            listadoSociosTipo();
            break;

        case 3:
            listadoCuotaSocio();
            break;

        case 4:
            listadoCuotaMonto();
            break;

        case 5:
            listadoSedeXid();
            break;

        case 6:
            listadoActividadXid();
            break;

        case 7:
            listadoParticipacionesSocio();
            break;

        case 8:
            listadoParticipacionesActividad();
            break;

        case 0:
            return;
        }

        system("pause");
    }
}
void consultas(){
    int opc;

    while(true){
        system("cls");

        cout<<"MENU CONSULTAS"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - CONSULTA DE SOCIOS"<<endl;
        cout<<"2 - CONSULTA DE JORNADAS"<<endl;
        cout<<"3 - CONSULTA DE ESTADO"<<endl;

        cin>>opc;
        system("cls");

        switch(opc){
        case 1:
            consultasSocios();
            break;

        case 2:
            consultasActividades();
            break;

        case 3:
            consultasDeEstado();
            break;

        case 0:
            break;
            return;
        }
        system("pause");
    }
}
void consultasSocios(){

    int opc;
      while(true){
        system("cls");

        cout<<"CONSULTAS SOCIOS"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - CONSULTA POR RANGO DE FECHAS"<<endl;
        cout<<"2 - CONSULTA POR ID DE SOCIO"<<endl;

        cin>>opc;
        system("cls");

        switch(opc){
        case 1:
            rangoDeFechas();
            break;

        case 2:
            consultaXidDeSocio();
            break;

        case 0:
            break;
            return;
        }
        system("pause");

}
}

void consultasActividades(){

    int opc;
      while(true){
        system("cls");

        cout<<"CONSULTAS DE ACTIVIDADES"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - CONSULTA POR ACTIVIDAD"<<endl;
        cout<<"2 - CONSULTA POR RESUMEN"<<endl;

        cin>>opc;
        system("cls");

        switch(opc){
        case 1:
            consultaXActividad();
            break;

        case 2:
            consultaXResumen();
            ///recuadacion mensual total (de todo el club).
            break;

        case 0:
            break;
            return;
        }
        system("pause");
      }
    }

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
///ordenar socios por apellido .
void listadoSociosApellido(){

    archivoSocio arc;

    int cant = arc.contarRegistros();

    socio *vec = new socio[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistros(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(strcmp(vec[i].getApellido(),
                      vec[j].getApellido())>0){

                socio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}

///ordenar  por tipo de socios
void listadoSociosTipo(){

    archivoSocio arc;

    int cant=arc.contarRegistros();

    socio *vec=new socio[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistros(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(vec[i].getTipoSocio()>
               vec[j].getTipoSocio()){

                socio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}
///ordenar cuota por id de socio.
void listadoCuotaSocio(){

    archivoCuota arc;

    int cant=arc.contarRegistros();

    cuota *vec=new cuota[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(vec[i].getIdsocio()>
               vec[j].getIdsocio()){

                cuota aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}


///ordenar por monto de deuda.

void listadoCuotaMonto(){

    archivoCuota arc;

    int cant=arc.contarRegistros();

    cuota *vec=new cuota[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(vec[i].getCuota()>
               vec[j].getCuota()){

                cuota aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}

///ordenar por id de sedes.

void listadoParticipacionesSocio(){

    archivoActividadesSocio arc;

    int cant=arc.contarRegistros();

    actividadSocio *vec=new actividadSocio[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(vec[i].getIdsocio()>
               vec[j].getIdsocio()){

                actividadSocio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}



void listadoParticipacionesActividad(){

    archivoActividadesSocio arc;

    int cant=arc.contarRegistros();

    actividadSocio *vec=new actividadSocio[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(vec[i].getIdactividad()>
               vec[j].getIdactividad()){

                actividadSocio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}


void listadoSedeXid(){

    archivoSede arc;

    int cant = arc.contarRegistro();

    sede *vec = new sede[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistro(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(vec[i].getIdsede() >
               vec[j].getIdsede()){

                sede aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}



void listadoActividadXid(){

    archivoActividades arc;

    int cant = arc.contarRegistros();

    actividad *vec = new actividad[cant];

    for(int i=0;i<cant;i++){
        vec[i]=arc.leerRegistros(i);
    }

    for(int i=0;i<cant-1;i++){

        for(int j=i+1;j<cant;j++){

            if(vec[i].getIdactividad() >
               vec[j].getIdactividad()){

                actividad aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(int i=0;i<cant;i++){

        if(vec[i].getEliminado()){

            vec[i].mostrar();
            cout<<endl;
        }
    }

    delete[] vec;
}

///INFORMES


actividad buscarActividadPorId(int idActividad){

    archivoActividades arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){

        actividad obj = arc.leerRegistros(i);

        if(obj.getIdactividad()==idActividad){
            return obj;
        }
    }

    actividad aux;
    aux.setIdactividad(-1);

    return aux;
}


void listarActividadesDeSocio(){

    int idSocio;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>idSocio;

    archivoActividadesSocio arc;

    int cant = arc.contarRegistros();

    bool encontro=false;

    for(int i=0;i<cant;i++){

        actividadSocio reg = arc.leerRegistro(i);

        if(reg.getIdsocio()==idSocio &&
           reg.getEliminado()){

            actividad act =
                buscarActividadPorId(reg.getIdactividad());

            if(act.getIdactividad()!=-1){

                act.mostrar();
                cout<<endl;

                encontro=true;
            }
        }
    }

    if(!encontro){
        cout<<"EL SOCIO NO TIENE ACTIVIDADES REGISTRADAS"<<endl;
    }
}




void recaudacionAnual(){

    archivoCuota arc;

    int cant = arc.contarRegistros();

    float total=0;

    for(int i=0;i<cant;i++){

        cuota obj = arc.leerRegistro(i);

        if(obj.getEliminado()){

            total += obj.getCuota();
        }
    }

    cout<<"RECAUDACION ANUAL: $"<<total<<endl;
}


void informes(){
    int opc;

    while(true){
        system("cls");

        cout<<"MENU INFORMES"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - Recaudacion anual"<<endl;
        cout<<"2 - Recaudacion por actividad"<<endl;
        cout<<"3 - Porcentaje de inscripciones por cada actividad"<<endl;
        cout<<"4 - Listar todas las actividades de un socio"<<endl;
        cout<<"5 - Ranking de actividades"<<endl;
        cout<<"6 - Listar socios con deudas pendientes"<<endl;
        cout<<"0 - Volver"<<endl;
        cout<<"=========================="<<endl;

        cin>>opc;

        system("cls");

        switch(opc){
        case 1:
            recaudacionAnual();
            break;

        case 2:
            recaudacionXActividad();
            break;

        case 3:
            porcentajeInscripciones();
            break;

        case 4:
             listarActividadesDeSocio();
            break;

        case 5:
            ranking();
            break;

        case 6:
            deudores();
            break;

        case 0:
            return;
        }

        system("pause");
    }
}
