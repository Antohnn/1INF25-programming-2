//
// Created by ANTONIO on 19/06/2026.
//

#ifndef LAB25_2_2NDTIME_ADMINISTRARMETRICAS_H
#define LAB25_2_2NDTIME_ADMINISTRARMETRICAS_H
#include "Lista/Lista.h"


class AdministrarMetricas {
    Lista listaDeMetricas;
public:
    void cargarArchivo(const char *);
    void generarReporte(const char *);
    void eliminarNodos();
};


#endif //LAB25_2_2NDTIME_ADMINISTRARMETRICAS_H
