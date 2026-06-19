//
// Created by ANTONIO on 18/06/2026.
//

#ifndef LAB25_2_2NDTIME_METRICA_H
#define LAB25_2_2NDTIME_METRICA_H
#include <string>

#include <fstream>
#include "enum.h"
using namespace std;
class Metrica {
    int id;
    string descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
public:
    Metrica();
    Metrica(const Metrica &);
    //
    int get_id() const;
    void set_id(int id);

    string get_descripcion() const;
    void set_descripcion(const string &descripcion);

    int get_fecha_calculo() const;
    void set_fecha_calculo(int fecha_calculo);

    int get_fecha_expiracion() const;
    void set_fecha_expiracion(int fecha_expiracion);

    bool get_estado() const;
    void set_estado(bool estado);
    //
    virtual ifstream& leer(ifstream &);
    virtual ofstream& imprimir(ofstream &);
    //
    virtual TipoMetrica get_tipo() const = 0;
    //
    Metrica &operator=(const Metrica &);
    //destructor
    virtual ~Metrica();
};


#endif //LAB25_2_2NDTIME_METRICA_H
