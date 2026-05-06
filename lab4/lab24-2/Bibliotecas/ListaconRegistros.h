//
// Created by ANTONIO on 3/05/2026.
//

#ifndef LAB24_2_LISTACONREGISTROS_H
#define LAB24_2_LISTACONREGISTROS_H
bool leeregistros(ifstream &arch,void *&registro);
bool leeordenes(ifstream &arch,void *&registro,void *&clave) ;
bool compruebaregistro(void *datoNodo,void *clave);
void imprimeregistros(ofstream &arch,void *datoNodo);
//aux
char *leerCadenaExacta(ifstream &arch,char delim);
#endif //LAB24_2_LISTACONREGISTROS_H
