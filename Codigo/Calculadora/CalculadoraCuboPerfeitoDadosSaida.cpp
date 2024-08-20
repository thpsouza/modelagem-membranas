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

    /// TODO: Inicializar as classes e realizar os calculos/operacoes no VC
    // Geometria das fibras
    FibraCilindrica fibra {entrada->getDiametroFibra()};
    fibra.setComprimento(cbrt(entrada->getVolumeVC()));
    fibra.calcularAreaSuperficial();
    fibra.calcularVolume();

    // Geometria do volume de controle
    CuboPerfeito cubo {fibra.getComprimento()};
    cubo.calcularVolume();

    // Construção do volume de controle
    VolumeControle VC {&cubo, &fibra, entrada};

    /// TODO: Reduzir o numero de fibras e a área de membrana totais para os valores do VC
    double razaoVolumes = entrada->getVolumeVC()/entrada->getVolumeTotalModulo();
    int numFibras = (int) (entrada->getNumTotalFibras()*razaoVolumes);
    double areaTransferencia = numFibras * fibra.getAreaSuperficial();
    ///

    VC.setNumFibras(numFibras);
    VC.setAreaTransferenciaTotal(areaTransferencia);
    VC.construirModelo();
    VC.calcularEmpacotamento();
    VC.calcularPorosidade();
    ///

    /// TODO: Calcular distancia media entre fibras (depende da distribuicao e da porosidade)
    double distanciaMedia = 0;
    ///


    /// TODO: Passar valores calculados para a classe de saída
    dadosPtr->setAreaTotalTransferencia(VC.getAreaTransferenciaTotal());
    dadosPtr->setPorosidade(VC.getPorosidade());
    dadosPtr->setNumFibras(VC.getNumFibras());
    ///

    return dadosPtr.release();
}


