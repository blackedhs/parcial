#include "informes.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDADAFICHES 100
int inf_impClientesAcobrar(Cliente*pBufferCli,int limiteCli,Afiche* pBufferAfi,int limiteAfi){
    int retorno=-1;
    int i;
    int cantidadACobrar;
    for(i=0;i<limiteCli;i++){
        if(!pBufferCli[i].isEmpty){
            printf("\nId: %d",pBufferCli[i].id);
            printf("\tNombre: %s",pBufferCli[i].nombre);
            printf("\tApellido: %s",pBufferCli[i].apellido);
            printf("\tCuit: %s",pBufferCli[i].cuit);
            cantidadACobrar=afi_aCobrarById(pBufferAfi,CANTIDADAFICHES,pBufferCli[i].id);
            printf("\tCan/A cobrar: %d",cantidadACobrar);
            retorno=0;
        }
    }
    return retorno;
}
