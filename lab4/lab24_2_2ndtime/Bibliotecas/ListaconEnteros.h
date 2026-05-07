//
// Created by ANTONIO on 6/05/2026.
//

#ifndef LAB24_2_2NDTIME_LISTACONENTEROS_H
#define LAB24_2_2NDTIME_LISTACONENTEROS_H
bool leenumeros(ifstream &arch,void *&dato);
bool leeregnumeros(ifstream &arch,void *&dato,void *&clave) ;
bool compruebanumero(void *nodoActual,void *clave);
void imprimenumeros(ofstream &archRep,void *nodoActual);
#endif //LAB24_2_2NDTIME_LISTACONENTEROS_H
