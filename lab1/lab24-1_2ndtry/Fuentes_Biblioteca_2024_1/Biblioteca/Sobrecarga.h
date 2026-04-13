//
// Created by ANTONIO on 9/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_1_SOBRECARGA_H
#define FUENTES_BIBLIOTECA_2024_1_SOBRECARGA_H
using namespace std;
//Lectura
bool operator>>(ifstream &archLibro,Libro &libro);
bool operator>>(ifstream &archCliente,Cliente &cliente);
//Operaciones
bool operator>>(LibroSolicitado &libroSol,Libro *arrLibros) ;
bool operator<<(LibroSolicitado &libroSol,Cliente &cliente);

void operator ++(Cliente &cliente);
void operator<<(ofstream &archRepLibro,Libro &libro) ;
void operator<<(ofstream &archRepCliente,Cliente &cliente);

//aux
void abrirIn(ifstream &archEntrada,const char *nombArch) ;
void abrirOut(ofstream &archReporte,const char *nombArch) ;
#endif //FUENTES_BIBLIOTECA_2024_1_SOBRECARGA_H
