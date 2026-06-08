#ifndef CLSARCHIVOSEDE_H_INCLUDED
#define CLSARCHIVOSEDE_H_INCLUDED
#include"clsSede.h"

class archivoSede{
private:
    char nombre[50];
public:
   archivoSede(const char *n="sedes.dat");
   sede leerRegistro(int);
   bool modificarRegistro(sede,int);
   bool grabarRegistro(sede);
   int contarRegistro();
   int buscarRegistro(int);
   void listarRegistro();


};


#endif // CLSARCHIVOSEDE_H_INCLUDED
