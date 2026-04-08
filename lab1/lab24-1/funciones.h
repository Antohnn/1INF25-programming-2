//
// Created by anton on 6/04/2026.
//

#ifndef LAB24_1_FUNCIONES_H
#define LAB24_1_FUNCIONES_H
#include <iostream>
#include "Estructuras.h"

using namespace std;

void abrirArch(ifstream & archEntrada, const char * str);
//Lectura

bool operator>>(ifstream &archLibro,Libro &libro);
bool operator>>(ifstream &archCliente,Cliente &cliente);
//operaciones
bool operator>>(LibroSolicitado libroPedido,Libro *arrLibros) ;
bool operator<<(LibroSolicitado &libroPedido,Cliente &cliente);
void operator++(Cliente &cliente);

void operator<<(ofstream &archRepLibro,Libro &libro);
void operator<<(ofstream &archRepCliente,Cliente &cliente) ;

#endif //LAB24_1_FUNCIONES_H
