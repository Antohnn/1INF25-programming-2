//
// Created by anton on 26/06/2026.
//

#ifndef LAB25_2_2NDTIME_SISTEMADEGESTION_H
#define LAB25_2_2NDTIME_SISTEMADEGESTION_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <map>
#include <string>

#include "Categoria.h"
#include "Comentario.h"
#include "Etiqueta.h"
#include "Streamer.h"
using namespace std;

class SistemaDeGestion {
    list<Categoria> categorias;
    list<Comentario> comentarios;
    map<string,Etiqueta> etiquetas;
    list<Streamer> streamers;

    void completarCategoria(Streamer &);
    void completarComentarios(Streamer &);
    void completarEtiquetas(Streamer &);
public:
    void cargarCategorias(const char* );
    void cargaComentarios(const char* );
    void cargaEtiquetas(const char* );
    void cargaStreamers(const char* );
    void completarStreamers();
    void reporteDeStreamers(const char* );
    void eliminarStreamers(const string &);
};


#endif //LAB25_2_2NDTIME_SISTEMADEGESTION_H
