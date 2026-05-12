//
// Created by ANTONIO on 11/05/2026.
//
#include <iostream>
#include <fstream>

#include "Cliente.h"
#include "Plato.h"

using namespace std;

#include "Restaurante.h"

Restaurante::Restaurante() {
    clientes=nullptr;
    cantidadClientes=0;
    capacidadClientes=0;
    plato=nullptr;
    cantidadPlatos=0;
    capacidadPlatos=0;
}
Restaurante::~Restaurante() {
    delete[] clientes;
    delete[] plato;
}
