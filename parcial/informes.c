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
        printf("\nCon la cantidad es de: %d",mayorMenor);
        printf("%s",msj);
        cli_impById(pBufferCli,limiteCli,auxId);

    }
    return retorno;
}
int inf_clienteMasACobrar(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli){
    int i;
    int auxMayorId;
    int auxMaxVentas;
    int flag=0;
    if(pBufferCli!=NULL && limiteCli>0 && pBufferAfi!=NULL && limiteAfi>0){
        for(i=0;i<limiteCli;i++){
            if (!pBufferCli[i].isEmpty){
                if(!flag || auxMaxVentas<afi_cantidadDeVentasByIdCliente(pBufferAfi,limiteAfi,pBufferCli[i].id,0)){
                    flag=1;
                    auxMaxVentas=afi_cantidadDeVentasByIdCliente(pBufferAfi,limiteAfi,pBufferCli[i].id,0);
                    auxMayorId=pBufferCli[i].id;
                }

            }
        }
        if(!auxMaxVentas){
            printf("\nNo posee ventas a cobrar");
        }else{
            printf("\nNumero mayor de ventas a cobrar : %d",auxMaxVentas);
            cli_impById(pBufferCli,limiteCli,auxMayorId);
        }
    }
    return 0;
}
int inf_clienteMasCobradas(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli){
    int i;
    int auxMayorId;
    int auxMaxVentas;
    int flag=0;
    if(pBufferCli!=NULL && limiteCli>0 && pBufferAfi!=NULL && limiteAfi>0){
        for(i=0;i<limiteCli;i++){
            if (!pBufferCli[i].isEmpty){
                if(!flag || auxMaxVentas<afi_cantidadDeVentasByIdCliente(pBufferAfi,limiteAfi,pBufferCli[i].id,1)){
                    flag=1;
                    auxMaxVentas=afi_cantidadDeVentasByIdCliente(pBufferAfi,limiteAfi,pBufferCli[i].id,1);
                    auxMayorId=pBufferCli[i].id;
                }

            }
        }
        if(!auxMaxVentas){
            printf("\nNo posee ventas Cobradas");
        }else{
            printf("\nNumero mayor de ventas cobradas: %d",auxMaxVentas);
            cli_impById(pBufferCli,limiteCli,auxMayorId);
        }
    }
    return 0;
}
int inf_clienteMasventas(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli){
    int i;
    int auxMayorId;
    int auxMaxVentas;
    int flag=0;
    if(pBufferCli!=NULL && limiteCli>0 && pBufferAfi!=NULL && limiteAfi>0){
        for(i=0;i<limiteCli;i++){
            if (!pBufferCli[i].isEmpty){
                if(!flag || auxMaxVentas<afi_cantidadDeVentasByIdTotales(pBufferAfi,limiteAfi,pBufferCli[i].id)){
                    flag=1;
                    auxMaxVentas=afi_cantidadDeVentasByIdTotales(pBufferAfi,limiteAfi,pBufferCli[i].id);
                    auxMayorId=pBufferCli[i].id;
                }

            }
        }
        if(!auxMaxVentas){
            printf("\nNo posee ventas");
        }else{
            printf("\nNumero mayor de ventas: %d",auxMaxVentas);
            cli_impById(pBufferCli,limiteCli,auxMayorId);
        }
    }
    return 0;
}
int inf_impCliByMayorAfichesACobrar(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli,char* msj){
    int i;
    int auxId;
    int mayorMenor;
    int auxMayorMenor;
    int retorno=-1;
    if(pBufferCli!=NULL && limiteCli>0 && pBufferAfi!=NULL && limiteAfi>0){
        for(i=0;i<limiteCli;i++){
            auxMayorMenor=afi_cantidadDeAfichesACobrarByIdCliente(pBufferAfi,limiteAfi,pBufferCli[i].id);
            if(!i){
                mayorMenor=auxMayorMenor;
                auxId=i;
            }else if(mayorMenor<auxMayorMenor){
                mayorMenor=auxMayorMenor;
                auxId=i;
            }
        }
        printf("\nCon la cantidad es de: %d",mayorMenor);
        printf("%s",msj);
        cli_impById(pBufferCli,limiteCli,auxId);

    }
    return retorno;
}
int inf_zonaMenosAfiVendidos(Afiche* pBuffer,int limite){
    int i;
    int zonaMin;
    int zonaNumero;
    if(pBuffer!=NULL && limite>0){
        zonaMin=afi_cantidadAfichesByZona(pBuffer,limite,1);
        zonaNumero=1;
        for(i=2;i<4;i++){
            if(zonaMin>afi_cantidadAfichesByZona(pBuffer,limite,i)){
                zonaNumero=i;
                zonaMin=afi_cantidadAfichesByZona(pBuffer,limite,i);
            }
        }
        if(!zonaMin){
            printf("\nNo posee afiches colocados");
        }else{
            printf("La zona con menos afiches vendidos es:");
            switch (zonaNumero){
                    case 1:
                        printf("\nZona: CABA");
                        break;
                    case 2:
                        printf("\nZona: ZONA SUR");
                        break;
                    case 3:
                        printf("\nZona: ZONA OESTE");
                    break;
                }
        }
    }
    return 0;
}
int inf_cantidadConMenos100Afi(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli){
    int i;
    int cantidad=0;
    if(pBufferCli!=NULL && limiteCli>0&& pBufferAfi!=NULL && limiteAfi>0){
        for(i=0;i<limiteCli;i++){
            if(!pBufferCli[i].isEmpty && 1000>afi_cantidadDeAfichesByIdCliente(pBufferAfi,limiteAfi,pBufferCli[i].id)){
                cantidad++;
            }
        }
        if(!cantidad){
            printf("\nNingun cliente compro menos de 1000 afiches");
        }else {
            printf("\nLa cantidad de clientes que compraron menos de 1000 es: %d",cantidad-1);
        }
    }
    return 0;
}
int inf_cantidadAfiByZona(Afiche* pBuffer,int limite){
    if(pBuffer!=NULL && limite){
        printf("\nCABA : %d",afi_cantidadAfichesByZona(pBuffer,limite,1));
        printf("\nZONA SUR : %d",afi_cantidadAfichesByZona(pBuffer,limite,2));
        printf("\nZONA NORTE : %d",afi_cantidadAfichesByZona(pBuffer,limite,3));
    }
    return 0;
}
int inf_ordenarAfiByZona(Afiche* pBuffer,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Afiche auxBuffer;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && pBuffer[i].zona< pBuffer[i+1].zona)||(flag && pBuffer[i].zona> pBuffer[i+1].zona)){
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
int inf_promedioAfichesByCliente(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli){
    float promedio;
    promedio=afi_cantidadAfiches(pBufferAfi,limiteAfi)/cli_cantidadClientes(pBufferCli,limiteCli);
    if(!promedio){
        printf("\nNo posee ventas de afiches");
    }else {
        printf("\nEl promedio de afiches/Clientes es : %.2f ",promedio);
    }
    return 0;
}
