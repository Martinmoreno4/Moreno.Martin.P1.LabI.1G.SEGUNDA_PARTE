#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int mostrarDestinos(eDestino destinos[], int tam)
{
    int todoOk = 0;
    if(destinos != NULL && tam > 0)
    {

        printf(" *** Comidas ***\n\n");
        printf("   Id        Descripcion      precios\n");
        for(int i=0; i<tam; i++)
        {
            printf("   %d       %10s    %.2f\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }

        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionDestino(eDestino destinos[],int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(destinos != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(destinos[i].id == id)
            {
                strcpy(descripcion, destinos[i].descripcion);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int validarDestinos(int id, eDestino destinos[], int tam)
{
    int todoOk = 0;
    if(destinos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(destinos[i].id == id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarPrecioDestino(eDestino destinos[],int tam, int id, float precio)
{
    int todoOk = 0;
    int flag = 1;
    if(destinos != NULL && tam > 0 && precio > 0)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(destinos[i].id == id)
            {
                precio = destinos[i].precio;
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
