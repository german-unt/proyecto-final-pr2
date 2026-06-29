#ifndef CLSMANAGERCOUTA_H_INCLUDED
#define CLSMANAGERCOUTA_H_INCLUDED
#include"clsCuota.h"
#include"clsArchivoCuota.h"
void menuCuota();
///REVISAR
void altaCuota();
void bajaCuota();
void modificarCuota();
void listarCuota();
float obtenerDeudaTotalSocio(int idsocio);
float obtenerTotalPagadoSocio(int idSocio);
float calcularDeudaHistorica (int idSocio);

#endif // CLSMANAGERCOUTA_H_INCLUDED
