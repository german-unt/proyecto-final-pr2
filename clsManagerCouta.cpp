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

// 3. CORRECCIÓN: altaCuota con la matemática en su lugar
void altaCuota() {
    int idSocio;
    cout << "INGRESE EL ID DEL SOCIO: ";
    cin >> idSocio;

    // VALIDACIÓN: Comprobar manualmente si existe inscripción activa
    archivoActividadesSocio arcActSocio;
    int cantIns = arcActSocio.contarRegistros();
    bool tieneActividad = false;

    for(int i = 0; i < cantIns; i++) {
        actividadSocio obj = arcActSocio.leerRegistro(i);
        if(obj.getIdSocio() == idSocio && obj.getEstado() == true) {
            tieneActividad = true;
            break;
        }
    }

    if (!tieneActividad) {
        cout << "\nERROR: El socio NO ESTA INSCRIPTO en ninguna actividad." << endl;
        cout << "No se puede cobrar cuota." << endl;
        return;
    }

    archivoCuota arc;
    float deudaHistorica = calcularDeudaHistorica(idSocio);
    float totalPagado = obtenerTotalPagadoSocio(idSocio); // Ahora sí, esto valdrá 0 al principio o 1000 si ya pagó
    float deudaPendiente = deudaHistorica - totalPagado;

    cout << "\n--------------------------------------------------" << endl;
    cout << "DEUDA TOTAL ACUMULADA HISTORICA: $" << deudaHistorica << endl;
    cout << "TOTAL YA ABONADO HASTA AHORA:    $" << totalPagado << endl;
    cout << "SALDO PENDIENTE ACTUAL:          $" << deudaPendiente << endl;
    cout << "--------------------------------------------------\n" << endl;

    cuota obj;
    obj.cargar(idSocio);

    if (arc.grabarRegistro(obj)) {
        cout << "CUOTA CARGADA CON EXITO" << endl;
    } else {
        cout << "ERROR AL GRABAR LA CUOTA" << endl;
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
    socio objSocio;

    // 1. Buscamos al socio para ver su tipo y saber cuánto paga
    int posSocio = arcSocio.buscarRegistros(idSocio);
    if (posSocio < 0) return 0;

    objSocio = arcSocio.leerRegistros(posSocio);
    float valorMensual = 10000;
    if (objSocio.getTipoSocio() == 2) valorMensual = 20000;
    else if (objSocio.getTipoSocio() == 3) valorMensual = 30000;

    // 2. Buscamos de forma manual si tiene alguna inscripción activa
    archivoActividadesSocio arcActividadSocio;
    int cantInscripciones = arcActividadSocio.contarRegistros();
    actividadSocio objInscripcion;
    bool estaInscripto = false;

    for(int i = 0; i < cantInscripciones; i++) {
        objInscripcion = arcActividadSocio.leerRegistro(i);
        // Acá comprobamos que el ID SOCIO coincida y esté activo
        if(objInscripcion.getIdSocio() == idSocio && objInscripcion.getEstado() == true) {
            estaInscripto = true;
            break; // Encontramos su registro, cortamos la búsqueda
        }
    }

    if (!estaInscripto) {
        return 0; // Si no tiene actividad, no debe nada.
    }

    // 3. Fechas para calcular meses
    time_t t = time(nullptr);
    tm* hoy = localtime(&t);
    int mesActual = hoy->tm_mon + 1;
    int anioActual = hoy->tm_year + 1900;

    int mesAlta = objInscripcion.getFechaAlta().getMes();
    int anioAlta = objInscripcion.getFechaAlta().getAnio();

    int mesesTotalesActual = (anioActual * 12) + mesActual;
    int mesesTotalesAlta = (anioAlta * 12) + mesAlta;
    int mesesTranscurridos = mesesTotalesActual - mesesTotalesAlta;

    // Si se acaba de inscribir este mes, al menos debe 1 mes (el actual)
    if (mesesTranscurridos <= 0) {
        mesesTranscurridos = 1;
    }

    return mesesTranscurridos * valorMensual;
}

// 2. CORRECCIÓN: Ahora calcula la DEUDA real (Deuda Histórica - Lo que ya pagó)
float obtenerDeudaTotalSocio(int idSocio) {
    float deudaHistorica = calcularDeudaHistorica(idSocio);
    float totalPagado = obtenerTotalPagadoSocio(idSocio);
    return deudaHistorica - totalPagado;
}
// 1. NUEVA FUNCIÓN: Solo suma los billetes reales que el socio ingresó en caja
float obtenerTotalPagadoSocio(int idSocio) {
    archivoCuota arc;
    float totalPagado = 0;
    int cant = arc.contarRegistros();

    for(int i = 0; i < cant; i++) {
        cuota aux = arc.leerRegistro(i);
        if(aux.getIdsocio() == idSocio && aux.getEstado() == true) {
            totalPagado += aux.getImportePagado(); // Acá suma los 1000 pesos
        }
    }
    return totalPagado;
}
