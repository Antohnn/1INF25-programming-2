//
// Created by ANTONIO on 11/05/2026.
//

#ifndef LAB24_2_RESTAURANTE_H
#define LAB24_2_RESTAURANTE_H


class Restaurante {
    class Cliente *clientes;
    int cantidadClientes;
    int capacidadClientes;
    class Plato *platos;
    int cantidadPlatos;
    int capacidadPlatos;

    void incrementarClientes();
    void incrementarPlatos();

    void leerPedidos(ifstream &,int ,int );
    int buscarClientePorDni(int ) const ;
    int buscarPlatoPorCod(char *)const ;
    void actualizarDatos(int ,int ,int);
    void imprimirHeaderPlatos(ofstream &);
    void imprimirCaracter(ofstream &,int ,char );
    void imprimirHeaderCliente(ofstream &);

    public:
    Restaurante();
    Restaurante& operator<(const char*);
    Restaurante& operator<=(const char*);
    Restaurante& operator<<=(const char*);
    Restaurante& operator>>(const char *);

    ~Restaurante();
};


//aux
void abrirIn(ifstream &arch,const char *nombArch);
void abrirOut(ofstream &arch,const char *nombArch);

#endif //LAB24_2_RESTAURANTE_H
