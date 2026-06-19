//
// Created by ANTONIO on 18/06/2026.
//

#ifndef LAB25_2_2NDTIME_LISTA_H
#define LAB25_2_2NDTIME_LISTA_H
#include "Nodo.h"


class Lista {
    Nodo *listaDoblementeLigada;
    void imprimirLinea(ofstream &, char );
public:
    Lista();
    ~Lista();
    void insertarOrdenado(Metrica *);
    bool vaAntes(Metrica *,Metrica *);
    void imprimir(ofstream &);
    void eliminarExpiradas();


    void eliminarNodo(Nodo *);
    void eliminarLista();
};


#endif //LAB25_2_2NDTIME_LISTA_H
