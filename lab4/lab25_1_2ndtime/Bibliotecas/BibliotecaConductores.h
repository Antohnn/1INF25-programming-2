//
// Created by ANTONIO on 7/05/2026.
//

#ifndef LAB25_1_2NDTIME_BIBLIOTECACONDUCTORES_H
#define LAB25_1_2NDTIME_BIBLIOTECACONDUCTORES_H

bool leeconductores(ifstream &arch,void *&dato);
void *buscalistaconductores(void *lista,void *dato);
int cmpcondcutores(void *nodoActual,void *dato);
//aux
char *leerCadenaExacta(ifstream &arch,char delim) ;

#endif //LAB25_1_2NDTIME_BIBLIOTECACONDUCTORES_H
