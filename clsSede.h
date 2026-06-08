#ifndef CLSSEDE_H_INCLUDED
#define CLSSEDE_H_INCLUDED
class sede{
private:
    int idSede;
    char nombreSede[50];
    char direccion[100];
    int tipoActividad;
    bool eliminado;

public:
    void setIdsede(int);
    void setNombresede(char*);
    void setDireccion(char*);
    void setTipoactividad(int);
    void setEliminado(bool);

    int getIdsede();
    char* getNombresede();
    char* getDireccion();
    int getTipoactividad();
    bool getEliminado();

    void cargar(int id=-1);
    void  mostrar();

};


#endif // CLSSEDE_H_INCLUDED
