//
// Created by ANTONIO on 9/04/2026.
//

#include <iostream>

#include "Funciones.h"

#include <cstring>
#include <fstream>
#include <iomanip>

#include "Estructuras.h"

using namespace std;
//sobrecarga

//Lectura
void operator>>(ifstream &archPlato,Plato &plato) {
    //archPlato>>plato
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
    archRepartidor.getline(repartidor.codigo,7,',');
    if (archRepartidor.eof())return;
    archRepartidor.getline(repartidor.nombre,60,',');
    archRepartidor.getline(repartidor.tipoDeVehiculo,15);

    repartidor.cantidadDeOrdenes=0;
    repartidor.pagoPorEntregas=0;
}

void operator>>(ifstream &archPedido,Pedido &pedido) {
    archPedido>>pedido.dniDelCliente;
    if (archPedido.eof())return;
    archPedido>>pedido.codigoDelPlato>>pedido.cantidad>>pedido.codigoDelRepartidor>>pedido.distanciaARecorrer;

    pedido.precio=0;
}
//Operaciones
bool operator<=(Pedido &pedido,Plato *arrPlatos) {
    for (int i=0;strcmp(arrPlatos[i].codigo,"FIN")!=0;i++) {
        if (strcmp(arrPlatos[i].codigo,pedido.codigoDelPlato)==0) {
            pedido.precio=arrPlatos[i].precio;
            arrPlatos[i].totalDePedidos++;
            arrPlatos[i].totalRecaudado+=arrPlatos[i].precio;
            return true;
        }
    }
    return false;
}
void operator<=(Repartidor *arrRepartidores,Pedido &pedido) {
    int cantOrden,cantPlatos;

    for (int i=0;strcmp(arrRepartidores[i].codigo,"FIN")!=0;i++) {
        if (strcmp(arrRepartidores[i].codigo,pedido.codigoDelRepartidor)==0) {
            for (int j=0;j<arrRepartidores[i].cantidadDeOrdenes;j++) {
                if (arrRepartidores[i].ordenesDeCompra[j].dniDelCliente==pedido.dniDelCliente) {
                    //agregando platos a ordenes
                    cantPlatos=arrRepartidores[i].ordenesDeCompra[j].cantidadDePlatos;
                    strcpy(arrRepartidores[i].ordenesDeCompra[j].platosSolicitados[cantPlatos].codigo,pedido.codigoDelPlato);
                    arrRepartidores[i].ordenesDeCompra[j].platosSolicitados[cantPlatos].precio=pedido.precio;
                    arrRepartidores[i].ordenesDeCompra[j].platosSolicitados[cantPlatos].cantidad=pedido.cantidad;
                    //agregando los datos a las ordenes
                    arrRepartidores[i].ordenesDeCompra[j].montoPorCobrar+=pedido.precio*pedido.cantidad;
                    arrRepartidores[i].ordenesDeCompra[j].cantidadDePlatos++;
                    return;
                }
            }
            //por si no se encuentra cliente
            cantOrden=arrRepartidores[i].cantidadDeOrdenes;
            //datos Orden
            arrRepartidores[i].ordenesDeCompra[cantOrden].dniDelCliente=pedido.dniDelCliente;
            arrRepartidores[i].ordenesDeCompra[cantOrden].distancia=pedido.distanciaARecorrer;
            //datos del Plato
            strcpy(arrRepartidores[i].ordenesDeCompra[cantOrden].platosSolicitados[0].codigo,pedido.codigoDelPlato);
            arrRepartidores[i].ordenesDeCompra[cantOrden].platosSolicitados[0].precio=pedido.precio;
            arrRepartidores[i].ordenesDeCompra[cantOrden].platosSolicitados[0].cantidad=pedido.cantidad;
            //actualizar datos
            arrRepartidores[i].ordenesDeCompra[cantOrden].montoPorCobrar=pedido.precio*pedido.cantidad;
            arrRepartidores[i].ordenesDeCompra[cantOrden].cantidadDePlatos=1;
            arrRepartidores[i].cantidadDeOrdenes++;
        }
    }
}
void operator!(OrdenDeCompra &ordenDeCompra) {
    if (ordenDeCompra.distancia>20) {
        ordenDeCompra.pagoPorEnvio=31.70;
    }else if (ordenDeCompra.distancia>12 and ordenDeCompra.distancia<=20) {
        ordenDeCompra.pagoPorEnvio=23.60;
    }else if (ordenDeCompra.distancia>8 and ordenDeCompra.distancia<=12) {
        ordenDeCompra.pagoPorEnvio=14.80;
    }else {
        ordenDeCompra.pagoPorEnvio=10.50;
    }
}
void operator!(Repartidor &repartidor) {
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        repartidor.pagoPorEntregas+=repartidor.ordenesDeCompra[i].pagoPorEnvio;
    }
}
void operator<<(ofstream &archRepPlato,const Plato &plato) {
    archRepPlato<<fixed<<setprecision(2);
    archRepPlato<<left<<setw(8)<<plato.codigo<<setw(60)<<plato.nombre<<right<<setw(15)<<plato.precio
        <<setw(15)<<plato.totalDePedidos<<setw(15)<<plato.totalRecaudado<<endl;
}
void operator<<(ofstream &archRepRepar,const Repartidor &repartidor) {
    double total;

    archRepRepar<<fixed<<setprecision(2);
    archRepRepar<<left<<setw(8)<<repartidor.codigo<<setw(60)<<repartidor.nombre<<setw(20)
    <<repartidor.tipoDeVehiculo<<right<<setw(15)<<repartidor.pagoPorEntregas<<endl;
    archRepRepar<<"ORDENES ENTREGADAS: "<<endl;
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        archRepRepar<<repartidor.ordenesDeCompra[i].dniDelCliente<<setw(15)
        <<repartidor.ordenesDeCompra[i].distancia<<setw(15)<<repartidor.ordenesDeCompra[i].montoPorCobrar
        <<setw(15)<<repartidor.ordenesDeCompra[i].pagoPorEnvio<<endl;
        archRepRepar<<"PAGOS SOLICITADOS: "<<endl;
        for (int j=0;j<repartidor.ordenesDeCompra[i].cantidadDePlatos;j++) {
            total=repartidor.ordenesDeCompra[i].platosSolicitados[j].cantidad*repartidor.ordenesDeCompra[i].platosSolicitados[j].precio;
            archRepRepar<<"- "<<left<<setw(8)<<repartidor.ordenesDeCompra[i].platosSolicitados[j].codigo<<right
            <<setw(8)<<repartidor.ordenesDeCompra[i].platosSolicitados[j].precio<<setw(8)
            <<repartidor.ordenesDeCompra[i].platosSolicitados[j].cantidad<<setw(5)<<total<<endl;
        }
    }
}


//Aux
void abrirIn(ifstream &archEntrada,const char *nombArch) {
    archEntrada.open(nombArch,ios::in);
    if (not archEntrada.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }

}
void abrirOut(ofstream &archReporte,const char *nombArch) {
    archReporte.open(nombArch,ios::out);
    if (not archReporte.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }

}