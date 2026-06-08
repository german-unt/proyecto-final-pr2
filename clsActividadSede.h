#ifndef CLSACTIVIDADSEDE_H_INCLUDED
#define CLSACTIVIDADSEDE_H_INCLUDED
#include "clsFecha.h"
class actividadSede{
private:
    int idActividad;
    int idSede;
    int posicionDeJuego;
    Fecha fechaAlta;
    Fecha fechaBaja;
    bool eliminado;


public:
    void setIdactividad(int);
    void setIdsede(int);
    void setPosicion(int);
    void setFechaAlta(Fecha);
    void setFechaBaja(Fecha);
    void setEliminado(bool);

    int getIdactividad();
    int getIdsede();
    int getPosicion();
    Fecha getFechaAlta();
    Fecha getFechaBaja();
    bool getEliminado();

    void cargar();
    void mostrar();
};


#endif // CLSACTIVIDADSEDE_H_INCLUDED
