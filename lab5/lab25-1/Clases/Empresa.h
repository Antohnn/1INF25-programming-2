//
// Created by ANTONIO on 14/05/2026.
//

#ifndef LAB25_1_EMPRESA_H
#define LAB25_1_EMPRESA_H

#include "Multa.h"

class Empresa {
    int dni;
    char *nombre;
    char *placas[10];
    int numPlacas;
    class Multa multas[100];
    int numMultas;

public:
    Empresa();
    ~Empresa();

    int get_dni() const;
    void set_dni(int dni);
    void get_nombre(char *nomb) const;
    void set_nombre(char *nombre);
    int get_num_placas() const;
    void set_num_placas(int num_placas);
    int get_num_multas() const;
    void set_num_multas(int num_multas);

    void setPlacaI(const char *,int i);
    void getPlacaI(char *,int i)const;
};

ifstream &operator>>(ifstream &,Empresa &);


#endif //LAB25_1_EMPRESA_H
