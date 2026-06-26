//
// Created by ANTONIO on 24/06/2026.
//

#ifndef LAB25_1_INFRACCION_H
#define LAB25_1_INFRACCION_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Infraccion {
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
public:
    Infraccion();
    Infraccion(const Infraccion &);
    //setters and getters
    string get_codigo() const;
    void set_codigo(const string &codigo);

    double get_multa() const;
    void set_multa(double multa);

    string get_gravedad() const;
    void set_gravedad(const string &gravedad);

    string get_descripcion() const;
    void set_descripcion(const string &descripcion);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &) const;
    //
    Infraccion& operator=(const Infraccion &);
    //destructor
    ~Infraccion();

    bool operator<(const Infraccion &) const;
};
ifstream& operator>> (ifstream &, Infraccion &);
ofstream& operator<< (ofstream &, const Infraccion &);


#endif //LAB25_1_INFRACCION_H
