cmake_minimum_required(VERSION 4.2)
project(lab23_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab23_2 main.cpp
        Bibliotecas/FlotaGenerica.cpp
        Bibliotecas/FlotaGenerica.h
        Bibliotecas/enums.h
        Bibliotecas/PilaConEnteros.cpp
        Bibliotecas/PilaConEnteros.h)
