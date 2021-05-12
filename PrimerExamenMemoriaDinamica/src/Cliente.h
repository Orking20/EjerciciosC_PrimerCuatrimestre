#ifndef CLIENTE_H_
#define CLIENTE_H_
#define TAM_NOMBRE 64
#define TAM_APELLIDO 64
#define TAM_CUIT 24

typedef struct
{
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	char cuit[TAM_CUIT];
	int idCliente;
	int isEmpty;
}Cliente;

int cliente_inicializar(Cliente** pCliente, int limite);
void cliente_harcodeo(Cliente* pCliente, int limite);

int cliente_alta(Cliente** pCliente, int limite);
int cliente_modificar(Cliente* pCliente, int limite);

int cliente_mostrarId(Cliente* pCliente, int indice);
int cliente_mostrar(Cliente* pCliente, int limite);
int cliente_buscarIndiceVacio(Cliente** pCliente, int limite);
int cliente_buscarPorId(Cliente* pCliente, int limite, int id);
int cliente_buscar(Cliente* pCliente, int limite);

#endif /* CLIENTE_H_ */
