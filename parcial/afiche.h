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

/** \brief  Borra un afiche,recibiendo su id como parametro,colocando isEmpty en 1
 *\param afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id a borrar
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int afi_eliminarbyId(Afiche* pBuffer,int limite,int id);

/** \brief  incia todos los campos is Empty en 1 para saber q esta vacio.
 *\param Afiche puntero al array clientes
 *\param int limite del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int afi_inicializarArray(Afiche* pBuffer,int limite);

/** \brief  lista todos los afiches con isEmty en 0
 *\param Afiche puntero al array clientes
 *\param int limite del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int afi_listar(Afiche* pBuffer,int limite);

/** \brief  Da de alta un nuevo afiche.pone isEmpty en 0 y estado en 1= a cobrar
 *\param Afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id del cliente
 *\param int cantidaAfiches numero de afiches comprados
 *\param int zona acepta solo valores 1- CABA 2-ZONA SUR 3-ZONA OESTE
 *\param char nombeAfi nombre del afiche
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int afi_alta(Afiche* pBuffer,int id,int limite,int cantidaAfiches,int zona,char* nombreAfi);

/** \brief  modifica un afiche,recibiendo su id como parametro y permite modificar su
            cantidad de afiches y la zona
 *\param Cliente puntero al array clientes
 *\param int limite del array
 *\param id numero de id a modificar
 *\param int cantidaAfiches numero de afiches comprados
 *\param int zona acepta solo valores 1- CABA 2-ZONA SUR 3-ZONA OESTE
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int afi_editar(Afiche* pBuffer,int id,int limite,int cantidaAfiches,int zona);

/** \brief  Cambia el estado de una compra a 0 = Cobrada
 *\param Afiche puntero al array clientes
 *\param int limiteAfi del array
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param id numero de id del afiche
 *\param int devuelve el subindice del array afiches para poder modificar su estado de a cobrar a cobrado
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int afi_cobrarVenta(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli,int id,int* indice);

/** \brief  devuelve la cantidad de afiches a cobrar que tiene un cliente
 *\param afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id a verificar
 * \return int Return devuelve la cantidad de afiches que tiene para cobrar
 */
int afi_aCobrarById(Afiche* pbuffer,int limite,int idCliente);

/** \brief  valida si el afiche existe
 *\param afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id a validar
 * \return int Return comienza en 0 si existe y -1 si no
 */
int afi_existeId(Afiche* pbuffer,int limite,int id);

/** \brief  retorna la cantidad de afiches que cliente
 *\param afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id del cliente
 * \return int Return cantidad de afiches
 */
int afi_cantidadDeAfichesByIdCliente(Afiche* pBuffer,int limite,int idCliente);

/** \brief  retorna la cantidad de afiches que cliente a cobrar
 *\param afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id del cliente
 * \return int Return cantidad de afiches
 */
int afi_cantidadDeAfichesACobrarByIdCliente(Afiche* pBuffer,int limite,int idCliente);

/** \brief  retorna la cantidad de ventas que tiene un clientecliente
 *\param afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id del cliente
 *\param int flag 0 a cobrar 1 cobrado
 * \return int Return cantidad de ventas
 */
int afi_cantidadDeVentasByIdCliente(Afiche* pBuffer,int limite,int idCliente,int flag);

/** \brief  retorna la cantidad de ventas que tiene un clientecliente
 *\param afiche puntero al array clientes
 *\param int limite del array
 *\param id numero de id del cliente
 * \return int Return cantidad de ventas
 */
int afi_cantidadDeVentasByIdTotales(Afiche* pBuffer,int limite,int idCliente);

int afi_cantidadAfichesByZona(Afiche *pBuffer,int limite,int zona);
int afi_cantidadAfiches(Afiche* pBuffer,int limite);
#endif // AFICHE_H_INCLUDED
