//
// Created by ANTONIO on 14/05/2026.
//

#ifndef LAB25_1_MINISTERIODETRANSPORTE_H
#define LAB25_1_MINISTERIODETRANSPORTE_H


#include "Empresa.h"

class MinisterioDeTransporte {
    class Infraccion *infracciones;
    int numInf;
    class Empresa empresas[50];
    int numEmp;
    double buscarMultaEnInfra(int );
    int buscarEmpresaPorPlaca(char *);
    void imprimeHeader(ofstream &);
    void imprimirCaracter(ofstream &,int n,char car);
    void imprimirHeaderEmp(ofstream &);
public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();


    MinisterioDeTransporte& operator<(const char*);
    MinisterioDeTransporte& operator<=(const char*);
    MinisterioDeTransporte& operator<<=(const char*);
    MinisterioDeTransporte& operator>>(const char*);
};


#endif //LAB25_1_MINISTERIODETRANSPORTE_H
