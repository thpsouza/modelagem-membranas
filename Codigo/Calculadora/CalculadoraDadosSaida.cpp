//
// Created by LABCFD on 7/5/2024.
//

#include "CalculadoraDadosSaida.h"
#include "../Saida/DadosSaidaModelo.h"

CalculadoraDadosSaida::CalculadoraDadosSaida(DadosEntradaModelo::TipoDistribuicao distribuicao) :
dadosPtr(std::make_unique<DadosSaidaModelo>()),
distribuicao(distribuicao)
{

}

DadosSaidaModelo *CalculadoraDadosSaida::calcular() {
    return nullptr;
}

