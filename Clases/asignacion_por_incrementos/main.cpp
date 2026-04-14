#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "Funciones.h"

int main() {
    int *numeros,cantDatos;

    guardarDatosPorIncremento(numeros,cantDatos,"Archivos/numeros.txt");

    return 0;
}
