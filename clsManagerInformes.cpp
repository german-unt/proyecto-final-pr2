#include <iostream>
#include"clsManagerInformes.h"

using namespace std;
void informes()
{
    int opc;

    while(true)
    {
        system("cls");

        cout<<"MENU INFORMES"<<endl;
        cout<<"=========================="<<endl;
        cout<<"1 - Recaudacion anual"<<endl;
        cout<<"2 - Recaudacion por actividad"<<endl;
        cout<<"3 - Porcentaje de inscripciones por cada actividad"<<endl;
        cout<<"4 - Listar todas las actividades de un socio"<<endl;
        cout<<"5 - Ranking de actividades"<<endl;
        cout<<"6 - Listar socios con deudas pendientes"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=========================="<<endl;

        cin>>opc;

        system("cls");

        switch(opc)
        {
        case 1:
            recaudacionAnual();
            break;

        case 2:
            recaudacionXActividad();
            break;

        case 3:
            porcentajeInscripciones();
            break;

        case 4:
            listarActividadesDeSocio();
            break;

        case 5:
            ranking();
            break;

        case 6:
            deudores();
            break;

        case 0:
            return;
        }

        system("pause");
    }
}

///INFORME : RECAUDACION ANUAL
void recaudacionAnual()
{

    archivoCuota arc;

    int cant = arc.contarRegistros();

    float total=0;

    for(int i=0; i<cant; i++)
    {

        cuota obj = arc.leerRegistro(i);

        if(obj.getEstado())
        {

            total += obj.getCuota();
        }
    }
    cout<<"- - - - - - - - - - - - - - - "<<endl<<endl;
    cout<<"RECAUDACION ANUAL: $"<<total<<endl<<endl;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
}
///INFORME :RECAUDACION POR ACTIVIDAD
void recaudacionXActividad()
{

    archivoActividades arcAct;
    archivoActividadesSocio arcSocio;
    archivoCuota arcCuota;

    int cantAct=arcAct.contarRegistros();
    int cantSoc=arcSocio.contarRegistros();
    int cantCuo=arcCuota.contarRegistros();

    for(int i=0; i<cantAct; i++)
    {

        actividad act=arcAct.leerRegistros(i);

        float total=0;

        for(int j=0; j<cantSoc; j++)
        {

            actividadSocio as=arcSocio.leerRegistro(j);

            if(as.getIdactividad()==act.getIdactividad())
            {

                for(int k=0; k<cantCuo; k++)
                {

                    cuota c=arcCuota.leerRegistro(k);

                    if(c.getIdsocio()==as.getIdSocio())
                    {

                        total+=c.getCuota();
                    }
                }
            }
        }

        cout<<"ACTIVIDAD: "<<act.getNombreActividad()<<endl;
        cout<<"RECAUDACION: $"<<total<<endl<<endl;
    }
}
///INFORME : PORCENTAJE DE INSCRIPCIONES
void porcentajeInscripciones()
{

    archivoActividades arcAct;
    archivoActividadesSocio arc;

    int cantAct = arcAct.contarRegistros();
    int cant = arc.contarRegistros();

    int total = 0;

    for(int i=0; i<cant; i++)
    {

        actividadSocio obj = arc.leerRegistro(i);

        if(obj.getEstado()==true)
        {
            total++;
        }
    }

    for(int i=0; i<cantAct; i++)
    {

        actividad act = arcAct.leerRegistros(i);

        int cantidad = 0;

        for(int j=0; j<cant; j++)
        {

            actividadSocio obj = arc.leerRegistro(j);

            if(obj.getEstado()==true)
            {

                if(obj.getIdactividad()==act.getIdactividad())
                {
                    cantidad++;
                }
            }
        }

        float porcentaje = 0;

        if(total>0)
        {
            porcentaje = cantidad * 100.0 / total;
        }

        cout<<"ACTIVIDAD: "<<act.getNombreActividad()<<endl;
        cout<<"PORCENTAJE DE INSCRIPCIONES: "<<porcentaje<<"%"<<endl;
        cout<<endl;
    }
}
///BUSCA ACTIVIDAD POR ID PARA REALIZAR INFORME ACTIVIDADES QUE HACE CADA SOCIO
actividad buscarActividadPorId(int idActividad)
{

    archivoActividades arc;

    int cant = arc.contarRegistros();

    for(int i=0; i<cant; i++)
    {

        actividad obj = arc.leerRegistros(i);

        if(obj.getIdactividad()==idActividad)
        {
            return obj;
        }
    }

    actividad aux;
    aux.setIdactividad(-1);

    return aux;
}
///INFORME : ACTIVIDADES QUE HACE CADA SOCIO
void listarActividadesDeSocio()
{

    int idSocio;

    cout<<"INGRESE EL ID DEL SOCIO: ";
    cin>>idSocio;

    archivoActividadesSocio arc;

    int cant = arc.contarRegistros();

    bool encontro=false;

    for(int i=0; i<cant; i++)
    {

        actividadSocio reg = arc.leerRegistro(i);

        if(reg.getIdSocio()==idSocio &&
                reg.getEstado())
        {

            actividad act =
                buscarActividadPorId(reg.getIdactividad());

            if(act.getIdactividad()!=-1)
            {

                act.mostrar();
                cout<<endl;

                encontro=true;
            }
        }
    }

    if(!encontro)
    {
        cout<<"EL SOCIO NO TIENE ACTIVIDADES REGISTRADAS"<<endl;
    }
}

