//
// Created by ANTONIO on 21/06/2026.
//

#ifndef LAB25_2_COMENTARIO_H
#define LAB25_2_COMENTARIO_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Comentario {
    string canal;
    string comentario;
public:
    Comentario();
    Comentario(const string &);
    //setters and getters
    string get_canal() const;
    void set_canal(const string &canal);

    string get_comentario() const;
    void set_comentario(const string &comentario);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //
    Comentario& operator =(const Comentario &);
    bool operator<(Comentario & ) const;
    //destructor
    ~Comentario();
};
ifstream& operator>> (ifstream &, Comentario &);
ofstream& operator<< (ofstream &, Comentario &);


#endif //LAB25_2_COMENTARIO_H
