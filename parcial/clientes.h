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

int cli_obtenerID();
int cli_inicializarArray(Cliente* pBuffer,int limite);
int cli_alta(Cliente* pBuffer,int id,int limite,char* apellido,char* nombre,char*cuit);
int cli_modificarbyId(Cliente* pBuffer,int limite,int id);
int cli_eliminarbyId(Cliente* pBuffer,int limite,int id);
int cli_existeId(Cliente* pbuffer,int limite,int id);
#endif // CLIENTES_H_INCLUDED
