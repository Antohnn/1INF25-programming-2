/*/
 * Antonio Rios
 * 20233537
 *
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Bibliotecas/MetodoExactoDeMemoria.h"

int main(int argc,char** argv) {
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;

    lecturaDeLibros("Archivos/Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("Archivos/ReporteDeLibrosInicial.txt",libros,stock);

    atencionDePedidos("Archivos/Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
    pruebaDeLecturaDeLibros("Archivos/ReporteDeLibrosFinal.txt",libros,stock);

    reporteDeEntregaDePedidos("Archivos/ReporteDeEntregaDePedidos.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);

    return 0;
}
