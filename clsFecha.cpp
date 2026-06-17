#include <iostream>
#include "clsFecha.h"
#include "funciones.h"
#include <ctime>
using namespace std;

Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::setDia(int d)
{
    dia = d;
}

void Fecha::setMes(int m)
{

}

void Fecha::setAnio(int a)
{

}

int Fecha::getDia()
{
    return dia;
}

int Fecha::getMes()
{
    return mes;
}

int Fecha::getAnio()
{
    return anio;
}

void Fecha::Cargar()
{

    time_t t;
    t=time(NULL);

    tm *hoy=localtime(&t);

    int diaActual=hoy->tm_mday;
    int mesActual=hoy->tm_mon+1;
    int anioActual=hoy->tm_year+1900;

    while(true)
    {

        cout<<"DIA: ";
        cin>>dia;

        cout<<"MES: ";
        cin>>mes;

        cout<<"ANIO: ";
        cin>>anio;

        if(mes<1 || mes>12)
        {
            cout<<"MES INVALIDO"<<endl;
            continue;
        }

        int maxDias;

        if(mes==4 || mes==6 || mes==9 || mes==11)
        {
            maxDias=30;
        }
        else
        {

            if(mes==2)
            {

                if((anio%4==0 && anio%100!=0) || anio%400==0)
                {
                    maxDias=29;
                }
                else
                {
                    maxDias=28;
                }

            }
            else
            {
                maxDias=31;
            }

        }

        if(dia<1 || dia>maxDias)
        {
            cout<<"DIA INVALIDO"<<endl;
            continue;
        }

        Fecha fechaIngresada(dia,mes,anio);
        Fecha fechaActual(diaActual,mesActual,anioActual);

        if(fechaIngresada>fechaActual)
        {
            cout<<"NO SE PUEDE INGRESAR UNA FECHA MAYOR A LA ACTUAL"<<endl;
            continue;
        }

        break;
    }
}
void Fecha::Mostrar()
{
    cout<<dia<<"/"<<mes<<"/"<<anio;
}
int Fecha::obtenerValor()
{
    return anio * 10000 + mes * 100 + dia;
}

bool Fecha::operator>=(Fecha f)
{
    return obtenerValor() >= f.obtenerValor();
}

bool Fecha::operator<=(Fecha f)
{
    return obtenerValor() <= f.obtenerValor();
}

bool Fecha::operator>(Fecha f)
{
    return obtenerValor() > f.obtenerValor();
}

bool Fecha::operator<(Fecha f)
{
    return obtenerValor() < f.obtenerValor();
}

bool Fecha::operator==(Fecha f)
{
    return obtenerValor() == f.obtenerValor();
}
