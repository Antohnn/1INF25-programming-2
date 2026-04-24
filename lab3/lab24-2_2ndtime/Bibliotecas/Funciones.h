//
// Created by ANTONIO on 24/04/2026.
//

#ifndef LAB24_2_2NDTIME_FUNCIONES_H
#define LAB24_2_2NDTIME_FUNCIONES_H
void cargarInventario(const char *nombArch,void *&inventario);
bool leerInventario(ifstream &arch,void *&insumo);
//aux
void abrirIn(ifstream &arch,const char *nombArch);
void abrirOut(ofstream &arch,const char *nombArch);
char *leerCadena(ifstream &arch,char delim);
void aumentarRegistro(void **&regInventario,int num,int &capacidad);
#endif //LAB24_2_2NDTIME_FUNCIONES_H
