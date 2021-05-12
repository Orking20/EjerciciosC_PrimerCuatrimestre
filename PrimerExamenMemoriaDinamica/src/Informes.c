#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cliente.h"
#include "Compra.h"
#include "Relacion.h"

/*
a) Cliente con más compras pagadas.
b) Cliente con más compras pendientes.
c) Lista de compras pendientes de pago con información de la compra y del cliente.*/

static int info_colorDeBarbijoMasComprado(Compra* pCompra, int limiteCompra);
static int info_comprasPendientes(Compra* pCompra, int limiteCompra);
static int info_precioPorUnidadMinimo(Compra* pCompra, int limiteCompra);
static int info_listadoComprasPendientes(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra);
static int info_clienteConMasComprasPagadas(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra);
static int info_clienteConMasComprasPendientes(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra);

/**
 * brief Muestra todos los clientes con todas las compras que le corresponden a cada uno
 * \param Cliente* pCliente: Cadena que se usa para mostrar los datos de cada cliente
 * \param Compra* pCompra: Cadena que se usa para mostrar los datos de cada compra
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se mostraron los datos o -1 (ERROR) si no*/
int info_mostrarTodo(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra)
{
	int retorno = -1;

	if(pCliente != NULL && pCompra != NULL && limiteCliente > 0 && limiteCompra > 0)
	{
		if(cliente_buscar(pCliente, limiteCliente) == 1)
		{
			for(int i = 1; i <= limiteCliente; i++)
			{
				if(pCliente[i - 1].idCliente == i)
				{
					printf("\nCliente: %s %-25s CUIT: %s\n\n", pCliente[i - 1].nombre, pCliente[i - 1].apellido, pCliente[i - 1].cuit);
					cliente_mostrarComprasPorId(pCompra, limiteCompra, &i);
				}
			}
		}
		else
		{
			printf("\nError. Todavía no se ingresó ningun cliente. Primero tiene que dar de alta un cliente para añadir una compra.");
		}
	}

	return retorno;
}

/**
 * brief Muestra todos los informes
 * \param Cliente* pCliente: Cadena que se usa para llamar a otras funciones
 * \param Compra* pCompra: Cadena que se usa para llamar a otras funciones
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se mostraron los informes o -1 (ERROR) si no*/
int info_mostrarInformes(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra)
{
	int retorno = -1;

	if(pCompra != NULL && limiteCompra > 0)
	{
		if(compra_buscar(pCompra, limiteCompra) == 1)
		{
			info_colorDeBarbijoMasComprado(pCompra, limiteCompra);
			info_comprasPendientes(pCompra, limiteCompra);
			info_precioPorUnidadMinimo(pCompra, limiteCompra);
			info_listadoComprasPendientes(pCliente, pCompra, limiteCliente, limiteCompra);
			info_clienteConMasComprasPagadas(pCliente, pCompra, limiteCliente, limiteCompra);
			info_clienteConMasComprasPendientes(pCliente, pCompra, limiteCliente, limiteCompra);

		}
		else
		{
			printf("\nError. Todavía no se ingresó ninguna compra. Primero tiene que dar de alta una compra para mostrar los informes.");
		}
	}

	return retorno;
}

