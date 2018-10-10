#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "afiche.h"

static int afi_buscarIndiceVacio(Afiche* pBuffer,int limite,int*indice);
static int afi_obtenerID();
int afi_eliminarbyId(Afiche* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0&& pBuffer[i].idCliente==id){
                pBuffer[i].isEmpty=1;
                retorno=0;

            }
        }
    }
    return retorno;
}
int afi_inicializarArray(Afiche* pBuffer,int limite){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        for(i=0;i<limite;i++){
            pBuffer[i].isEmpty=1;
        }
    }
    return retorno;
}
static int afi_buscarIndiceVacio(Afiche* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==1){
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int afi_alta(Afiche* pBuffer,int id,int limite,int cantidaAfiches,int zona,char* nombreAfi){
    int indice;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0 && cantidaAfiches>0 && (zona<4&&zona>0)&& nombreAfi!= NULL){
        retorno=0;
        if(afi_buscarIndiceVacio(pBuffer,limite,&indice)==0){
            pBuffer[indice].id=afi_obtenerID();
            pBuffer[indice].isEmpty=0;
            pBuffer[indice].canAfiches=cantidaAfiches;
            pBuffer[indice].idCliente=id;
            strcpy(pBuffer[indice].nombreArchivo,nombreAfi);
            pBuffer[indice].zona=zona;
            pBuffer[indice].estado=1;
        }
    }
    return retorno;
}
/** \brief  devuelve un numero de Id que no se repite.
 * \return int Return comienza en 0 y se incrementa en 1
 */
static int afi_obtenerID(){
    static int ID=0;
    return ID++;
}
int afi_listar(Afiche* pBuffer,int limite){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0){
                retorno=0;
                printf("\nId: %d",pBuffer[i].id);
                printf("\tId Cli: %d",pBuffer[i].idCliente);
                printf("\tCant/Afi: %d",pBuffer[i].canAfiches);
                printf("\tArchivo: %s",pBuffer[i].nombreArchivo);
                switch (pBuffer[i].zona){
                    case 1:
                        printf("\tZona: CABA");
                        break;
                    case 2:
                        printf("\tZona: ZONA SUR");
                        break;
                    case 3:
                        printf("\tZona: ZONA OESTE");
                    break;
                }
                switch (pBuffer[i].estado){
                    case 1:
                        printf("\tEstado: a pagar");
                        break;
                    case 0:
                        printf("\tEstado: Cobrada");
                        break;
                }

            }
        }
    }
    return retorno;
}
int afi_editar(Afiche* pBuffer,int id,int limite,int cantidaAfiches,int zona){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0 && (zona<4&&zona>0)&& cantidaAfiches>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].id==id){
                pBuffer[i].canAfiches=cantidaAfiches;
                pBuffer[i].zona=zona;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int afi_cobrarVenta(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli,int id,int* indice){
    int i,j;
    int retorno=-1;
    if(pBufferAfi!=NULL&&limiteAfi>0&& pBufferCli!= NULL && limiteCli>0){
        for(i=0;i<limiteAfi;i++){
            if(pBufferAfi[i].id==id){
                for(j=0;j<limiteCli;j++){
                    if(pBufferAfi[i].idCliente==pBufferCli[i].id&& !pBufferAfi[i].isEmpty){
                        printf("\nId: %d",pBufferCli[i].id);
                        printf("\tNombre: %s",pBufferCli[i].nombre);
                        printf("\tApellido: %s",pBufferCli[i].apellido);
                        printf("\tCuit: %s",pBufferCli[i].cuit);
                        retorno=0;
                        *indice=i;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}
int afi_aCobrarById(Afiche* pbuffer,int limite,int idCliente){
    int i;
    int retorno=0;
    for(i=0;i<limite;i++){
        if(pbuffer[i].idCliente==idCliente&& pbuffer[i].estado== 1 && !pbuffer[i].isEmpty){
            retorno++;
        }
    }
    return retorno;
}
int afi_existeId(Afiche* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].id==id && !pBuffer[i].isEmpty){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int afi_cantidadDeVentasByIdCliente(Afiche* pBuffer,int limite,int idCliente,int flag){
    int i;
    int cantidad=0;
    if(pBuffer!=NULL&& limite >0){
        for(i=0;i<limite;i++){
            if(!pBuffer[i].isEmpty && ((!flag &&pBuffer[i].idCliente==idCliente && pBuffer[i].estado==1)||
            ((flag && pBuffer[i].idCliente==idCliente && pBuffer[i].estado==0)))){
                cantidad++;
            }
        }
    }
    return cantidad;
}

int afi_cantidadDeAfichesByIdCliente(Afiche* pBuffer,int limite,int idCliente){
    int i;
    int cantidad=0;
    if(pBuffer!=NULL&& limite >0){
        for(i=0;i<limite;i++){
            if(!pBuffer[i].isEmpty && pBuffer[i].idCliente==idCliente ){
                cantidad+=pBuffer[i].canAfiches;
            }
        }
    }
    return cantidad;
}
int afi_cantidadDeAfichesACobrarByIdCliente(Afiche* pBuffer,int limite,int idCliente){
    int i;
    int cantidad=0;
    if(pBuffer!=NULL&& limite >0){
        for(i=0;i<limite;i++){
            if(!pBuffer[i].isEmpty && pBuffer[i].idCliente==idCliente && pBuffer[i].estado==1){
                cantidad+=pBuffer[i].canAfiches;
            }
        }
    }
    return cantidad;
}
int afi_cantidadDeVentasByIdTotales(Afiche* pBuffer,int limite,int idCliente){
    int i;
    int cantidad=0;
    if(pBuffer!=NULL&& limite >0){
        for(i=0;i<limite;i++){
            if(!pBuffer[i].isEmpty && pBuffer[i].idCliente==idCliente ){
                cantidad++;
            }
        }
    }
    return cantidad;
}
int afi_cantidadAfichesByZona(Afiche *pBuffer,int limite,int zona){
    int i;
    int cantidad=0;
    if(pBuffer!=NULL&& limite >0){
        for(i=0;i<limite;i++){
            if(!pBuffer[i].isEmpty && pBuffer[i].zona== zona){
                cantidad+=pBuffer[i].canAfiches;
            }
        }
    }
    return cantidad;
}
int afi_cantidadAfiches(Afiche* pBuffer,int limite){
    int i;
    int cantidad=0;
    if(pBuffer!=NULL&& limite >0){
        for(i=0;i<limite;i++){
            if(!pBuffer[i].isEmpty){
                cantidad+=pBuffer[i].canAfiches;
            }
        }
    }
    return cantidad;
}
