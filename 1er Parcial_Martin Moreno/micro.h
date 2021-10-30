#include "tipo.h"
#include "empresa.h"
#include "chofer.h"
#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED

typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int idChofer;
    int capacidad;
    int isEmpty;

}eMicro;

#endif // MICRO_H_INCLUDED

int menu();
int menuModificacion();

int inicializarMicros(eMicro micros[], int tam);
int altaMicro(eMicro micros[], int tam, int* nextId, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);
int buscarLibre(eMicro micros[], int tam);
int buscarMicroId(eMicro micros[], int tam, int id);
void mostrarMicro(eMicro micro, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC);
int mostrarMicros(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC);
int modificarMicro(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);
int bajaMicro(eMicro micros[], int tam, eTipo tipos[],int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC);
int ordenarMicros(eMicro micros[], int tam);
int cargarEmpresaMicro(eMicro micros[],int tam, int id, char empresaDesc[], eEmpresa empresa[], int tamE);
int mostrarMicrosIdEmpresa(int idEmpresa, eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);
int mostrarMicrosDeUnaEmpresa(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);
int mostrarMicrosIdTipos(int idTipo, eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);
int mostrarMicrosDeUnTipo(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);
int mostrarPorcentajeVipEmpresa(eMicro micros[], int tam, eEmpresa empresas[],int tamE);
int mostrarPorcentajeVipIdEmpresa(int idEmpresa, eMicro micros[], int tam, eEmpresa empresas[],int tamT);
int mostraMicrosTodasEmpresas(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);
int empresaConMasCapacidad(eMicro micros[], int tam, eEmpresa empresas[],int tamE);
int empresaConMenorCantidadDeMicros(eMicro micros[], int tam, eEmpresa empresas[],int tamE);

