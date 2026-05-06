//
// Created by ANTONIO on 3/05/2026.
//

#ifndef LAB24_2_BIBLIOTECAGENERICA_H
#define LAB24_2_BIBLIOTECAGENERICA_H
void creaLista(void *&lista,bool (*leeDatos)(ifstream &,void*& ),const char *nombArch);
void muestralista(void *lista,void (*imp)(ofstream &,void *),const char* nombArch);
void cargarlista(void *lista,bool (*comprueba)(void *,void *),bool (*leeDatos)(ifstream &,void*&,void*&),const char *nombArch) ;
void *buscarDupla(bool (*comprueba)(void *,void *),void *lista,void *clave);
void insertarEnDupla(void *&dupla,void *&registro);
void añadirEspacioExacto(void **&regNum,void *registro);
//aux
void abrirIn(ifstream &arch,const char *nombArch);
void abrirOut(ofstream &archRep,const char *nombArch) ;
#endif //LAB24_2_BIBLIOTECAGENERICA_H
