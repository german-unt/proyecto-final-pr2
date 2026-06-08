#ifndef CLSARCHIVOSOCIO_H_INCLUDED
#define CLSARCHIVOSOCIO_H_INCLUDED
#include"clsSocio.h"
class archivoSocio{
private:
    char nombre[50];
public:
    archivoSocio(const char *n="socios.dat");
    socio leerRegistros(int);
    bool grabarRegistros(socio);
    bool modificarRegistro(socio,int);
    int contarRegistros();
    int buscarRegistros(int);
    void listarRegistros();

};
#endif // CLSARCHIVOSOCIO_H_INCLUDED
