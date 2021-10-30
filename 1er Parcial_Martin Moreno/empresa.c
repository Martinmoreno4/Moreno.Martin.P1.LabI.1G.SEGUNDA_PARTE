#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"

int mostrarEmpresas(eEmpresa empresas[], int tam)
{
    int todoOk = 0;
    if(empresas != NULL && tam > 0)
    {

        printf(" *** empresas ***\n\n");
        printf("   Id        Descripcion\n");
        for(int i=0; i<tam; i++)
        {
            printf("   %d       %10s\n", empresas[i].id, empresas[i].descripcion);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarEmpresas(int id, eEmpresa empresas[], int tam)
{
    int todoOk = 0;
    if(empresas != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(empresas[i].id == id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionEmpresa(eEmpresa empresas[], int tam, int idEmpresa, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(empresas != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(empresas[i].id == idEmpresa)
            {
                strcpy(descripcion, empresas[i].descripcion);
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
