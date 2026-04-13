#include <iostream>
#include <cstring>
#include <fstream>

#include "Bibliotecas/Estructuras.h"
#include "Bibliotecas/Sobrecarga.h"

using namespace std;

int main() {
    ifstream archPlato,archRepartidor,archPedido;
    ofstream archRepPlato,archRepRepartidor;

    abrirIn(archPlato,"Archivos/PlatosOfrecidos.csv");
    abrirIn(archRepartidor,"Archivos/RepartidoresContratados.csv");
    abrirIn(archPedido,"Archivos/OrdenesDeCompra.txt");

    abrirOut(archRepPlato,"Archivos/ReportePlatos.txt");
    abrirOut(archRepRepartidor,"Archivos/ReporteRepartidor.txt");

    Plato arrPlato[150]{};
    Repartidor arrRepartidor[50]{};
    Pedido pedido{};

    for (int i=0;i<150;i++) {
        archPlato>>arrPlato[i];
        if (archPlato.eof()) {
            strcpy(arrPlato[i].codigo,"FIN");
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
        archPedido>>pedido;
        if (archPedido.eof()) break;
        pedido<=arrPlato;
        arrRepartidor<=pedido;
    }

    for (int i=0;strcmp(arrRepartidor[i].codigo,"FIN")!=0;i++) {
        for (int j=0;j<arrRepartidor[i].cantidadDeOrdenes;j++) {
            !arrRepartidor[i].ordenesDeCompra[j];
        }
        !arrRepartidor[i];
    }

    for (int i=0;strcmp(arrRepartidor[i].codigo,"FIN")!=0;i++) {
        archRepRepartidor<<arrRepartidor[i];
    }

    for (int i=0;strcmp(arrPlato[i].codigo,"FIN")!=0;i++) {
        archRepPlato<<arrPlato[i];
    }




    return 0;
}
