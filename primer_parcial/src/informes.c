#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#include "piloto.h"
#include "utn_biblioteca.h"




int printAvionSegunAerolinea(aerolinea aerolineaList[], int lenAerolinea, avion avionList[], int lenAvion, tipo tipoList[], int lenTipo, piloto pilotoList[], int lenPiloto, int id)
{
	int retorno = 0;

	if(aerolineaList != NULL && lenAerolinea > 0 && avionList != NULL && lenAvion > 0)
	{
		printAerolineas(aerolineaList, lenAerolinea);
		if(aerolineaList->id == id)
		{
			printAvion(avionList, lenAvion, aerolineaList, lenAerolinea, tipoList, lenTipo, pilotoList, lenPiloto);
			retorno = 1;
		}
	}


	return retorno;
}

int printAvionSegunTipo(tipo tipoList[], int lenTipo, aerolinea aerolineaList[], int lenAerolinea, avion avionList[], int lenAvion, piloto pilotoList[], int lenPiloto, int id)
{
	int retorno = 0;

	if(tipoList != NULL && lenTipo > 0)
	{
		printTipos(tipoList, lenTipo);
		if(tipoList->id == id)
		{
			printAvion(avionList, lenAvion, aerolineaList, lenAerolinea, tipoList, lenTipo, pilotoList, lenPiloto);
			retorno = 1;
		}
	}


	return retorno;
}

int promedioAvionJet(avion avionList[], int len, tipo tipoList[], int lenTipo)
{
	int retorno = 0;
	int acum = 0;
	int contJets = 0;
	int promedioJet = 0;
	if(avionList != NULL && len > 0 && tipoList != NULL && lenTipo > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(avionList->isEmpty == 0 && tipoList->id == 5000)
			{
				contJets++;
			}
			acum+=acum;
		}

		promedioJet = acum / contJets;

		printf("El promedio de jets es: %d", promedioJet);
		retorno = 1;
	}


	return retorno;
}

int printAerolineaMenorCantidadAviones(avion avionList[], int len, aerolinea aerolineaList[], int lenAerolinea)
{
	int retorno = -1;
	int i;
	int j;
	int contAerolinea;
	int idMin;
	int contAerolineaMin;
	int flag = 0;

	if(avionList != NULL && len > 0 && aerolineaList != NULL && lenAerolinea > 0)
	{
		retorno = 0;
		for(i = 0; i < lenAerolinea; i++)
		{
			contAerolinea = 0;
			for(j = 0; j < len; j++)
			{
				if(avionList[j].isEmpty == 0 && avionList[j].id == aerolineaList[i].id)
				{
					contAerolinea++;
				}
			}
			if(flag == 0 || contAerolinea < contAerolineaMin)
			{
				idMin = i;
				contAerolineaMin = contAerolinea;
				flag = 1;
			}
		}
		switch(aerolineaList[idMin].id)
		{
			case 1000:
				printf("La aerolinea con la menor cantidad de aviones es: Lan\n");
				break;
			case 1001:
				printf("La aerolinea con la menor cantidad de aviones es: Iberia\n");
				break;
			case 1002:
				printf("La aerolinea con la menor cantidad de aviones es: Norwegian\n");
				break;
			case 1003:
				printf("La aerolinea con la menorcantidad de aviones es: American\n");
				break;
			case 1004:
				printf("La aerolinea con la menor cantidad de aviones es: Austral\n");
				break;
		}
	}

	return retorno;
}
