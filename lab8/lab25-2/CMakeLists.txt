cmake_minimum_required(VERSION 4.2)
project(lab25_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2 main.cpp
        Bibliotecas/Metrica/Metrica.cpp
        Bibliotecas/Metrica/Metrica.h
        Bibliotecas/Metrica/MetricaBasica.cpp
        Bibliotecas/Metrica/MetricaBasica.h
        Bibliotecas/Metrica/MetricaEngagement.cpp
        Bibliotecas/Metrica/MetricaEngagement.h
        Bibliotecas/Metrica/MetricaCalidad.cpp
        Bibliotecas/Metrica/MetricaCalidad.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Lista.cpp
        Bibliotecas/Lista.h
        Bibliotecas/Metrica/enum.h
        Bibliotecas/AdministrarMetricas.cpp
        Bibliotecas/AdministrarMetricas.h)
