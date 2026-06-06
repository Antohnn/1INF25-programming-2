//
// Created by ANTONIO on 4/06/2026.
//

#ifndef LAB25_2_2NDTIME_STREAMER_H
#define LAB25_2_2NDTIME_STREAMER_H


class Streamer {
    int id;
    char  *cuenta;
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
    void copiarCadena(char *&,char *);
    void imprimirCaracter(ofstream &,int ,char );
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //operador asignacion
    Streamer & operator=(const Streamer &);

    //destructor
    ~Streamer();
};
ifstream& operator>> (ifstream &,Streamer &);
ofstream& operator<< (ofstream &,Streamer &);

#endif //LAB25_2_2NDTIME_STREAMER_H
