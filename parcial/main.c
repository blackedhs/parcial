#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "clientes.h"
#include "afiche.h"
#include "informes.h"
#define CANTIDADAFICHES 100
#define CANTIDADCLIENTES 100
int menu(int*opcion);
int main()
{
    Cliente clientes[CANTIDADCLIENTES];
    Afiche afiches[CANTIDADAFICHES];
    int opcion;
    int auxid,auxCantidadAfiches,auxZona;
    char auxNombre [50];
    char auxApellido[50];
    char auxCuit[50];
    char auxNombreAfiche[50];
    int confirmar;
    int i;
    cli_inicializarArray(clientes,CANTIDADCLIENTES);
    afi_inicializarArray(afiches,CANTIDADAFICHES);
    afi_alta(afiches,0,CANTIDADAFICHES,100,2,"picazo");
    afi_alta(afiches,1,CANTIDADAFICHES,450,3,"picazo");
    afi_alta(afiches,2,CANTIDADAFICHES,10,3,"picazo");
    afi_alta(afiches,3,CANTIDADAFICHES,500,2,"picazo");
    afi_alta(afiches,3,CANTIDADAFICHES,600,1,"picazo");
    afi_alta(afiches,3,CANTIDADAFICHES,500,1,"lala");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"andrade","juan","34152942");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"perez","pedro","152461535");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"mafia","lucia","22250452");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"elnono","juana","001154226");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"nilose","juan","014253475");
    do{
        system("clear");
        menu(&opcion);
        switch (opcion){
            case 1:
                if(!utn_getLetras(auxNombre,50,3,"\nIngrese el nombre: ","\nError..El nombre debe contener solo letras")&&
                    !utn_getLetras(auxApellido,50,3,"\nIngrese el apellido: ","\nError..El apellido debe contener solo letras")&&
                    !utn_getCuit(auxCuit,50,3,"Ingrese el cuit: ","Error...Ingrese el cuit debe ingresarse solo con numero Cant 11")){
                        auxid=cli_obtenerID();
                        cli_alta(clientes,auxid,CANTIDADCLIENTES,auxApellido,auxNombre,auxCuit);
                        printf("Alta satisfactoria Nº de Id: %d",auxid);
                        getchar();
                    }
                break;
            case 2:
                if(!utn_getEntero(&auxid,3,"\nIngrese el id: ","\nError...Ingrese un id valido ",-1,999)&&
                    !cli_existeId(clientes,CANTIDADCLIENTES,auxid)){
                    cli_modificarbyId(clientes,CANTIDADCLIENTES,auxid);
                }else{
                        printf("\nEl id no existe..Vuelva A Intentarlo");
                        getchar();
                    }
                break;
            case 3:
                if(!utn_getEntero(&auxid,3,"\nIngrese el id: ","\nError...Ingrese un id valido ",-1,999)&&
                    !cli_existeId(clientes,CANTIDADCLIENTES,auxid)&&
                    !utn_getEntero(&confirmar,3,"\nEsta seguro q desea eliminar? 0-si 1-no ","Error..elija una opcion valida",0,1)&&
                    !confirmar){
                    cli_eliminarbyId(clientes,CANTIDADCLIENTES,auxid);
                    afi_eliminarbyId(afiches,CANTIDADAFICHES,auxid);
                }else{
                        printf("\nEl id no existe..Vuelva A Intentarlo");
                        getchar();
                    }

                break;
            case 4:
                if(!utn_getEntero(&auxid,3,"\nIngrese el id del cliente: ","\nError...Ingrese un id valido ",-1,999)&&
                    !cli_existeId(clientes,CANTIDADCLIENTES,auxid)&&
                    !utn_getEntero(&auxCantidadAfiches,3,"\nIngrese la cantidad de afiches :","\nError ingrese un numero valido",0,9999)&&
                    !utn_getLetrasYNumeros(auxNombreAfiche,50,"\nIngrese nombre de la imagen :") &&
                    !utn_getEntero(&auxZona,3,"\nIngrese la zona: 1- CABA 2-ZONA SUR 3-ZONA OESTE :","\nError...ingrese una opcion valida",1,3)
                    ){
                        afi_alta(afiches,auxid,CANTIDADAFICHES,auxCantidadAfiches,auxZona,auxNombreAfiche);
                    }else{
                        printf("\nERROR..Vuelva A Intentarlo");
                        getchar();
                    }
                break;
            case 5:
                afi_listar(afiches,CANTIDADAFICHES);
                if(!utn_getEntero(&auxid,3,"\nIngrese el id de venta: ","\nError...Ingrese un id valido ",-1,999)&&
                    !afi_existeId(afiches,CANTIDADAFICHES,auxid)&&
                    !utn_getEntero(&auxCantidadAfiches,3,"\nIngrese la cantidad de afiches :","\nError ingrese un numero valido",0,9999)&&
                    !utn_getEntero(&auxZona,3,"\nIngrese la zona: 1- CABA 2-ZONA SUR 3-ZONA OESTE :","\nError...ingrese una opcion valida",1,3)){
                        afi_editar(afiches,auxid,CANTIDADAFICHES,auxCantidadAfiches,auxZona);
                }else{
                        printf("\nERROR..Vuelva A Intentarlo");
                        getchar();
                }
                break;
            case 6:
                afi_listar(afiches,CANTIDADAFICHES);
                    if(!utn_getEntero(&auxid,3,"\nIngrese el id de venta: ","\nError...Ingrese un id valido ",-1,999) &&
                        !afi_cobrarVenta(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES,auxid,&i)&&
                        !utn_getEntero(&confirmar,3,"\nDesea cobrar esta venta? 0-si 1-no","\nError...ingrese una opcion valida",0,1)&&
                        !confirmar){
                            afiches[i].estado=0;
                    }else{
                        printf("\nERROR..Vuelva A Intentarlo");
                        getchar();
                    }
                break;
            case 7:
                inf_impClientesAcobrar(clientes,CANTIDADCLIENTES,afiches,CANTIDADAFICHES);
                //inf_impCliByMayorOrMenorCanAfiches(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES,1,"\nEl que tiene menos afiches es: ");
                getchar();
                break;
            case 8:
                printf("\na)");
                inf_clienteMasACobrar(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);
                printf("\nb)");
                inf_clienteMasCobradas(afiches,CANTIDADAFICHES,clientes,CANTIDADAFICHES);
                printf("\nc)");
                inf_clienteMasventas(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);
                printf("\nd)");
                inf_impCliByMayorAfichesACobrar(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES,"\nEl cliente con mas a cobrar es: ");
                printf("\ne)");
                inf_impCliByMayorOrMenorCanAfiches(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES,0,"\nEl que mas compro es: ");
                printf("\nf)");
                inf_zonaMenosAfiVendidos(afiches,CANTIDADAFICHES);
                printf("\ng)");
                inf_cantidadConMenos100Afi(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);
                printf("\nh)");
                inf_cantidadAfiByZona(afiches,CANTIDADAFICHES);
                printf("\ni)");
                inf_ordenarAfiByZona(afiches,CANTIDADAFICHES,0);
                afi_listar(afiches,CANTIDADAFICHES);
                printf("\nj)");
                inf_promedioAfichesByCliente(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);
                getchar();
        }
    }while(opcion!=9);
    return 0;
}
int menu(int*opcion){
    printf("\n1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-VENDER AFICHE\n5-EDITAR VENTA\n6-COBRAR VENTA\n7-IMPRIMIR CLIENTES\n8-INFORMAR\n9-SALIR");
    utn_getEntero(opcion,3,"\nIngrese una opcion: ","\nError...ingrese una opcion valida...",1,8);
    return 0;

}
