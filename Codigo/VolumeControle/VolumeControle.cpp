/**
 * @file VolumeControle.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <cmath>
#include <memory>
#include "../Entrada/DadosEntradaModelo.h"
#include "VolumeControle.h"
#include "Geometrias/GeometriaBase.h"
#include "Fibras/FibraBase.h"
#include "Distribuicoes/DistribuicaoBase.h"
#include "Distribuicoes/DistribuicaoUniforme.h"


/**
 * @brief Construtor do volume de controle.
 * 
 * @param geometria : Ponteiro para um objeto da classe de geometria do volume de controle.
 * @param fibra : Ponteiro para um objeto da classe de geometria da fibra.
 * @param entrada : Ponteiro para um objeto da classe de dados de entrada.
 */
VolumeControle::VolumeControle(const GeometriaBase *geometria,
                               const FibraBase *fibra,
                               const DadosEntradaModelo *entrada) :
    geometria(geometria),
    fibra(fibra),
    entrada(entrada)
{
}

/**
 * @brief Método para construir o modelo de cálculos para o volume de controle, levando em conta a distribuição de fibras escolhida.
 */
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

/**
 * @brief Calcula a porosidade a partir do parâmetro de empacotamento, definido na classe de entrada.
 */
void VolumeControle::calcularPorosidade() {
    setPorosidade(1 - entrada->getEmpacotamento());
}

/**
 * @brief Calcula a porosidade a partir dos volumes do volume de controle e da fibra, e da porosidade, calculada previamente pela propria classe.
 */
void VolumeControle::calcularNumFibras() {
    setNumFibras((int) round(geometria->getVolume() * (1 - getPorosidade()) / fibra->getVolume()));
}

/**
 * @brief Calcula a área total de transferência, com base no número de fibras, calculado anteriormente pela própria classe, e na área de superfície de cada fibra.
 */
void VolumeControle::calcularAreaTotalTransferencia() {
    setAreaTransferenciaTotal(numFibras * fibra->getAreaSuperficial());
}

/// TODO: Implementar os cálculos para diferentes distribuições


/**
 * @brief Define um novo valor para a variável 'porosidade'
 * @param valor : Nova porosidade calculada.
 */
void VolumeControle::setPorosidade(double valor) {
    porosidade = valor;
}

/**
 * @brief Define um novo valor para a variável 'numFibras'
 * @param valor : Novo número de fibras calculado.
 */
void VolumeControle::setNumFibras(int valor) {
    numFibras = valor;
}

/**
 * @brief Define um novo valor para a variável 'areaTransferenciaTotal'
 * @param valor : Nova área total de transferência calculada.
 */
void VolumeControle::setAreaTransferenciaTotal(double valor) {
    areaTransferenciaTotal = valor;
}

/**
 * @brief Retorna a porosidade calculada.
 * @return double 
 */
double VolumeControle::getPorosidade() const {
    return porosidade;
}

/**
 * @brief Retorna o número de fibras calculado.
 * @return int 
 */
int VolumeControle::getNumFibras() const {
    return numFibras;
}

/**
 * @brief Retorna a área total de transferência calculada.
 * @return double 
 */
double VolumeControle::getAreaTransferenciaTotal() const {
    return areaTransferenciaTotal;
}
