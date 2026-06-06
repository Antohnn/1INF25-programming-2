//
// Created by ANTONIO on 28/05/2026.
//


#ifndef LAB25_2_METRICA_H
#define LAB25_2_METRICA_H

#include <fstream>

using namespace std;

class Metrica {
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;


public:
    //constructor por defecto
    Metrica();
    //constructor por copia
    Metrica(const Metrica &);
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

    //metodos utiles
    void copiarCadena(char *&,char *);
    char *leerCadena(ifstream &,char );

    //ifstreams and ofstreams 
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);

    void imprimirDescripcion(ofstream &);


    Metrica& operator=(const Metrica &);
    //destructor
    ~Metrica();
};

ifstream& operator>> (ifstream &, Metrica &);
ofstream& operator<< (ofstream &, Metrica &);



#endif //LAB25_2_METRICA_H
