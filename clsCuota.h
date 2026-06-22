#ifndef CLSCUOTA_H_INCLUDED
#define CLSCUOTA_H_INCLUDED
#include "clsFecha.h"

class cuota {
private:
    int idSocio;
    float importePagado;
    float montoEsperado;
    Fecha fechaPago;
    bool estado;

public:
    cuota() { estado = true; importePagado = 0; montoEsperado = 0; }

    // Setters y Getters
    void setIdsocio(int id);
    void setImportePagado(float imp);
    void setMontoEsperado(float mon);
    void setFechaPago(Fecha f);
    void setEstado(bool e);

    int getIdsocio();
    float getImportePagado();
    float getMontoEsperado();
    Fecha getFechaPago();
    bool getEstado();

    // Métodos de acción
    void cargar(int id = -1);
    void mostrar();
};

#endif
