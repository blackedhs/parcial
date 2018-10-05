#ifndef AFICHE_H_INCLUDED
#define AFICHE_H_INCLUDED
#include "clientes.h"

typedef struct{
    int id;
    int idCliente;
    int canAfiches;
    char nombreArchivo[50];
    int zona;
    int estado;
    int isEmpty;
}Afiche;

int afi_eliminarbyId(Afiche* pBuffer,int limite,int id);
int afi_inicializarArray(Afiche* pBuffer,int limite);
int afi_listar(Afiche* pBuffer,int limite);
int afi_alta(Afiche* pBuffer,int id,int limite,int cantidaAfiches,int zona,char* nombreAfi);
int afi_editar(Afiche* pBuffer,int id,int limite,int cantidaAfiches,int zona);
int afi_cobrarVenta(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli,int id,int* indice);
int afi_aCobrarById(Afiche* pbuffer,int limite,int idCliente);
int afi_existeId(Afiche* pbuffer,int limite,int id);
#endif // AFICHE_H_INCLUDED
