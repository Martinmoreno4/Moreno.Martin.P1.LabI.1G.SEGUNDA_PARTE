#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"
#include "destino.h"
#include "micro.h"

int inicializarViajes(eViaje viajes[], int tam)
{
    int todoOk = 0;
    if( viajes != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            viajes[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreViaje(eViaje viajes[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(viajes[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarViaje(eViaje viaje, eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE)
{
    char empresaMicro[20];
    char descDestino[20];

    if(cargarDescripcionDestino(destinos, tamD, viaje.idDestino, descDestino) == 1
       && cargarEmpresaMicro(micros, tam, viaje.idMicro, empresaMicro, empresas, tamE) == 1)
    {
        printf("    %d    %10s    %10s   %d/%d/%d\n",
        viaje.id,
        empresaMicro,
        descDestino,
        viaje.fecha.dia,
        viaje.fecha.mes,
        viaje.fecha.anio
        );
    }


}

int mostrarViajes(eViaje viajes[], eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE)
{
    int todoOk =0;
    int flag = 1;
    if(micros != NULL && tam > 0 && destinos != NULL && empresas != NULL)
    {
        printf("          *** Lista de viajes ***\n");
        printf("----------------------------------------------------------\n");
        printf("    id        micro      destino   Fecha\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!viajes[i].isEmpty)
            {
                mostrarViaje(viajes[i], micros, tam, destinos, tamD, empresas, tamE);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay viajes para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int altaViaje(eViaje viaje[], int tamV, eMicro micros[], int tamM, eEmpresa empresas[],int tamE ,eTipo tipos[], int tamT, eDestino destinos[], int tamD, int* pIdViaje, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    eViaje auxViaje;

    if( micros != NULL && tamM>0 && pIdViaje != NULL && empresas != NULL && tamE>0 && tipos!= NULL && tamD > 0 && viaje != NULL && tamV >0 && tipos != NULL && tamE >0)
    {
        system("cls");
        printf("     *** Alta Viaje ***\n\n");

        indice = buscarLibreViaje(viaje, tamV);
        if(indice == -1)
        {
            printf("no hay lugar \n");
        }
        else
        {

            auxViaje.id = *pIdViaje;
            (*pIdViaje)++;

            mostrarDestinos(destinos, tamD);
            printf("ingrese id destino: ");
            scanf("%d", &auxViaje.idDestino);
            while(!validarDestinos(auxViaje.idDestino, destinos, tamD))
            {
                mostrarDestinos(destinos, tamD);
                printf("id invalido, ingrese id destino VALIDO: ");
                scanf("%d", &auxViaje.idDestino);
            }

            mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE, choferes, tamC);
            printf("ingrese id Micro: ");
            scanf("%d", &auxViaje.idMicro);
            while(buscarMicroId(micros, tamM, auxViaje.idMicro) == -1)
            {
                mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE, choferes, tamC);
                printf("id invalido, ingrese id Micro VALIDO: ");
                scanf("%d", &auxViaje.idMicro);
            }

            printf("ingrese fecha: ");
            scanf("%d/%d/%d", &auxViaje.fecha.dia, &auxViaje.fecha.mes, &auxViaje.fecha.anio);

            auxViaje.isEmpty = 0;

            viaje[indice] = auxViaje;

            todoOk = 1;
        }


    }
    return todoOk;
}

int mostrarViajesDeUnMicro(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC, eViaje viajes[], int tamV, eDestino destinos[], int tamD)
{
    int todoOk = 0;
    int indice;
    int id;

    if(micros != NULL && tam>0)
    {
        system("cls");
        printf("     *** Viajes de un Micro ***\n\n");
        mostrarMicros(micros, tam, tipos, tamT, empresas, tamE, choferes, tamC);
        printf("     *** Seleccione Micros para mostrar los viajes ***\n\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMicroId(micros, tam, id);

        if(indice == -1)
        {
            printf("El id; %d no esta registrado\n", id);
        }
        else
        {
            for(int i=0; i<tam; i++)
            {
                if(!viajes[i].isEmpty && (viajes[i].idMicro ==micros[indice].id))
                {
                    mostrarViaje(viajes[i], micros, tam, destinos, tamD, empresas, tamE);
                }
            }
        }
    }
    return todoOk;
}

int mostrarSumaDePreciosDeUnMicro(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC, eViaje viajes[], int tamV, eDestino destinos[], int tamD)
{
    int todoOk = 0;
    int indice;
    int id;
    int flagPrecio=0;
    float precio=0;
    float acumPrecio=0;

    if(micros != NULL && tam>0)
    {
        system("cls");
        printf("     *** Precios acumulados de un Micro ***\n\n");
        mostrarMicros(micros, tam, tipos, tamT, empresas, tamE, choferes, tamC);
        printf("     *** Seleccione Micros para mostrar el Precio ***\n\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMicroId(micros, tam, id);

        if(indice == -1)
        {
            printf("El id; %d no esta registrado\n", id);
        }
        else
        {
            for(int i=0; i<tam; i++)
            {
                if(!viajes[i].isEmpty && (viajes[i].idMicro == micros[indice].id))
                {
                    cargarPrecioDestino(destinos, tamD, viajes[i].idDestino, precio);
                    acumPrecio += precio;
                    flagPrecio=1;
                }
            }
        }
        if(flagPrecio!=0)
        {
            printf("el precio acumulado de este micro es: %.2f\n", acumPrecio);
        }
        else
        {
            printf("error en el proceso\n");
        }

    }
    return todoOk;
}
