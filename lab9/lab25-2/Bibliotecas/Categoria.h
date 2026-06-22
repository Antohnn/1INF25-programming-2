//
// Created by ANTONIO on 21/06/2026.
//

#ifndef LAB25_2_CATEGORIA_H
#define LAB25_2_CATEGORIA_H
#include <string>

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Categoria {
    string codigo;
    string nombrea;
    string descripcion;
public:
    Categoria();
    Categoria(const Categoria &);
    //setters and getters
    string get_codigo() const;
    void set_codigo(const string &codigo);

    string get_nombrea() const;
    void set_nombrea(const string &nombrea);

    string get_descripcion() const;
    void set_descripcion(const string &descripcion);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //
    Categoria &operator=(const Categoria &);
    //destructor
    ~Categoria();
};
ifstream& operator>> (ifstream &, Categoria &);
ofstream& operator<< (ofstream &, Categoria &);


#endif //LAB25_2_CATEGORIA_H