/**
 * brief Calcula y muestra el color más veces comprados
 * \param Compra* pCompra: Cadena que se usa para calcular el color más veces comprado
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se mostró el color más veces comprado o -1 (ERROR) si no*/
static int info_colorDeBarbijoMasComprado(Compra* pCompra, int limiteCompra)
{
	int retorno = -1;
	char coloresSinRepetir[limiteCompra][TAM_COLOR];
	int flagAdd = 1;
	int j;
	int contBarbijos = 0;
	int barbijosMaximos;
	char colorMasComprado[TAM_COLOR];

	if(pCompra != NULL && limiteCompra > 0)
	{
		for(int i = 0; i < limiteCompra; i++)
		{
			strncpy(coloresSinRepetir[i], "", sizeof(coloresSinRepetir[i]));
		}

		strncpy(coloresSinRepetir[0], pCompra[0].color, TAM_COLOR);

		for(int i = 1; i < limiteCompra; i++)
		{
			flagAdd = 1;
			for(j = 0; j < limiteCompra; j++)
			{
				if(strncmp(coloresSinRepetir[j], "", TAM_COLOR) != 0 && pCompra[i].estado != VACIO && strncmp(pCompra[i].color, coloresSinRepetir[j], TAM_COLOR) == 0)
				{
					flagAdd = 0;
					break;
				}
			}
			if(flagAdd)
			{
				strncpy(coloresSinRepetir[i], pCompra[i].color, TAM_COLOR);
			}
		}

		for(int i = 0; i < limiteCompra; i++)
		{
			contBarbijos = 0;
			for(int j = 0; j < limiteCompra; j++)
			{
				if(strncmp(coloresSinRepetir[i], "", TAM_COLOR) != 0 && pCompra[j].estado != VACIO && strncmp(coloresSinRepetir[i], pCompra[j].color, TAM_COLOR) == 0)
				{
					contBarbijos++;
				}
			}
			if(i == 0 || contBarbijos > barbijosMaximos)
			{
				barbijosMaximos = contBarbijos;
				strncpy(colorMasComprado, pCompra[i].color, sizeof(colorMasComprado));
			}
		}

		printf("\nEl color de barbijo más comprado es: %s", colorMasComprado);
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra la cantidad de compras que están pendientes
 * \param Compra* pCompra: Cadena que se usa para calcular las compras pendientes
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se mostraron la cantidad de compras pendientes o -1 (ERROR) si no*/
static int info_comprasPendientes(Compra* pCompra, int limiteCompra)
{
	int retorno = -1;
	int contPendientes = 0;

	if(pCompra != NULL && limiteCompra > 0)
	{
		for(int i = 0; i < limiteCompra; i++)
		{
			if(pCompra[i].estado == PENDIENTE_COBRAR)
			{
				contPendientes++;
			}
		}

		printf("\nCantidad de compras pendientes: %d", contPendientes);
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra el precio por unidad más bajo
 * \param Compra* pCompra: Cadena que se usa para calcular el precio por unidad mínimo
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se muestra el precio por unidad mínimo o -1 (ERROR) si no*/
static int info_precioPorUnidadMinimo(Compra* pCompra, int limiteCompra)
{
	int retorno = -1;
	float precioPorUnidad;
	float precioPorUnidadMinimo;
	int flagMinimo = 0;

	if(pCompra != NULL && limiteCompra > 0)
	{
		for(int i = 0; i < limiteCompra; i++)
		{
			if(pCompra[i].estado == COBRADO)
			{
				precioPorUnidad = pCompra[i].importe / pCompra[i].cantBarbijos;

				if(!flagMinimo || precioPorUnidad < precioPorUnidadMinimo)
				{
					precioPorUnidadMinimo = precioPorUnidad;
					flagMinimo = 1;
				}
			}
		}

		printf("\nPrecio por unidad más bajo: %.2f", precioPorUnidadMinimo);
		retorno = 0;
	}

	return retorno;
}

/**
 * brief uestra una lista de compras pendientes de pago con información de la compra y del cliente
 * \param Cliente* pCliente: Cadena que se usa para listar los clientes
 * \param Compra* pCompra: Cadena que se usa para listar las compras pendientes
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se muestra el cliente y sus compras pendientes o -1 (ERROR) si no*/
static int info_listadoComprasPendientes(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra)
{
	int retorno = -1;

	if(pCompra != NULL && limiteCompra > 0)
	{
		for(int i = 1; i <= limiteCliente; i++)
		{
			if(pCliente[i - 1].idCliente == i)
			{
				printf("\nCliente %s %-15s  CUIT: %-15s\n", pCliente[i - 1].nombre, pCliente[i - 1].apellido, pCliente[i - 1].cuit);
				for(int j = 0; j < limiteCompra; j++)
				{
					if(pCompra[j].estado == PENDIENTE_COBRAR && pCliente[i - 1].idCliente == pCompra[j].idCliente)
					{
						printf("\tDirección: %-15s Color: %-15s Cantidad de días: %-15d\n", pCompra[j].direccion, pCompra[j].color, pCompra[j].cantBarbijos);
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra el cliente con más compras pagadas
 * \param Cliente* pCliente: Cadena que se usa para calcular el cliente con mas compras pagadas
 * \param Compra* pCompra: Cadena que se usa para calcular el cliente con mas compras pagadas
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se muestra el cliente con más compras pagadas o -1 (ERROR) si no*/
static int info_clienteConMasComprasPagadas(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra)
{
	int retorno = -1;
	char clienteConMasCompras[TAM_NOMBRE];
	int contPagosCobrados = 0;
	int cobradosMaximos;

	if(pCompra != NULL && pCompra != NULL && limiteCliente > 0 && limiteCompra > 0)
	{
		for(int i = 1; i <= limiteCliente; i++)
		{
			if(pCliente[i - 1].idCliente == i)
			{
				contPagosCobrados = 0;
				for(int j = 0; j < limiteCompra; j++)
				{
					if(pCompra[j].estado == COBRADO && pCliente[i - 1].idCliente == pCompra[j].idCliente)
					{
						contPagosCobrados++;
					}
				}
				if(i == 1 || contPagosCobrados > cobradosMaximos)
				{
					cobradosMaximos = contPagosCobrados;
					strncpy(clienteConMasCompras, pCliente[i - 1].nombre, TAM_NOMBRE);
				}
			}
		}

		printf("\nCliente con más compras pagadas: %s", clienteConMasCompras);
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra el cliente con más compras pendientes
 * \param Cliente* pCliente: Cadena que se usa para calcular el cliente con mas compras pendientes
 * \param Compra* pCompra: Cadena que se usa para calcular el cliente con mas compras pendientes
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se muestra el cliente con más compras pendientes o -1 (ERROR) si no*/
static int info_clienteConMasComprasPendientes(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra)
{
	int retorno = -1;
	char clienteConMasCompras[TAM_NOMBRE];
	int contPagosPendientes = 0;
	int cobradosMaximos;

	if(pCompra != NULL && pCompra != NULL && limiteCliente > 0 && limiteCompra > 0)
	{
		for(int i = 1; i <= limiteCliente; i++)
		{
			if(pCliente[i - 1].idCliente == i)
			{
				contPagosPendientes = 0;
				for(int j = 0; j < limiteCompra; j++)
				{
					if(pCompra[j].estado == PENDIENTE_COBRAR && pCliente[i - 1].idCliente == pCompra[j].idCliente)
					{
						contPagosPendientes++;
					}
				}
				if(i == 1 || contPagosPendientes > cobradosMaximos)
				{
					cobradosMaximos = contPagosPendientes;
					strncpy(clienteConMasCompras, pCliente[i - 1].nombre, TAM_NOMBRE);
				}
			}
		}

		printf("\nCliente con más compras pendientes: %s", clienteConMasCompras);
		retorno = 0;
	}

	return retorno;
}
