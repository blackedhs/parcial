#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int acobrar;
    int isEmpty;
}Cliente;

/** \brief  devuelve un numero de Id que no se repite.
 * \return int Return comienza en 0 y se incrementa en 1
 */
int cli_obtenerID();
/** \brief  incia todos los campos is Empty en 1 para saber q esta vacio.
 *\param Cliente puntero al array clientes
 *\param int limite del array
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int cli_inicializarArray(Cliente* pBuffer,int limite);
/** \brief  Da de alta un nuevo cliente.
 *\param Cliente puntero al array clientes
 *\param int limite del array
 *\param id numero de id
 *\param apellido apellido a cargar
 *\param nombre nombre a cargar
 *\param cuit a cargar
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int cli_alta(Cliente* pBuffer,int id,int limite,char* apellido,char* nombre,char*cuit);
/** \brief  modifica un cliente,recibiendo su id como parametro y permite modificar su
            apellido nombre y cuit.Coloca isEmpty en 0
 *\param Cliente puntero al array clientes
 *\param int limite del array
 *\param id numero de id a modificar
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int cli_modificarbyId(Cliente* pBuffer,int limite,int id);
/** \brief  Borra un cliente,recibiendo su id como parametro,colocando isEmpty en 1
 *\param Cliente puntero al array clientes
 *\param int limite del array
 *\param id numero de id a borrar
 * \return int Return comienza en 0 si esta todo bien y -1 si algun parametro es incorrecto
 */
int cli_eliminarbyId(Cliente* pBuffer,int limite,int id);
/** \brief  valida si el cliente existe
 *\param Cliente puntero al array clientes
 *\param int limite del array
 *\param id numero de id a validar
 * \return int Return comienza en 0 si existe y -1 si no
 */
int cli_existeId(Cliente* pbuffer,int limite,int id);

/** \brief  Imprime cliente por id
 *\param Cliente puntero al array clientes
 *\param int limite del array
 *\param id numero de id a imprimir
 * \return int Return comienza en 0 si existe y -1 si no
 */
int cli_impById(Cliente* pBuffer,int limite,int idCliente);

int cli_cantidadClientes(Cliente* pBuffer,int limite);
#endif // CLIENTES_H_INCLUDED
