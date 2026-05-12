//
// Created by ANTONIO on 11/05/2026.
//

#ifndef LAB24_2_CLIENTE_H
#define LAB24_2_CLIENTE_H

#include <fstream>
using namespace std;
class Cliente {
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
    public:
    //constructor de inicializacion y constructor de copia
    Cliente();
    Cliente(const Cliente &);

    //setters and getters
    void setDni(int dni);
    int getDni() const;
    void setNombre(char *nombre);
    char *getNombre() const;
    void setDistrito(char *nombre);
    char *getDistrito() const;
    void setDescuento(double descuento);
    double getDescuento() const;
    void setTotalPagado(double totalPagado);
    double getTotalPagado() const;

    //sobrecarga del operador para la asignacion
    Cliente& operator=(const Cliente &);
    //destructor de clase
    ~Cliente();
};

ifstream& operator>> (ifstream &, Cliente &);


#endif //LAB24_2_CLIENTE_H
