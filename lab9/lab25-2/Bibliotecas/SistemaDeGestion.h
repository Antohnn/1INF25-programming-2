//
// Created by anton on 22/06/2026.
//

#ifndef LAB25_2_SISTEMADEGESTION_H
#define LAB25_2_SISTEMADEGESTION_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include "Comentario.h"
#include "Categoria.h"
#include "Etiqueta.h"
#include "Streamer.h"

using namespace std;
class SistemaDeGestion {
    list<Categoria> categorias;
    list<Comentario> comentarios;
    map<string,Etiqueta> etiquetas;
    list<Streamer> streamers;

    void completarCategorias(Streamer &);
    void completarEtiquetas(Streamer &);
    void completarComentarios(Streamer &);
    void imprimirHeader(ofstream &);
public:
    void cargarCategorias(const char* );
    void cargaComentarios(const char* );
    void cargaEtiquetas(const char* );
    void cargaStreamers(const char* );
    void completarStreamers();
    void reporteDeStreamers(const char *);
};


#endif //LAB25_2_SISTEMADEGESTION_H
