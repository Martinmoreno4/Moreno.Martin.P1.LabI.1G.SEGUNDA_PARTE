#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eEmpresa;

#endif // EMPRESA_H_INCLUDED

int mostrarEmpresas(eEmpresa empresas[], int tam);
int validarEmpresas(int id, eEmpresa empresas[], int tam);
int cargarDescripcionEmpresa(eEmpresa empresas[], int tam, int idEmpresa, char descripcion[]);
