//
// Created by ANTONIO on 7/05/2026.
//
#include <iostream>
#include <fstream>

using namespace std;

#include "PilaConEnteros.h"
#include "enums.h"

bool leenumero(ifstream &arch,void *&dato) {
    int numero;
    arch>>numero;
    if (arch.eof())return false;

    void **reg=new void *[1];
    reg[0]=new int(numero);

    dato=reg;
    return true;
}
double calculanumero(void *dato) {
    void **numDato=(void **)dato;

    double pesoDato=*(double *)numDato[0];
    return pesoDato;
}
int cmpnumero(const void *a,const void *b) {
    const void **ptrPilaA=(const void **)a;
    const void **ptrPilaB=(const void **)b;

    const void **auxPilaA=(const void **)*ptrPilaA;
    const void **auxPilaB=(const void **)*ptrPilaB;

    const double pesoA = *(const double *)auxPilaA[PESO];
    const double pesoB = *(const double *)auxPilaB[PESO];

    if (pesoA>pesoB) return 1;
    if (pesoB>pesoA) return -1;
    return 0;
}
