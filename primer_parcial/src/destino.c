#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"
#include "utn_biblioteca.h"


int printDestinos(destino destinoList[], int len)
{
	int retorno = 0;
	if(destinoList != NULL && len > 0)
	{
		printf("					**LISTADO DE DESTINOS**					\n");
		printf("ID |		Descripcion|		Precio\n");
	    for(int i; i< len; i++)
		{
		    printf("%d,		%s,		%d\n",destinoList[i].id,destinoList[i].descripcion,destinoList[i].precio);
		}
		retorno = 1;
	}

	return retorno;
}

int validarDestinos(int id, destino destinos[], int len)
{
	int retorno = 0;
	if(destinos != NULL && len >0)
	{
		for(int i = 0;i < len; i++)
		{
			if(destinos[i].id == id)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
