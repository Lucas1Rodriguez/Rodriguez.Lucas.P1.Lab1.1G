#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelo.h"
#include "avion.h"
#include "destino.h"
#include "utn_biblioteca.h"

static int getId(void);

int initVuelos(vuelo vuelosList[],int len)
{
	int i;
	int retorno = -1;

	if(vuelosList != NULL && len > 0)
	{
		for(i=0; i < len; i++)
		{
			vuelosList[i].isEmpty = 1;
		}
		retorno=1;
	}
	return retorno;
}

int addVuelos(vuelo* list, destino* destinoList, int len, int lenDestino)
{
	int retorno=0;
	int auxIdAvion;
	int auxIdDestino;


	if(list!=NULL)
	{
			if(utn_getNumeroInt(&auxIdAvion, "\nIngrese el id del avion: ", "Error, ingrese un id valido\n",1, 20, 3)==0)
			{
			    printDestinos(destinoList, lenDestino);
				if(utn_getNumeroInt(&auxIdDestino, "\nIngrese el tipo de avion:\n", "Error, ingrese un tipo valido\n",2000, 2003, 3)==0)
				{
					printf("Ingrese la fecha del vuelo:");
					scanf("%d/%d/%d", &list->fecha.dia, &list->fecha.mes, &list->fecha.ano);
					list-> idAvion = auxIdAvion;
					list-> idDestino = auxIdDestino;
					list->id = getId();
					list->isEmpty = 0;
					retorno = 1;
				}
			}
	}
	return retorno;
}


static int getId(void)
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}


//recorro el array
//verifico que haya espacio
//retorno la posicion
int findEmptyPositionVuelo(vuelo* pVuelo, int len)
{
	int retorno=-1;
	int i;

	if(pVuelo!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pVuelo[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}




int printVuelos(vuelo vuelosList[], int len)
{
	int retorno = 0;
	if(vuelosList != NULL && len > 0)
	{
	    printf("					**LISTADO DE AEROLINEAS**					\n");
	    printf("ID |		Dia/Mes/Año|\n");
	    for(int i; i< len; i++)
		{
	    	printf("%d,		%d,%d,%d\n",vuelosList[i].id,vuelosList[i].fecha.dia,vuelosList[i].fecha.mes,vuelosList[i].fecha.ano);
		}
		retorno = 1;
	}

	return retorno;
}
