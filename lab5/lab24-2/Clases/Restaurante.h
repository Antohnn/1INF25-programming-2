//
// Created by ANTONIO on 11/05/2026.
//

#ifndef LAB24_2_RESTAURANTE_H
#define LAB24_2_RESTAURANTE_H


class Restaurante {
    class Cliente *clientes;
    int cantidadClientes;
    int capacidadClientes;
    class Plato *plato;
    int cantidadPlatos;
    int capacidadPlatos;
    public:
    Restaurante();
    ~Restaurante();
};


#endif //LAB24_2_RESTAURANTE_H
