cmake_minimum_required(VERSION 4.2)
project(lab25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_1 main.cpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.h
        Bibliotecas/enums.h
        Bibliotecas/BibliotecaConductores.cpp
        Bibliotecas/BibliotecaConductores.h
        Bibliotecas/BibliotecaInfracciones.cpp
        Bibliotecas/BibliotecaInfracciones.h
)