///INFORME :RANKING ACTIVIDADES
void ranking()
{
    archivoActividadesSocio arcActiviXSocio;
    archivoActividades arcActivida;

    int cantAxS= arcActiviXSocio.contarRegistros();
    int cantActi= arcActivida.contarRegistros();

    if(cantActi<=0)
    {
        cout<< "ERROR: NO HAY ACTIVIDADES REGISTRADAS"<<endl;    /// VALIDACION DE REGISTROS
        return;
    }

    int *VcontarActividad= new int[cantActi]();
    actividad *VranquearActividad = new actividad[cantActi];
    actividadSocio registro;
    actividad auxActi;
    int aux;

    for(int i= 0; i<cantActi; i++)
    {
        VranquearActividad[i]= arcActivida.leerRegistros(i);
    }

    for(int i= 0; i<cantAxS; i++)
    {
        registro= arcActiviXSocio.leerRegistro(i);

        if (registro.getEstado()==true) ///VALIDA QUE LOS REGISTROS ESTEN ACTIVOS
        {
            for(int j=0; j<cantActi; j++)
            {
                if(registro.getIdactividad()==VranquearActividad[j].getIdactividad())
                {
                    VcontarActividad[j]++;
                    break;
                }
            }
        }
    }
    for(int a=0; a<cantActi-1; a++)
    {

        for(int b=0; b<cantActi-a-1; b++)
        {

            if(VcontarActividad[b]<VcontarActividad[b+1])
            {
                aux= VcontarActividad[b];
                VcontarActividad[b]= VcontarActividad[b+1];
                VcontarActividad[b+1]= aux;
                ///ORDENAMOS EL CONTADOR Y EL REGISTRO TAMBIEN
                auxActi= VranquearActividad[b];
                VranquearActividad[b]= VranquearActividad[b+1];
                VranquearActividad[b+1]= auxActi;
            }
        }
    }
    for(int i=0; i<cantActi; i++)
    {
        if (VcontarActividad[i]>0)
        {
            cout<< "#"<<i+1<<" : "<<VranquearActividad[i].getNombreActividad()<<". TOTAL INSCRIPTOS: "<<VcontarActividad[i]<<endl;
            cout<<"- - - - - - - - - - - - - - - "<<endl;

        }
    }

    delete[] VranquearActividad;
    delete[] VcontarActividad;
}

///INFORME :SOCIOS DEUDORES
void deudores()
{
    archivoCuota arc;
    cuota deudor;
    archivoSocio arcSocio;
    int pos;
    socio obj;
    int contDeudores=0;
    int cant=arc.contarRegistros();

    cout<<"SOCIOS CON DEUDAS PENDIENTES: "<<endl;
    for(int i =0; i<cant; i++)
    {
        deudor= arc.leerRegistro(i);
        if(deudor.calcularDeuda()>0)
        {
            if(deudor.getEstado())
            {
                pos=arcSocio.buscarRegistros(deudor.getIdsocio());
                obj=arcSocio.leerRegistros(pos);
                if(pos>=0)
                {
                    cout<<"ID: "<<deudor.getIdsocio()<<" | APELLIDO Y NOMBRE: "<<obj.getApellido()<<" "<<obj.getNombre()
                        <<" | DEUDA TOTAL: $"<<deudor.calcularDeuda()<<endl<<endl;
                        cout<<"==============================================================================="<<endl;
                    contDeudores++;
                }
            }
        }

    }
    cout<<"CANTIDAD TOTAL DE SOCIOS CON DEUDA: "<<contDeudores;
}

