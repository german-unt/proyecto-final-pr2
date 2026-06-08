#ifndef CLSARCHIVOACTIVIDADES_H_INCLUDED
#define CLSARCHIVOACTIVIDADES_H_INCLUDED
#include "funciones.h"
#include "clsActividad.h"
class archivoActividades{
private:
    char nombre[50];
public:
    archivoActividades(const char *n="actividades.dat");
    actividad leerRegistros(int);
    bool grabarRegistros(actividad);
    bool modificarRegistros(actividad,int);
    int contarRegistros();
    int buscarRegistros(int);
    void listarRegistros();
} ;



#endif // CLSARCHIVOACTIVIDADES_H_INCLUDED
