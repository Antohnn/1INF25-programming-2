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
public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();
};


#endif //LAB25_1_MINISTERIODETRANSPORTE_H
