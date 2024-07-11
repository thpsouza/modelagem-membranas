cmake_minimum_required(VERSION 3.27)
project(modelagem_membranas)

set(CMAKE_CXX_STANDARD 17)

include_directories(Entrada)
include_directories(Saida)

add_executable(modelagem_membranas main.cpp
        Entrada/DadosEntradaModelo.h
        Entrada/DadosEntradaModelo.cpp
        Saida/DadosSaidaModelo.h
        Saida/DadosSaidaModelo.cpp
        Gerador/GeradorDadosSaida.h
        Gerador/GeradorDadosSaida.cpp
        Modelos/CalculadoraDadosSaida.h
        Modelos/CalculadoraDadosSaida.cpp
        Modelos/CalculadoraCuboPerfeitoDadosSaida.h
        Modelos/CalculadoraCuboPerfeitoDadosSaida.cpp
        VolumeControle/GeometriaBase.h
        VolumeControle/GeometriaBase.cpp
        VolumeControle/CuboPerfeito.h
        VolumeControle/CuboPerfeito.cpp
        VolumeControle/FibraBase.h
        VolumeControle/FibraBase.cpp
        VolumeControle/VolumeControle.h
        VolumeControle/VolumeControle.cpp)
