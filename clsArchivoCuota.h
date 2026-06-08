#ifndef CLSARCHIVOCUOTA_H_INCLUDED
#define CLSARCHIVOCUOTA_H_INCLUDED
#include"funciones.h"
#include"clsCuota.h"
class archivoCuota{
private:
    char nombre[50];
public:
    archivoCuota(const char *n="cuota.dat");
    cuota leerRegistro(int);
    bool grabarRegistro(cuota);
    bool modificarRegistro(cuota,int);
    int contarRegistros();
    int buscarRegistros(int);
    void listarRegistros();

};


#endif // CLSARCHIVOCUOTA_H_INCLUDED
