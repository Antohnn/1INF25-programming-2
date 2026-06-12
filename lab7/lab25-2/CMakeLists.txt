cmake_minimum_required(VERSION 4.2)
project(lab25_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2 main.cpp
        Bibliotecas/Metrica.cpp
        Bibliotecas/Metrica.h
        Bibliotecas/MetricaBasica.cpp
        Bibliotecas/MetricaBasica.h
        Bibliotecas/MetricaEngagement.cpp
        Bibliotecas/MetricaEngagement.h
        Bibliotecas/MetricaCalidad.cpp
        Bibliotecas/MetricaCalidad.h
        Bibliotecas/streamer/Streamer.cpp
        Bibliotecas/streamer/Streamer.h
        Bibliotecas/streamer/StreamerGratuito.cpp
        Bibliotecas/streamer/StreamerGratuito.h
        Bibliotecas/streamer/StreamerPago.cpp
        Bibliotecas/streamer/StreamerPago.h
        Bibliotecas/enum.h
        Bibliotecas/GestorStreamers.cpp
        Bibliotecas/GestorStreamers.h)
