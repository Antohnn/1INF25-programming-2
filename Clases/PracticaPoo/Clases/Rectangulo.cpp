//
// Created by ANTONIO on 10/05/2026.
//
#include <cstring>
#include <iostream>

using namespace std;

#include "Rectangulo.h"

Rectangulo::Rectangulo() {
    base=0;
    altura=0;
    nombre=nullptr;
}

void Rectangulo::setBase(double b) {
    base=b;
}
void Rectangulo::setAltura(double a) {
    altura=a;
}

void Rectangulo::setNombre(char *n) {
    nombre=new char[strlen(n)+1];
    strcpy(nombre,n);
}

double Rectangulo::getBase() const {
    return base;
}

double Rectangulo::getAltura() const {
    return altura;
}
char *Rectangulo::getNombre() const {
    return nombre;
}

double Rectangulo::calcularArea() const {
    return (base*altura);
}

double Rectangulo::calcularPerimetro() const {
    return (2*(base+altura));
}

Rectangulo::~Rectangulo() {
    delete [] nombre;
}