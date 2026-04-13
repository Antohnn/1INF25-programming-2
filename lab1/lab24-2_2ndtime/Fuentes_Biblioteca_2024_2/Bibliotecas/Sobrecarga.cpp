#include <iostream>
#include <cstring>
#include <fstream>

#include "Estructuras.h"
#include "Sobrecarga.h"

#include <iomanip>

using namespace std;

//Lectura
void operator>>(ifstream &archPlato,Plato &plato) {
    //arch>>pedido
    char tipo[40];

    archPlato.getline(plato.codigo,7,',');
    if (archPlato.eof())return;
    archPlato.getline(plato.nombre,60,',');
    archPlato>>plato.precio;
    archPlato.get();
    archPlato.getline(tipo,40);

    plato.totalDePedidos=0;
    plato.totalRecaudado=0;
}
void operator>>(ifstream &archRepartidor,Repartidor &repartidor) {
    //arch>>repartidor
    archRepartidor.getline(repartidor.codigo,7,',');
    if (archRepartidor.eof())return;
    archRepartidor.getline(repartidor.nombre,60,',');
    archRepartidor.getline(repartidor.tipoDeVehiculo,15);

    repartidor.cantidadDeOrdenes=0;
    repartidor.pagoPorEntregas=0;
}
void operator>>(ifstream &archPedido,Pedido &pedido) {
    //arch>>pedido
    archPedido>>pedido.dniDelCliente;
    if (archPedido.eof())return;
    archPedido>>pedido.codigoDelPlato>>pedido.cantidad>>pedido.codigoDelRepartidor>>pedido.distanciaARecorrer;

    pedido.precio=0;
}
//Operaciones
bool operator<=(Pedido &pedido,Plato *arrPlato) {
    //pedido<=arrPlato
    for (int i=0;strcmp(arrPlato[i].codigo,"FIN")!=0;i++) {
        if (strcmp(arrPlato[i].codigo,pedido.codigoDelPlato)==0) {
            pedido.precio=arrPlato[i].precio;
            arrPlato[i].totalDePedidos++;
            arrPlato[i].totalRecaudado+=arrPlato[i].precio;
            return true;
        }
    }
    return false;
}
void operator<=(Repartidor *arrRepartidor,Pedido &pedido) {
    int cantOrden,cantPlatos;
    for (int i=0;strcmp(arrRepartidor[i].codigo,"FIN")!=0;i++) {
        if (strcmp(arrRepartidor[i].codigo,pedido.codigoDelRepartidor)==0) {
            for (int j=0;j<arrRepartidor[i].cantidadDeOrdenes;j++) {
                if (arrRepartidor[i].ordenesDeCompra[j].dniDelCliente==pedido.dniDelCliente) {
                    cantPlatos = arrRepartidor[i].ordenesDeCompra[j].cantidadDePlatos;
                    //guardando datos en PlatoSolicitado de OrdenDeCompra
                    strcpy(arrRepartidor[i].ordenesDeCompra[j].platosSolicitados[cantPlatos].codigo,pedido.codigoDelPlato);
                    arrRepartidor[i].ordenesDeCompra[j].platosSolicitados[cantPlatos].cantidad=pedido.cantidad;
                    arrRepartidor[i].ordenesDeCompra[j].platosSolicitados[cantPlatos].precio=pedido.precio;

                    arrRepartidor[i].ordenesDeCompra[j].montoPorCobrar+=pedido.precio*pedido.cantidad;
                    arrRepartidor[i].ordenesDeCompra[j].cantidadDePlatos++;
                    return;
                }
            }
            //En caso no hallan ordenes gaurdadas
            cantOrden=arrRepartidor[i].cantidadDeOrdenes;
            arrRepartidor[i].ordenesDeCompra[cantOrden].dniDelCliente=pedido.dniDelCliente;
            arrRepartidor[i].ordenesDeCompra[cantOrden].distancia=pedido.distanciaARecorrer;
            //Agregando un plato en caso de una orden
            strcpy(arrRepartidor[i].ordenesDeCompra[cantOrden].platosSolicitados[0].codigo,pedido.codigoDelPlato);
            arrRepartidor[i].ordenesDeCompra[cantOrden].platosSolicitados[0].cantidad=pedido.cantidad;
            arrRepartidor[i].ordenesDeCompra[cantOrden].platosSolicitados[0].precio=pedido.precio;
            //Ordenes
            arrRepartidor[i].ordenesDeCompra[cantOrden].cantidadDePlatos=1;
            arrRepartidor[i].ordenesDeCompra[cantOrden].montoPorCobrar=pedido.precio*pedido.cantidad;

            arrRepartidor[i].cantidadDeOrdenes++;
        }
    }
}
void operator!(OrdenDeCompra &orden) {
    if (orden.distancia<=8) {
        orden.pagoPorEnvio=10.50;
    }else if (orden.distancia>8 and orden.distancia<=12) {
        orden.pagoPorEnvio=14.80;
    } else if (orden.distancia>12 and orden.distancia<=20) {
        orden.pagoPorEnvio=23.60;
    }else {
        orden.pagoPorEnvio=31.70;
    }
}
void operator!(Repartidor &repartidor) {
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        repartidor.pagoPorEntregas+=repartidor.ordenesDeCompra[i].pagoPorEnvio;
    }
}

void operator<<(ofstream &archRepPlato,const Plato &plato) {
    archRepPlato<<left<<setw(7)<<plato.codigo<<setw(60)<<plato.nombre<<right<<setw(15)<<plato.precio
    <<setw(15)<<plato.totalDePedidos<<setw(15)<<plato.totalRecaudado<<endl;
}
void operator<<(ofstream &archRepRepart,const Repartidor &repartidor) {
    OrdenDeCompra orden{};
    PlatoSolicitado platoSolicitado{};
    double total;

    archRepRepart<<left<<setw(8)<<repartidor.codigo<<setw(60)<<repartidor.nombre<<setw(16)
    <<repartidor.tipoDeVehiculo<<right<<setw(15)<<repartidor.pagoPorEntregas<<endl;
    archRepRepart<<"OREDENES ENTREGADAS: "<<endl;
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        orden=repartidor.ordenesDeCompra[i];
        archRepRepart<<orden.dniDelCliente<<setw(15)<<orden.distancia<<setw(15)<<orden.montoPorCobrar
        <<setw(15)<<orden.pagoPorEnvio<<endl;
        archRepRepart<<"PLATOS SOLICITADOS: "<<endl;
        for (int j=0;j<orden.cantidadDePlatos;j++) {
            platoSolicitado=orden.platosSolicitados[j];
            total=platoSolicitado.precio*platoSolicitado.cantidad;
            archRepRepart<<"- "<<platoSolicitado.codigo<<setw(15)<<platoSolicitado.precio
            <<setw(15)<<platoSolicitado.cantidad<<setw(15)<<total<<endl;
        }
    }
}


//Aux
void abrirIn(ifstream &archEntrada,const char * nombArch) {
    archEntrada.open(nombArch,ios::in);
    if (not archEntrada.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &archReporte,const char * nombArch) {
    archReporte.open(nombArch,ios::out);
    if (not archReporte.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
}

