//
// Created by ANTONIO on 18/06/2026.
//

#ifndef LAB25_2_2NDTIME_NODO_H
#define LAB25_2_2NDTIME_NODO_H

#include "../Metrica/Metrica.h"

class Nodo {
    Metrica *metrica;
    Nodo *anterior;
    Nodo *siguiente;
public:
    Nodo();
    ~Nodo();
    friend class Lista;
};


#endif //LAB25_2_2NDTIME_NODO_H
