#include <cstring>
#include <iostream>
#include <fstream>

#include "Funciones.h"
#include "Estructuras.h"

using namespace std;

int main() {

    ifstream archCliente,archProducto,archPedido;
    ofstream archRepCliente,archRepProd;

    abrirIn(archCliente,"Archivos/Clientes.csv");
    abrirIn(archProducto,"Archivos/Productos.csv");
    abrirIn(archPedido,"Archivos/Pedidos.csv");

    abrirOut(archRepCliente,"Archivos/ReporteCliente.txt");
    abrirOut(archRepProd,"Archivos/ReporteProducto.txt");

    Cliente arrClientes[150]{},cliente{};
    Producto arrProductos[200]{},producto{};
    Pedido pedido{};

    for (int i=0;i<150;i++ ) {
        if (!(archCliente>>cliente)) {
            arrClientes[i].dni=0;
            break;
        }
        arrClientes[i]=cliente;
    }

    for (int i=0;i<200;i++ ) {
        if (!(archProducto>>producto)) {
            strcpy(arrProductos[i].codigo,"XXXXXXX");
            break;
        }
        arrProductos[i]=producto;
    }

    while (archPedido>>pedido) {
        arrProductos+=pedido;
        arrClientes+=pedido;
    }

    for (int i=0;arrClientes[i].dni!=0;i++ ) {
        archRepCliente<<arrClientes[i];
    }

    for (int i=0;strcmp(arrProductos[i].codigo,"XXXXXXX") != 0;i++ ) {
        archRepProd<<arrProductos[i];
    }






    return 0;
}
