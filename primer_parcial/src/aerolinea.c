#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aerolinea.h"

int obtenerDescripcionAerolinea(aerolinea aerolineasList[],int id, int len, char descripcion[])
{
	int retorno = 0;
	if(aerolineasList != NULL && len >0 && descripcion != NULL)
	{
		for(int i; i<= len; i++)
		{
			if(aerolineasList[i].id == id)
			{
				strcpy(descripcion, aerolineasList[i].descripcion);
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int printAerolineas(aerolinea aerolineasList[], int len)
{
	int retorno = 0;
	if(aerolineasList != NULL && len > 0)
	{
	    printf("					**LISTADO DE AEROLINEAS**					\n");
	    printf("ID |		Descripcion|\n");
	    for(int i; i< len; i++)
		{
	    	printf("%d,		%s\n",aerolineasList[i].id,aerolineasList[i].descripcion);
		}
		retorno = 1;
	}

	return retorno;
}
