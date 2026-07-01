#include <iostream>
#include "clsManagerCouta.h"
#include "clsArchivoCuota.h"
#include "clsCuota.h"
#include "funciones.h"
#include <ctime>
using namespace std;

void menuCuota()
{
    int opc;
    while(true)
    {
        system("cls");
        blanco();
        cout << "MENU CUOTA" << endl;
        negro();
        cout << "=======================" << endl;
        blanco();
        cout << "1 - ALTA" << endl;
        cout << "2 - BAJA" << endl;
        cout << "3 - MODIFICACION" << endl;
        cout << "4 - LISTADO" << endl;
        cout << "5 - LISTADO: POR MONTO" << endl;
        cout << "0 - VOLVER AL MENU PRINCIPAL" << endl;
        negro();
        cout << "=======================" << endl;
        blanco();
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

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
        case 5:
            listadoCuotaMonto();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}

// FUNCION AUXILIAR PARA LISTAR PAGOS DE UN SOCIO ESPECIFICO
void listarPagosSocio(int idSocio) {
    archivoCuota arc;
    int cant = arc.contarRegistros();
    bool encontro = false;

    blanco();
    cout << "HISTORIAL DE PAGOS DEL SOCIO ";
    negro();
    cout << idSocio;
    blanco();
    cout << " ---" << endl;
    negro();
    cout << "=========================================" << endl;

    for(int i = 0; i < cant; i++) {
        cuota obj = arc.leerRegistro(i);
        // FILTRAMOS POR ID Y ESTADO ACTIVO
        if(obj.getIdsocio() == idSocio && obj.getEstado()) {
            obj.mostrar();
            encontro = true;
        }
    }

    if(!encontro) {
        rojo();
        cout << "ERROR: NO HAY PAGOS REGISTRADOS DE ESTE SOCIO." << endl;
        blanco();
    }
}

// 3. CORRECCION: ALTACUOTA CON LA MATEMATICA Y VALIDACION DE TOPE
void altaCuota() {
    int idSocio;
    blanco();
    cout << "INGRESE EL ID DEL SOCIO: ";
    cin >> idSocio;

    // VALIDACION: COMPROBAR MANUALMENTE SI EXISTE INSCRIPCION ACTIVA
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
        rojo();
        cout << "ERROR: EL SOCIO NO ESTA INSCRIPTO A NINGUNA ACTIVIDAD." << endl;
        cout << "NO SE PUDO REGISTRAR CUOTA." << endl;
        blanco();
        return;
    }

    archivoCuota arc;
    float deudaHistorica = calcularDeudaHistorica(idSocio);
    float totalPagado = obtenerTotalPagadoSocio(idSocio);
    float deudaPendiente = deudaHistorica - totalPagado;

    negro();
    cout << "--------------------------------------------------" << endl;
    blanco();
    cout << "DEUDA TOTAL ACUMULADA HISTORICA: ";
    violeta();
    cout << "$" << deudaHistorica << endl;
    blanco();
    cout << "TOTAL YA ABONADO HASTA AHORA:    ";
    violeta();
    cout << "$" << totalPagado << endl;
    blanco();
    cout << "SALDO PENDIENTE ACTUAL:          ";
    violeta();
    cout << "$" << deudaPendiente << endl;
    negro();
    cout << "--------------------------------------------------" << endl;

    if (deudaPendiente <= 0) {
        amarillo();
        cout << "EL SOCIO NO TIENE SALDO PENDIENTE." << endl;
        blanco();
        return;
    }

    cuota obj;
    obj.cargar(idSocio); // NOTA: ESTA FUNCION YA PIDE EL MONTO DENTRO DE TU CLASE CUOTA

    // VALIDACION: COMPROBAR QUE EL IMPORTE CARGADO NO SUPERE EL SALDO PENDIENTE
    if (obj.getImportePagado() > deudaPendiente) {
        rojo();
        cout << "ERROR: EL MONTO INGRESADO DE ";
        violeta();
        cout << "$" << obj.getImportePagado();
        rojo();
        cout << ", SUPERA EL SALDO PENDIENTE DE ";
        violeta();
        cout << "$" << deudaPendiente;
        rojo();
        cout << "." << endl;
        cout << "NO SE PUDO REGISTRAR." << endl;
        blanco();
        return;
    }

    if (arc.grabarRegistro(obj)) {
        amarillo();
        cout << "CUOTA CARGADA CON EXITO" << endl;
        blanco();
    } else {
        rojo();
        cout << "ERROR AL GRABAR LA CUOTA" << endl;
        blanco();
    }
}

void bajaCuota() {
    // EN UN SISTEMA CONTABLE, NO BORRAMOS. ANULAMOS EL PAGO MEDIANTE EL ID DEL PAGO (O SU POSICION).
    // AQUI IMPLEMENTAMOS UNA LOGICA PARA ANULAR UN MOVIMIENTO ESPECIFICO.
    int pos;
    blanco();
    cout << "INGRESE LA POSICION (INDICE) DEL PAGO A ANULAR: ";
    cin >> pos;

    archivoCuota arc;
    cuota obj = arc.leerRegistro(pos);

    if(obj.getImportePagado() == -1) {
        rojo();
        cout << "ERROR: PAGO NO ENCONTRADO." << endl;
        blanco();
        return;
    }

    obj.setEstado(false); // DAMOS DE BAJA EL REGISTRO LOGICO
    if(arc.modificarRegistro(obj, pos)) {
        amarillo();
        cout << "PAGO ANULADO CORRECTAMENTE." << endl;
        blanco();
    }
}

