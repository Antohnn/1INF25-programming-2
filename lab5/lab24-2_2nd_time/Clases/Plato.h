//
// Created by ANTONIO on 15/05/2026.
//

#ifndef LAB24_2_2ND_TIME_PLATO_H
#define LAB24_2_2ND_TIME_PLATO_H
#include "Cliente.h"


class Plato {
    char *codigo;
    char *nombre;
    double precio;
    char *categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtendidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;
public:
    Plato();
    Plato(const Plato &);
    ~Plato();

    void get_codigo(char *code) const;
    void set_codigo(char *codigo);

    void get_nombre(char *nomb) const;
    void set_nombre(char *nombre);

    double get_precio() const;
    void set_precio(double precio);

    void get_categoria(char *cate) const;
    void set_categoria(char *categoria);

    int get_preparados() const;
    void set_preparados(int preparados);

    double get_descuento() const;
    void set_descuento(double descuento);

    int get_atendidos() const;
    void set_atendidos(int atendidos);

    int get_no_atendidos() const;
    void set_no_atendidos(int no_atendidos);

    double get_total_esperado() const;
    void set_total_esperado(double total_esperado);

    double get_total_bruto() const;
    void set_total_bruto(double total_bruto);

    double get_total_neto() const;
    void set_total_neto(double total_neto);

    //asignacion
    Plato &operator=(const Plato &);
};


#endif //LAB24_2_2ND_TIME_PLATO_H
