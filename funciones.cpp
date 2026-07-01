#include <iostream>
#include<cstring>
#include"funciones.h"
#include "clsActividad.h"
#include "clsSocio.h"
#include "clsCuota.h"
#include "clsActividadSocio.h"
#include "cargarCadena.h"
#include "clsFecha.h"
#include"clsManagerSocio.h"
#include"clsManagerActividad.h"
#include"clsManagerCouta.h"
#include"clsManagerInformes.h"
#include "clsArchivoSocio.h"
#include"clsArchivoCuota.h"
#include"clsArchivoActividadesSocio.h"
#include"clsArchivoActividades.h"
#include "clsManagerActividadSocio.h"

using namespace std;

void menuPrincipal()
{
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);
    int opc;
    while(true)
    {
        system("cls");
        rlutil::setColor(rlutil::WHITE);

        cout<<"<<BIENVENIDO A FC-CODE>>"<<endl;
        cout<<"   MENU PRINCIPAL   "<<endl;
        rlutil::setColor(rlutil::BLACK);
        cout<<"================================"<<endl;
        blanco();
        cout<<"1 - SOCIOS"<<endl;
        cout<<"2 - ACTIVIDADES"<<endl;
        cout<<"3 - INSCRIPCION A ACTIVIDADES"<<endl;
        cout<<"4 - CUOTA"<<endl;
        cout<<"5 - INFORMES"<<endl;
        cout<<"6 - CONSULTAS"<<endl;
        cout<<"0 - SALIR"<<endl;
       negro();
        cout<<"================================"<<endl;
        blanco();
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            menuSocios();
            break;
        case 2:
            menuActividades();
            break;
        case 3:
            menuActividadSocio();
            break;
        case 4:
            menuCuota();
            break;
        case 5:
            informes();
            break;
        case 6:
            consultas();
            break;
        case 0:
            return;
        }
    }
}

void consultas()
{
    int opc;

    while(true)
    {
        system("cls");
        blanco();
        cout<<"MENU CONSULTAS"<<endl;
        negro();
        cout<<"=============================="<<endl;
        blanco();
        cout<<"1 - CONSULTA DE SOCIOS"<<endl;
        cout<<"2 - CONSULTA DE ACTIVIDADES"<<endl;
        cout<<"3 - CONSULTA DE ESTADO"<<endl;
        cout<<"0 - SALIR"<<endl;
        negro();
        cout<<"=============================="<<endl;
        blanco();
        cout<<"INGRESE UNA OPCION: ";

        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            consultasSocios();
            break;

        case 2:
            menuConsultaActividades();
            break;

        case 3:
            consultasDeEstado();
            break;

        case 0:
            return;
        }
    }
}
void consultasSocios()
{

    int opc;
    while(true)
    {
       system("cls");
        blanco();
        cout<<"CONSULTAS SOCIOS"<<endl;
        negro();
        cout<<"=============================="<<endl;
        blanco();
        cout<<"1 - CONSULTA POR RANGO DE FECHAS"<<endl;
        cout<<"2 - CONSULTA POR ID DE SOCIO"<<endl;
        cout<<"0 - SALIR"<<endl;
        negro();
        cout<<"=============================="<<endl;
        blanco();
        cout<<"INGRESE UNA OPCION: ";

        cin>>opc;

        system("cls");
        switch(opc)
        {
        case 1:
            rangoDeFechas();
            break;

        case 2:
            consultaXSocio();
            break;

        case 0:
            return;
        }
        pausa();

    }
}
void menuConsultaActividades()

{

    int opc;
    while(true)
    {
        system("cls");
        blanco();
        cout<<"CONSULTAS DE ACTIVIDADES"<<endl;
        negro();
        cout<<"=============================="<<endl;
        blanco();
        cout<<"1 - CONSULTA POR ACTIVIDAD"<<endl;
        cout<<"2 - CONSULTA POR RESUMEN"<<endl;
        cout<<"0 - SALIR"<<endl;
        negro();
        cout<<"=============================="<<endl;
        blanco();
        cout<<"INGRESE UNA OPCION: ";

        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            consultaXActividad();
            break;

        case 2:
            consultaResumen();
            break;
        case 0:
            return;
        }
        pausa();
    }
}

