#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "micro.h"


int menu()
{
    char opcion;
    system("cls");
    printf("A. Alta Micro\n");
    printf("B. Modificar Micro\n");
    printf("C. Baja Micro\n");
    printf("D. Listar Micros\n");
    printf("E. Listar Empresas\n");
    printf("F. Listar Tipos\n");
    printf("G. Listar Destinos\n");
    printf("H. Alta Viaje\n");
    printf("I. Listar Viajes\n");
    printf("J. Mostrar micros de la empresa seleccionada\n");
    printf("K. Mostrar micros de un tipo seleccionado\n");
    printf("L. Porcentaje de micros de tipo Vip sobre una empresa\n");
    printf("M. Mostrar un listado de los micros separados por empresa\n");
    printf("N. Listar empresa/s con mas pasajeros\n");
    printf("O. Empresa con menor cantidad de micros\n");
    printf("P. Mostrar viajes de un micro\n");
    printf("Q. Mostrar suma de precios de viajes de un micro\n");
    printf("R. Mostrar datos de viajes de un Destino\n");
    printf("S. Mostrar viajes de una fecha\n");
    printf("X. Salir\n");
    printf("ingrese opcion: ");
    scanf("%c",&opcion);

    return opcion;

}

int menuModificacionMicro()
{
    int opcion;

    printf("1- Tipo \n");
    printf("2- Capacidad\n");
    printf("3- cancelar \n");

    printf("ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int inicializarMicros(eMicro micros[], int tam)
{
    int todoOk = 0;
    if( micros != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            micros[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eMicro micros[], int tam)
{

    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(micros[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaMicro(eMicro micros[], int tam, int* nextId, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    eMicro auxMicro;

    if( micros != NULL && tam>0)
    {
        system("cls");
        printf("     *** Alta Micro ***\n\n");

        indice = buscarLibre(micros, tam);
        if(indice == -1)
        {
            printf("no hay lugar \n");
        }
        else
        {
            auxMicro.id = *nextId;
            (*nextId)++;

            mostrarEmpresas(empresas, tamE);
            printf("ingrese id de Empresa: ");
            scanf("%d", &auxMicro.idEmpresa);
            while(!validarEmpresas(auxMicro.idEmpresa, empresas, tamE))
            {
                mostrarEmpresas(empresas, tamE);
                printf("id invalido, ingrese id de Empresa VALIDO: ");
                scanf("%d", &auxMicro.idEmpresa);
            }

            mostrarTipos(tipos, tamT);
            printf("ingrese id de Tipos: ");
            scanf("%d", &auxMicro.idTipo);
            while(!validarTipos(auxMicro.idTipo, tipos, tamT))
            {
                mostrarTipos(tipos, tamT);
                printf("id invalido, ingrese id de Tipo VALIDO: ");
                scanf("%d", &auxMicro.idTipo);
            }

            mostrarChoferes(choferes, tamC);
            printf("ingrese id de Chofer: ");
            scanf("%d", &auxMicro.idChofer);
            while(!validarChofer(auxMicro.idChofer, choferes, tamC))
            {
                mostrarChoferes(choferes, tamC);
                printf("id invalido, ingrese id de Chofer VALIDO: ");
                scanf("%d", &auxMicro.idChofer);
            }

            printf("ingrese capacidad: ");
            scanf("%d", &auxMicro.capacidad);
            while(auxMicro.capacidad > 50 || auxMicro.capacidad < 1)
            {
                printf("valor invalido, debe ser un numero entre 1 y 50. ingrese capacidad valida: ");
                scanf("%d", &auxMicro.capacidad);
            }

            auxMicro.isEmpty = 0;

            micros[indice] = auxMicro;

            todoOk = 1;
        }


    }
    return todoOk;
}

int buscarMicroId(eMicro micros[], int tam, int id)
{
    int indice = -1;
    if(micros != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty && micros[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarMicro(eMicro micro, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC)
{
    char descTipo[20];
    char descEmpresa[20];
    char nombreChofer[20];

    if(cargarDescripcionTipo(tipos, tamT, micro.idTipo, descTipo) == 1
       && cargarDescripcionEmpresa(empresas, tamE, micro.idEmpresa, descEmpresa) == 1
       && cargarNombreChofer(choferes, tamC, micro.idChofer, nombreChofer))
    {
        printf("    %d     %10s     %10s     %10s    %d\n",
        micro.id,
        descTipo,
        descEmpresa,
        nombreChofer,
        micro.capacidad
        );
    }
}

int mostrarMicros(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC)
{
    int todoOk =0;
    int flag = 1;
    if(micros != NULL && tam > 0)
    {
        printf("          *** Lista de Micros ***\n");
        printf("----------------------------------------------------------\n");
        printf("    id      Empresa       Tipo       Chofer      Capacidad\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty)
            {
                mostrarMicro(micros[i], tipos, tamT, empresas, tamE, choferes, tamC);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay micros para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int modificarMicro(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    int auxCapacidad;
    eMicro auxMicro;


    if(micros != NULL && tam>0)
    {
        system("cls");
        printf("      *** Modificar Micro ***\n\n");
        mostrarMicros(micros, tam, tipos, tamT, empresas, tamE, choferes, tamC);
        printf("Ingrese id de micro a modificar: ");
        scanf("%d", &id);

        indice = buscarMicroId(micros, tam, id);

        if(indice == -1)
        {
            printf("El id; %d no esta registrado\n", id);
        }
        else
        {
            mostrarMicro(micros[indice], tipos, tamT, empresas, tamE, choferes, tamC);
            printf("Confirma Modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                switch(menuModificacionMicro())
                {
                case 1:
                    mostrarTipos(tipos, tamT);
                    printf("ingrese id de tipos: ");
                    scanf("%d", &auxMicro.idTipo);
                    while(buscarTipoId(tipos, tam, auxMicro.idTipo) == -1)
                    {
                        mostrarTipos(tipos, tamT);
                        printf("id invalido, ingrese id de tipo VALIDO: ");
                        scanf("%d", &auxMicro.idTipo);
                    }
                    break;

                case 2:

                    printf("Ingrese nueva Capacidad: ");
                    fflush(stdin);
                    scanf("%d", &auxCapacidad);
                    while(auxCapacidad<1 || auxCapacidad>50)
                    {
                        printf("ingrese valor valido de capacidad, deve ser entr 1 y 50: ");
                        fflush(stdin);
                        scanf("%d", &auxCapacidad);
                    }
                    micros[indice].capacidad=auxCapacidad;
                    break;

                case 3:
                    break;

                default:
                    printf("Opcion invalida!!\n");
                }

                todoOk = 1;
            }
            else
            {
                printf("Modificacion cancelada\n");
            }
        }
    }
    return todoOk;
}

int bajaMicro(eMicro micros[], int tam, eTipo tipos[],int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(micros != NULL && tam>0)
    {
        system("cls");
        printf("      *** Baja Micro ***\n\n");
        mostrarMicros(micros, tam, tipos, tamT, empresas, tamE, choferes, tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMicroId(micros, tam, id);

        if(indice == -1)
        {
            printf("El id; %d no esta registrado\n", id);
        }
        else
        {
            mostrarMicro(micros[indice], tipos, tamT, empresas, tamE, choferes, tamC);
            printf("Confirma Baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                micros[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada\n");
            }
        }
    }
    return todoOk;
}

int ordenarMicros(eMicro micros[], int tam)
{
    int todoOk = 0;
    eMicro auxMicro;

    if(micros != NULL && tam > 0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if( (micros[i].idTipo > micros[j].idTipo) ||
                    (micros[i].idTipo == micros[j].idTipo &&
                     (micros[i].capacidad > micros[j].capacidad)))
                {
                    auxMicro = micros[i];
                    micros[i] = micros[j];
                    micros[j] = auxMicro;
                }
            }
        }

        todoOk=1;
    }

    return todoOk;
}

int cargarEmpresaMicro(eMicro micros[],int tam, int id, char empresaDesc[], eEmpresa empresa[], int tamE)
{
    int todoOk = 0;
    int flag = 1;
    if(micros != NULL && tam > 0 && empresaDesc != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(micros[i].id == id)
            {
                cargarDescripcionEmpresa(empresa, tamE, micros[i].idEmpresa, empresaDesc);
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

int mostrarMicrosIdEmpresa(int idEmpresa, eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk =0;
    int flag = 1;
    char descEmpresa[20];

    if(micros != NULL && tam > 0 && empresas != NULL && tamE)
    {

        printf("          *** Lista de Micros ***\n");
        printf("----------------------------------------------------------\n");
        printf("    id      Empresa       Tipo        Capacidad\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty && micros[i].idEmpresa==idEmpresa)
            {
                mostrarMicro(micros[i], tipos, tamT, empresas, tamE, choferes, tamC);
                flag=0;
            }
        }
        if(flag)
        {
            cargarDescripcionEmpresa(empresas, tamE, idEmpresa, descEmpresa);
            printf("    No hay micros de empresa %s\n", descEmpresa);
        }

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMicrosDeUnaEmpresa(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk =0;
    int idEmpresa;

    if(micros != NULL && tam > 0 && empresas != NULL && tamE)
    {
        system("cls");
        printf("          *** micros de una empresa ***\n");
        mostrarEmpresas(empresas, tamE);
        printf("ingrese un id de empresa: ");
        scanf("%d", &idEmpresa);
        while(!validarEmpresas(idEmpresa, empresas, tamE))
        {
            mostrarEmpresas(empresas, tamE);
            printf("id invalido, ingrese id Empresa VALIDO: ");
            scanf("%d", &idEmpresa);
        }

        mostrarMicrosIdEmpresa(idEmpresa, micros, tam, empresas, tamE, tipos, tamT, choferes, tamC);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMicrosIdTipos(int idTipo, eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk =0;
    int flag = 1;
    char descTipo[20];

    if(micros != NULL && tam > 0 && tipos != NULL && tamT)
    {

        printf("          *** Lista de Micros ***\n");
        printf("----------------------------------------------------------\n");
        printf("    id      Empresa       Tipo         Capacidad\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty && micros[i].idTipo==idTipo)
            {
                mostrarMicro(micros[i], tipos, tamT, empresas, tamE, choferes, tamC);
                flag=0;
            }
        }
        if(flag)
        {
            cargarDescripcionTipo(tipos, tamT, idTipo, descTipo);
            printf("    No hay micros de tipo %s\n", descTipo);
        }

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMicrosDeUnTipo(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk =0;
    int idTipo;

    if(micros != NULL && tam > 0 && tipos != NULL && tamE)
    {
        system("cls");
        printf("          *** micros de un tipo ***\n");
        mostrarTipos(tipos, tamT);
        printf("ingrese un id de tipo: ");
        scanf("%d", &idTipo);
        while(!validarTipos(idTipo, tipos, tamT))
        {
            mostrarTipos(tipos, tamT);
            printf("id invalido, ingrese id Tipo VALIDO: ");
            scanf("%d", &idTipo);
        }

        mostrarMicrosIdTipos(idTipo, micros, tam, empresas, tamE, tipos, tamT, choferes, tamC);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPorcentajeVipEmpresa(eMicro micros[], int tam, eEmpresa empresas[],int tamE)
{
    int todoOk =0;
    int idEmpresa;

    if(micros != NULL && tam > 0 && empresas != NULL && tamE)
    {
        system("cls");
        printf("          *** Porcentaje de VIP en una Empresa ***\n");
        mostrarEmpresas(empresas, tamE);
        printf("ingrese id Empresa: ");
        scanf("%d", &idEmpresa);

        while(!validarEmpresas(idEmpresa, empresas, tamE))
        {
            printf("id invalido, ingrese id de Empresa VALIDO: ");
            scanf("%d", &idEmpresa);
        }
        mostrarPorcentajeVipIdEmpresa(idEmpresa, micros, tam, empresas, tamE);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPorcentajeVipIdEmpresa(int idEmpresa, eMicro micros[], int tam, eEmpresa empresas[],int tamT)
{
    int todoOk =0;
    char descEmpresa[20];
    int contadorT=0;
    int contadorE=0;
    float porcentaje;

    if(micros != NULL && tam > 0 && empresas != NULL && tamT)
    {
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty && micros[i].idEmpresa==idEmpresa)
            {
                contadorE++;

                if(micros[i].idTipo==5003)
                {
                    contadorT++;
                }
            }
        }

        cargarDescripcionEmpresa(empresas,tamT,idEmpresa,descEmpresa);
        if(contadorT && contadorE)
        {
            porcentaje = (contadorT/100)*contadorE;
            printf("Porcentaje de Micros Vip en %s: %.2f porciento\n", descEmpresa, porcentaje);
        }
        else
        {
            printf("    No hay Micros Vip en %s\n", descEmpresa);
        }

        todoOk = 1;
    }
    return todoOk;
}

int mostraMicrosTodasEmpresas(eMicro micros[], int tam, eEmpresa empresas[],int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk =0;

    if(micros != NULL && tam > 0 && empresas != NULL && tamE)
    {
        system("cls");
        printf("          *** Micros de cada Empresa ***\n");
        for(int i=0; i<tamE; i++)
        {
            printf("Empresa: %s\n", empresas[i].descripcion);
            mostrarMicrosIdEmpresa(empresas[i].id, micros, tam, empresas, tamE, tipos, tamT, choferes, tamC);
            printf("\n\n-----------------------------------------------------------\n");
        }

        todoOk=1;
    }
    return todoOk;
}

int empresaConMasCapacidad(eMicro micros[], int tam, eEmpresa empresas[],int tamE)
{
    int todoOk =0;
    int capacidades[tamE];
    int flag;
    int flagCap=0;
    int acumCapacidad;
    int mayorCapacidad=0;

    for(int i=0; i<tamE; i++)
    {
        capacidades[i] = 0;
    }

    if(micros != NULL && tam > 0 && empresas != NULL && tamE)
    {
        system("cls");
        printf("    *** Empresa con mas pasajeros ***\n");
        for(int i=0; i<tamE; i++)
        {
            flag = 0;
            acumCapacidad = 0;
            for(int j=0; j < tam; j++)
            {
                if(!micros[j].isEmpty && (micros[j].idEmpresa == empresas[i].id))
                {
                    flag = 1;
                    acumCapacidad += micros[j].capacidad;
                }
            }

            if(flag!=0)
            {
               capacidades[i] = acumCapacidad;
            }
        }
        flagCap=0;
        for(int i=0; i<tamE; i++)
        {
            if(flagCap==0 || (capacidades[i] > mayorCapacidad))
            {
                flagCap=1;
                mayorCapacidad = capacidades[i];
            }
        }

        printf("la empresa con mas capacidad es: ");
        for(int i=0; i<tamE; i++)
        {
            if(capacidades[i] == mayorCapacidad)
            {
                printf("%d  %s\n", capacidades[i], empresas[i].descripcion);
            }
        }

        todoOk=1;
    }
    return todoOk;
}

int empresaConMenorCantidadDeMicros(eMicro micros[], int tam, eEmpresa empresas[],int tamE)
{
    int todoOk =0;
    int cantMicros[tamE];
    int acumMicros;
    int menorCantidad;
    int flag;

    for(int i=0; i<tamE; i++)
    {
        cantMicros[i] = 0;
    }

    if(micros != NULL && tam > 0 && empresas != NULL && tamE)
    {
        system("cls");
        printf("          *** Empresa con menos micros ***\n");
        for(int i=0; i<tamE; i++)
        {
            flag =0;
            acumMicros = 0;
            for(int j=0; j < tam; j++)
            {
                if(!micros[j].isEmpty && micros[j].idEmpresa == empresas[i].id)
                {
                    flag = 1;
                    acumMicros++;
                }
            }

            if(flag!=0)
            {
               cantMicros[i] = acumMicros;
               printf("%d  %s\n", cantMicros[i], empresas[i].descripcion);
            }
        }

        for(int i=0; i<tamE; i++)
        {
            if(i==0 || cantMicros[i] < menorCantidad)
            {
                menorCantidad = cantMicros[i];
            }
        }
        printf("\n-------------------------------------------\n");
        printf("la empresa/s con menos micros a su nombre: \n\n");
        for(int i=0; i<tamE; i++)
        {
            if(cantMicros[i] == menorCantidad)
            {
                printf("%s\n", empresas[i].descripcion);
            }
        }

        todoOk=1;
    }
    return todoOk;
}
