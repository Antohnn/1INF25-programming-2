//
// Created by ANTONIO on 25/06/2026.
//

#ifndef LAB25_1_MULTA_H
#define LAB25_1_MULTA_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Multa {
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagado;
    int fechaDePago;
public:
    Multa();
    Multa(const Multa &);
    //setters and getters

    int get_fecha() const;
    void set_fecha(int fecha);

    string get_placa() const;
    void set_placa(const string &placa);

    string get_cod_multa() const;
    void set_cod_multa(const string &cod_multa);

    double get_multa() const;
    void set_multa(double multa);

    bool is_pagado() const;
    void set_pagado(bool pagado);

    int get_fecha_de_pago() const;
    void set_fecha_de_pago(int fecha_de_pago);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &) const;
    //
    Multa& operator=(const Multa &);
    bool operator<(const Multa &) const;

    //destructor
    ~Multa();
};
ifstream& operator>> (ifstream &, Multa &);
ofstream& operator<< (ofstream &, Multa &);


#endif //LAB25_1_MULTA_H
