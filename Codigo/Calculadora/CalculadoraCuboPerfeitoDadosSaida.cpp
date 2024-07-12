//
// Created by LABCFD on 7/5/2024.
//

#include <memory>
#include "CalculadoraCuboPerfeitoDadosSaida.h"
#include "../Saida/DadosSaidaModelo.h"
#include "../VolumeControle/VolumeControle.h"
#include "../VolumeControle/Geometrias/CuboPerfeito.h"
#include "../VolumeControle/Fibras/FibraCilindrica.h"


CalculadoraCuboPerfeitoDadosSaida::CalculadoraCuboPerfeitoDadosSaida(DadosEntradaModelo::TipoDistribuicao distribuicao)
        : CalculadoraDadosSaida(distribuicao) {
}


DadosSaidaModelo *CalculadoraCuboPerfeitoDadosSaida::calcular() {
    /// TODO: Realizar os calculos/operacoes
    CuboPerfeito *cubo;
    FibraCilindrica *fibra;

    /// TODO: Receber do input do usuario os valores do VC
    cubo->setAresta(1.2);
    fibra->setComprimento(1.2);
    fibra->setDiametro(0.012);

    VolumeControle VC {cubo, fibra};
    VC.construirModelo(distribuicao);
    VC.calcularPorosidade();
    VC.calcularNumFibras();
    VC.calcularAreaTotalTransferencia();
    dadosPtr->setAreaTotalTransferencia(VC.getAreaTransferenciaTotal());
    dadosPtr->setPorosidade(VC.getPorosidade());
    dadosPtr->setNumFibras(VC.getNumFibras());
    ///

    return dadosPtr.release();
}


