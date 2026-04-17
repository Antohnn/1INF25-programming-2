cmake_minimum_required(VERSION 4.2)
project(lab25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_1 main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
        Bibliotecas/conductores.h
        Bibliotecas/infracciones.h
        Bibliotecas/faltas.h
)
