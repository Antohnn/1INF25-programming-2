//
// Created by ANTONIO on 29/03/2026.
//

#ifndef LAB25_2_ESTRUCTURAS_H
#define LAB25_2_ESTRUCTURAS_H
using namespace std;

struct Cliente {
    int dni;
    char *nombre;
    int telefono;
};

struct Producto {
    int codigo;
    char *descripcion;
    double precio;
    int stock;
};

struct Pedido {
    char *codProd;
    int dni;
};
#endif //LAB25_2_ESTRUCTURAS_H
