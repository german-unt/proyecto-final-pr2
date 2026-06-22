#include <iostream>
#include "clsManagerCouta.h"
#include "clsArchivoCuota.h"
#include "clsCuota.h"
#include <ctime>
using namespace std;

void menuCuota()
{
    int opc;
    while(true)
    {
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
        switch(opc)
        {
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

// Función auxiliar para listar pagos de un socio específico
/// revisar en que se puede usar
void listarPagosSocio(int idSocio) {
    archivoCuota arc;
    int cant = arc.contarRegistros();
    bool encontro = false;

    cout << "HISTORIAL DE PAGOS DEL SOCIO " << idSocio << " ---" << endl;
    for(int i = 0; i < cant; i++) {
        cuota obj = arc.leerRegistro(i);
        // Filtramos por ID y estado activo
        if(obj.getIdsocio() == idSocio && obj.getEstado()) {
            obj.mostrar();
            encontro = true;
        }
    }
    if(!encontro) cout << "No hay pagos registrados para este socio." << endl;
}

void altaCuota() {
    int idSocio;
    cout << "INGRESE EL ID DEL SOCIO QUE REALIZA EL PAGO: ";
    cin >> idSocio;

    // Ya no validamos si "ya tiene cuota", porque ahora cada pago es una transacción nueva.
    // Esto permite pagos mensuales, parciales o múltiples.
    cuota obj;
    obj.cargar(idSocio);

    archivoCuota arc;
    if(arc.grabarRegistro(obj)) {
        cout << "PAGO REGISTRADO CORRECTAMENTE." << endl;
    } else {
        cout << "ERROR AL GUARDAR EL PAGO." << endl;
    }
}

void bajaCuota() {
    // En un sistema contable, no borramos. ANULAMOS el pago mediante el ID del pago (o su posición).
    // Aquí implementamos una lógica para anular un movimiento específico.
    int pos;
    cout << "INGRESE LA POSICION (INDICE) DEL PAGO A ANULAR: ";
    cin >> pos;

    archivoCuota arc;
    cuota obj = arc.leerRegistro(pos);

    if(obj.getImportePagado() == -1) {
        cout << "PAGO NO ENCONTRADO." << endl;
        return;
    }

    obj.setEstado(false); // Damos de baja el registro lógico
    if(arc.modificarRegistro(obj, pos)) {
        cout << "PAGO ANULADO CORRECTAMENTE." << endl;
    }
}

void modificarCuota() {
    // La modificación es delicada. Solo permitimos cambiar el importe si hubo error.
    int pos;
    cout << "INGRESE LA POSICION DEL PAGO A CORREGIR: ";
    cin >> pos;

    archivoCuota arc;
    cuota obj = arc.leerRegistro(pos);

    if(obj.getImportePagado() == -1 || !obj.getEstado()) {
        cout << "REGISTRO INVALIDO O DADO DE BAJA." << endl;
        return;
    }

    obj.mostrar();
    cout << "INGRESE EL NUEVO IMPORTE: ";
    float nuevoImp;
    cin >> nuevoImp;
    obj.setImportePagado(nuevoImp);

    if(arc.modificarRegistro(obj, pos)) {
        cout << "PAGO MODIFICADO CORRECTAMENTE." << endl;
    }
}

void listarCuota() {
    archivoCuota arc;
    int cant = arc.contarRegistros();

    if(cant <= 0) {
        cout << "NO HAY PAGOS EN EL SISTEMA." << endl;
        return;
    }

    cout << "LISTADO COMPLETO DE MOVIMIENTOS:" << endl;
    for(int i = 0; i < cant; i++) {
        cuota obj = arc.leerRegistro(i);
        if(obj.getEstado()) {
            cout << "[POSICION " << i << "]" << endl;
            obj.mostrar();
            cout<<endl;
            cout<<"======================================="<<endl;
        }
    }
}
float calcularDeudaHistorica(int idSocio) {

    archivoSocio arcSocio;
    archivoActividadesSocio arcActividadSocio;
    actividadSocio obj;

    int pos = arcSocio.buscarRegistros(idSocio);
    if (pos < 0) {return -1 ;}

    socio objSocio = arcSocio.leerRegistros(pos);

    // 1. Determinar el valor mensual
    float valorMensual = 10000;
    if(objSocio.getTipoSocio() == 2) valorMensual = 20000;
    else if(objSocio.getTipoSocio() == 3) valorMensual = 30000;

    // 2. Obtener fecha actual (usando time como haces en Fecha::Cargar)
    time_t t = time(NULL);
    tm* hoy = localtime(&t);
    int mesActual = hoy->tm_mon + 1;
    int anioActual = hoy->tm_year + 1900;
    int posAXS = arcActividadSocio.buscarRegistro(idSocio);
    if (posAXS < 0) {return -1 ;}
    obj= arcActividadSocio.leerRegistro(posAXS);
    // 3. Obtener fecha de alta del socio
    int mesAlta = obj.getFechaAlta().getMes();
    int anioAlta = obj.getFechaAlta().getAnio();

    // 4. Cálculo de diferencia en meses
    // Convertimos años a meses y sumamos los meses actuales
    int mesesTotalesActual = (anioActual * 12) + mesActual;
    int mesesTotalesAlta = (anioAlta * 12) + mesAlta;

    int mesesTranscurridos = mesesTotalesActual - mesesTotalesAlta;

    // Si el resultado es negativo (por error de fecha) o cero, devolvemos 0
    if(mesesTranscurridos < 0) mesesTranscurridos = 0;

    return mesesTranscurridos * valorMensual;
}

float obtenerDeudaTotalSocio(int idSocio) {
    archivoCuota arc;
    float totalPagado = 0;

    // 1. Sumamos todo lo que el socio pagó en la historia
    for(int i = 0; i < arc.contarRegistros(); i++) {
        cuota aux = arc.leerRegistro(i);
        if(aux.getIdsocio() == idSocio && aux.getEstado()) {
            totalPagado += aux.getImportePagado();
        }
    }

    // 2. Calculamos cuánto debía pagar según su antigüedad
    // (Esto requiere saber cuándo se inscribió)
    float totalDeberiaHaberPagado = calcularDeudaHistorica(idSocio);
    float restoTotalCalculado= totalDeberiaHaberPagado - totalPagado;

    return restoTotalCalculado;

}
