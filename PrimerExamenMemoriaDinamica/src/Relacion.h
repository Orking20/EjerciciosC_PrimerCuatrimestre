#ifndef RELACION_H_
#define RELACION_H_

int compra_alta(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente, int indice);
int cliente_baja(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra);
int compra_pagarImporte(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente);
int compra_baja(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente);

int compra_mostrarClientesRelacionados(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente, int* indice, int* flagValidarId);
int cliente_mostrarComprasPorId(Compra* pCompra, int limiteCompra, int* auxiliarId);

#endif /* RELACION_H_ */
