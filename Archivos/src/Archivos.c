/*
 ============================================================================
 Name        : Archivos.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Primeros pasos con archivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	int i;

	fp = fopen("archivo.txt", "w");
	if(fp != NULL)
	{
		i = 127;

		fprintf(fp, "%d\n", i);
		fwrite(&i, sizeof(int), 1, fp);

		fclose(fp);
	}
	else
	{
		printf("\nHubo un error abriendo el archivo");
	}

	return EXIT_SUCCESS;
}
