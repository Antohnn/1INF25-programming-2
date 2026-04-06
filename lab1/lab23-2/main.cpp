#include <iostream>
#include <cstring>

#include "Librerias/AperturaDeArchivos.h"


using namespace std;

#include "Funciones.h"
#include "Estructuras.h"

int main() {
    struct Cliente arrClientes[150]{},cliente1{};
    struct Producto arrProductos[200]{},producto1{};
    struct Pedido pedido1{};

    ifstream archCliente,archProd,archPedido;
    ofstream archRepCliente,archRepProducto;
    //lectura cliente
    abrirArch(archCliente,"Archivos/Clientes.csv");
    abrirArch(archProd,"Archivos/Productos.csv");
    abrirArch(archPedido,"Archivos/Pedidos.csv");

    abrirOut(archRepCliente,"Archivos/ReporteCliente.txt");
    abrirOut(archRepProducto,"Archivos/ReporteProducto.txt");

    for (int i=0;i<150;i++) {
        if (!(archCliente>>cliente1)) {
            arrClientes[i].dni=0;
            break;
        }
        arrClientes[i]=cliente1;
    }
    for (int i=0;i<200;i++) {
        if (!(archProd>>producto1)) {
            strcpy(arrProductos[i].codigo,"XXXXXXX");
            break;
        }
        arrProductos[i]=producto1;
    }

    while (archPedido>>pedido1) {
        arrProductos+=pedido1;
        arrClientes+=pedido1;
    }

    for (int i=0;arrClientes[i].dni!=0;i++) {
        archRepCliente<<arrClientes[i];
    }
    for (int i=0;strcmp(arrProductos[i].codigo,"XXXXXXX")!=0;i++) {
        archRepProducto<<arrProductos[i];
    }


    return 0;
}
