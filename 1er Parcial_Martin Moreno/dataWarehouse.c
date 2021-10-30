#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "micro.h"
#include "viaje.h"

int idEmpresa[5]={1000, 1001, 1000, 1002, 1003};

int idTipo[5]={5000, 5002, 5001, 5003, 5002};

int idChofer[5]={3000, 3004, 3001, 3003, 3002};

int capacidad[5]={35, 40, 10, 25, 20};

int hardcodearMicro(eMicro micros[], int tam, int cant, int* pId)
{
    int contador = -1;

    if(micros !=NULL && tam>0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i=0; i<cant; i++)
        {
            micros[i].id= *pId;
            (*pId)++;
            micros[i].idEmpresa = idEmpresa[i];
            micros[i].idTipo = idTipo[i];
            micros[i].idChofer = idChofer[i];
            micros[i].capacidad= capacidad[i];
            micros[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}

eFecha fechas[5]={
    {10, 12 ,2021},
    {14, 12 ,2021},
    {17, 12 ,2021},
    {22, 12 ,2021},
    {26, 12 ,2021}
};

int hardcodearViaje(eViaje viajes[], int tamV, int cant, int* pId, eMicro micros[], int tamM, eDestino destinos[], int tamD)
{
    int contador = -1;

    if(viajes !=NULL && tamV>0 && cant >= 0 && cant <= tamV && pId != NULL && tamM>0 && cant <= tamM && tamD>0 && cant <= tamD)
    {
        contador = 0;
        for(int i=0; i<cant; i++)
        {
            viajes[i].id= *pId;
            (*pId)++;
            viajes[i].idMicro = micros[i].id;
            viajes[i].idDestino = destinos[i].id;
            viajes[i].fecha.dia = fechas[i].dia;
            viajes[i].fecha.mes = fechas[i].mes;
            viajes[i].fecha.anio = fechas[i].anio;
            viajes[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}
