//
// Created by ANTONIO on 11/05/2026.
//
#include <chrono>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

#include "Funciones.h"

char *leerCadenaExacta(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
