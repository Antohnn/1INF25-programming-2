cmake_minimum_required(VERSION 4.2)
project(lab25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_1 main.cpp
        Clases/Infraccion.cpp
        Clases/Infraccion.h
        Clases/Empresa.cpp
        Clases/Empresa.h
        Clases/Multa.cpp
        Clases/Multa.h
        Clases/MinisterioDeTransporte.cpp
        Clases/MinisterioDeTransporte.h
)
