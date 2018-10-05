#include "clientes.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int cli_buscarIndiceVacio(Cliente* pBuffer,int limite,int*indice);
int cli_inicializarArray(Cliente* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
        pBuffer[i].acobrar=0;
    }
    return 0;
}
int cli_alta(Cliente* pBuffer,int id,int limite,char* apellido,char* nombre,char*cuit){
    int indice;
    if(cli_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].id=id;
        pBuffer[indice].isEmpty=0;
        strcpy(pBuffer[indice].apellido,apellido);
        strcpy(pBuffer[indice].nombre,nombre);
        strcpy(pBuffer[indice].cuit,cuit);
    }
    return 0;
}
static int cli_buscarIndiceVacio(Cliente* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int cli_obtenerID(){
    static int ID=0;
    return ID++;
}
int cli_modificarbyId(Cliente* pBuffer,int limite,int id){
    int i;
    char auxNombre [50];
    char auxApellido[50];
    char auxCuit[50];
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].id==id&& pBuffer[i].isEmpty==0){
                if(!utn_getLetras(auxNombre,50,3,"\nIngrese el nombre: ","\nError..El nombre debe contener solo letras")&&
                    !utn_getLetras(auxApellido,50,3,"\nIngrese el apellido: ","\nError..El apellido debe contener solo letras")&&
                    !utn_getLetrasYNumeros(auxCuit,50,"Ingrese el cuit: ")){
                        strcpy(pBuffer[i].apellido,auxApellido);
                        strcpy(pBuffer[i].nombre,auxNombre);
                        strcpy(pBuffer[i].cuit,auxCuit);
                        printf("Modificacion satisfactoria ");
                        getchar();
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}
int cli_eliminarbyId(Cliente* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0&& pBuffer[i].id==id){
            pBuffer[i].isEmpty=1;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int cli_existeId(Cliente* pbuffer,int limite,int id){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pbuffer[i].id==id && !pbuffer[i].isEmpty){
            retorno=0;
            break;
        }
    }
    return retorno;
}