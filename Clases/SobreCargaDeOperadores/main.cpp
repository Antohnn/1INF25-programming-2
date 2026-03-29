#include <iostream>

#include "Estructuras.h"
#include "funciones.h"

using namespace std;

int main() {
    Cliente cliente1{123456789,20};

    Cliente d=cliente1++;

    cout<<d.edad<<endl;
    cout<<cliente1.edad<<endl;

    ++cliente1;
    cout<<cliente1.edad<<endl;

    cliente1--;
    cout<<cliente1.edad<<endl;

    --cliente1;
    cout<<cliente1.edad<<endl;

    Pedido pedido1{1111111,300};
    Pedido pedido2{1111111,200};

    Pedido pedido3=pedido1+pedido2;
    cout<<endl;
    cout<<cliente1<<pedido3<<endl;

    return 0;
}