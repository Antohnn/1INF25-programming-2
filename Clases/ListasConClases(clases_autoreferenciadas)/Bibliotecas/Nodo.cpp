//
// Created by ANTONIO on 8/06/2026.
//

#include <iostream>
using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    dato=0;
    siguiente=nullptr;
}
//setters and getters
int Nodo::get_dato() const {
    return dato;
}
void Nodo::set_dato(int dato) {
    this->dato = dato;
}

Nodo * Nodo::get_siguiente() const {
    return siguiente;
}
void Nodo::set_siguiente(Nodo *siguiente) {
    this->siguiente = siguiente;
}
