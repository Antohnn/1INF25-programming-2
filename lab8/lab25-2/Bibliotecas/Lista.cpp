//
// Created by ANTONIO on 15/06/2026.
//

#include <iostream>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    listaDoblementeLigada=nullptr;
}

void Lista::insertar(Nodo *nodo,Metrica *metrica) {
    Nodo *nuevo=new Nodo();
    nuevo->metrica=metrica;
    nuevo->siguiente=nullptr;

    if (nodo==nullptr) {
        nuevo->siguiente=this->listaDoblementeLigada;
        this->listaDoblementeLigada=nuevo;
    }else {
        nuevo->siguiente=nodo->siguiente;
        nodo->siguiente=nuevo;
    }
}
bool Lista::estaVacia() const {
    return listaDoblementeLigada==nullptr;
}