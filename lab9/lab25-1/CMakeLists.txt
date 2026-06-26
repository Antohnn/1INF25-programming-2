cmake_minimum_required(VERSION 4.2)
project(lab25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_1 main.cpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.h
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.h
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.h
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.h
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.h)
