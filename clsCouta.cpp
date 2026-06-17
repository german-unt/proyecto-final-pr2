#include<iostream>
#include<ctime>

#include"clsCuota.h"
#include"clsSocio.h"
#include"clsArchivoSocio.h"

using namespace std;

void cuota::cargar(int id)
{

    if(id == -1)
    {
        cout<<"INGRESE EL ID DEL SOCIO: ";
        cin>>idSocio;
    }
    else
    {
        idSocio=id;
    }

    archivoSocio arcSocio;

    int pos=arcSocio.buscarRegistros(idSocio);

    if(pos>=0)
    {

        socio objSocio=arcSocio.leerRegistros(pos);

        switch(objSocio.getTipoSocio())
        {

        case 1:
            cuota=10000;
            break;

        case 2:
            cuota=20000;
            break;

        case 3:
            cuota=30000;
            break;

        default:
            cuota=10000;
            break;
        }
    }

    cout<<"INGRESE FECHA DEL ULTIMO PAGO: "<<endl;
    FechaPago.Cargar();

    estado=true;
}

void cuota::mostrar()
{

    cout<<"ID SOCIO: "<<idSocio<<endl;
    cout<<"VALOR DE LA CUOTA: $"<<cuota<<endl;
    cout<<"ULTIMO PAGO: ";
    FechaPago.Mostrar();
    cout<<endl;

    cout<<"DEUDA ACTUAL: $"<<calcularDeuda()<<endl;
}

float cuota::calcularDeuda()
{

    time_t t=time(NULL);

    tm *fechaActual=localtime(&t);

    int mesActual=fechaActual->tm_mon+1;
    int anioActual=fechaActual->tm_year+1900;

    int mesesAdeudados=
        (anioActual-FechaPago.getAnio())*12+
        (mesActual-FechaPago.getMes());

    if(mesesAdeudados<0)
    {
        mesesAdeudados=0;
    }

    return mesesAdeudados*cuota;
}

void cuota::setIdsocio(int id)
{
    idSocio=id;
}

void cuota::setCuota(float c)
{
    cuota=c;
}

void cuota::setEstado(bool e)
{
    estado=e;
}

void cuota::setFechaPago(Fecha f)
{
    FechaPago=f;
}

int cuota::getIdsocio()
{
    return idSocio;
}

float cuota::getCuota()
{
    return cuota;
}

bool cuota::getEstado()
{
    return estado;
}

Fecha cuota::getFechaPago()
{
    return FechaPago;
}
