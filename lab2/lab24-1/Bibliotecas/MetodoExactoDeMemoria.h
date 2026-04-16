//
// Created by ANTONIO on 14/04/2026.
//

#ifndef LAB24_1_METODOEXACTODEMEMORIA_H
#define LAB24_1_METODOEXACTODEMEMORIA_H

//lectura de libros
void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock);
char **leerLibros(ifstream &archLib);
char *leerCadenaExacta(ifstream &arch,char delim);
int *leerStock(ifstream &archLib);
//prueba reporte libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock);
//lectura pedidos
void atencionDePedidos(const char *nombArch,char ***libros,int **stock,int **&pedidosClientes,char ***&pedidosLibros,
    bool **&pedidosAtendidos);
int buscarCliente(int **buffPedCli,int dni) ;
void agregarCliente(int *buffPedCli,int dni,int &idCliente,int &cantCli);
void agregarPedido(int *buffPedCli,int numPed);
void leerPedidos(ifstream &archPed,char ***libros,int **stock,char **&buffPedLib,bool *&buffPedAten,int &cantLibEnPed);
void copiarCadena(char *destino,const char *origen) ;
int buscarLibro(char ***libros,char *codLib);
void modificarPedidoAtendido(int *stock,bool &seAtendio) ;
void cargaClienteNivelInterno(int *pedidosClientes,int *buffPedCli);
void cargarPedidoNivelInterno(char **pedidosLibros,bool *pedidosAtendidos,char **buffPedLib,bool *buffPedAten,int n) ;
//reporte Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,char ***pedidosLibros,bool **pedidosAtendidos);

#endif //LAB24_1_METODOEXACTODEMEMORIA_H
