//
// Created by ANTONIO on 15/05/2026.
//

#ifndef LAB24_2_2ND_TIME_CLIENTE_H
#define LAB24_2_2ND_TIME_CLIENTE_H


class Cliente {
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
public:
    Cliente();
    Cliente(const Cliente &);
    ~Cliente();

    int get_dni() const;
    void set_dni(int dni);

    void get_nombre(char *nomb)const ;
    void set_nombre(char *nombre);

    void get_distrito(char *dist) const;
    void set_distrito(char *distrito);

    double get_descuento() const;
    void set_descuento(double descuento);

    double get_total_pagado() const;
    void set_total_pagado(double total_pagado);

    //asignacion
    Cliente &operator=(const Cliente &);
};


#endif //LAB24_2_2ND_TIME_CLIENTE_H
