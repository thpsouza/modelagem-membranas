//
// Created by LABCFD on 7/5/2024.
//

#include "CalculadoraDadosSaida.h"
#include "../Saida/DadosSaidaModelo.h"

CalculadoraDadosSaida::CalculadoraDadosSaida() :
dadosPtr(std::make_unique<DadosSaidaModelo>())
{

}

DadosSaidaModelo *CalculadoraDadosSaida::calcular() {
    return nullptr;
}