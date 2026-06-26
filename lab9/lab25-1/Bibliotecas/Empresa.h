//
// Created by ANTONIO on 25/06/2026.
//

#ifndef LAB25_1_EMPRESA_H
#define LAB25_1_EMPRESA_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>

#include "Vehiculo.h"
#include "Multa.h"
using namespace std;

class Empresa {
    int dni;
    string nombre;
    string distrito;
    map<string,Vehiculo> vehiculos;
    vector<Multa> multasRecibidas;


public:
    Empresa();
    Empresa(const Empresa &);
    //setters and getters
    int get_dni() const;
    void set_dni(int dni);

    string get_nombre() const;
    void set_nombre(const string &nombre);

    string get_distrito() const;
    void set_distrito(const string &distrito);

    void agregarVehiculo(Vehiculo &);
    void agregarMulta(Multa &);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //
    bool operator<(const Empresa &);
    bool tieneVehiculo(const string &);
    void ordenarMultas();
    void eliminaInfraccionesPagadas();
    //destructor
    ~Empresa();
};
ifstream& operator>>(ifstream &, Empresa &);
ofstream& operator<<(ofstream &, Empresa &);


#endif //LAB25_1_EMPRESA_H
