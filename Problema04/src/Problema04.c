/*
 ============================================================================
 Name        : Problema04.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA, los datos solicitados son:
			   Legajo
			   Tipo cursada(L: &quot;libre&quot; - P: &quot;presencial&quot; – R: &quot;remota&quot;)
			   Cantidad de materias( mas de cero y menos de 8)
			   Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
			   Nota promedio (entre 0 y 10)
			   Edad (validar)
			   Se debe informar de existir, o informar que no existe , en el caso que corresponda.
			   a) El Legajo del mejor promedio femenino.
			   b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
			   c) El promedio de nota por sexo.
			   d) La edad y legajo del que cursa más materias. (Sin importar su género)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main(void)
{
	setbuf(stdout, NULL);

	long legajo;
	char cursada;
	int cantMaterias;
	char sexo;
	int notaPromedio;
	int edad;
	char continuar;
	//a)
	int promedioMaxFemenino;
	long legajoMaxPromedio;
	int flagPromedio;
	//b)
	int edadMinimaLibreMasculino;
	int flagEdad;
	long legajoEdadMinLibreMasculino;
	//c)
	int sumaNotaMasculino;
	int sumaNotaFemenino;
	int contMasculinos;
	int contFemeninos;
	float promedioMasculino;
	float promedioFemenino;
	//d)
	int alumnoMasMaterias;
	int edadMasMaterias;
	long legajoMasMaterias;
	int flagMaterias;

	sumaNotaMasculino = 0;
	sumaNotaFemenino = 0;
	contMasculinos = 0;
	contFemeninos = 0;

	flagPromedio = TRUE;
	flagEdad = TRUE;
	flagMaterias = TRUE;

	do
	{
		printf("Legajo (DNI): ");
		fflush(stdin);
		scanf("%ld", &legajo);
		while(legajo < 0)
		{
			printf("Error. Legajo (DNI): ");
			fflush(stdin);
			scanf("%ld", &legajo);
		}

		printf("Tipo de cursada (L: Libre - P: Presencial - R: Remota): ");
		fflush(stdin);
		scanf("%c", &cursada);
		while(cursada != 'L' && cursada != 'P' && cursada != 'R')
		{
			printf("Error. Tipo de cursada (L: Libre - P: Presencial - R: Remota): ");
			fflush(stdin);
			scanf("%c", &cursada);
		}

		printf("Cantidad de materias (entre 1 y 7): ");
		fflush(stdin);
		scanf("%d", &cantMaterias);
		while(cantMaterias < 1 || cantMaterias > 7)
		{
			printf("Error. Cantidad de materias (entre 1 y 7): ");
			fflush(stdin);
			scanf("%d", &cantMaterias);
		}

		printf("Sexo (M: Masculino - F: Femenino): ");
		fflush(stdin);
		scanf("%c", &sexo);
		while(sexo != 'M' && sexo != 'F')
		{
			printf("Error. Sexo (M: Masculino - F: Femenino): : ");
			fflush(stdin);
			scanf("%c", &sexo);
		}

		printf("Nota promedio (entre 0 y 10): ");
		fflush(stdin);
		scanf("%d", &notaPromedio);
		while(notaPromedio < 0 || notaPromedio > 10)
		{
			printf("Error. Nota promedio (entre 0 y 10): ");
			fflush(stdin);
			scanf("%d", &notaPromedio);
		}

		printf("Edad: ");
		fflush(stdin);
		scanf("%d", &edad);
		while(edad < 0)
		{
			printf("Error. Edad: ");
			fflush(stdin);
			scanf("%d", &edad);
		}

		switch(sexo)
		{
			case 'M':
			{
				if(cursada == 'L')
				{
					if(flagEdad || edad < edadMinimaLibreMasculino)
					{
						edadMinimaLibreMasculino = edad;
						legajoEdadMinLibreMasculino = legajo;
						flagEdad = FALSE;
					}
				}

				contMasculinos++;
				sumaNotaMasculino += notaPromedio;
				break;
			}
			case 'F':
			{
				if(flagPromedio || notaPromedio > promedioMaxFemenino)
				{
					promedioMaxFemenino = notaPromedio;
					legajoMaxPromedio = legajo;
					flagPromedio = FALSE;
				}

				contFemeninos++;
				sumaNotaFemenino += notaPromedio;
				break;
			}
		}

		if(flagMaterias || cantMaterias > alumnoMasMaterias)
		{
			alumnoMasMaterias = cantMaterias;
			legajoMasMaterias = legajo;
			edadMasMaterias = edad;
			flagMaterias = FALSE;
		}

		printf("¿Desea continuar? (s/n): \n");
		fflush(stdin);
		scanf("%c", &continuar);
	}while(continuar == 's');

	if(contMasculinos > 0)
	{
		promedioMasculino = (float)sumaNotaMasculino / contMasculinos;
	}
	else
	{
		promedioMasculino = 0;
	}
	if(contFemeninos > 0)
	{
		promedioFemenino = (float)sumaNotaFemenino / contFemeninos;
	}
	else
	{
		promedioFemenino = 0;
	}

	printf("El legajo del mejor promedio femenino es: %ld\n", legajoMaxPromedio);
	printf("El legajo del más joven de los masculinos que dan libre: %ld\n", legajoEdadMinLibreMasculino);
	printf("Promedio de nota de masculinos: %0.2f\n", promedioMasculino);
	printf("Promedio de nota de femeninos: %0.2f\n", promedioFemenino);
	printf("El legajo del alumno con más materias es %ld con %d años\n", legajoMasMaterias, edadMasMaterias);

	return EXIT_SUCCESS;
}
