//
// Created by ANTONIO on 1/04/2026.
//

#ifndef LAB25_1_2ND_TRY_FUNCIONES_H
#define LAB25_1_2ND_TRY_FUNCIONES_H
//incializcion
void operator!(CadenaDeCaracteres &cad) ;
//Asignacion
void operator<=(CadenaDeCaracteres &cad,const char* cadena);
void operator<=(CadenaDeCaracteres &cad,int espacios);
void operator<=(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2);
//concatenacion
bool operator+=(CadenaDeCaracteres &cad,const char* cadena) ;
bool operator+=(CadenaDeCaracteres &cad,CadenaDeCaracteres &cad2) ;
//comparar

bool operator==(CadenaDeCaracteres &cad1,const char* cadena);
bool operator==(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2);
bool operator<(CadenaDeCaracteres &cad1,const char* cadena);
bool operator<(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2);
bool operator>(CadenaDeCaracteres &cad1,const char* cadena);
bool operator>(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2);
bool operator >>(istream &is,CadenaDeCaracteres &cad);
void operator &&(CadenaDeCaracteres &cad1,CadenaDeCaracteres &cad2);
ostream &operator<<(ostream &os,CadenaDeCaracteres &cad);

#endif //LAB25_1_2ND_TRY_FUNCIONES_H
