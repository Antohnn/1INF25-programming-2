//
// Created by ANTONIO on 14/05/2026.
//

#ifndef LAB25_1_INFRACCION_H
#define LAB25_1_INFRACCION_H

using namespace std;
class Infraccion {
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;

public:
    //constructor inicializar, constructor copia y destructor
    Infraccion();
    Infraccion(const Infraccion &);
    ~Infraccion();

    int get_codigo() const;
    void set_codigo(int codigo);
    void get_descripcion(char *desc) const;
    void set_descripcion(char *desc);
    void get_gravedad(char *grav) const;
    void set_gravedad(char *gravedad);
    double get_multa() const;
    void set_multa(double multa);

    Infraccion &operator=(const Infraccion &);

};

ifstream &operator>> (ifstream &, Infraccion &);
ofstream &operator<< (ofstream &, Infraccion &);


#endif //LAB25_1_INFRACCION_H
