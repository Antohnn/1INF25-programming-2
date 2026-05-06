//
// Created by ANTONIO on 3/05/2026.
//
#include <iostream>
#include <fstream>

using namespace std;

#include "ListaConEnteros.h"
#include "enums.h"

bool leenumeros(ifstream &arch,void *&registro) {
    int num;

    arch>>num;
    if (arch.eof())return false;

    void **reg=new void*[cantDatosDupla];
    reg[duplaDato]=new int(num);
    reg[duplaArr]=nullptr;

    registro=reg;
    return true;
}
void imprimenumeros(ofstream &arch,void *dato) {
    void **datoAux=(void **)dato;
    int numero=*(int *)datoAux[duplaDato];
    void **reg=(void **)datoAux[duplaArr];

    arch<<numero<<endl;
    for (int i=0;reg[i];i++) {
        void **datoNum=(void **)reg[i];
        int numEror=*(int *)datoNum[0];

        arch<<numEror<<' ';
    }
    arch<<endl;
}
bool leeregnumeros(ifstream &arch,void *&registro,void *&clave) {
    int numero,arrNumero;

    arch>>numero;
    if (arch.eof())return false;
    arch>>arrNumero;

    void **reg=new void*[1];
    reg[0]=new int(arrNumero);

    clave=new int(numero);
    registro=reg;
    return true;
}
bool compruebanumero(void *datoNodo,void *clave) {
    void **dupla=(void **)datoNodo;

    int numero=*(int *)dupla[duplaDato];
    int numActual=*(int *)clave;

    return numero==numActual;
}