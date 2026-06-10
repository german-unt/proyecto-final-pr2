#ifndef CLSACTIVIDAD_H_INCLUDED
#define CLSACTIVIDAD_H_INCLUDED

class actividad {
private:
    int idActividad;
    int idSede;
    char nombreActividad[20];
    bool eliminado;
public:
    void setIdactividad(int);
    void setNombreactividad(char*);
    void setEliminado(bool);

    int getIdactividad();
    char* getNombreActividad();
    bool getEliminado();

    void cargar(int id=-1);
    void mostrar();
};


#endif // CLSACTIVIDAD_H_INCLUDED
