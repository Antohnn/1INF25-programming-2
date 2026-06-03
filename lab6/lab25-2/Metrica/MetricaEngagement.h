//
// Created by ANTONIO on 2/06/2026.
//

#ifndef LAB25_2_METRICAENGAGEMENT_H
#define LAB25_2_METRICAENGAGEMENT_H
#include "Metrica.h"
#include <fstream>

class MetricaEngagement:public Metrica{
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
public:
    MetricaEngagement();
    MetricaEngagement(const MetricaEngagement& );

    //setters and getters
    int get_mensajes_chat() const;
    void set_mensajes_chat(int mensajes_chat);

    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(int usuarios_unicos_chat);

    int get_clips_generados() const;
    void set_clips_generados(int clips_generados);

    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);

    MetricaEngagement& operator=(const MetricaEngagement&);
};
ifstream& operator>>(ifstream &,MetricaEngagement&);
ofstream& operator<<(ofstream &,MetricaEngagement&);


#endif //LAB25_2_METRICAENGAGEMENT_H
