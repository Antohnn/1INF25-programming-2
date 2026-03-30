//
// Created by ANTONIO on 29/03/2026.
//
#include <iostream>

using namespace std;

#include "funciones.h"
#include "Estructuras.h"

Cliente& operator++(Cliente &cliente, int) {
    cliente.edad++;
    return cliente;
}

Cliente& operator++(Cliente &cliente) {
    ++cliente.edad;
    return cliente;
}

Cliente& operator--(Cliente &cliente, int) {
    cliente.edad--;
    return cliente;
}

Cliente& operator--(Cliente &cliente) {
    --cliente.edad;
    return cliente;
}

Pedido operator+(Pedido &p1, Pedido &p2) {
    Pedido p3={p1.dni,p1.total+p2.total};
    return p3;
}

ostream& operator<<(ostream &os, Pedido &p) {
    os<<"Datos del pedido:"<<endl;
    os<<"DNI: "<<p.dni<<endl;
    os<<"TOTAL: "<<p.total<<endl;
    return os;
}

ostream& operator<<(ostream &os, Cliente &c) {
    os<<"Datos del cliente:"<<endl;
    os<<"DNI: "<<c.dni<<endl;
    os<<"EDAD: "<<c.edad<<endl;
    return os;
}