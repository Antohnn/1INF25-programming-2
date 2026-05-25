//
// Created by ANTONIO on 11/05/2026.
//

#ifndef LAB24_2_PLATO_H
#define LAB24_2_PLATO_H

using namespace std;
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

    void setCodigo(char *codigo);
    char *getCodigo() const;
    void setNombre(char *nombre);
    char *getNombre() const;
    void setPrecio(double precio);
    double getPrecio() const;
    void setCategoria(char *categoria);
    char *getCategoria() const;
    void setPreparados(int preparados);
    int getPreparados() const;
    void setDescuento(double descuento);
    double getDescuento() const;
    void setAtendidos(int atendidos);
    int getAtendidos() const;
    void setNoAtendidos(int noAtendidos);
    int getNoAtendidos() const;
    void setTotalEsperado(double totalEsperado);
    double getTotalEsperado() const;
    void setTotalBruto(double totalBruto);
    double getTotalBruto() const;
    void setTotalNeto(double totalNeto);
    double getTotalNeto() const;

    int atenderPedido(int );
    void sumarTotalEsperado(double ) ;
    void sumarTotalBruto(double );
    void sumarTotalNeto(double );

    Plato& operator=(const Plato &);
    ~Plato();
};
ifstream &operator>> (ifstream &, Plato &);
ofstream &operator<< (ofstream &, Plato &);


#endif //LAB24_2_PLATO_H
