//
// Created by ANTONIO on 29/03/2026.
//

#ifndef LAB25_1_FUNCIONES_H
#define LAB25_1_FUNCIONES_H

#include "funciones.h"
#include "Estructuras.h"

void operator !(CadenaDeCaracteres &cad);
void operator<=(CadenaDeCaracteres &cad,int cantidad);
void operator<=(CadenaDeCaracteres &cad,const char *cadena);
void operator<=(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2);
bool operator+=(CadenaDeCaracteres &cad,const char *cadena);
bool operator+=(CadenaDeCaracteres &cad1,const CadenaDeCaracteres &cad2);
bool operator==(CadenaDeCaracteres &cad,const char *cadena) ;
bool operator==(CadenaDeCaracteres &cad1,const CadenaDeCaracteres &cad2);
bool operator<(CadenaDeCaracteres &cad,const char *cadena);
bool operator<(CadenaDeCaracteres &cad1,const CadenaDeCaracteres &cad2);
bool operator>(CadenaDeCaracteres &cad,const char *cadena);
bool operator>(CadenaDeCaracteres &cad1,const CadenaDeCaracteres &cad2);
bool operator>>(ifstream& archivo, CadenaDeCaracteres& cad);

#endif //LAB25_1_FUNCIONES_H
