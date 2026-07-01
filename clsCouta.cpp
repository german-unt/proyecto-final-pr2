#include <iostream>
#include "clsCuota.h"
#include "clsArchivoSocio.h"
#include "clsSocio.h"
#include "clsManagerCouta.h"
#include "estetico.h"
using namespace std;

void cuota::cargar(int id) {
    archivoSocio arcSocio;
    socio obj;
    int pos = -1;

    if(id == -1) {
        cout << "INGRESE EL ID DEL SOCIO: ";
        cin >> idSocio;
    } else {
        idSocio = id;
    }

    pos = arcSocio.buscarRegistros(idSocio);

    if (pos < 0) {
        cout << "ERROR: EL ID DE SOCIO NO EXISTE EN EL SISTEMA." << endl;
        return;
    }

    obj = arcSocio.leerRegistros(pos);
    if (obj.getEstado() == false) {
        cout << "ERROR: EL SOCIO EXISTE PERO ESTA DADO DE BAJA." << endl;
        return;
    }

    // 1. Calculamos el valor de la cuota mensual como dato INFORMATIVO
    float valorBase = 10000;
    if(obj.getTipoSocio() == 2) valorBase = 20000;
    else if(obj.getTipoSocio() == 3) valorBase = 30000;

    // 2. TALLADO EN PIEDRA: Guardamos la deuda total en el momento del pago
    montoEsperado = obtenerDeudaTotalSocio(idSocio);

    cout << "SOCIO: " << obj.getNombre() << " " << obj.getApellido() << endl;
    cout << "VALOR CUOTA MENSUAL (TIPO " << obj.getTipoSocio() << "): $" << valorBase << endl;
    cout << "DEUDA TOTAL ACUMULADA: $" << montoEsperado << endl;
    cout << "IMPORTE A PAGAR AHORA: ";
    cin >> importePagado;

    cout << "INGRESE FECHA DE PAGO: " << endl;
    fechaPago.Cargar();

    estado = true;
}

void cuota::mostrar() {
blanco();
    cout << "ID SOCIO: " << idSocio << endl;
    cout << "FECHA DE PAGO: ";
    fechaPago.Mostrar();
    cout << endl;

    cout << "DEUDA PREVIA AL PAGO: $" << montoEsperado << endl;
    cout << "IMPORTE ABONADO:      $" << importePagado << endl;
    cout << "SALDO PENDIENTE:      $" << (montoEsperado - importePagado) << endl;
}
void cuota::setIdsocio(int id)
{
    idSocio=id;
}

void cuota::setMontoEsperado(float mon)
{
    montoEsperado=mon;
}
void cuota::setImportePagado(float imp)
{
    importePagado=imp;
}

void cuota::setEstado(bool e)
{
    estado=e;
}

void cuota::setFechaPago(Fecha f)
{
    fechaPago=f;
}

int cuota::getIdsocio()
{
    return idSocio;
}

float cuota::getMontoEsperado()
{
    return montoEsperado;
}
float cuota::getImportePagado()
{
    return importePagado;
}

bool cuota::getEstado()
{
    return estado;
}

Fecha cuota::getFechaPago()
{
    return fechaPago;
}
