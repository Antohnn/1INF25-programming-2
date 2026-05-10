//
// Created by ANTONIO on 7/05/2026.
//

#ifndef LAB23_2_FLOTAGENERICA_H
#define LAB23_2_FLOTAGENERICA_H
void cargacamiones(void *&flota,int numcamiones,double pesomaximo,
    bool (*lee)(ifstream &,void *&),double (*calcula)(void *),const char *nombArch);
void construyeFlota(void *&flota,int numcamiones);
void construyePila(void *&flota);
void push(void *&flota,void *&dato,double pesoDato) ;
double obtenerPeso(void *auxFlota) ;
void aumentoPeso(void *flota,double pesoDato) ;
//aux
void abrirIn(ifstream &arch,const char *nombArch);
void abrirOut(ofstream &archRep,const char *nombArch);
void construyeLista(void *&flota);
void *buscaUltimoNodo(void *flota);
void insertarSiguiente(void *flota,void *nodo,void *dato) ;
bool esListaVacia(void *flota);
#endif //LAB23_2_FLOTAGENERICA_H
