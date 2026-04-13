#include <cstring>
#include <iostream>
#include <fstream>

#include "Biblioteca/Funciones.h"
#include "Biblioteca/Estructuras.h"


using namespace std;


int main() {
    ifstream archPlato,archRepartidor,archPedido;
    ofstream archRepRepartidor,archRepPlato;

    abrirIn(archPlato,"Archivos/PlatosOfrecidos.csv");
    abrirIn(archRepartidor,"Archivos/RepartidoresContratados.csv");
    abrirIn(archPedido,"Archivos/OrdenesDeCompra.txt");

    abrirOut(archRepRepartidor,"Archivos/ReporteRepartidor.txt");
    abrirOut(archRepPlato,"Archivos/ReportePlato.txt");

    struct Plato arrPlatos[120],platos{};
    struct Repartidor arrRepartidor[50],repartidor{};
    struct Pedido ped{};

    for (int i=0;i<120;i++) {
        archPlato>>arrPlatos[i];
        if (archPlato.eof()) {
            strcpy(arrPlatos[i].codigo,"FIN");
            break;
        }
    }
    for (int i=0;i<50;i++) {
        archRepartidor>>arrRepartidor[i];
        if (archRepartidor.eof()) {
            strcpy(arrRepartidor[i].codigo,"FIN");
            break;
        }
    }

    while (true) {
        archPedido>>ped;
        if (archPedido.eof())break;
        ped<=arrPlatos;
        arrRepartidor<=ped;
    }

    for (int i=0;strcmp(arrRepartidor[i].codigo,"FIN")!=0;i++) {
        for (int j=0;j<arrRepartidor[i].cantidadDeOrdenes;j++) {
            !arrRepartidor[i].ordenesDeCompra[j];
        }
        !arrRepartidor[i];
    }

    for (int i=0;strcmp(arrPlatos[i].codigo,"FIN")!=0;i++) {
        archRepPlato<<arrPlatos[i];
    }
    for (int i=0;strcmp(arrRepartidor[i].codigo,"FIN")!=0;i++) {
        archRepRepartidor<<arrRepartidor[i];
    }


    return 0;
}
