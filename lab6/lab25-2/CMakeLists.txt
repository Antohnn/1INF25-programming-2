cmake_minimum_required(VERSION 4.2)
project(lab25_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2 main.cpp
        Metrica/Metrica.cpp
        Metrica/Metrica.h
        Metrica/MetricaBasica.cpp
        Metrica/MetricaBasica.h
        Metrica/MetricaEngagement.cpp
        Metrica/MetricaEngagement.h
        Metrica/MetricaCalidad.cpp
        Metrica/MetricaCalidad.h
        Streamer/Streamer.cpp
        Streamer/Streamer.h
        Streamer/StreamerGratuito.cpp
        Streamer/StreamerGratuito.h
        streamer/StreamerPago.cpp
        streamer/StreamerPago.h
        streamer/StreamerPago.cpp
        Bibliotecas/GestorStreamers.cpp
        Bibliotecas/GestorStreamers.h)
