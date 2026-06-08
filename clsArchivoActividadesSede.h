#ifndef CLSARCHIVOACTIVIDADESSEDE_H_INCLUDED
#define CLSARCHIVOACTIVIDADESSEDE_H_INCLUDED
#include"funciones.h"
#include "clsActividadSede.h"
class archivoActividadesSede{
private:
    char nombre[50];
public:
archivoActividadesSede(const char *n="actividadesXsede.dat" );
actividadSede leerRegistro(int);
bool grabarRegistro(actividadSede);
bool modificarRegistro(actividadSede, int);
int contarRegistros();
int buscarRegistro(int);
void listarRegistros();

};


#endif // CLSARCHIVOACTIVIDADESSEDE_H_INCLUDED
