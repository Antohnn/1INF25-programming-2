//
// Created by ANTONIO on 6/05/2026.
//

#ifndef LAB24_2_2NDTIME_BIBLIOTECAGENERICA_H
#define LAB24_2_2NDTIME_BIBLIOTECAGENERICA_H

void creaLista(void *&lista,bool (*leeDatos)(ifstream &,void *&),const char *nombArch);
void cargaLista(void *lista,bool (*cmp)(void *,void *),bool (*leeDatos)(ifstream &,void *&,void *&),const char *nombArch);
void *buscarDupla(void *lista,void *clave,bool (*cmp)(void *,void *)) ;
void insertaEnDupla(void *dupla,void *dato) ;
void insertarExacto(void **&registros,void *dato);
void muestraLista(void *lista,void (*imprime)(ofstream &,void*),const char *nombArch);
//aux
void construirLista(void *&lista);
void *obtenerUltimo(void *lista);
void insertaSiguiente(void *lista,void *nodo,void *dato);
bool esListaVacia(void *lista);
//arch
void abrirIn(ifstream &arch,const char *nombArch) ;
void abrirOut(ofstream &archRep,const char *nombArch);
#endif //LAB24_2_2NDTIME_BIBLIOTECAGENERICA_H
