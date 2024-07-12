//
// Created by LABCFD on 7/5/2024.
//

#include "CalculadoraCuboPerfeitoDadosSaida.h"
#include "../Saida/DadosSaidaModelo.h"
#include "../VolumeControle/VolumeControle.h"


CalculadoraCuboPerfeitoDadosSaida::CalculadoraCuboPerfeitoDadosSaida(DadosEntradaModelo::TipoDistribuicao distribuicao)
        : CalculadoraDadosSaida(distribuicao) {
}


DadosSaidaModelo *CalculadoraCuboPerfeitoDadosSaida::calcular() {

    double teste = 10.;
    dadosPtr->setPorosidade(teste);


    /// TODO: Realizar os calculos/operacoes
    VolumeControle VC;
    VC.construirModelo(DadosEntradaModelo::TipoGeometria::CuboPerfeito, distribuicao);


    ///

    return dadosPtr.release();
}


