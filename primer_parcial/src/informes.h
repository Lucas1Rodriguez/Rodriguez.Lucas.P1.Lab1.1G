#ifndef INFORMES_H_
#define INFORMES_H_

int printAvionSegunAerolinea(aerolinea aerolineaList[], int lenAerolinea, avion avionList[], int lenAvion, tipo tipoList[], int lenTipo, piloto pilotoList[], int lenPiloto, int id);
int printAvionSegunTipo(tipo tipoList[], int lenTipo, aerolinea aerolineaList[], int lenAerolinea, avion avionList[], int lenAvion, piloto pilotoList[], int lenPiloto, int id);
int promedioAvionJet(avion avionList[], int len, tipo tipoList[], int lenTipo);
int printAerolineaMenorCantidadAviones(avion avionList[], int len, aerolinea aerolineaList[], int lenAerolinea);
#endif /* INFORMES_H_ */
