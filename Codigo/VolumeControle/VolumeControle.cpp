//
// Created by LABCFD on 7/11/2024.
//

#include <cmath>
#include <memory>
#include "VolumeControle.h"
#include "Geometrias/CuboPerfeito.h"
#include "Geometrias/GeometriaBase.h"
#include "Fibras/FibraBase.h"
#include "Distribuicoes/DistribuicaoBase.h"
#include "Distribuicoes/DistribuicaoUniforme.h"


/// Construtor
VolumeControle::VolumeControle(GeometriaBase *geometria, FibraBase *fibra) :
geometria(geometria),
fibra(fibra)
{
}


void VolumeControle::construirModelo(DadosEntradaModelo::TipoDistribuicao tipoDistribuicao) {
    /// TODO: Aplicar a distribuicao no calculo
//    std::unique_ptr<DistribuicaoBase> modelo;
//    // TODO: Criar as demais distribuicoes
//    switch (tipoDistribuicao) {
//        case DadosEntradaModelo::TipoDistribuicao::UniformeUmaDirecao:
//            modelo = std::make_unique<DistribuicaoUniforme>();
//            break;
//        default:
//            ;
//    }
//    modelo->calcular();
}


/// Calculadoras
void VolumeControle::calcularPorosidade() {
    /// TODO: Implementar o calculo da porosidade
    setPorosidade(0.907);
}

void VolumeControle::calcularNumFibras() {
    setNumFibras((int) round(geometria->getVolume() * (1 - getPorosidade()) / fibra->getVolume()));
}

void VolumeControle::calcularAreaTotalTransferencia() {
    setAreaTransferenciaTotal(numFibras * fibra->getAreaSuperficial());
}


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
