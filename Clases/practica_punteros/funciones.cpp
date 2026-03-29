//
// Created by ANTONIO on 29/03/2026.
//

#include "funciones.h"

#include <iostream>
#include <ostream>

using namespace std;

void incrementarPorValor(int *x) {
    *x=*x+1;
    cout<<"Direccion a la que apunta x"<<x<<endl;
    cout<<"Direccion de x"<<&x<<endl;
}
void incrementarPorRef(int *&x) {
    *x=*x+1;
    delete x;
    x=new int(20);

}
