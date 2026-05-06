//
// Created by ANTONIO on 3/05/2026.
//

#ifndef LAB24_2_LISTA_H
#define LAB24_2_LISTA_H

void construirLista(void *&lista);
bool esListaVacia(const void *lista);
void *ultimo(void *lista);
void insertarSiguiente(void *lista,void *nodo,void *dato);

#endif //LAB24_2_LISTA_H
