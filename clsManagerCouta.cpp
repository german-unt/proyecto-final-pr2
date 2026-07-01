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
        cout<<"MENU CUOTA"<<endl;
        cout<<"======================="<<endl;
        cout<<"1 - ALTA"<<endl;
        cout<<"2 - BAJA"<<endl;
        cout<<"3 - MODIFICACION"<<endl;
        cout<<"4 - LISTADO"<<endl;
        cout<<"5 - LISTADO: POR MONTO"<<endl;
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
        case 5:
            listadoCuotaMonto();
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
    if(!encontro) cout << "NO HAY PAGOS REGISTRADOS DE ESTE SOCIO." << endl;
}

// 3. CORRECCIÓN: altaCuota con la matemática y validación de tope
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
        cout << "ERROR: EL SOCIO NO ESTA INSCRIPTO A NINGUNA ACTIVIDAD." << endl;
        cout << "NO SE PUDO REGISTRA CUOTA." << endl;
        return;
    }

    archivoCuota arc;
    float deudaHistorica = calcularDeudaHistorica(idSocio);
    float totalPagado = obtenerTotalPagadoSocio(idSocio);
    float deudaPendiente = deudaHistorica - totalPagado;

    cout << "--------------------------------------------------" << endl;
    cout << "DEUDA TOTAL ACUMULADA HISTORICA: $" << deudaHistorica << endl;
    cout << "TOTAL YA ABONADO HASTA AHORA:    $" << totalPagado << endl;
    cout << "SALDO PENDIENTE ACTUAL:          $" << deudaPendiente << endl;
    cout << "--------------------------------------------------" << endl;

    if (deudaPendiente <= 0) {
        cout << "EL SOCIO NO TIENE SALDO PENDIENTE." << endl;
        return;
    }

    cuota obj;
    obj.cargar(idSocio); // Nota: Esta función ya pide el monto dentro de tu clase cuota

    // VALIDACIÓN: Comprobar que el importe cargado no supere el saldo pendiente
    if (obj.getImportePagado() > deudaPendiente) {
        cout << "ERROR: EL MONTO INGRESADO DE $" << obj.getImportePagado()
             << ", SUPERA EL SALDO PENDIENTE DE $" << deudaPendiente << "." << endl;
        cout << "NO SE PUDO REGISTRA." << endl;
        return;
    }

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
    cout<<endl;
    char confirmar;
    cout << "DESEA MODIFICAR ESTA CUOTA? (S/N): ";
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 's')
    {
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

    // 1. Obtener tipo de socio
    int posSocio = arcSocio.buscarRegistros(idSocio);
    if (posSocio < 0) return 0;
    objSocio = arcSocio.leerRegistros(posSocio);

    float valorMensual = 10000;
    if(objSocio.getTipoSocio() == 2) valorMensual = 20000;
    else if(objSocio.getTipoSocio() == 3) valorMensual = 30000;

    // 2. BUSCAR LA INSCRIPCIÓN MÁS ANTIGUA
    archivoActividadesSocio arcInscripciones;
    int cantInscripciones = arcInscripciones.contarRegistros();

    int mesMin = 13, anioMin = 3000; // Valores iniciales altos
    bool encontroAlguna = false;

    for(int i = 0; i < cantInscripciones; i++) {
        actividadSocio aux = arcInscripciones.leerRegistro(i);

        if(aux.getIdSocio() == idSocio && aux.getEstado() == true) {
            int mes = aux.getFechaAlta().getMes();
            int anio = aux.getFechaAlta().getAnio();

            // Si encontramos una fecha más chica (más vieja), la guardamos
            if(anio < anioMin || (anio == anioMin && mes < mesMin)) {
                anioMin = anio;
                mesMin = mes;
                encontroAlguna = true;
            }
        }
    }

    if (!encontroAlguna) return 0;

    // 3. Cálculo de meses transcurridos desde esa fecha mínima
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
