//
// Created by ANTONIO on 26/06/2026.
//

#ifndef LAB25_2_2NDTIME_STREAMER_H
#define LAB25_2_2NDTIME_STREAMER_H


#include "Categoria.h"
#include "Etiqueta.h"
#include <vector>

using coment=string;
class Streamer {
    string canal;
    int fecha;
    Categoria categoria;
    string etiquetasStr;
    vector<Etiqueta> etiquetasVector;
    string idioma;
    vector<coment> comentarios;
public:
    Streamer();
    Streamer(const Streamer &);
    //setters and getters

    string get_canal() const;
    void set_canal(const string &canal);

    int get_fecha() const;
    void set_fecha(int fecha);

    string get_etiquetas_str() const;
    void set_etiquetas_str(const string &etiquetas_str);

    string get_idioma() const;
    void set_idioma(const string &idioma);
    //
    ifstream& leer(ifstream &);

    //destructor
    ~Streamer();

};


#endif //LAB25_2_2NDTIME_STREAMER_H
