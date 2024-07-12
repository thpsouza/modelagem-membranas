//
// Created by LABCFD on 7/5/2024.
//

#include "CalculadoraCuboPerfeitoDadosSaida.h"
#include "../Saida/DadosSaidaModelo.h"

CalculadoraCuboPerfeitoDadosSaida::CalculadoraCuboPerfeitoDadosSaida() : CalculadoraDadosSaida() {

}

DadosSaidaModelo *CalculadoraCuboPerfeitoDadosSaida::calcular() {

    double teste = 10.;

    /// TODO: Realizar os calculos/operacoes
    dadosPtr->setPorosidade(teste);
    ///

    return dadosPtr.release();
}

