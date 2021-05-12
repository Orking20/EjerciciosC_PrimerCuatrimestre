#ifndef COMPRA_H_
#define COMPRA_H_
#define TAM_DIRECCION 64
#define TAM_COLOR 32
#define TAM_ESTADO 30
#define VACIO 0
#define PENDIENTE_COBRAR 1
#define COBRADO 2

typedef struct
{
	char direccion[TAM_DIRECCION];
	char color[TAM_COLOR];
	int cantBarbijos;
	float importe;
	int idCompra;
	int idCliente;
	int estado;
}Compra;

int compra_inicializar(Compra* pCompra, int limite);
void compra_harcodeo(Compra* pCompra, int limite);

int compra_mostrarId(Compra* pCompra, int indice);
int compra_mostrar(Compra* pCompra, int limite);
int compra_mostrarConId(Compra* pCompra, int limite);
int compra_buscarIndiceVacio(Compra* pCompra, int limite);
int compra_buscarPorId(Compra* pCompra, int limite, int id);
int compra_buscar(Compra* pCompra, int limite);

#endif /* COMPRA_H_ */
