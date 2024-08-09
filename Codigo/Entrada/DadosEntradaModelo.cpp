/**
 * @file DadosEntradaModelo.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "DadosEntradaModelo.h"

/**
 * @brief Construtor parcial da classe de entrada de dados, com entrada de fator de empacotamento, e razão cf/df
 *
 * @param geometria : Especificação da geometria do volume de controle.
 * @param distribuicao : Especificação do tipo de distribuição de fibras ao longo do volume de controle.
 * @param empacotamento : Fator de empacotamento das fibras no volume de controle.
 * @param volumeVC : Volume do volume de controle.
 * @param razaoComprimentoDiametroFibra : Razão entre comprimento da fibra e do diâmetro da fibra (TEMPORÁRIO).
 */
DadosEntradaModelo::DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                                       double empacotamento, double volumeVC, double razaoComprimentoDiametroFibra):
        geometria(geometria),
        distribuicao(distribuicao),
        empacotamento(empacotamento),
        volumeVC(volumeVC),
        razaoComprimentoDiametroFibra(razaoComprimentoDiametroFibra)
{
}

/**
 * @brief Construtor parcial da classe de entrada de dados, com entrada de área e número de fibras.
 *
 * @param geometria : Especificação da geometria do volume de controle.
 * @param distribuicao : Especificação do tipo de distribuição de fibras ao longo do volume de controle.
 * @param areaTotalMembrana : Área total de fibras no módulo de membranas.
 * @param numTotalFibras : Número de fibras total no módulo de membranas.
 * @param diametroFibra : Diâmetro médio das fibras no volume de controle.
 */
DadosEntradaModelo::DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                                       double areaTotalMembrana, int numTotalFibras, double diametroFibra):
        geometria(geometria),
        distribuicao(distribuicao),
        areaTotalMembrana(areaTotalMembrana),
        numTotalFibras(numTotalFibras),
        diametroFibra(diametroFibra)
{
}

/**
 * @brief Construtor completo da classe de entrada de dados.
 *
 * @param geometria : Especificação da geometria do volume de controle.
 * @param distribuicao : Especificação do tipo de distribuição de fibras ao longo do volume de controle.
 * @param areaTotalMembrana : Área total de fibras no módulo de membranas.
 * @param numTotalFibras : Número de fibras total no módulo de membranas.
 * @param diametroFibra : Diâmetro médio das fibras no volume de controle.
 * @param volumeTotalModulo : Volume total do módulo de membranas.
 * @param volumeVC : Volume do volume de controle.
 * @param empacotamento : Fator de empacotamento das fibras no volume de controle.
 * @param razaoComprimentoDiametroFibra : Razão entre comprimento da fibra e do diâmetro da fibra (TEMPORÁRIO).
 */
DadosEntradaModelo::DadosEntradaModelo(DadosEntradaModelo::TipoGeometria geometria,
                                       DadosEntradaModelo::TipoDistribuicao distribuicao,
                                       double areaTotalMembrana, int numTotalFibras, double diametroFibra,
                                       double volumeTotalModulo, double volumeVC,
                                       double empacotamento, double razaoComprimentoDiametroFibra) :

        geometria(geometria),
        distribuicao(distribuicao),
        areaTotalMembrana(areaTotalMembrana),
        numTotalFibras(numTotalFibras),
        diametroFibra(diametroFibra),
        volumeTotalModulo(volumeTotalModulo),
        volumeVC(volumeVC),
        empacotamento(empacotamento),
        razaoComprimentoDiametroFibra(razaoComprimentoDiametroFibra)
{
}

/**
 * @return Tipo de geometria do volume de controle.
 */
DadosEntradaModelo::TipoGeometria DadosEntradaModelo::getGeometria() const {
    return geometria;
}

/**
 * @return Tipo de distribuição de fibras no volume de controle.
 */
DadosEntradaModelo::TipoDistribuicao DadosEntradaModelo::getDistribuicao() const {
    return distribuicao;
}

/**
 * @return Fator de empacotamento das fibras no volume de controle.
 */
double DadosEntradaModelo::getEmpacotamento() const {
    return empacotamento;
}

/**
 * @return Área total de transferência no módulo de membranas.
 */
double DadosEntradaModelo::getAreaTotalMembrana() const {
    return areaTotalMembrana;
}

/**
 * @return Número total de fibras no módulo de membranas.
 */
int DadosEntradaModelo::getNumTotalFibras() const {
    return numTotalFibras;
}

/**
 * @return Diâmetro médio das fibras no volume de controle.
 */
double DadosEntradaModelo::getDiametroFibra() const {
    return diametroFibra;
}

/**
 * @return Volume total do módulo de membranas
 */
double DadosEntradaModelo::getVolumeTotalModulo() const {
    return volumeTotalModulo;
}

/**
 * @return Volume do volume de controle.
 */
double DadosEntradaModelo::getVolumeVC() const {
    return volumeVC;
}



