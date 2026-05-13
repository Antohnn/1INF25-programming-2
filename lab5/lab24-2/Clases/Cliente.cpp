//
// Created by ANTONIO on 11/05/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Cliente.h"
#include "Funciones.h"
#include "Restaurante.h"


Cliente::Cliente() {
    dni=0;
    nombre=nullptr;
    distrito=nullptr;
    descuento=0;
    totalPagado=0;
}
Cliente::Cliente(const Cliente &origin):Cliente() {
    *this=origin;
}
void Cliente::setDni(int dni) {
    this->dni=dni;
}
int Cliente::getDni() const {
    return dni;
}
void Cliente::setNombre(char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}
char *Cliente::getNombre() const {
    return nombre;
}
void Cliente::setDistrito(char *distrito) {
    delete[] this->distrito;
    this->distrito=new char[strlen(distrito)+1];
    strcpy(this->distrito,distrito);
}
char *Cliente::getDistrito() const {
    return distrito;
}
void Cliente::setDescuento(double descuento) {
    this->descuento=descuento;
}
double Cliente::getDescuento() const {
    return descuento;
}
void Cliente::setTotalPagado(double totalPagado) {
    this->totalPagado=totalPagado;
}
double Cliente::getTotalPagado() const {
    return totalPagado;
}

Cliente& Cliente::operator=(const Cliente &origin) {
    if (this!=&origin) {
        this->setDni(origin.getDni());
        this->setNombre(origin.getNombre());
        this->setDistrito(origin.getDistrito());
        this->setDescuento(origin.getDescuento());
        this->setTotalPagado(origin.getTotalPagado());
    }
    return *this;
}
Cliente::~Cliente() {
    delete[] nombre;
    delete[] distrito;
}
void Cliente::agregarMonto(double monto) {
    totalPagado+=monto;
}
ifstream& operator>> (ifstream &arch, Cliente &cliente) {
    int dni;
    char *nombre,*distrito,hayDescuento,c;
    double descuento;

    arch>>dni;
    if (arch.eof())return arch;
    arch.get();
    nombre=leerCadenaExacta(arch,',');
    distrito=leerCadenaExacta(arch,',');
    arch>>hayDescuento;
    if (hayDescuento=='S') {
        arch>>c>>descuento>>c;
    }else descuento=0;

    cliente.setDni(dni);
    cliente.setNombre(nombre);
    cliente.setDistrito(distrito);
    cliente.setDescuento(descuento);
    cliente.setTotalPagado(0);

    delete[] nombre;
    delete[] distrito;

    return arch;
}
ofstream &operator<<(ofstream &arch, Cliente &cliente) {
    arch<<setprecision(2)<<fixed;
    arch<<cliente.getDni()<<left<<setw(60)<<cliente.getNombre()<<setw(40)<<cliente.getDistrito()<<
        right<<setw(20)<<cliente.getDescuento()<<'%'<<cliente.getTotalPagado()<<endl;
    return arch;
}

