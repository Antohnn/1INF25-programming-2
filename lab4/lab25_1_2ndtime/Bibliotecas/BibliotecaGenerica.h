//
// Created by ANTONIO on 7/05/2026.
//

#ifndef LAB25_1_2NDTIME_BIBLIOTECAGENERICA_H
#define LAB25_1_2NDTIME_BIBLIOTECAGENERICA_H

using namespace std;

void generalista(void *&lista) ;
void creaLista(void *lista,bool (*leeDatos) (ifstream &,void *&),int (*cmp)(void *,void *),void *(*buscalista)(void *,void *),
    const char *nombArch);
void insertaLista(void *lista,int (*cmp)(void *,void *),void *(*buscalista)(void *,void *),void *dato);
//aux
void abrirIn(ifstream &arch,const char *nombArch);
void abrirOut(ofstream &archRep,const char *nombArch);
void insertaSiguiente(void *lista,void *nodo,void *dato) ;
bool esListaVacia(void *lista);
#endif //LAB25_1_2NDTIME_BIBLIOTECAGENERICA_H
