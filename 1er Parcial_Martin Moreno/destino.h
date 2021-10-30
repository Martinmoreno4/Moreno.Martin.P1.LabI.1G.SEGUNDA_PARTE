#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
}eDestino;

#endif // DESTINO_H_INCLUDED

int mostrarDestinos(eDestino destinos[], int tam);
int cargarDescripcionDestino(eDestino destinos[],int tam, int id, char descripcion[]);
int validarDestinos(int id, eDestino destinos[], int tam);
int cargarPrecioDestino(eDestino destinos[],int tam, int id, float precio);
