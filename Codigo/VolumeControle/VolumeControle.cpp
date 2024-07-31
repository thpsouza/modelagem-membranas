//
// Created by LABCFD on 7/11/2024.
//

#include <cmath>
#include <memory>
#include "../Entrada/DadosEntradaModelo.h"
#include "VolumeControle.h"
#include "Geometrias/GeometriaBase.h"
#include "Fibras/FibraBase.h"
#include "Distribuicoes/DistribuicaoBase.h"
#include "Distribuicoes/DistribuicaoUniforme.h"


/// Construtor
VolumeControle::VolumeControle(const GeometriaBase *geometria,
                               const FibraBase *fibra,
                               const DadosEntradaModelo *entrada) :
    geometria(geometria),
    fibra(fibra),
    entrada(entrada)
{
}


void VolumeControle::construirModelo() {
    std::unique_ptr<DistribuicaoBase> modelo;
    /// TODO: Criar as demais distribuicoes
    switch (entrada->getDistribuicao()) {
        case DadosEntradaModelo::TipoDistribuicao::UniformeUmaDirecao:
            modelo = std::make_unique<DistribuicaoUniforme>();
            break;
        default:
            ;
    }
    /// TODO: Implementar os cálculos para diferentes distribuições
    // Na prática, o modelo de cálculo adotado já assume uma distribuição uniforme unidimensional; portanto, não serão
    // implementadas, por enquanto, as alterações necessárias para uma distribuição qualquer.
    //modelo->aplicar();
    ///
}


/// Calculadoras - TODO: Implementar os cálculos para diferentes distribuições
void VolumeControle::calcularPorosidade() {
    setPorosidade(1 - entrada->getEmpacotamento());
}

void VolumeControle::calcularNumFibras() {
    setNumFibras((int) round(geometria->getVolume() * (1 - getPorosidade()) / fibra->getVolume()));
}

void VolumeControle::calcularAreaTotalTransferencia() {
    setAreaTransferenciaTotal(numFibras * fibra->getAreaSuperficial());
}
///


/// Setters and Getters
void VolumeControle::setPorosidade(double valor) {
    porosidade = valor;
}

void VolumeControle::setNumFibras(int valor) {
    numFibras = valor;
}

void VolumeControle::setAreaTransferenciaTotal(double valor) {
    areaTransferenciaTotal = valor;
}

double VolumeControle::getPorosidade() const {
    return porosidade;
}

int VolumeControle::getNumFibras() const {
    return numFibras;
}

double VolumeControle::getAreaTransferenciaTotal() const {
    return areaTransferenciaTotal;
}
