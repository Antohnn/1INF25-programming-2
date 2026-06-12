//
// Created by ANTONIO on 10/06/2026.
//

#ifndef LAB25_2_METRICA_H
#define LAB25_2_METRICA_H

#include <fstream>

#include "enum.h"
using namespace std;
class Metrica {
    int id;
    char* descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
public:
    Metrica();
    Metrica(const Metrica& );
    //setters and getters
    int get_id() const;
    void set_id(int id);

    char * get_descripcion() const;
    void set_descripcion(char *descripcion);

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
    void copiarCadena(char *&,char *);
    void imprimirDescripcion(ofstream &);
    virtual TipoMetrica getTipo() const=0;
    //operador asignacion
    Metrica& operator = (const Metrica &);
    //destructor
    virtual ~Metrica();
};
ifstream& operator >> (ifstream &, Metrica &);
ofstream& operator << (ofstream &, Metrica &);


#endif //LAB25_2_METRICA_H
