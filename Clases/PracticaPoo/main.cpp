#include <iostream>

using namespace std;
#include "Clases/Rectangulo.h"

int main() {
    Rectangulo r1;

    char nombre[20]="Rectangulo1";
    r1.setBase(10);
    r1.setAltura(8);
    r1.setNombre(nombre);

    cout<<"Nombre : "<<r1.getNombre()<<endl;
    cout<<"Base: "<<r1.getBase()<<endl;
    cout<<"Altura: "<<r1.getAltura()<<endl;
    cout<<"Area: "<<r1.calcularArea()<<endl;
    cout<<"Perimetro: "<<r1.calcularPerimetro()<<endl;

    return 0;
}
