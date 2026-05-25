//
// Created by ANTONIO on 15/05/2026.
//
#include <cstring>
#include <iostream>

using namespace std;

#include "Plato.h"

Plato::Plato() {
    codigo=nullptr;
    nombre=nullptr;
    precio=0;
    categoria=nullptr;
    preparados=0;
    descuento=0;
    atendidos=0;
    noAtendidos=0;
    totalEsperado=0;
    totalBruto=0;
    totalNeto=0;
}
Plato::Plato(const Plato &origin):Plato() {
    *this = origin;
}
Plato::~Plato() {
    delete [] codigo;
    delete [] nombre;
    delete [] categoria;
}

void Plato::get_codigo(char *code) const {
    if (codigo==nullptr) code[0]=0;
    else strcpy(code,codigo);
}
void Plato::set_codigo(char *codigo) {
    delete [] this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Plato::get_nombre(char *nomb) const {
    if (nombre==nullptr) nombre[0]=0;
    else strcpy(nomb,nombre);
}
void Plato::set_nombre(char *nombre) {
    delete [] this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

double Plato::get_precio() const {
    return precio;
}
void Plato::set_precio(double precio) {
    this->precio = precio;
}

void Plato::get_categoria(char *cate) const {
    if (categoria==nullptr) cate[0]=0;
    else strcpy(cate,categoria);
}
void Plato::set_categoria(char *categoria) {
    delete [] this->categoria;
    this->categoria = new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}

int Plato::get_preparados() const {
    return preparados;
}
void Plato::set_preparados(int preparados) {
    this->preparados = preparados;
}

double Plato::get_descuento() const {
    return descuento;
}
void Plato::set_descuento(double descuento) {
    this->descuento = descuento;
}

int Plato::get_atendidos() const {
    return atendidos;
}
void Plato::set_atendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::get_no_atendidos() const {
    return noAtendidos;
}
void Plato::set_no_atendidos(int no_atendidos) {
    noAtendidos = no_atendidos;
}

double Plato::get_total_esperado() const {
    return totalEsperado;
}
void Plato::set_total_esperado(double total_esperado) {
    totalEsperado = total_esperado;
}

double Plato::get_total_bruto() const {
    return totalBruto;
}
void Plato::set_total_bruto(double total_bruto) {
    totalBruto = total_bruto;
}

double Plato::get_total_neto() const {
    return totalNeto;
}
void Plato::set_total_neto(double total_neto) {
    totalNeto = total_neto;
}

Plato &Plato::operator=(const Plato &origin) {
    if (this!=&origin) {
        set_codigo(origin.codigo);
        set_nombre(origin.nombre);
        set_precio(origin.precio);
        set_categoria(origin.categoria);
        set_preparados(origin.preparados);
        set_descuento(origin.descuento);
        set_atendidos(origin.atendidos);
        set_no_atendidos(origin.noAtendidos);
        set_total_esperado(origin.totalEsperado);
        set_total_bruto(origin.totalBruto);
        set_total_neto(origin.totalNeto);
    }
    return *this;
}
