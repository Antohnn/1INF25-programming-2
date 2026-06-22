//
// Created by ANTONIO on 22/06/2026.
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
    string canalStreamer,codCateStreamer,etiquetasStreamer,idiomaStreamer;
    int dd,mm,aa,fechaStreamer;
    char car;
    getline(arch,canalStreamer,',');
    arch>>dd>>car>>mm>>car>>aa;
    fechaStreamer=aa*10000+mm*100+dd;
    getline(arch,codCateStreamer,',');
    getline(arch,etiquetasStreamer,',');
    getline(arch,idiomaStreamer);

    this->set_canal(canalStreamer);
    this->set_fecha(fechaStreamer);
    this->categoria.set_codigo(codCateStreamer);
    this->set_etiquetas_str(etiquetasStreamer);
    this->set_idioma(idiomaStreamer);

    return arch;
}
ofstream& Streamer::imprimir(ofstream &archRep) {
    archRep<<"CANAL: "<<this->get_canal()<<endl;
    archRep<<"FECHA: "<<this->get_fecha()<<endl;
    archRep<<"LENGUAJE: "<<this->get_idioma()<<endl;
    archRep<<"CATEGORIA"<<endl;
    archRep<<categoria<<endl;

    return archRep;
}
//

//destructor
Streamer::~Streamer()=default;