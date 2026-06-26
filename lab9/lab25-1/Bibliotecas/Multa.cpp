//
// Created by ANTONIO on 25/06/2026.
//

#include "Multa.h"

Multa::Multa() {
    fecha=0;
    multa=0;
    pagado=false;
    fechaDePago=0;
}
Multa::Multa(const Multa &origin):Multa() {
    *this=origin;
}

int Multa::get_fecha() const {
    return fecha;
}
void Multa::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Multa::get_placa() const {
    return placa;
}
void Multa::set_placa(const string &placa) {
    this->placa = placa;
}

string Multa::get_cod_multa() const {
    return codMulta;
}
void Multa::set_cod_multa(const string &cod_multa) {
    codMulta = cod_multa;
}

double Multa::get_multa() const {
    return multa;
}
void Multa::set_multa(double multa) {
    this->multa = multa;
}

bool Multa::is_pagado() const {
    return pagado;
}
void Multa::set_pagado(bool pagado) {
    this->pagado = pagado;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}
void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}
//
ifstream& Multa::leer(ifstream &arch) {
    int dd,mm,aa,fechaMulta,ddP,mmP,aaP,fechaMultaP;
    string placaMulta,codigoMulta;
    char pagadoLet,car;

    arch>>dd>>car>>mm>>car>>aa>>car;
    fechaMulta=aa*10000+mm*100+dd;
    getline(arch,placaMulta,',');
    getline(arch,codigoMulta,',');
    arch>>pagadoLet;
    if (pagadoLet=='P') {
        arch>>car>>ddP>>car>>mmP>>car>>aaP;
        fechaMultaP=aaP*10000+mmP*100+ddP;
    }else fechaMultaP=0;

    this->set_fecha(fechaMulta);
    this->set_placa(placaMulta);
    this->set_cod_multa(codigoMulta);
    if (pagadoLet=='P') {
        this->set_pagado(true);
        this->set_fecha_de_pago(fechaMultaP);
    }else this->set_pagado(false);



    return arch;
}
ofstream& Multa::imprimir(ofstream &archRep) const {
    string codInfra=this->get_cod_multa();
    string numInfra=codInfra.substr(1,4);

    archRep<<this->get_placa()<<" "<<this->get_fecha()<<" "<<numInfra<<" "<<this->get_multa()<<" ";
    if (this->is_pagado()) {
        archRep<<"SI"<<" "<<this->get_fecha_de_pago();
    }else archRep<<"NO";
    archRep<<endl;
    return archRep;
}
//
Multa& Multa::operator=(const Multa &origin) {
    if (this!=&origin) {
        this->set_fecha(origin.get_fecha());
        this->set_placa(origin.get_placa());
        this->set_cod_multa(origin.get_cod_multa());
        this->set_multa(origin.get_multa());
        this->set_pagado(origin.is_pagado());
        this->set_fecha_de_pago(origin.get_fecha_de_pago());
    }
    return *this;
}
//
bool Multa::operator<(const Multa &other) const {
    return this->get_fecha()>other.get_fecha();
}
//destructor
Multa::~Multa() = default;
//
ifstream& operator>> (ifstream &arch, Multa &multa) {
    return multa.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Multa &multa) {
    return multa.imprimir(archRep);
}