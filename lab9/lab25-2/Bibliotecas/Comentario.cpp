//
// Created by ANTONIO on 21/06/2026.
//

#include "Comentario.h"
Comentario::Comentario() {
    canal = "";
    comentario = "";
}
Comentario::Comentario(const string &origin) {
    *this=origin;
}

string Comentario::get_canal() const {
    return canal;
}
void Comentario::set_canal(const string &canal) {
    this->canal = canal;
}

string Comentario::get_comentario() const {
    return comentario;
}
void Comentario::set_comentario(const string &comentario) {
    this->comentario = comentario;
}
//
ifstream& Comentario::leer(ifstream &arch) {
    string canalComent,comentarioComent;
    getline(arch,canalComent,',');
    getline(arch,comentarioComent);

    this->set_canal(canalComent);
    this->set_comentario(comentarioComent);

    return arch;
}
ofstream& Comentario::imprimir(ofstream &archRep) {
    archRep<<this->get_comentario()<<endl;

    return archRep;
}
//
Comentario& Comentario::operator=(const Comentario &origin) {
    if (this != &origin) {
        this->set_canal(origin.get_canal());
        this->set_comentario(origin.get_comentario());
    }
    return *this;
}
bool Comentario::operator<(Comentario & coment) const {
    return this->get_canal()<coment.get_canal();
}
//destructor
Comentario::~Comentario()= default;
//
ifstream& operator>> (ifstream &arch, Comentario &comentario) {
    return comentario.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Comentario &comentario) {
    return comentario.imprimir(archRep);
}
