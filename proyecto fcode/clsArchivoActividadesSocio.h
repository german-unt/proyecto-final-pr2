#ifndef CLSARCHIVOACTIVIDADESSEDE_H_INCLUDED
#define CLSARCHIVOACTIVIDADESSEDE_H_INCLUDED
#include"funciones.h"
#include "clsActividadSocio.h"
class archivoActividadesSocio{
private:
    char nombre[50];
public:
archivoActividadesSocio(const char *n="actividadesXsede.dat" );
actividadSocio leerRegistro(int);
bool grabarRegistro(actividadSocio);
bool modificarRegistro(actividadSocio, int);
int contarRegistros();
int buscarRegistro(int);
void listarRegistros();

};


#endif // CLSARCHIVOACTIVIDADESSEDE_H_INCLUDED
