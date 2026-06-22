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
#include "Comentario.h"
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

    string get_codCategoria() const;
    void set_Categoria(const Categoria &categoria);
    void agregarEtiqueta(const Etiqueta &);
    void agregarComentario(const string &comentario);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //operador de asignacion
    Streamer& operator= (const Streamer &);
    bool operator< (const Streamer &) const;
    //destructor
    ~Streamer();
};
ifstream& operator>> (ifstream &, Streamer &);
ofstream& operator<< (ofstream &, Streamer &);


#endif //LAB25_2_STREAMER_H