void modificarCuota() {
    // LA MODIFICACION ES DELICADA. SOLO PERMITIMOS CAMBIAR EL IMPORTE SI HUBO ERROR.
    int pos;
    blanco();
    cout << "INGRESE LA POSICION DEL PAGO A CORREGIR: ";
    cin >> pos;

    archivoCuota arc;
    cuota obj = arc.leerRegistro(pos);

    if(obj.getImportePagado() == -1 || !obj.getEstado()) {
        rojo();
        cout << "ERROR: REGISTRO INVALIDO O DADO DE BAJA." << endl;
        blanco();
        return;
    }

    cout << endl;
    char confirmar;
    amarillo();
    cout << "DESEA MODIFICAR ESTA CUOTA? (S/N): ";
    blanco();
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 's')
    {
        return;
    }

    obj.mostrar();

    blanco();
    cout << "INGRESE EL NUEVO IMPORTE: ";
    violeta();
    float nuevoImp;
    cin >> nuevoImp;
    obj.setImportePagado(nuevoImp);

    if(arc.modificarRegistro(obj, pos)) {
        amarillo();
        cout << "PAGO MODIFICADO CORRECTAMENTE." << endl;
        blanco();
    }
}

void listarCuota() {
    archivoCuota arc;
    int cant = arc.contarRegistros();

    if(cant <= 0) {
        rojo();
        cout << "ERROR: NO HAY PAGOS EN EL SISTEMA." << endl;
        blanco();
        return;
    }

    amarillo();
    cout << "LISTADO COMPLETO DE MOVIMIENTOS:" << endl;
    negro();
    cout << "=======================================" << endl;

    for(int i = 0; i < cant; i++) {
        cuota obj = arc.leerRegistro(i);
        if(obj.getEstado()) {
            blanco();
            cout << "[";
            negro();
            cout << "POSICION " << i;
            blanco();
            cout << "]" << endl;

            obj.mostrar();
            cout << endl;

            negro();
            cout << "=======================================" << endl;
        }
    }
    blanco();
}
float calcularDeudaHistorica(int idSocio) {
    archivoSocio arcSocio;
    socio objSocio;

    // 1. OBTENER TIPO DE SOCIO
    int posSocio = arcSocio.buscarRegistros(idSocio);
    if (posSocio < 0) return 0;
    objSocio = arcSocio.leerRegistros(posSocio);

    float valorMensual = 10000;
    if(objSocio.getTipoSocio() == 2) valorMensual = 20000;
    else if(objSocio.getTipoSocio() == 3) valorMensual = 30000;

    // 2. BUSCAR LA INSCRIPCION MAS ANTIGUA
    archivoActividadesSocio arcInscripciones;
    int cantInscripciones = arcInscripciones.contarRegistros();

    int mesMin = 13, anioMin = 3000; // VALORES INITIALES ALTOS
    bool encontroAlguna = false;

    for(int i = 0; i < cantInscripciones; i++) {
        actividadSocio aux = arcInscripciones.leerRegistro(i);

        if(aux.getIdSocio() == idSocio && aux.getEstado() == true) {
            int mes = aux.getFechaAlta().getMes();
            int anio = aux.getFechaAlta().getAnio();

            // SI ENCONTRAMOS UNA FECHA MAS CHICA (MAS VIEJA), LA GUARDAMOS
            if(anio < anioMin || (anio == anioMin && mes < mesMin)) {
                anioMin = anio;
                mesMin = mes;
                encontroAlguna = true;
            }
        }
    }

    if (!encontroAlguna) return 0;

    // 3. CALCULO DE MESES TRANSCURRIDOS DESDE ESA FECHA MINIMA
    time_t t = time(nullptr);
    tm* hoy = localtime(&t);
    int mesActual = hoy->tm_mon + 1;
    int anioActual = hoy->tm_year + 1900;

    int mesesTotalesActual = (anioActual * 12) + mesActual;
    int mesesTotalesAlta = (anioMin * 12) + mesMin;
    int mesesTranscurridos = mesesTotalesActual - mesesTotalesAlta;

    if (mesesTranscurridos <= 0) mesesTranscurridos = 1;

    return mesesTranscurridos * valorMensual;
}

// CORRECCION: AHORA CALCULA LA DEUDA REAL (DEUDA HISTORICA - LO QUE YA PAGO)
float obtenerDeudaTotalSocio(int idSocio) {
    float deudaHistorica = calcularDeudaHistorica(idSocio);
    float totalPagado = obtenerTotalPagadoSocio(idSocio);
    return deudaHistorica - totalPagado;
}

// NUEVA FUNCION: SOLO SUMA LOS BILLETES REALES QUE EL SOCIO INGRESO EN CAJA
float obtenerTotalPagadoSocio(int idSocio) {
    archivoCuota arc;
    float totalPagado = 0;
    int cant = arc.contarRegistros();

    for(int i = 0; i < cant; i++) {
        cuota aux = arc.leerRegistro(i);
        if(aux.getIdsocio() == idSocio && aux.getEstado() == true) {
            totalPagado += aux.getImportePagado(); // ACA SUMA LOS 1000 PESOS
        }
    }
    return totalPagado;
}
