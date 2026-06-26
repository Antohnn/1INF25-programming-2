//
// Created by ANTONIO on 26/06/2026.
//

#include "Streamer.h"

Streamer::Streamer() {
    fecha=0;
}
Streamer::Streamer(const Streamer &origin):Streamer() {
    *this=origin;
}

string Streamer::get_canal() const {
    return canal;
}
void Streamer::set_canal(const string &canal) {
    this->canal = canal;
}

int Streamer::get_fecha() const {
    return fecha;
}
void Streamer::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Streamer::get_etiquetas_str() const {
    return etiquetasStr;
}
void Streamer::set_etiquetas_str(const string &etiquetas_str) {
    etiquetasStr = etiquetas_str;
}

string Streamer::get_idioma() const {
    return idioma;
}
void Streamer::set_idioma(const string &idioma) {
    this->idioma = idioma;
}
//
ifstream& Streamer::leer(ifstream &arch) {
    
}

//destructor
Streamer::~Streamer() = default;
