//
// Created by ANTONIO on 18/06/2026.
//

#include <iostream>
using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    metrica=nullptr;
    anterior=nullptr;
    siguiente=nullptr;
}
Nodo::~Nodo() {
    delete  metrica;
}