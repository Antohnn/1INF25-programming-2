//
// Created by ANTONIO on 14/05/2026.
//

#ifndef LAB25_1_MULTA_H
#define LAB25_1_MULTA_H

using namespace std;
class Multa {
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;

public:
    Multa();
    Multa(const Multa &);
    ~Multa();

    void get_placa(char *plac) const;
    void set_placa(char *placa);
    int get_fecha_de_infraccion() const;
    void set_fecha_de_infraccion(int fecha_de_infraccion);
    int get_fecha_de_pago() const;
    void set_fecha_de_pago(int fecha_de_pago);
    int get_codigo_infraccion() const;
    void set_codigo_infraccion(int codigo_infraccion);
    double get_multa() const;
    void set_multa(double multa);

    Multa &operator=(const Multa &);
};
ifstream &operator>> (ifstream &, Multa &);
ofstream &operator<< (ofstream &, Multa &);

#endif //LAB25_1_MULTA_H
