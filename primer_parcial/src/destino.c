
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
		printf("%d,		%s,		%d\n",destinoList->id,destinoList->descripcion,destinoList->precio);
	}

	return retorno;
}
