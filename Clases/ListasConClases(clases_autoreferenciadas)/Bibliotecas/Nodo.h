//
// Created by ANTONIO on 8/06/2026.
//

#ifndef LISTASCONCLASES_CLASES_AUTOREFERENCIADAS__NODO_H
#define LISTASCONCLASES_CLASES_AUTOREFERENCIADAS__NODO_H


class Nodo {
    int dato;
    Nodo *siguiente;
public:
    Nodo();

    int get_dato() const;
    void set_dato(int dato);

    Nodo * get_siguiente() const;
    void set_siguiente(Nodo *siguiente);

    friend class Lista;
};


#endif //LISTASCONCLASES_CLASES_AUTOREFERENCIADAS__NODO_H
