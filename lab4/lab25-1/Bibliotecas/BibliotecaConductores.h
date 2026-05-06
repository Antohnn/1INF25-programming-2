//
// Created by ANTONIO on 6/05/2026.
//

#ifndef LAB25_1_BIBLIOTECACONDUCTORES_H
#define LAB25_1_BIBLIOTECACONDUCTORES_H

using namespace std;

bool leeconductores(ifstream &arch,void *&dato);
void *buscalistaconductores(void *lista,void *dato);
int cmpconductores(void *nodoAct,void *dato);
void cargaUnidades(void *lista,const char *nombArch);
bool leerLista(ifstream &arch,void *&dato,int &licenciaConductor);
void *buscarConductor(void *&lista,int licenciaConductor);
void insertarEnListaConductor(void *conducActual,void *dato);
void incrementarExacto(void **&registroPlacas,void *dato) ;
void imprimeconductores(ofstream &archRep,void *nodoActual) ;
void imprimePlaca(ofstream &archRep,void *placa) ;
void imprimeInfraccion(ofstream &archRep,void *infraccion);
//aux
char *leerCadenaExacta(ifstream &arch,char delim);
#endif //LAB25_1_BIBLIOTECACONDUCTORES_H
