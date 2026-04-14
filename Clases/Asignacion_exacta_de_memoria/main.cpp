#include <iostream>
#include <cstring>

#include "Funciones.h"

using namespace std;


int main() {
    int *numeros,n;

    leerNumeroExactos(numeros,n,"Archivos/numeros.txt");

    for (int i=0;i<n;i++) {
        cout<<numeros[i]<<endl;
    }

    return 0;
}
