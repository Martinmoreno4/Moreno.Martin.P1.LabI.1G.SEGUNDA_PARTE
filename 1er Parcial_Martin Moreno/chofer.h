#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;

}eChofer;

#endif // CHOFER_H_INCLUDED
int mostrarChoferes(eChofer choferes[], int tamC);
int validarChofer(int id, eChofer choferes[], int tamC);
int cargarNombreChofer(eChofer choferes[], int tam, int idChofer, char nombre[]);
