//
// Created by ANTONIO on 15/06/2026.
//

#ifndef LAB25_2_LISTA_H
#define LAB25_2_LISTA_H
#include "Nodo.h"


class Lista {
    Nodo *listaDoblementeLigada;

    bool comprobarOrden(Metrica *,Metrica *) ;
public:
    Lista();
    void insertar(Metrica *);
    bool estaVacia() const;
    void imprimir(ofstream &);
    void eliminarNodo(Nodo *);
    void eliminarExpiradas();
    void eliminarLista();

    //destructor
    ~Lista();

};


#endif //LAB25_2_LISTA_H
