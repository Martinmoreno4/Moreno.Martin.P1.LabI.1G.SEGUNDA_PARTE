#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int mostrarTipos(eTipo tipos[], int tam);
int validarTipos(int id, eTipo tipos[], int tam);
int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo, char descripcion[]);
int buscarTipoId(eTipo tipos[], int tam, int id);
