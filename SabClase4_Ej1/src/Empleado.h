/*
 * Empleado.h
 *
 *  Created on: 17 abr. 2021
 *      Author: mateo
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
	int idEmpleado;
	char nombre[100];
	char puesto[64];
	long int sueldo;
	int esAnalista;
	int esTester;
}Empleado;

int cargarEmpleados(Empleado* pEmpleados, int limite, int indice);
int mostrarEmpleados(Empleado* pEmpleados, int limite);
int mostrarAnalistas(Empleado* pEmpleados, int limite);
int buscarIndiceVacio(Empleado* pEmpleados, int limite);
int ordenarPorPuestos(Empleado* pEmpleados, int limite);

#endif /* EMPLEADO_H_ */
