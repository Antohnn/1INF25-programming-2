//
// Created by ANTONIO on 16/04/2026.
//

#ifndef LAB25_1_FALTAS_H
#define LAB25_1_FALTAS_H
#include "conductores.h"
#include "infracciones.h"

struct Faltas {
    Conductores conductores;
    Infracciones infracciones;

    char ***placas;
    int *capacidades;
};
#endif //LAB25_1_FALTAS_H
