//
// Created by ANTONIO on 6/05/2026.
//

#ifndef LAB24_2_2NDTIME_LISTACONREGISTROS_H
#define LAB24_2_2NDTIME_LISTACONREGISTROS_H

bool leeregistros(ifstream &arch,void *&dato);
bool leeordenes(ifstream &arch,void *&dato,void *&clave);
bool compruebaregistro(void *nodoActual,void *clave);
void imprimeregistros(ofstream &archRep, void *nodoActual) ;
//aux
char *leerCadenaExacta(ifstream &arch,char delim);
#endif //LAB24_2_2NDTIME_LISTACONREGISTROS_H
