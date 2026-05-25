//
// Created by anton on 11/05/2026.
//

#ifndef LAB25_2_STREAMER_H
#define LAB25_2_STREAMER_H


class Streamer {
    //atributos
    char *cuenta;
    long long tiempo_total;
    double promedio_espectadores;
    int n_seguidores;
    char *categoria;

    public:
    //constructores
    Streamer();
    Streamer(const Streamer &);
    //Setters and getters
    void setCuenta(char *cuenta);
    char *getCuenta() const;
    void setTiempoTotal(long long tiempo_total);
    long long getTiempoTotal() const;
    void setPromedio(double promedio);
    double getPromedio() const;
    void setNSeguidores(int n_seguidores);
    int getNSeguidores() const;
    void setCategoria(char *categoria);
    char *getCategoria() const;
    //Sobrecarga de operador para asignacion
    Streamer& operator=(const Streamer &);

    void leerStreamer();
};


#endif //LAB25_2_STREAMER_H
