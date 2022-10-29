#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piloto.h"
#include "utn_biblioteca.h"

int obtenerNombrePiloto(piloto pilotosList[],int id, int len, char nombre[])
{
	int retorno = 0;
	if(pilotosList != NULL && len >0 && nombre != NULL)
	{
		for(int i; i<= len; i++)
		{
			if(pilotosList[i].id == id)
			{
				strcpy(nombre, pilotosList[i].nombre);
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int printPilotos(piloto pilotosList[], int len)
{
	int retorno = 0;
	if(pilotosList != NULL && len > 0)
	{
	    printf("					**LISTADO DE PILOTOS**					\n");
	    printf("ID |		Nombre|		Sexo\n");
	    for(int i; i< len; i++)
		{
	    	printf("%d,		%s,		%s\n",pilotosList[i].id,pilotosList[i].nombre,pilotosList[i].sexo);
		}
		retorno = 1;
	}

	return retorno;
}
