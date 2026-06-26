#include <iostream>
#include "clsCuota.h"
#include "clsArchivoSocio.h"
#include "clsSocio.h"
#include "clsManagerCouta.h"

using namespace std;

void cuota::cargar(int id) {
    archivoSocio arcSocio;
    socio obj;
    int pos = -1;

    // 1. Lógica de entrada del ID (si no vino por parámetro)
    if(id == -1) {
        cout << "INGRESE EL ID DEL SOCIO: ";
        cin >> idSocio;
    } else {
        idSocio = id;
    }

    // 2. Buscar al socio en el archivo
    pos = arcSocio.buscarRegistros(idSocio);

    // 3. Validar: ¿Existe el ID?
    if (pos < 0) {
        cout << "ERROR: EL ID DE SOCIO NO EXISTE EN EL SISTEMA." << endl;
        // Aquí deberías manejar el error, por ejemplo, saliendo de la función

        return;
    }

    // 4. Leer el objeto y validar: ¿Está activo?
    obj = arcSocio.leerRegistros(pos);
    if (obj.getEstado() == false) {
        cout << "ERROR: EL SOCIO EXISTE PERO ESTA DADO DE BAJA." << endl;

        return;
    }

    // 5. Si pasó las validaciones, procedemos con la asignación de valores
    // Calculamos el monto esperado según su tipo
    float valorBase = 10000;
    if(obj.getTipoSocio() == 2) valorBase = 20000;
    else if(obj.getTipoSocio() == 3) valorBase = 30000;

    montoEsperado = valorBase;

    cout << "SOCIO: " << obj.getNombre() << " " << obj.getApellido() << endl;
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
    cout<<endl;
    // Ahora la deuda se calcula de forma externa y precisa
    cout << "IMPORTE TOTAL A DEBER: $" << obtenerDeudaTotalSocio(idSocio) << endl;
    cout << endl<<endl;
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
