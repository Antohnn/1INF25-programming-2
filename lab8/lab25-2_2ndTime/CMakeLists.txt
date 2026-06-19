cmake_minimum_required(VERSION 4.2)
project(lab25_2_2ndTime)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2_2ndTime main.cpp
        Bibliotecas/Metrica/Metrica.cpp
        Bibliotecas/Metrica/Metrica.h
        Bibliotecas/Metrica/MetricaBasica.cpp
        Bibliotecas/Metrica/MetricaBasica.h
        Bibliotecas/Metrica/MetricaEgagement.cpp
        Bibliotecas/Metrica/MetricaEgagement.h
        Bibliotecas/Metrica/MetricaCalidad.cpp
        Bibliotecas/Metrica/MetricaCalidad.h
        Bibliotecas/Lista/Nodo.cpp
        Bibliotecas/Lista/Nodo.h
        Bibliotecas/Lista/Lista.cpp
        Bibliotecas/Lista/Lista.h
        Bibliotecas/Metrica/enum.h
        Bibliotecas/AdministrarMetricas.cpp
        Bibliotecas/AdministrarMetricas.h)
