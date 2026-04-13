#include <iostream>
#include <cstring>
#include <fstream>

#include "Biblioteca/Estructuras.h"
#include "Biblioteca/Sobrecarga.h"

using namespace std;

int main() {
    ifstream archLibro,archCliente,archPedidos;

    abrirIn(archLibro,"Archivos/Libros.csv");
    abrirIn(archCliente,"Archivos/Clientes.csv");
    abrirIn(archPedidos,"Archivos/Pedidos.csv");

    Libro arrLibros[280],libro{};
    Cliente arrCliente[100],cliente{};
    LibroSolicitado libroPedido{};

    //lectura
    archLibro>>libro;
    archCliente>>cliente;

    for (int i=0;i<280;i++) {
        if (!(archLibro>>libro)) {
            strcpy(arrLibros[i].codigo,"FIN");
            break;
        }
        arrLibros[i]=libro;
    }
    for (int i=0;i<100;i++) {
        if (!(archCliente>>cliente)) {
            arrCliente[i].dni=0;
            break;
        }
        arrCliente[i]=cliente;
    }

    

    return 0;
}
