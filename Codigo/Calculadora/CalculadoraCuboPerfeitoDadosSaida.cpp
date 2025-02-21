/**
 * @file CalculadoraCuboPerfeitoDadosSaida.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <cmath>
#include "CalculadoraCuboPerfeitoDadosSaida.h"
#include "../Entrada/DadosEntradaModelo.h"
#include "../Saida/DadosSaidaModelo.h"
#include "../VolumeControle/VolumeControle.h"
#include "../VolumeControle/Geometrias/CuboPerfeito.h"
#include "../VolumeControle/Fibras/FibraCilindrica.h"
#include "../Gerais/gerais.h"


/**
 * @brief Construtor da classe calculadora de dados de saída para uma geometria de cubo perfeito.
 * Passa os parâmetros de entrada para o construtor da classe base.
 *
 * @param entrada : Ponteiro para um objeto da classe de dados de entrada.
 */
CalculadoraCuboPerfeitoDadosSaida::CalculadoraCuboPerfeitoDadosSaida(const DadosEntradaModelo* entrada) :
    CalculadoraDadosSaida(entrada)
{
}

/**
 * @brief Reimplementação do método de cálculo, para a geometria de cubo perfeito.
 *
 * @return DadosSaidaModelo* 
 */
DadosSaidaModelo *CalculadoraCuboPerfeitoDadosSaida::calcular() {
    /// TODO: Modificar dadosEntrada para receber do usuario as propriedades do VC.
    // - Por enquanto, está sendo passado apenas o empacotamento e o valor do volume.
    // - Como a geometria é cúbica e as fibras são cilindros perfeitos, pode-se obter os comprimentos a partir da
    // raiz cúbica do volume.
    // - O diâmetro da fibra poderia ser obtido a partir do empacotamento, pois para essa geometria, este equivale
    // à densidade de fibras na face; porém, isso requere já saber previamente o número de fibras no volume de controle...
    // - Assim, será assumido um diâmetro arbitrário temporariamente.
    // double l = cbrt(entrada->getVolume());
    // double d = l/entrada->razaoComprimentoDiametroFibra;
    ///

    // Variáveis principais
    double volumeVC = entrada->getDadosVC().volumeVC;
    double ladoVC = cbrt(volumeVC);
    double raioFibra = entrada->getDadosVC().diametroFibra/2;
    int numFibras = entrada->getDadosVC().numFibrasVC;

    // Geometria do volume de controle
    CuboPerfeito cubo {ladoVC, volumeVC};

    // Geometria das fibras
    FibraCilindrica fibra {raioFibra*2, ladoVC};
    fibra.calcularAreaSuperficial();
    fibra.calcularVolume();

    // Construção do volume de controle
    VolumeControle VC {&cubo, &fibra, entrada};
    VC.setNumFibras(numFibras);
    VC.construirModelo();

    //// CALCULOS ////
    // std::vector<double[2]> coordenadas = VC.calcularCoordenadasFibras(r, l, Ni);

    // Cálculo da distância media entre fibras, l, (depende da distribuição e da porosidade), para saber em que condição
    // se encontra o sistema.
    // - Se l = 0: Condição de empacotamento máximo teórico
    // - Se l > 0: Condição de subempacotamento
    // - Se l < 0: Condição de superempacotamento
    VC.calcularEspacamentoFibras();
    VC.calcularNumeroEfetivoDeFibras();
    VC.calcularPerimetroTotalFibras();
    VC.calcularEmpacotamento();
    VC.calcularPorosidade();
    VC.calcularAreaTotalTransferencia();

    //// SAIDA DE DADOS ////
    dadosPtr->setEspacamentoFibras(VC.getEspacamentoFibras());
    dadosPtr->setAreaTotalTransferencia(VC.getAreaTransferenciaTotal());
    dadosPtr->setPorosidade(VC.getPorosidade());
    dadosPtr->setNumFibras(VC.getNumFibras());
    return dadosPtr.release();
}


