#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "utn_biblioteca.h"

static int getId(void);
static int getFieldToModify(int*selectedField);
static int getCapacidad(int *capacidad);
static int getTipo(int *tipo);

#define LEN_AEROLINEA_Y_TIPO 20

int initAviones(avion avionList[],int len)
{
	int i;
	int retorno = -1;

	if(avionList != NULL && len > 0)
	{
		for(i=0; i < len; i++)
		{
			avionList[i].isEmpty = 1;
		}
		retorno=1;
	}
	return retorno;
}

//cargo los aviones
//llamo a la funcion pedir,numero,texto y float
//devuelvo el resultado por puntero
//cambio el valor de la bandera a 0
int addAviones(avion* list, int len, int id, int idAerolinea,int idTipo, int capacidad)
{
	int retorno=-1;
	int auxIdAerolinea;
	int auxIdTipo;
	int auxcapacidad;

	if(list!=NULL)
	{
		if(utn_getNumeroInt(&auxcapacidad, "\nIngrese la cantidad de pasajeros entre 10 y 300: ", "Error\n",10, 300, 3)==0)
		{
			if(utn_getNumeroInt(&auxIdAerolinea, "\nIngrese la aerolinea del avion: ", "Error\n",1000, 1004, 3)==0)
			{
				if(utn_getNumeroInt(&auxIdTipo, "\nIngrese el tipo de avion:\n", "Error\n",5000, 5004, 3)==0)
				{
						list-> capacidad = auxcapacidad;
						list-> idAerolinea = auxIdAerolinea;
						list-> idTipo = auxIdTipo;
						list->id = getId();
						list->isEmpty = 0;
						retorno=0;
				}
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


int findAvionById(avion* pAvion, int len, int idBuscado)
{
	int status=-1;
	int i;

	if(pAvion!=NULL && len>0 && idBuscado>=0)
	{
		for(i=0; i<len ; i++)
		{
			if( pAvion[i].id==idBuscado && pAvion[i].isEmpty == 0)
			{
				status = i;
				break;
			}
		}
	}
	return status;
}
//recorro el array
//verifico que haya espacio
//retorno la posicion
int findEmptyPosition(avion* pAvion, int len)
{
	int retorno=-1;
	int i;

	if(pAvion!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pAvion[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

//Para eliminar los aviones
//Cambio el isEmpty del id recibido a 1
int removeAvion(avion avionList[], int len, int idBuscado)
{
	int status = -1;
	if(avionList != NULL)
	{
		status = 1;
		avionList[idBuscado].isEmpty=1;
	}
	return status;
}

//Modifico posicion
//Llamo a funcion para seleccionar opcion
//Modifico la opcion elegida
int modifyAvion(avion* pAvion)
{
	int retorno=-1;
	int idamodificar;
	int auxCapacidad;
	int auxTipo;

	if(pAvion !=NULL)
	{
		if(getFieldToModify(&idamodificar)==1)
		{
			retorno=1;
			switch (idamodificar)
			{
			case 1:
				if(getCapacidad(&auxCapacidad)==1)
				{
					pAvion->capacidad = auxCapacidad;
				}
				break;
			case 2:
				if(getTipo(&auxTipo)==1)
				{
					pAvion->idTipo = auxTipo;
				}
				break;
			}
		}
	}
	return retorno;
}
//Funcion privada del archivo
//Llamo a la funcion pedir int
//Retorno por puntero el valor ingresado para la funcion modificar
static int getFieldToModify(int*selectedField)
{
	int status=-1;
	int auxSelectItem;

	if(utn_getNumeroInt(&auxSelectItem, "\nElegi la opcion:\n 1-Capacidad\n 2-Tipo\n", "Error",1 , 2, 2)==0)
	{
		status =1;
		*selectedField= auxSelectItem;
	}
	return status;
}


static int getCapacidad(int* capacidad)
{
	int status =-1;
	int auxCapacidad;
	if(utn_getNumeroInt(&auxCapacidad, "\nIngrese capacidad del avion entre 10 y 300:", "Error",10, 300, 3)==0)
	{
		status=1;
		*capacidad = auxCapacidad;
	}
	return status;
}
static int getTipo(int* tipo)
{
	int status =-1;
	int auxTipo;
	if(utn_getNumeroInt(&auxTipo, "\nIngrese la aerolinea del avion: ", "Error\n",1000, 1004, 3)==0)
	{
		status=1;
		*tipo = auxTipo;
	}
	return status;
}


int sortAvionesPorAerolineaYCapacidad(avion avionList[], int len)
{
	int status=-1;
	int flagSwap;
	int aux;
	avion buffer;
	if(avionList != NULL && len>=0)
	{
		flagSwap=0;
		do{
			flagSwap=0;
			for(int i=0; i<len-1; i++)
			{
				aux = strncmp(avionList[i].idAerolinea,avionList[i+1].idAerolinea,LEN_AEROLINEA_Y_TIPO);
				if(aux > 0 || (aux==0 && avionList[i].capacidad < avionList[i+1].capacidad))
				{
					flagSwap = 1;
					buffer = avionList[i];
					avionList[i] = avionList[i+1];
					avionList[i+1] = buffer;
					status=0;
				}
			}
			len--;
		}while(flagSwap);
	}
	return status;
}


int printAviones(avion* pAvion, int len,  aerolinea* pAerolinea, int lenAerolinea, tipo* pTipo, int lenTipo)
{
	int retorno = 0;
	char descripcionAerolinea[20];
	char descripcionTipo[20];
	if(pAvion->isEmpty ==0 && len > 0)
	{
		obtenerDescripcionAerolinea(pAerolinea,pAvion->id, lenAerolinea, descripcionAerolinea);
		obtenerDescripcionTipo(pTipo, pAvion->id, lenTipo, descripcionTipo);
		for(int i = 0;i< len; i++)
		{
			printf("					**LISTADO DE AVIONES**					");
			printf("ID |		CAPACIDAD		|		AEROLINEA 		|		TIPO		|");
			printf("%d,		 %d,		 %20s, 		%20s\n",pAvion[i].id, pAvion[i].capacidad, descripcionAerolinea, descripcionTipo);
		}
		retorno = 1;
	}
	return retorno;
}

int printAvion(avion pAvion, aerolinea pAerolinea[], int lenAerolinea, tipo pTipo[], int lenTipo)
{
	int retorno = 0;
	char descripcionAerolinea[20];
	char descripcionTipo[20];

		if(pAvion.isEmpty ==0)
		{
			obtenerDescripcionAerolinea(pAerolinea,pAvion.id, lenAerolinea, descripcionAerolinea);
			obtenerDescripcionTipo(pTipo, pAvion.id, lenTipo, descripcionTipo);
			printf("%d,		 %d,		 %20s, 		%20s\n",pAvion.id, pAvion.capacidad, descripcionAerolinea, descripcionTipo);
		}
	return retorno;
}

