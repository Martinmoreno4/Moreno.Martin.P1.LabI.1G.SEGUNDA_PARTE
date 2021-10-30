#include "micro.h"
#include "viaje.h"
#include "destino.h"
#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

int hardcodearMicro(eMicro micros[], int tam, int cant, int* pId);

int hardcodearViaje(eViaje viajes[], int tamV, int cant, int* pId, eMicro micros[], int tamM, eDestino destinos[], int tamD);

#endif // DATAWAREHOUSE_H_INCLUDED
