#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chofer.h"

int mostrarChoferes(eChofer choferes[], int tamC)
{
    int todoOk = 0;
    if(choferes != NULL && tamC > 0)
    {

        printf(" *** Choferes ***\n\n");
        printf("   Id        Nombres    sexo\n");
        for(int i=0; i<tamC; i++)
        {
            printf("   %d       %10s    %c\n", choferes[i].id, choferes[i].nombre, choferes[i].sexo);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarChofer(int id, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    if(choferes != NULL && tamC > 0)
    {
        for(int i=0; i<tamC; i++)
        {
            if(choferes[i].id == id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarNombreChofer(eChofer choferes[], int tam, int idChofer, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if(choferes != NULL && tam > 0 && nombre != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(choferes[i].id == idChofer)
            {
                strcpy(nombre, choferes[i].nombre);
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
