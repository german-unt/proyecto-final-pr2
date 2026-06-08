#ifndef CLSSOCIO_H_INCLUDED
#define CLSSOCIO_H_INCLUDED
#include "clsFecha.h"
class socio{
private:
    int idSocio;
    char nombre[20];
    char apellido[20];
    char telefono[15];
   Fecha fechaNacimiento;
    bool eliminado;
    int tipoSocio;
    int email;//cambair a char

public:
    ///sets
    void setIdSocio(int);
    void setNombre(char*);
    void setApellido(char*);
    void setTelefono(char*);
    void setFechaNacimiento(Fecha);
    void setEliminado (bool);
    void setTipoSocio(int);
    void setEmail(int);
    ///gets
    int getIdsocio();
    char* getNombre();
    char* getApellido();
    char* getTelefono();
    Fecha getFechaNacimiento();
    bool getEliminado();
    int getTipoSocio();
    int getEmail();

    void cargar(int id=-1);
    void mostrar();
};


#endif // CLSSOCIO_H_INCLUDED
