//
// Created by ANTONIO on 29/03/2026.
//

#ifndef SOBRECARGADEOPERADORES_FUNCIONES_H
#define SOBRECARGADEOPERADORES_FUNCIONES_H
#include <iostream>
#include "Estructuras.h"
#include "funciones.h"

using namespace std;


Cliente& operator++(Cliente &, int);
Cliente& operator++(Cliente &) ;
Cliente& operator--(Cliente &, int);
Cliente& operator--(Cliente &);
Pedido operator+(Pedido &,Pedido &);
ostream& operator<<(ostream &, Pedido &) ;
ostream& operator<<(ostream &, Cliente &);

#endif //SOBRECARGADEOPERADORES_FUNCIONES_H