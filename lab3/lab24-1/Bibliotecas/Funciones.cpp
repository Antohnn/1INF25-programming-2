//
// Created by ANTONIO on 23/04/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

#include "Funciones.h"
#include "enums.h"

//cargarClientes
void cargarClientes(void *&clientes) {
    ifstream arch;
    abrirIn(arch,"ArchivosDeDatos/Clientes.csv");
    void **buffer=new void*[100]{};
    void *cliente;
    int num=0;
    while (leerCliente(arch,cliente)) {
        buffer[num++]=cliente;
    }
    void **registro=new void*[num+1]{};
    for (int i=0;i<num;i++) {
        registro[i]=buffer[i];
    }
    registro[num]=nullptr;
    delete[] buffer;
    clientes=registro;
}
bool leerCliente(ifstream &arch,void *&cliente) {
    int dni;
    char *nombCliente;

    arch>>dni;
    if (arch.eof())return false;
    arch.get();
    nombCliente=leerCadenaExacta(arch,'\n');

    void **reg=new void*[clientNumDatos]{};
    reg[clientDni]=new int(dni);
    reg[clientNomb]=nombCliente;

    cliente=reg;
    return true;
}
//mostrarClientes
void mostrarClietes(const void *clientes) {
    ofstream archRep;
    abrirOut(archRep,"ArchivosDeReporte/MostraClientes.txt");
    const void **regCliente=(const void **)clientes;
    for (int i=0;regCliente[i];i++) {
        const void **datoCliente=(const void **)regCliente[i];
        const int dni=*(int *)datoCliente[clientDni];
        const char *nombCliente=(const char *)datoCliente[clientNomb];

        archRep<<dni<<setw(40)<<nombCliente<<endl;
    }
}
//crearReserva
void crearReserva(void *&reserva) {
    ifstream arch;
    abrirIn(arch,"ArchivosDeDatos/Libros.csv");
    void **buffer=new void*[350]{};
    void *libroReservado;
    int num=0;
    while (leerLibro(arch,libroReservado)) {
        buffer[num++]=libroReservado;
    }
    void **registro=new void*[num+1]{};
    for (int i=0;i<num;i++) {
        registro[i]=buffer[i];
    }
    registro[num]=nullptr;
    delete[] buffer;
    reserva=registro;
}
bool leerLibro(ifstream &arch,void *&libroReservado) {
    char *codLibro,*nombLibro,*autorLibro,c;
    int cantidad;
    double precio;

    codLibro=leerCadenaExacta(arch,',');
    if (arch.eof())return false;
    nombLibro=leerCadenaExacta(arch,',');
    autorLibro=leerCadenaExacta(arch,',');
    arch>>cantidad>>c>>precio;
    arch.get();

    void **reg=new void*[reservNumDatos]{};
    reg[reservCodLibro]=codLibro;
    reg[reservNombLibro]=nombLibro;
    reg[reservAutorLibro]=autorLibro;
    reg[reservPedCliLibro]=nullptr;
    reg[reservStockLibro]=new int(cantidad);

    libroReservado=reg;
    return true;
}
//mostrarReservas
void mostrarReservas(const void *reserva) {
    ofstream archRep;
    abrirOut(archRep,"ArchivosDeReporte/MostrarReservas.txt");
    const void **regReserva=(const void **)reserva;
    for (int i=0;regReserva[i];i++) {
        const void **datoReserva=(const void **)regReserva[i];

        const char *codLibro=(const char *)datoReserva[reservCodLibro];
        const char *nombLibro=(const char *)datoReserva[reservNombLibro];
        const char *autorLibro=(const char *)datoReserva[reservAutorLibro];
        const int cantidad=*(int *)datoReserva[reservStockLibro];

        archRep<<left<<setw(10)<<codLibro<<setw(60)<<nombLibro<<setw(40)<<autorLibro<<right<<setw(10)<<cantidad<<endl;
    }
}
//cargarReserva
void cargarReserva(void *clientes,void *reserva) {
    ifstream arch;
    abrirIn(arch,"ArchivosDeDatos/Pedidos2.csv");
    void *pedido;
    char *codLibro;
    while (leerPedido(arch,pedido,clientes,codLibro)) {
        void *reservaLibro=buscarReservaLibro(reserva,codLibro);
        agregarClienteReserva(reservaLibro,pedido);
    }
}
bool leerPedido(ifstream &arch,void* &pedido,void *clientes,char *&codLibro) {
    int dni;

    arch>>dni;
    if (arch.eof())return false;
    arch.get();
    codLibro=leerCadenaExacta(arch,'\n');
    void *cliente=buscarCliente(clientes,dni);
    void **datoCliente=(void **)cliente;
    char *nombCliente=(char *)datoCliente[clientNomb];
    char *nombre;
    copiarCadena(nombre,nombCliente);

    void **reg=new void*[pedNumDatos]{};
    reg[pedDniCli]=new int(dni);
    reg[pedNombCli]=nombre;

    pedido=reg;
    return true;
}
void *buscarCliente(const void *clientes,int dni) {
    const void **regClientes=(const void **)clientes;
    for (int i=0;regClientes[i];i++) {
        const void **datoCliente=(const void **)regClientes[i];
        const int dniCliente=*(const int *)datoCliente[clientDni];
        if (dniCliente==dni) {
            return datoCliente;
        }
    }
    return nullptr;
}
void *buscarReservaLibro(const void *reserva,char *codLibro) {
    const void **regReserva=(const void **)reserva;
    for (int i=0;regReserva[i];i++) {
        const void **datoReserva=(const void **)regReserva[i];
        const char *codLibroReserva=(const char *)datoReserva[reservCodLibro];
        if (strcmp(codLibro,codLibroReserva)==0) {
            return datoReserva;
        }
    }
    return nullptr;
}
void agregarClienteReserva(void *reservaLibro,void *pedido) {
    void **datoReservaLibro=(void **)reservaLibro;
    void **regPedCli=(void **)datoReservaLibro[reservPedCliLibro];
    int *stock=(int *)datoReservaLibro[reservStockLibro];


    if (*stock>0) {
        incrementarRegistroExacto(regPedCli,pedido);
        datoReservaLibro[reservPedCliLibro]=regPedCli;
        (*stock)--;
    }
}
void incrementarRegistroExacto(void **&regPedCli,void *pedido) {
    int num=0;
    if (regPedCli!=nullptr) {
        while (regPedCli[num])num++;
    }
    void **aux=new void*[num+2]{};
    for (int i=0;i<num;i++) {
        aux[i]=regPedCli[i];
    }
    aux[num]=pedido;
    aux[num+1]=nullptr;
    delete[] regPedCli;
    regPedCli=aux;
}
//reporteFinal
void reporteFinal(const void *reserva) {
    ofstream archRep;
    abrirOut(archRep,"ArchivosDeReporte/ReporteFinal.txt");
    archRep<<"Reporte de Libros Reservados"<<endl;
    imprimirCaracter(archRep,'=',60);

    const void **regReserva=(const void **)reserva;
    for (int i=0;regReserva[i];i++) {
        const void **datoReserva=(const void **)regReserva[i];
        const char *codLibro=(const char *)datoReserva[reservCodLibro];
        const char *nombLibro=(const char *)datoReserva[reservNombLibro];
        const char *autorLibro=(const char *)datoReserva[reservAutorLibro];
        archRep<<"Libro:"<<codLibro<<endl;
        archRep<<"Nombre del Libro:"<<nombLibro<<endl;
        archRep<<"Autor:"<<autorLibro<<endl;
        archRep<<"DNI"<<setw(30)<<"Nombre del solicitante"<<endl;
        imprimirCaracter(archRep,'-',60);
        const void **regPedCli=(const void **)datoReserva[reservPedCliLibro];
        if (regPedCli!=nullptr) {
            for (int j=0;regPedCli[j];j++) {
                void **datoPedCli=(void **)regPedCli[j];
                const int dniPedCli=*(const int *)datoPedCli[pedDniCli];
                const char *nombCli=(const char *)datoPedCli[pedNombCli];

                archRep<<left<<setw(12)<<dniPedCli<<setw(80)<<nombCli<<right<<endl;
            }
        }else {
            archRep<<"--------------------------------"<<endl;
        }
        archRep<<endl;
    }
}
void imprimirCaracter(ofstream &archRep,char car,int num) {
    for (int i=0;i<num;i++) {
        archRep<<car;
    }
    archRep<<endl;
}
//aux
void abrirIn(ifstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
}
char *leerCadenaExacta(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
void copiarCadena(char *&nombre,char *nombCliente) {
    nombre=new char[strlen(nombCliente)+1];
    strcpy(nombre,nombCliente);
}
