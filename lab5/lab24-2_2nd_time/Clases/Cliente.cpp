//
// Created by ANTONIO on 15/05/2026.
//
#include <cstring>
#include <iostream>

using namespace std;

#include "Cliente.h"

Cliente::Cliente() {
    dni=0;
    nombre=nullptr;
    distrito=nullptr;
    descuento=0;
    totalPagado=0;
}
Cliente::Cliente(const Cliente &origin):Cliente() {
    *this = origin;
}
Cliente::~Cliente() {
    delete[] nombre;
    delete[] distrito;
}

int Cliente::get_dni() const {
    return dni;
}
void Cliente::set_dni(int dni) {
    this->dni = dni;
}

void Cliente::get_nombre(char *nomb) const{
    if (nombre==nullptr) nomb[0]=0;
    strcpy(nomb,nombre);
}
void Cliente::set_nombre(char *nombre) {
    delete[] this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Cliente::get_distrito(char *dist) const {
    if (distrito==nullptr) dist[0]=0;
    strcpy(dist,distrito);
}
void Cliente::set_distrito(char *distrito) {
    delete[] this->distrito;
    this->distrito = new char[strlen(distrito)+1];
    strcpy(this->distrito,distrito);
}

double Cliente::get_descuento() const {
    return descuento;
}
void Cliente::set_descuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::get_total_pagado() const {
    return totalPagado;
}
void Cliente::set_total_pagado(double total_pagado) {
    totalPagado = total_pagado;
}

//asignacion
Cliente &Cliente::operator=(const Cliente &origin) {
    if (this!=&origin) {
        set_dni(origin.dni);
        set_nombre(origin.nombre);
        set_distrito(origin.distrito);
        set_descuento(origin.descuento);
        set_total_pagado(origin.totalPagado);
    }
    return *this;
}
