//
// Created by LABCFD on 7/5/2024.
//

#include "CalculadoraDadosSaida.h"
#include "../Entrada/DadosEntradaModelo.h"
#include "../Saida/DadosSaidaModelo.h"

CalculadoraDadosSaida::CalculadoraDadosSaida(const DadosEntradaModelo* entrada) :
    dadosPtr(std::make_unique<DadosSaidaModelo>()),
    entrada(entrada)
{

}

DadosSaidaModelo *CalculadoraDadosSaida::calcular() {
    return nullptr;
}

