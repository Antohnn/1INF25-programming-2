//
// Created by ANTONIO on 29/03/2026.
//
#include <cstring>
#include <string>


using namespace std;

#include "funciones.h"
#include "Estructuras.h"

void operator !(CadenaDeCaracteres &cad) {
    cad.cadena=nullptr;
    cad.longitud=0;
    cad.capacidad=0;
}

void operator<=(CadenaDeCaracteres &cad,int cantidad) {
    !cad;
    cad.cadena=new char[cantidad];
}

void operator<=(CadenaDeCaracteres &cad,const char *cadena) {
    cad<=strlen(cadena)+1;
    strcpy(cad.cadena,cadena);
}
