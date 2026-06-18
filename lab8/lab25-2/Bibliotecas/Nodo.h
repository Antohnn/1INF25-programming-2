//
// Created by ANTONIO on 15/06/2026.
//

#ifndef LAB25_2_NODO_H
#define LAB25_2_NODO_H

#include "../Bibliotecas/Metrica/Metrica.h"

class Nodo {
    Metrica *metrica;
    Nodo *anterior;
    Nodo *siguiente;

public:
    Nodo();
    friend class Lista;
};


#endif //LAB25_2_NODO_H
