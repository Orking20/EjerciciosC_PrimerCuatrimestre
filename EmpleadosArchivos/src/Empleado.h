/*
 * Empleado.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#define TAM_NOMBRE 64
#define TAM_APELLIDO 64
#define TAM_DNI 30

typedef struct
{
	int idEmpleado;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	char dni[TAM_DNI];
}Empleado;


//Memoria dinámica
Empleado* empleado_new(void);
Empleado* empleado_newParametro(int idEmpleado, char* nombre, char* apellido, char* dni);
int empleado_delete(Empleado* this);

//ABM
int empleado_inicializar(Empleado** pEmpleado, int limite);
int empleado_alta(Empleado** pEmpleado, int limite);
int empleado_baja(Empleado** pEmpleado, int limite);
int empleado_modificar(Empleado** pEmpleado, int limite);
int empleado_listado(Empleado** pEmpleado, int limite);
int empleado_ordenarPorNombre(Empleado** pEmpleado, int limite);
int empleado_buscarIndiceVacio(Empleado** pEmpleado, int limite);
int empleado_buscarEmpleado(Empleado** pEmpleado, int limite);
int empleado_generarId(void);
int empleado_buscarPorId(Empleado** pEmpleado, int limite, int id);

//Setters
int empleado_setIdEmpleado(Empleado* this, int idEmpleado);
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_setApellido(Empleado* this, char* apellido);
int empleado_setDni(Empleado* this, char* dni);

//Getters
int empleado_getIdEmpleado(Empleado* this, int* flagError);
char* empleado_getNombre(Empleado* this, int* flagError);
char* empleado_getApellido(Empleado* this, int *flagError);
char* empleado_getDni(Empleado* this, int* flagError);

//Validaciones
int isValidId(int id);
int isValidNombre(char* nombre);
int isValidApellido(char* apellido);
int isValidDni(char* dni);

//Archivos
int empleado_establecerDatos(Empleado** pEmpleado, int limite);
int empleado_guardarCambios(Empleado** pEmpleado, int limite);

#endif /* EMPLEADO_H_ */
