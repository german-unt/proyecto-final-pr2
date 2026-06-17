#ifndef CLSCUOTA_H_INCLUDED
#define CLSCUOTA_H_INCLUDED
#include "clsFecha.h"

class cuota{
private:
    int idSocio;
    float cuota;
    bool estado;
    Fecha FechaPago;

public:
    void setIdsocio(int);
    void setCuota(float);
    void setEstado(bool);
    void setFechaPago(Fecha);

    int getIdsocio();
    float getCuota();
    bool getEstado();
    Fecha getFechaPago();

    float calcularDeuda();

    void cargar(int id=-1);
    void mostrar();
};

#endif // CLSCUOTA_H_INCLUDED
