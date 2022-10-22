/*
 * aerolinea.c
 *
 *  Created on: 21 oct. 2022
 *      Author: USURIO
 */
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
				retorno = 1;
			}
		}
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
		printf("%d,		%s\n",aerolineasList->id,aerolineasList->descripcion);
	}


	return retorno;
}
