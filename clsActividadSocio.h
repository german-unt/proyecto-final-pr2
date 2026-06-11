#ifndef CLSACTIVIDADSEDE_H_INCLUDED
#define CLSACTIVIDADSEDE_H_INCLUDED
#include "clsFecha.h"
class actividadSocio{
private:
    int idActividad;
    int idSocio;
    Fecha fechaAlta;
    Fecha fechaBaja;
    bool estado;


public:
    void setIdactividad(int);
    void setIdSocio(int);
    void setFechaAlta(Fecha);
    void setFechaBaja(Fecha);
    void setEstado(bool);

    int getIdactividad();
    int getIdSocio();
    Fecha getFechaAlta();
    Fecha getFechaBaja();
    bool getEstado();

    void cargar();
    void mostrar();
};


#endif // CLSACTIVIDADSEDE_H_INCLUDED
