//
// Created by ANTONIO on 25/06/2026.
//

#ifndef LAB25_1_VEHICULO_H
#define LAB25_1_VEHICULO_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Vehiculo {
    string placa;
    string marca;
    string modelo;
public:
    Vehiculo();
    Vehiculo(const Vehiculo &);
    //setters and getters

    string get_placa() const;
    void set_placa(const string &placa);

    string get_marca() const;
    void set_marca(const string &marca);

    string get_modelo() const;
    void set_modelo(const string &modelo);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &) const;
    //
    Vehiculo& operator= (const Vehiculo &);
    //destructor
    ~Vehiculo();
};
ifstream& operator>> (ifstream &, Vehiculo &);
ofstream& operator<< (ofstream &, const Vehiculo &);


#endif //LAB25_1_VEHICULO_H
