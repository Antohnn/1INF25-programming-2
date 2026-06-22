//
// Created by ANTONIO on 21/06/2026.
//

#ifndef LAB25_2_ETIQUETA_H
#define LAB25_2_ETIQUETA_H
#include <string>

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Etiqueta {
    string codigo;
    string nombre;
public:
    Etiqueta();
    Etiqueta(const Etiqueta &);
    //setters and getters
    string get_codigo() const;
    void set_codigo(const string &codigo);

    string get_nombre() const;
    void set_nombre(const string &nombre);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //
    Etiqueta &operator=(const Etiqueta &);
    //destructor
    ~Etiqueta();
};
ifstream& operator>>(ifstream &, Etiqueta &);
ofstream& operator<<(ofstream &, Etiqueta &);


#endif //LAB25_2_ETIQUETA_H
