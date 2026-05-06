//
// Created by ANTONIO on 3/05/2026.
//
#include <iostream>


using namespace std;

#include "Lista.h"
#include "enums.h"

void construirLista(void *&lista) {
    void **listaAux=new void*[3];
    listaAux[CABEZA]=nullptr;
    listaAux[COLA]=nullptr;
    listaAux[LONGITUD]=new int(0);

    lista=listaAux;
}
bool esListaVacia(const void *lista) {
    const void **aux=(const void**)lista;
    return aux[CABEZA]==nullptr;
}
void *ultimo(void *lista) {
    void **auxLista=(void **)lista;
    return auxLista[COLA];
}
void insertarSiguiente(void *lista,void *nodo,void *dato) {
    void **auxLista=(void **)lista;
    int *cantNodos=(int *)auxLista[LONGITUD];

    void **nuevoNodo=new void*[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SIGUIENTE]=nullptr;

    if (nodo==nullptr) {
        if (esListaVacia(lista)) {
            auxLista[CABEZA]=nuevoNodo;
            auxLista[COLA]=nuevoNodo;
        }else {
            nuevoNodo[SIGUIENTE]=auxLista[CABEZA];
            auxLista[CABEZA]=nuevoNodo;
        }
    }else {
        void **auxNodo=(void **)nodo;

        nuevoNodo[SIGUIENTE]=auxNodo[SIGUIENTE];
        auxNodo[SIGUIENTE]=nuevoNodo;
        if (nodo==auxLista[COLA]) {
            auxLista[COLA]=nuevoNodo;
        }
    }
    (*cantNodos)++;
}


