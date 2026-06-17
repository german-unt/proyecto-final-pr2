#ifndef CLSMANAGERINFORMES_H_INCLUDED
#define CLSMANAGERINFORMES_H_INCLUDED
#include "clsActividad.h"
#include "clsSocio.h"
#include "clsCuota.h"
#include "clsActividadSocio.h"
#include"clsManagerSocio.h"
#include"clsManagerActividad.h"
//---------------------------
#include "clsArchivoSocio.h"
#include"clsArchivoCuota.h"
#include"clsArchivoActividadesSocio.h"
#include"clsArchivoActividades.h"
///REVISAR
void informes();
void recaudacionAnual();
void listarActividadesDeSocio();
actividad buscarActividadPorId(int idActividad);
void recaudacionXActividad();
void porcentajeInscripciones();
void ranking();
void deudores();


#endif // CLSMANAGERINFORMES_H_INCLUDED
