//
// Created by ANTONIO on 3/05/2026.
//

#ifndef LAB24_2_LISTACONENTEROS_H
#define LAB24_2_LISTACONENTEROS_H
bool leenumeros(ifstream &arch,void *&registro) ;
void imprimenumeros(ofstream &arch,void *dato) ;
bool leeregnumeros(ifstream &arch,void *&registro,void *&clave) ;
bool compruebanumero(void *datoNodo,void *clave) ;
#endif //LAB24_2_LISTACONENTEROS_H
