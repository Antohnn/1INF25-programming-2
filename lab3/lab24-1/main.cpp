#include <iostream>
#include <fstream>

using namespace std;

#include "Bibliotecas/Funciones.h"

int main() {
    void *clientes,*reserva;

    //cargarClientes
    cargarClientes(clientes);
    //mostrarClietes
    mostrarClietes(clientes);
    //crearReserva
    crearReserva(reserva);
    //mostrarReservas
    mostrarReservas(reserva);
    //cargarReserva
    cargarReserva(clientes,reserva);
    //reporteFinal
    reporteFinal(reserva);

    return 0;
}
