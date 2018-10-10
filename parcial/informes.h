#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "clientes.h"
#include "afiche.h"

/** \brief  imprime por pantalla una lista de clientes a cobrar
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param afiche puntero al array clientes
 *\param int limiteAfi del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
            o no hay clientes a cobrar
 */
int inf_impClientesAcobrar(Cliente*pBufferCli,int limiteCli,Afiche* pBufferAfi,int limiteAfi);

/** \brief  ordena Clientes por id
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param int flag 0 de mayor a menor o 1 de menor a mayor
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int inf_ordenarCliById(Cliente* pBuffer,int limite,int flag);

/** \brief  ordena Afiches por id
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param int flag 0 de mayor a menor o 1 de menor a mayor
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int inf_ordenarAfiById(Afiche* pBuffer,int limite,int flag);

/** \brief  ordena Cliente por cuit
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param int flag 0 de mayor a menor o 1 de menor a mayor
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int inf_ordenarCliByCuit(Cliente* pBuffer,int limite,int flag);

/** \brief  ordena Cliente por apellido
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param int flag 0 de mayor a menor o 1 de menor a mayor
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int inf_ordenarCliByNombre(Cliente* pBuffer,int limite,int flag);

/** \brief  ordena Cliente por nombre
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param int flag 0 de mayor a menor o 1 de menor a mayor
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int inf_ordenarCliByNombre(Cliente* pBuffer,int limite,int flag);

/** \brief  imprime por pantalla el cliente con mas afiches o menos
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param afiche puntero al array clientes
 *\param int limiteAfi del array
 *\param int flag 0 para buscar el mayor 1 al menor
 *\param msj mensaje a imprimir antes de mostar al mayor o menor
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
            o no hay clientes a cobrar
 */
int inf_impCliByMayorOrMenorCanAfiches(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli,int flag,char* msj);

/** \brief  imprime por pantalla el cliente con mas afiches a cobrar
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param afiche puntero al array clientes
 *\param int limiteAfi del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
            o no hay clientes a cobrar
 */
int inf_impCliByMayorAfichesACobrar(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli,char* msj);

/** \brief  imprime por pantalla el cliente con mas ventas a cobrar
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param afiche puntero al array clientes
 *\param int limiteAfi del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
            o no hay clientes a cobrar
*/
int inf_clienteMasACobrar(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli);

/** \brief  imprime por pantalla el cliente con mas ventas cobradas
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param afiche puntero al array clientes
 *\param int limiteAfi del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
            o no hay clientes a cobrar
*/
int inf_clienteMasCobradas(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli);

/** \brief  imprime por pantalla el cliente con mas ventas
 *\param Cliente puntero al array clientes
 *\param int limiteCli del array
 *\param afiche puntero al array clientes
 *\param int limiteAfi del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
            o no hay clientes a cobrar
*/
int inf_clienteMasventas(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli);

int inf_zonaMenosAfiVendidos(Afiche* pBuffer,int limite);

int inf_cantidadConMenos100Afi(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli);

int inf_cantidadAfiByZona(Afiche* pBuffer,int limite);

int inf_ordenarAfiByZona(Afiche* pBuffer,int limite,int flag);
int inf_promedioAfichesByCliente(Afiche* pBufferAfi,int limiteAfi,Cliente* pBufferCli,int limiteCli);
#endif // INFORMES_H_INCLUDED
