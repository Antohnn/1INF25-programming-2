//
// Created by anton on 11/05/2026.
//
#include <cstring>
#include <iostream>

using namespace std;

#include "Streamer.h"

Streamer::Streamer() {
    this->cuenta=nullptr;
    this->tiempo_total=0;
    this->promedio_espectadores=0;
    this->n_seguidores=0;
    this->categoria=nullptr;
}
//constructor de copia
Streamer::Streamer(const Streamer &origin):Streamer(){
    *this=origin;
}
Streamer& Streamer::operator=(const Streamer &origin) {
    if (this != &origin) {
        this->setCuenta(origin.getCuenta());
        this->setTiempoTotal(origin.getTiempoTotal());
        this->setPromedio(origin.getPromedio());
        this->setNSeguidores(origin.getNSeguidores());
        this->setCategoria(origin.getCategoria());
    }
    return *this;
}

void Streamer::setCuenta(char *cuenta) {
    delete[] this->cuenta;
    this->cuenta=new char[strlen(cuenta)+1];
    strcpy(this->cuenta,cuenta);
}
char * Streamer::getCuenta() const {
    return cuenta;
}
void Streamer::setTiempoTotal(long long tiempo_total) {
    this->tiempo_total=tiempo_total;
}
long long Streamer::getTiempoTotal() const {
    return tiempo_total;
}
void Streamer::setPromedio(double promedio) {
    this->promedio_espectadores=promedio;
}
double Streamer::getPromedio() const {
    return promedio_espectadores;
}
void Streamer::setNSeguidores(int n_seguidores) {
    this->n_seguidores=n_seguidores;
}
int Streamer::getNSeguidores() const {
    return n_seguidores;
}
void Streamer::setCategoria(char *categoria) {
    delete[] this->categoria;
    this->categoria=new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}
char *Streamer::getCategoria() const {
    return categoria;
}