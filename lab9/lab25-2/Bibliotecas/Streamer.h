//
// Created by ANTONIO on 22/06/2026.
//

#ifndef LAB25_2_STREAMER_H
#define LAB25_2_STREAMER_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "Categoria.h"
#include "Etiqueta.h"
using namespace std;
using coment=string;

class Streamer {
    string canal;
    int fecha;
    Categoria categoria;
    string etiquetasStr;
    vector<Etiqueta> etiquetasVector;
    string idioma;
    vector<coment> comentarios;

    Categoria& buscarCategoria(string &codCateStreamer);
public:
    Streamer();
    Streamer(const Streamer &);
    //
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
    ofstream& imprimir(ofstream &);

    //destructor
    ~Streamer();
};


#endif //LAB25_2_STREAMER_H
