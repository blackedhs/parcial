#include "informes.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDADAFICHES 100

int inf_impClientesAcobrar(Cliente*pBufferCli,int limiteCli,Afiche* pBufferAfi,int limiteAfi){
    int retorno=-1;
    int i;
    int cantidadACobrar;
    if(pBufferCli!=NULL && limiteCli>0 && pBufferAfi!=NULL && limiteAfi>0){
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
    }
    return retorno;
}
int inf_ordenarCliById(Cliente* pBuffer,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Cliente auxBuffer;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && pBuffer[i].id< pBuffer[i+1].id)||(flag && pBuffer[i].id> pBuffer[i+1].id)){
                        auxBuffer=pBuffer[i];
                        pBuffer[i]=pBuffer[i+1];
                        pBuffer[i+1]=auxBuffer;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarAfiById(Afiche* pBuffer,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Afiche auxBuffer;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && pBuffer[i].id< pBuffer[i+1].id)||(flag && pBuffer[i].id> pBuffer[i+1].id)){
                        auxBuffer=pBuffer[i];
                        pBuffer[i]=pBuffer[i+1];
                        pBuffer[i+1]=auxBuffer;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarCliByCuit(Cliente* pBuffer,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Cliente auxBuffer;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && strcmp(pBuffer[i].cuit, pBuffer[i+1].cuit)<0 )||(flag && strcmp(pBuffer[i].cuit, pBuffer[i+1].cuit)>0)){
                        auxBuffer=pBuffer[i];
                        pBuffer[i]=pBuffer[i+1];
                        pBuffer[i+1]=auxBuffer;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarCliByNombre(Cliente* pBuffer,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Cliente auxBuffer;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && strcmp(pBuffer[i].nombre, pBuffer[i+1].nombre)<0 )||(flag && strcmp(pBuffer[i].nombre, pBuffer[i+1].nombre)>0)){
                        auxBuffer=pBuffer[i];
                        pBuffer[i]=pBuffer[i+1];
                        pBuffer[i+1]=auxBuffer;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarCliByApellido(Cliente* pBuffer,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Cliente auxBuffer;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && strcmp(pBuffer[i].apellido, pBuffer[i+1].apellido)<0 )||(flag && strcmp(pBuffer[i].apellido, pBuffer[i+1].apellido)>0)){
                        auxBuffer=pBuffer[i];
                        pBuffer[i]=pBuffer[i+1];
                        pBuffer[i+1]=auxBuffer;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_impCliByMayorOrMenorCanAfiches(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli,int flag,char* msj){
    int i;
    int auxId;
    int mayorMenor;
    int auxMayorMenor;
    int retorno=-1;
    if(pBufferCli!=NULL && limiteCli>0 && pBufferAfi!=NULL && limiteAfi>0){
        for(i=0;i<limiteCli;i++){
            auxMayorMenor=afi_cantidadDeAfichesByIdCliente(pBufferAfi,limiteAfi,pBufferAfi[i].idCliente);
            if(!i){
                mayorMenor=auxMayorMenor;
                auxId=i;
            }else if((!flag && mayorMenor<auxMayorMenor)||(flag && mayorMenor>auxMayorMenor)){
                mayorMenor=auxMayorMenor;
                auxId=i;
            }
        }
        printf("Con la cantidad de: %d",mayorMenor);
        printf("%s",msj);
        cli_impById(pBufferCli,limiteCli,auxId);

    }
    return retorno;
}
