//
// Created by ANTONIO on 23/04/2026.
//

#ifndef LAB24_1_FUNCIONES_H
#define LAB24_1_FUNCIONES_H
//cargarClientes
void cargarClientes(void *&clientes) ;
bool leerCliente(ifstream &arch,void *&cliente);
//mostrarClientes
void mostrarClietes(const void *clientes);
//crearReserva
void crearReserva(void *&reserva) ;
bool leerLibro(ifstream &arch,void *&libroReservado);
//mostrarReservas
void mostrarReservas(const void *reserva);
//cargarReserva
void cargarReserva(void *clientes,void *reserva);
bool leerPedido(ifstream &arch,void* &pedido,void *clientes,char *&codLibro);
void *buscarCliente(const void *clientes,int dni) ;
void *buscarReservaLibro(const void *reserva,char *codLibro);
void agregarClienteReserva(void *reservaLibro,void *pedido);
void incrementarRegistroExacto(void **&regPedCli,void *pedido);
//reporteFinal
void reporteFinal(const void *reserva);
void imprimirCaracter(ofstream &archRep,char car,int num);
//aux
void abrirIn(ifstream &arch,const char *nombArch) ;
void abrirOut(ofstream &arch,const char *nombArch) ;
char *leerCadenaExacta(ifstream &arch,char delim);
void copiarCadena(char *&nombre,char *nombCliente) ;
#endif //LAB24_1_FUNCIONES_H
