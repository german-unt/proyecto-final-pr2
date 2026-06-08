#ifndef CLSCUOTA_H_INCLUDED
#define CLSCUOTA_H_INCLUDED
/// capaz sea necesario unir o con un SOCIO.H O ARCHIVOSOCIO.H, O CON UNA HERENCIA
class cuota{
private :
    int idSocio;
    float cuota;
    bool deuda;
    bool eliminado;
public:
    void setIdsocio(int);
    void setCuota (float);
    void setDeuda(bool);
    void setEliminado(bool);

    int getIdsocio();
    float getCuota();
    bool getDeuda();
    bool getEliminado();

    void cargar(int id=-1);
    void mostrar();
};


#endif // CLSCUOTA_H_INCLUDED
