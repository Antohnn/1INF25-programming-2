//
// Created by ANTONIO on 11/05/2026.
//
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Plato.h"
#include "Funciones.h"

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
    *this=origin;
}

void Plato::setCodigo(char *codigo) {
    delete [] this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}
char *Plato::getCodigo() const {
    return codigo;
}
void Plato::setNombre(char *nombre) {
    delete [] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}
char *Plato::getNombre() const {
    return nombre;
}
void Plato::setPrecio(double precio) {
    this->precio=precio;
}
double Plato::getPrecio() const {
    return precio;
}
void Plato::setCategoria(char *categoria) {
    delete [] this->categoria;
    this->categoria=new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}
char *Plato::getCategoria() const {
    return categoria;
}
void Plato::setPreparados(int preparados) {
    this->preparados=preparados;
}
int Plato::getPreparados() const {
    return preparados;
}
void Plato::setDescuento(double descuento) {
    this->descuento=descuento;
}
double Plato::getDescuento() const {
    return descuento;
}
void Plato::setAtendidos(int atendidos) {
    this->atendidos=atendidos;
}
int Plato::getAtendidos() const {
    return atendidos;
}
void Plato::setNoAtendidos(int noAtendidos) {
    this->noAtendidos=noAtendidos;
}
int Plato::getNoAtendidos() const {
    return noAtendidos;
}
void Plato::setTotalEsperado(double totalEsperado) {
    this->totalEsperado=totalEsperado;
}
double Plato::getTotalEsperado() const {
    return totalEsperado;
}
void Plato::setTotalBruto(double totalBruto) {
    this->totalBruto=totalBruto;
}
double Plato::getTotalBruto() const {
    return totalBruto;
}
void Plato::setTotalNeto(double totalNeto) {
    this->totalNeto=totalNeto;
}
double Plato::getTotalNeto() const {
    return totalNeto;
}

Plato& Plato::operator=(const Plato &origin) {
    if (this!=&origin) {
        this->setCodigo(origin.getCodigo());
        this->setNombre(origin.getNombre());
        this->setPrecio(origin.getPrecio());
        this->setCategoria(origin.getCategoria());
        this->setPreparados(origin.getPreparados());
        this->setDescuento(origin.getDescuento());
        this->setAtendidos(origin.getAtendidos());
        this->setNoAtendidos(origin.getNoAtendidos());
        this->setTotalEsperado(origin.getTotalEsperado());
        this->setTotalBruto(origin.getTotalBruto());
        this->setTotalNeto(origin.getTotalNeto());
    }
    return *this;
}
Plato::~Plato() {
    delete [] codigo;
    delete [] nombre;
    delete [] categoria;
}
int Plato::atenderPedido(int cantPlatoPedido) {
    int disponibles=preparados-atendidos;
    int cantidadAtendida;

    if (cantPlatoPedido<=disponibles) {
        cantidadAtendida=cantPlatoPedido;
    }else {
        cantidadAtendida=disponibles;
    }
    atendidos+=cantidadAtendida;
    noAtendidos+=cantPlatoPedido-cantidadAtendida;

    return cantidadAtendida;
}
void Plato::sumarTotalEsperado(double monto) {
    totalEsperado+=monto;
}
void Plato::sumarTotalBruto(double monto) {
    totalBruto+=monto;
}
void Plato::sumarTotalNeto(double monto) {
    totalNeto+=monto;
}
ifstream &operator>> (ifstream &arch, Plato &plato) {
    char *codPlato,*nombPlato,*categoriaPlato,c;
    int numeroPlato;
    double precioPlato,descuentoPlato;

    codPlato=leerCadenaExacta(arch,',');
    if (arch.eof()) return arch;
    nombPlato=leerCadenaExacta(arch,',');
    arch>>precioPlato>>c;
    categoriaPlato=leerCadenaExacta(arch,',');
    arch>>numeroPlato;
    if (arch.get()!='\n') {
        arch>>descuentoPlato>>c;
    }else descuentoPlato=0;
    arch.get();

    plato.setCodigo(codPlato);
    plato.setNombre(nombPlato);
    plato.setPrecio(precioPlato);
    plato.setCategoria(categoriaPlato);
    plato.setPreparados(numeroPlato);
    plato.setDescuento(descuentoPlato);
    plato.setAtendidos(0);
    plato.setNoAtendidos(0);
    plato.setTotalEsperado(0);
    plato.setTotalBruto(0);
    plato.setTotalNeto(0);


    delete[] codPlato;
    delete[] nombPlato;
    delete[] categoriaPlato;

    return arch;
}
ofstream &operator<< (ofstream &arch, Plato &plato) {
    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(10)<<plato.getCodigo()<<setw(60)<<plato.getNombre()<<setw(40)<<plato.getPrecio()<<setw(25)
        <<plato.getCategoria()<<right<<setw(10)<<plato.getPreparados()<<setw(7)<<plato.getDescuento()<<'%'
        <<setw(10)<<plato.getAtendidos()<<setw(10)<<plato.getNoAtendidos()<<setw(7)<<plato.getTotalEsperado()
        <<plato.getTotalBruto()<<setw(7)<<plato.getTotalNeto()<<endl;
    return arch;
}
