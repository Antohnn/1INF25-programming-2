//
// Created by ANTONIO on 15/06/2026.
//

#ifndef LAB25_2_LISTA_H
#define LAB25_2_LISTA_H
#include "Nodo.h"


class Lista {
    Nodo *listaDoblementeLigada;
public:
    Lista();
    void insertar(Nodo *,Metrica *);
    bool estaVacia() const;
};


#endif //LAB25_2_LISTA_H
