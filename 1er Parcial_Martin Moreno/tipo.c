#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int mostrarTipos(eTipo tipos[], int tam)
{
    int todoOk = 0;
    if(tipos != NULL && tam > 0)
    {

        printf(" *** Tipos ***\n\n");
        printf("   Id        Descripcion\n");
        for(int i=0; i<tam; i++)
        {
            printf("   %d       %10s\n", tipos[i].id, tipos[i].descripcion);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarTipos(int id, eTipo tipos[], int tam)
{
    int todoOk = 0;
    if(tipos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(tipos != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
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

int buscarTipoId(eTipo tipos[], int tam, int id)
{
    int indice = -1;
    if(tipos != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
