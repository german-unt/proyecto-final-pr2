#ifndef CLSACTIVIDAD_H_INCLUDED
#define CLSACTIVIDAD_H_INCLUDED

class actividad {
private:
    int idActividad;
    int idSede;
    char nombreActividad[20];
    bool estado;
public:
    void setIdactividad(int);
    void setNombreactividad(char*);
    void setEstado(bool);

    int getIdactividad();
    char* getNombreActividad();
    bool getEstado();

    void cargar(int id=-1);
    void mostrar();
};


#endif // CLSACTIVIDAD_H_INCLUDED
