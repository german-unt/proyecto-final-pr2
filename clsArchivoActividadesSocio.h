#ifndef CLSARCHIVOACTIVIDADESSOCIO_H_INCLUDED
#define CLSARCHIVOACTIVIDADESSOCIO_H_INCLUDED
#include"funciones.h"
#include "clsActividadSocio.h"
class archivoActividadesSocio{
private:
    char nombre[50];
public:
archivoActividadesSocio(const char *n="actividadesXsocio.dat" );
actividadSocio leerRegistro(int);
bool grabarRegistro(actividadSocio);
bool modificarRegistro(actividadSocio, int);
int contarRegistros();
int buscarRegistro(int);
void listarRegistros();
int buscarRegistroSocio(int);
};


#endif // CLSARCHIVOACTIVIDADESSOCIO_H_INCLUDED
