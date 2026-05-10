//
// Created by ANTONIO on 10/05/2026.
//

#ifndef PRACTICAPOO_RECTANGULO_H
#define PRACTICAPOO_RECTANGULO_H


class Rectangulo {
    double base;
    double altura;
    char *nombre;
public:
    //constructor
    Rectangulo();

    //setters
    void setBase(double b);
    void setAltura(double h);
    void setNombre(char *n);

    //getters
    double getBase() const;
    double getAltura() const;
    char *getNombre() const;

    //otros metodos
    double calcularArea() const;
    double calcularPerimetro() const;

     ~Rectangulo();
};


#endif //PRACTICAPOO_RECTANGULO_H
