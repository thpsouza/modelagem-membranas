//
// Created by LABCFD on 7/5/2024.
//

#include "CalculadoraCuboPerfeitoDadosSaida.h"
#include "../Saida/DadosSaidaModelo.h"

DadosSaidaModelo *CalculadoraCuboPerfeitoDadosSaida::calcular() {
    DadosSaidaModelo dados;
    DadosSaidaModelo *dadosPtr = &dados;

    /// TODO: Realizar os calculos/operacoes
    dados.setPorosidade(10);
    ///

    return dadosPtr;
}
