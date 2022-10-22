#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int obtenerDescripcionTipo(tipo tipoList[],int id, int len, char descripcion[])
{
	int retorno = 0;
	if(tipoList != NULL && len >0 && descripcion != NULL)
	{
		for(int i; i<= len; i++)
		{
			if(tipoList[i].id == id)
			{
				strcpy(descripcion, tipoList[i].descripcion);
				break;
				retorno = 1;
			}
		}
	}
	return retorno;
}
int printTipos(tipo tipoList[], int len)
{
	int retorno = 0;
	if(tipoList != NULL && len > 0)
	{
		printf("					**LISTADO DE TIPOS**					\n");
		printf("ID |		Descripcion|\n");
		printf("%d,		%s\n",tipoList->id,tipoList->descripcion);
	}


	return retorno;
}
