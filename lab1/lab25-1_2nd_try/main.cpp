#include <iostream>
#include <cstring>

using namespace std;

#include "Estructuras.h"
#include "funciones.h"

int main() {
    CadenaDeCaracteres cadena,cad1;
    //incializacion
    !cadena;
    !cad1;
    //asignacion
    cadena<="Valentina Gutierrez";
    cadena<=10;
    cad1<="Andres Garcia";
    cadena<=cad1;
    //concatenacion
    cadena+="Naomi Gutierrez";
    cadena+=cad1;

    //comparar
    cadena=="Juan Garcia";



    return 0;
}
