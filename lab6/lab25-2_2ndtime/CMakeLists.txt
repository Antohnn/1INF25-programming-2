cmake_minimum_required(VERSION 4.2)
project(lab25_2_2ndtime)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2_2ndtime main.cpp
        Bibliotecas/Metrica/Metrica.cpp
        Bibliotecas/Metrica/Metrica.h
        Bibliotecas/Metrica/MetricaBasica.cpp
        Bibliotecas/Metrica/MetricaBasica.h
        Bibliotecas/Metrica/MetricaEngagement.cpp
        Bibliotecas/Metrica/MetricaEngagement.h
        Bibliotecas/Metrica/MetricaCalidad.cpp
        Bibliotecas/Metrica/MetricaCalidad.h
        Bibliotecas/Streamer/Streamer.cpp
        Bibliotecas/Streamer/Streamer.h
        Bibliotecas/Streamer/StreamerGratuito.cpp
        Bibliotecas/Streamer/StreamerGratuito.h)
