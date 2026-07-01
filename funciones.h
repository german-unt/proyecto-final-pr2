#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include"funciones.h"
#include "clsActividad.h"
#include "clsSocio.h"
#include "clsCuota.h"
#include "clsActividadSocio.h"
#include"clsManagerSocio.h"
#include"clsManagerActividad.h"
#include"clsManagerInformes.h"
//---------------------------
#include "clsArchivoSocio.h"
#include"clsArchivoCuota.h"
#include"clsArchivoActividadesSocio.h"
#include"clsArchivoActividades.h"
#include "estetico.h"
void menuPrincipal();

void listadoSociosApellido();//borrar .dat
void listadoSociosTipo();
void listadoCuotaMonto();


void consultas();
void consultasSocios();
void consultaXActividad();
void consultasDeEstado();
void rangoDeFechas();
void consultaXSocio();
void consultaResumen();
void menuConsultaActividades();



#endif // FUNCIONES_H_INCLUDED
