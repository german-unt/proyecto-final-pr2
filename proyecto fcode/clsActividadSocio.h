#ifndef CLSACTIVIDADSEDE_H_INCLUDED
#define CLSACTIVIDADSEDE_H_INCLUDED
#include "clsFecha.h"
class actividadSocio{
private:
    int idActividad;
    int idSocio;
    int posicionDeJuego;
    Fecha fechaAlta;
    Fecha fechaBaja;
    bool eliminado;


public:
    void setIdactividad(int);
    void setIdsocio(int);
    void setPosicion(int);
    void setFechaAlta(Fecha);
    void setFechaBaja(Fecha);
    void setEliminado(bool);

    int getIdactividad();
    int getIdsocio();
    int getPosicion();
    Fecha getFechaAlta();
    Fecha getFechaBaja();
    bool getEliminado();

    void cargar();
    void mostrar();
};


#endif // CLSACTIVIDADSEDE_H_INCLUDED
