#include <fstream>
#include <iostream>
#include <cstring>

#include "Biblioteca/AperturaDeArchivos.h"

using namespace std;

#include "Estructuras.h"
#include "funciones.h"



int main() {
    ifstream archLibro,archCliente;

    abrirArch(archLibro,"Archivos/Libros.csv");
    abrirArch(archCliente,"Archivos/Cientes.csv");

    Libro arrLibros[300],libro1{};
    Cliente cliente1{};

    archLibro>>libro1;

    archCliente>>cliente1;




    return 0;
}
