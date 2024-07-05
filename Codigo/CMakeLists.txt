cmake_minimum_required(VERSION 3.27)
project(New_folder)

set(CMAKE_CXX_STANDARD 17)

include_directories(Entrada)
include_directories(Saida)

add_executable(New_folder
        Entrada/DadosEntradaModelo.cpp
        Entrada/DadosEntradaModelo.h
        Saida/DadosSaidaModelo.cpp
        Saida/DadosSaidaModelo.h
        main.cpp
        Gerador/GeradorDadosSaida.h
        CalculadoraDadosSaida.h
        Gerador/GeradorDadosSaida.cpp
        CalculadoraDadosSaida.cpp
        CalculadoraCuboPerfeitoDadosSaida.h
        CalculadoraCuboPerfeitoDadosSaida.cpp)
