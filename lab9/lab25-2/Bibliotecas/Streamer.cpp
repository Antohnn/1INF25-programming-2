//
// Created by ANTONIO on 22/06/2026.
//

#include "Streamer.h"

#include "Comentario.h"

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
string Streamer::get_codCategoria() const {
    return categoria.get_codigo();
}
void Streamer::set_Categoria(const Categoria &categoria) {
    this->categoria=categoria;
}
void Streamer::agregarEtiqueta(const Etiqueta &etiqueta) {
       etiquetasVector.push_back(etiqueta);
}
void Streamer::agregarComentario(const string &comentario) {
    this->comentarios.push_back(comentario);
}
//
ifstream& Streamer::leer(ifstream &arch) {
    string canalStreamer,codCateStreamer,etiquetasStreamer,idiomaStreamer;
    int dd,mm,aa,fechaStreamer;
    char car;
    getline(arch,canalStreamer,',');
    arch>>dd>>car>>mm>>car>>aa>>car;
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
    archRep<<"ETIQUETAS STR: "<<this->get_etiquetas_str()<<endl;
    archRep<<"ETIQUETAS: "<<endl;
    int i=1;
    for (auto itEt=etiquetasVector.begin();itEt!=etiquetasVector.end();itEt++) {
        archRep<<i<<") ";
        archRep<<*itEt<<endl;
        i++;
    }
    archRep<<"COMENTARIOS"<<endl;
    int j=1;
    for (auto itCo=comentarios.begin();itCo!=comentarios.end();itCo++) {
        archRep<<j<<") ";
        archRep<<*itCo<<endl;
        j++;
    }

    return archRep;
}
//
Streamer& Streamer::operator= (const Streamer &origin) {
    if (this != &origin) {
        this->set_canal(origin.get_canal());
        this->set_fecha(origin.get_fecha());
        this->categoria=origin.categoria;
        this->set_etiquetas_str(origin.get_etiquetas_str());
        this->etiquetasVector=origin.etiquetasVector;
        this->set_idioma(origin.get_idioma());
        this->comentarios=origin.comentarios;
    }
    return *this;
}
bool Streamer::operator< (const Streamer &streamer) const {
    if (this->categoria.get_codigo()!=streamer.categoria.get_codigo()) {
        return this->categoria.get_codigo()<streamer.categoria.get_codigo();
    }
    return this->get_fecha()<streamer.get_fecha();
}
//destructor
Streamer::~Streamer()=default;
//
ifstream& operator>> (ifstream &arch, Streamer &streamer) {
    return streamer.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Streamer &streamer) {
    return streamer.imprimir(archRep);
}