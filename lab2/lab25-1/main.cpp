#include <iostream>
#include <fstream>
#include <cstring>

#include "Bibliotecas/faltas.h"

using namespace std;

#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/faltas.h"

int main() {
    Faltas faltas{};
    cargar_faltas_de_los_conductores("Archivos/Faltas.csv",faltas);


    return 0;
}
