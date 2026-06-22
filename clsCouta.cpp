#include <iostream>
#include "clsCuota.h"
#include "clsArchivoSocio.h"
#include "clsSocio.h"
#include "clsManagerCouta.h"

using namespace std;

void cuota::cargar(int id) {
/// VALIDAR LOS IDs SI EXITEN O NO
    if(id == -1) {
        cout << "INGRESE EL ID DEL SOCIO: ";
        cin >> idSocio;
    } else {
        idSocio = id;
    }

    // Obtenemos el tipo de socio para saber cuánto debe pagar
    archivoSocio arcSocio;
    int pos = arcSocio.buscarRegistros(idSocio);
    float valorBase = 10000; // Valor por defecto

    if(pos >= 0) {
        socio obj = arcSocio.leerRegistros(pos);
        if(obj.getTipoSocio() == 2) valorBase = 20000;
        else if(obj.getTipoSocio() == 3) valorBase = 30000;
    }

    montoEsperado = valorBase;

    cout << "IMPORTE A PAGAR (Esperado: $" << montoEsperado << "): ";
    cin >> importePagado;

    cout << "INGRESE FECHA DE PAGO: " << endl;
    fechaPago.Cargar();

    estado = true;
}

void cuota::mostrar() {
    cout << "ID SOCIO: " << idSocio << endl;
    cout << "IMPORTE PAGADO: $" << importePagado << endl;
    cout << "FECHA DE PAGO: ";
    fechaPago.Mostrar();
    // Ahora la deuda se calcula de forma externa y precisa
    cout << "IMPORTE TOTAL A DEBER: $" << obtenerDeudaTotalSocio(idSocio) << endl;
    cout << endl;
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
