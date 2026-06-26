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

string Streamer::getCodCategoria() const {
    return categoria.get_codigo();
}
void Streamer::setCategoria(Categoria &categoria) {
    this->categoria = categoria;
}

void Streamer::agregarComentario(Comentario &comentario) {
    comentarios.push_back(comentario.get_descripcion());
}
void Streamer::agregarEtiqueta(Etiqueta &etiqueta) {
    etiquetasVector.push_back(etiqueta);
}
//
ifstream& Streamer::leer(ifstream &arch) {
    string nombStreamer,etiquetasStreamer,idiomaStreamer,codCateStreamer;
    int fechaStreamer,dd,mm,aa;
    char car;

    getline(arch,nombStreamer,',');
    arch>>dd>>car>>mm>>car>>aa>>car;
    fechaStreamer=aa*10000+mm*100+dd;
    getline(arch,codCateStreamer,',');
    getline(arch,etiquetasStreamer,',');
    getline(arch,idiomaStreamer);

    this->set_canal(nombStreamer);
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
    archRep<<"CATEGORIA: "<<endl;
    archRep<<categoria;
    archRep<<"ETIQUETAS STR: "<<this->get_etiquetas_str()<<endl;
    archRep<<"ETIQUETAS: "<<endl;
    for (auto itEt=etiquetasVector.begin();itEt!=etiquetasVector.end();itEt++) {
        archRep<<*itEt;
    }
    archRep<<"COMENTARIOS: "<<endl;
    for (auto itCo=comentarios.begin();itCo!=comentarios.end();itCo++) {
        archRep<<*itCo<<endl;
    }
    


    return archRep;
}
//
bool Streamer::operator<(const Streamer &other) const {
    if (this->get_fecha()!=other.get_fecha()) {
        return this->categoria.get_codigo()<other.categoria.get_codigo();
    }
    return this->get_fecha()<other.get_fecha();
}
//destructor
Streamer::~Streamer() = default;
//
ifstream& operator>> (ifstream &arch, Streamer &streamer) {
    return streamer.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Streamer &streamer) {
    return streamer.imprimir(archRep);
}
