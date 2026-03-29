#include <iostream>

#include "funciones.h"

using namespace std;

int main() {

    int *p=new int(5);

    incrementarPorValor(p);

    cout<<*p<<endl;
    cout<<"Direccion a la que apunta p: "<<p<<endl;
    cout<<"Direccion de p: "<<&p<<endl;

    *p=*p+2;
    cout<<"Direccion a la que apunta p: "<<p<<endl;
    cout<<"Direccion de p: "<<&p<<endl;

    incrementarPorRef(p);

    cout<<*p<<endl;
    cout<<"Direccion a la que apunta p: "<<p<<endl;
    cout<<"Direccion de p: "<<&p<<endl;

    return 0;
}
