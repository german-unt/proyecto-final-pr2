#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include"funciones.h"
#include "clsActividad.h"
#include "clsSocio.h"
#include "clsSede.h"
#include "clsCuota.h"
#include "clsActividad.h"
//---------------------------
#include "clsArchivoSocio.h"
#include"clsArchivoSede.h"
#include"clsArchivoCuota.h"
#include"clsArchivoActividadesSocio.h"
#include"clsArchivoActividades.h"
void menuPrincipal();
void menuSocios();
void menuActividades();
void menuCuota();
void menuSedes();
void listados();

void altaSocio();
void bajaSocio();
void modificarSocio();
void listarSocio();

void altaActividad();
void bajaActividad();
void modificarActividad();
void listarActividad();

void altaSede();
void bajaSede();
void modificarSede();
void listarSede();

void altaCuota();
void bajaCuota();
void modificarCuota();
void listarCuota();

void listadoSociosApellido();
void listadoSociosTipo();
void listadoCuotaSocio();
void listadoCuotaMonto();
void listadoSedeXid();
void listadoActividadXid();
void listadoParticipacionesSocio();
void listadoParticipacionesActividad();

void recaudacionAnual();
void listarActividadesDeSocio();
actividad buscarActividadPorId(int idActividad);

#endif // FUNCIONES_H_INCLUDED
