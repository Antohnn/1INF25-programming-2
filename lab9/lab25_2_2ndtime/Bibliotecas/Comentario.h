//
// Created by ANTONIO on 26/06/2026.
//

#ifndef LAB25_2_2NDTIME_COMENTARIO_H
#define LAB25_2_2NDTIME_COMENTARIO_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Comentario {
    string canal;
    string descripcion;
public:
    Comentario();
    Comentario(const string &);
    //setters and getters

    string get_canal() const;

    void set_canal(const string &canal);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);

    //destructor
    ~Comentario();
};
ifstream& operator>> (ifstream &, Comentario &);
ofstream& operator<< (ofstream &, Comentario &);

#endif //LAB25_2_2NDTIME_COMENTARIO_H