///ordenar socios por apellido
void listadoSociosApellido()
{
    archivoSocio arc;
    int cant = arc.contarRegistros();

    if (cant <= 0)
    {
        amarillo();
        cout << "NO HAY SOCIOS REGISTRADOS EN EL SISTEMA." << endl;
        blanco();
        return;
    }

    socio *vec = new socio[cant];
    int cantActivos = 0;

    // Cargar únicamente los socios activos para evitar procesar registros basura
    for(int i=0; i<cant; i++)
    {
        socio obj = arc.leerRegistros(i);
        if(obj.getEstado())
        {
            vec[cantActivos] = obj;
            cantActivos++;
        }
    }

    // Si no queda ningún socio activo, liberamos memoria y salimos
    if (cantActivos == 0)
    {
        amarillo();
        cout << "NO HAY SOCIOS ACTIVOS PARA LISTAR." << endl;
        blanco();
        delete[] vec;
        return;
    }

    // Ordenar los socios activos
    for(int i=0; i<cantActivos-1; i++)
    {
        for(int j=i+1; j<cantActivos; j++)
        {
            // Creamos copias temporales de los apellidos para estandarizarlos
            char auxI[20];
            char auxJ[20];
            strcpy(auxI, vec[i].getApellido());
            strcpy(auxJ, vec[j].getApellido());

            // Convertimos manualmente a mayúsculas para asegurar un orden alfabético real
            for(int k=0; auxI[k] != '\0'; k++)
            {
                if(auxI[k] >= 'a' && auxI[k] <= 'z') auxI[k] -= 32;
            }
            for(int k=0; auxJ[k] != '\0'; k++)
            {
                if(auxJ[k] >= 'a' && auxJ[k] <= 'z') auxJ[k] -= 32;
            }

            // Comparación limpia y justa
            if(strcmp(auxI, auxJ) > 0)
            {
                socio aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    //  Mostrar el listado ya depurado y ordenado correctamente
    for(int i=0; i<cantActivos; i++)
    {
        blanco();
        vec[i].mostrar();
        negro();
        cout<<"====================================="<<endl;
        blanco();
        cout<<endl;
    }

    delete[] vec;

}
void listadoSociosTipo() {
    archivoSocio arc;
    int cant = arc.contarRegistros();
    if(cant <= 0) {
            amarillo();
            cout << "NO HAY SOCIOS PARA LISTAR" << endl;
            blanco();
        return; }

    socio *vec = new socio[cant];
    for(int i = 0; i < cant; i++) {
        vec[i] = arc.leerRegistros(i);
    }

    // Ordenamiento BURBUJA
    for(int i = 0; i < cant - 1; i++) {
        for(int j = i + 1; j < cant; j++) {
            if(vec[i].getTipoSocio() > vec[j].getTipoSocio()) {
                socio aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    // Listado categorizado
    int tipoActual = -1;
    const char* nombresTipos[] = {"", "BASICO", "INTERMEDIO", "PREMIUM"};

    for(int i = 0; i < cant; i++) {
        if(vec[i].getEstado()) {
            // SI SE CAMBIA EL TIPO DE SOCIO:
            if(vec[i].getTipoSocio() != tipoActual) {
                tipoActual = vec[i].getTipoSocio();
                cout<<endl;
                negro();
                cout << "========================================" << endl;
                amarillo();
                cout << "TIPO DE SOCIO: " << nombresTipos[tipoActual] << endl<<endl;
                blanco();
            }

            // INFO DE LOS SOCIOS LISTADOS:
            cout <<"ID: "<< vec[i].getIdsocio();
            negro();
            cout << " -> ";
            blanco();
            cout<< vec[i].getApellido() << ", "
                 << vec[i].getNombre() << endl;
        }
    }

    delete[] vec;
}

///ordenar por monto PAGADO

void listadoCuotaMonto() {
    archivoCuota arc;
    int cant = arc.contarRegistros();

    if (cant <= 0) {
        amarillo();
        cout << "NO HAY CUOTAS REGISTRADAS." << endl;
        blanco();
        return;
    }

    //Cargamos las cuotas
    cuota *vec = new cuota[cant];
    int cantActivos = 0;

    for (int i = 0; i < cant; i++) {
        cuota aux = arc.leerRegistro(i);
        if (aux.getEstado() == true) {
            vec[cantActivos] = aux;
            cantActivos++;
        }
    }

    if (cantActivos == 0) {
        amarillo();
        cout << "NO HAY CUOTAS ACTIVAS PARA MOSTRAR." << endl;
        blanco();
        delete[] vec;
        return;
    }

    //Ordenamiento Burbuja de MENOR a MAYOR
    for (int i = 0; i < cantActivos - 1; i++) {
        for (int j = i + 1; j < cantActivos; j++) {
            if (vec[i].getImportePagado() > vec[j].getImportePagado()) {
                cuota aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    // Mostrar el vector ordenado
    blanco();
    cout << "--- LISTADO DE CUOTAS POR MONTO (MIN A MAX) ---" << endl;

    for (int i = 0; i < cantActivos; i++) {
        blanco();
        vec[i].mostrar();

        negro();
        cout << "-----------------------------------------------" << endl;
    }

    blanco();
    delete[] vec;
}

///consulta rango de fechas (no anda)
void rangoDeFechas()
{
    archivoActividadesSocio arc;
    actividadSocio obj;

    Fecha primeraFecha;
    Fecha segundaFecha;
blanco();
    cout << "INGRESE LA PRIMER FECHA: ";
    primeraFecha.Cargar();

    cout << "INGRESE LA SEGUNDA FECHA: ";
    segundaFecha.Cargar();

    int cantidad = 0;

    int cant = arc.contarRegistros();

    for(int i = 0; i < cant; i++)
    {

        obj = arc.leerRegistro(i);

        if(obj.getFechaAlta() >= primeraFecha &&
                obj.getFechaAlta() <= segundaFecha)
        {
            cantidad++;
        }
    }
blanco();
    cout << "LA CANTIDAD DE SOCIOS POR EL RANGO DE FECHA SOLICITADO ES: "
         << cantidad << endl;
}

///consultaXSocio
void consultaXSocio()
{
    socio obj;
    archivoSocio arc;
    bool encontrado=false;
    int cant=arc.contarRegistros();
    int id;
blanco();
    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>id;

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);


        if((obj.getIdsocio()==id) && (obj.getEstado()==true))
        {
            blanco();
            obj.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado)
    {   amarillo();
        cout << "NO EXISTE NINGUN SOCIO CON ESE ID." << endl;
        blanco();
    }
}
void consultaXActividad()
{
    actividad obj;
    archivoActividades arc;
    bool encontrado=false;
    int cant=arc.contarRegistros();
    int id;
    blanco();
    cout<<"INGRESE EL ID DE LA ACTIVIDAD: ";
    cin>>id;

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);

    if((obj.getIdactividad()==id) && (obj.getEstado()==true))
        {
            blanco();
            cout<<endl;
            negro();
            cout<<"====================================="<<endl;
            blanco();
            obj.mostrar();
            negro();
            cout<<"====================================="<<endl;
            blanco();
            encontrado=true;
        }

    }

    if(!encontrado)
    {
        amarillo();
        cout << "NO SE ENCONTRO NINGUNA ACTIVIDAD " << endl;
        blanco();
    }


}
///modificado deberia andar ahora
void consultaResumen()
{
    cuota obj;
    archivoCuota arc;
    int mes;
    blanco();
    cout << "INGRESE EL MES A RESUMIR: ";
    cin >> mes;
    float total = 0;
    int cant = arc.contarRegistros();

    for(int i = 0; i < cant; i++)
    {
        obj = arc.leerRegistro(i);
        if(obj.getFechaPago().getMes() == mes && obj.getEstado() == true)
        {
            // Aca sumamos la plata real que entro
            total += obj.getImportePagado();
        }
    }
    blanco();
    cout << "RECAUDACION TOTAL DEL MES: ";
    violeta();
    cout<<"$";
    cout<<total << endl;
    blanco();
}

void consultasDeEstado()
{
    socio obj;
    archivoSocio arc;
    bool encontrado=false;
    int cant= arc.contarRegistros();
    int id;
    blanco();
    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>id;

    for(int i=0; i<cant; i++ )
    {
        obj=arc.leerRegistros(i);

        amarillo();
        if((obj.getIdsocio()==id) && (obj.getEstado()==true))
        {
            cout<<endl;
            cout<<"EL SOCIO ESTA ACTIVO"<<endl;
            cout<<endl;
            blanco();
            obj.mostrar();
            encontrado=true;
            blanco();
            return;
        }
        else if((obj.getIdsocio()==id) && (obj.getEstado()==false))
        {   cout<<endl;
            cout<<"EL SOCIO ESTA INACTIVO "<<endl;
            blanco();
            return;
        }

    }
    if(!encontrado)
    {
        rojo();
        cout<<endl;
        cout << "NO EXISTE NINGUN SOCIO." << endl;
        blanco();
    }
}
