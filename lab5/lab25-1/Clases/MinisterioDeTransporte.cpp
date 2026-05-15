//
// Created by ANTONIO on 14/05/2026.
//
#include <iostream>

#include "Infraccion.h"

using namespace std;

#include "MinisterioDeTransporte.h"

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones=nullptr;
    numInf=0;
    numEmp=0;
}
MinisterioDeTransporte::~MinisterioDeTransporte() {
    delete[] infracciones;
}