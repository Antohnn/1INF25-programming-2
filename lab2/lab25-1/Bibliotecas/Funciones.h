//
// Created by ANTONIO on 16/04/2026.
//

#ifndef LAB25_1_FUNCIONES_H
#define LAB25_1_FUNCIONES_H
#include "conductores.h"
#include "infracciones.h"
#include "faltas.h"
//sobrecarga
void operator+=(Conductores &conductores,const char *nombArch);
bool leerConductores(ifstream &archivo,int &dni,char *&nombre);
//cargar Infracciones
void operator +=(Infracciones &infracciones,const char *nombArch);
bool leerInfraccion(ifstream &archivo,int &codInfra,char *&descripcion,char *&tipo,double &valor);
//cargarFaltas
void cargar_faltas_de_los_conductores(const char *nombArch,Faltas &faltas);
bool leerFalta(ifstream &archivo,int &dni,int &codInf,char *&placa) ;
int buscarConductor(Conductores &conductores,int dni);
bool placaRepetida(char **bloque,char *placa) ;
void insertarPlaca(char **&bloque,int &capacidad,char *placa) ;
int contarPlacas(char **bloque) ;
void incrementarBloque(char **&bloque,int &capacidad,int usados);
//aux
char* leerCadenaExacta(ifstream &archivo,char delim);
#endif //LAB25_1_FUNCIONES_H
