#include"fecha.h"
#include "micro.h"
#include "destino.h"
#include "empresa.h"
#include "chofer.h"
#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eViaje;

#endif // VIAJE_H_INCLUDED

int inicializarViajes(eViaje viajes[], int tam);
int buscarLibreViaje(eViaje viajes[], int tam);
void mostrarViaje(eViaje viaje, eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE);
int mostrarViajes(eViaje viajes[], eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE);
int altaViaje(eViaje viaje[], int tamV, eMicro micros[], int tamM, eEmpresa empresas[],int tamE ,eTipo tipos[], int tamT, eDestino destinos[], int tamD, int* pIdViaje, eChofer choferes[], int tamC);
int mostrarViajesDeUnMicro(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC, eViaje viajes[], int tamV, eDestino destinos[], int tamD);
int mostrarSumaDePreciosDeUnMicro(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC, eViaje viajes[], int tamV, eDestino destinos[], int tamD);
