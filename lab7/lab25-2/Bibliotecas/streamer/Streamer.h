//
// Created by ANTONIO on 11/06/2026.
//

#ifndef LAB25_2_STREAMER_H
#define LAB25_2_STREAMER_H

#include <fstream>

#include "../enum.h"
#include "../Metrica.h"
using namespace std;
class Streamer {
    int id;
    char *cuenta;
    int n_seguidores;
    char *categoria;
public:
    Streamer();
    Streamer(const Streamer &);
    //setters and getters
    int get_id() const;
    void set_id(int id);

    char * get_cuenta() const;
    void set_cuenta(char *cuenta);

    int get_n_seguidores() const;
    void set_n_seguidores(int n_seguidores);

    char * get_categoria() const;
    void set_categoria(char *categoria);
    //
    virtual ifstream& leer(ifstream &);
    virtual ofstream& imprimir(ofstream &);
    //
    void copiarCadena(char *&,char*);
    virtual TipoStreamer getTipoStreamer() const=0;
    virtual void agregar_metrica(Metrica *metrica)=0;
    //operador de asignacion
    Streamer& operator=(const Streamer &);
    //destructor
    virtual ~Streamer();
};
ifstream& operator>> (ifstream &, Streamer &);
ofstream& operator<< (ofstream &, Streamer &);


#endif //LAB25_2_STREAMER_H
