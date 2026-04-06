//
// Created by ANTONIO on 1/04/2026.
//
#include <cstring>
#include <iostream>

#include "Estructuras.h"

using namespace std;

#include "funciones.h"

void operator!(CadenaDeCaracteres &cad) {
    cad.cadena=nullptr;
    cad.longitud=0;
    cad.capacidad=0;
}
void operator<=(CadenaDeCaracteres &cad,const char* cadena) {
    cad<=strlen(cadena)+1;
    strcpy(cad.cadena,cadena);
}
void operator<=(CadenaDeCaracteres &cad,int espacios) {
    !cad;
    cad.cadena=new char [espacios];
}
void operator<=(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2) {
    cad1<=cad2.cadena;
}
//concatenacion
bool operator+=(CadenaDeCaracteres &cad,const char* cadena) {
    if (!cad.cadena) {
        return false;
    }
    strcat(cad.cadena,cadena);
    return true;
}
bool operator+=(CadenaDeCaracteres &cad,CadenaDeCaracteres &cad2) {
    return cad+=cad2.cadena;
}
//comparar

bool operator==(CadenaDeCaracteres &cad1,const char* cadena) {
    return strcmp(cad1.cadena,cadena)==0;
}
bool operator==(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2) {
    return cad1==cad2.cadena;
}

bool operator<(CadenaDeCaracteres &cad1,const char* cadena) {
    return strcmp(cad1.cadena,cadena)<0;
}
bool operator<(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2) {
    return cad1<cad2.cadena;
}
bool operator>(CadenaDeCaracteres &cad1,const char* cadena) {
    return strcmp(cad1.cadena,cadena)>0;
}
bool operator>(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2) {
    return cad1>cad2.cadena;
}

//lectura
bool operator >>(istream &is,CadenaDeCaracteres &cad) {
    is.getline(cad.cadena,cad.capacidad);
    return true;
}
void operator &&(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2) {
    CadenaDeCaracteres temp{};

    temp<=cad1;
    cad1<=cad2;
    cad2<=temp;
}
ostream &operator<<(ostream &os,CadenaDeCaracteres &cad) {
    os<<cad.cadena<<endl;
    return os;
}
