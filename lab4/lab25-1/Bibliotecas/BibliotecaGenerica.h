//
// Created by ANTONIO on 5/05/2026.
//

#ifndef LAB25_1_BIBLIOTECAGENERICA_H
#define LAB25_1_BIBLIOTECAGENERICA_H

void generaLista(void *&lista);
void creaLista(void *&lista,bool (*leeDatos)(ifstream &,void *&),int (* cmp)(void *,void *),void *(*busca)(void *,void *),
    const char *nombArch);
void insertaLista(void *listaDestino,void *dato,int (*cmp)(void *,void *));
void imprimeLista(void *lista,void (*imprimeconductores)(ofstream &,void *),const char *nombArch);
//aux
void abrirIn(ifstream &arch,const char *nombArch);
void abrirOut(ofstream &archRep,const char *nombArch) ;
bool esListaVacia(void *lista);
void insertarSiguiente(void *&lista,void *&nodo,void *dato) ;

#endif //LAB25_1_BIBLIOTECAGENERICA_H
