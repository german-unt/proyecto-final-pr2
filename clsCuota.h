#ifndef CLSCUOTA_H_INCLUDED
#define CLSCUOTA_H_INCLUDED
#include "clsFecha.h"
/// capaz sea necesario unir o con un SOCIO.H O ARCHIVOSOCIO.H, O CON UNA HERENCIA
class cuota{
private :
    int idSocio;
    float cuota;
    float deuda;
    bool estado;
    Fecha FechaPago;
public:
    void setIdsocio(int);
    void setCuota (float);
    void setDeuda(float);
    void setEstado(bool);
    void setFechaPago(Fecha);

    int getIdsocio();
    float getCuota();
    float getDeuda();
    bool getEstado();
    Fecha getFechaPago();

    void cargar(int id=-1);
    void mostrar();
};


#endif // CLSCUOTA_H_INCLUDED
