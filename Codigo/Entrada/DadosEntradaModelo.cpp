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
 * @param volume : Volume do volume de controle.
 * @param razaoComprimentoDiametroFibra : Razão entre comprimento da fibra e do diâmetro da fibra (TEMPORÁRIO).
 */
DadosEntradaModelo::DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                                       double empacotamento, double volume, double razaoComprimentoDiametroFibra):
        geometria(geometria),
        distribuicao(distribuicao),
        empacotamento(empacotamento),
        volume(volume),
        razaoComprimentoDiametroFibra(razaoComprimentoDiametroFibra)
{
}

/**
 * @brief Construtor parcial da classe de entrada de dados, com entrada de área e número de fibras.
 *
 * @param geometria : Especificação da geometria do volume de controle.
 * @param distribuicao : Especificação do tipo de distribuição de fibras ao longo do volume de controle.
 * @param areaMembrana : Área total de fibras no volume de controle.
 * @param numFibras : Número de fibras no volume de controle.
 * @param diametroFibra : Diâmetro médio das fibras no volume de controle.
 */
DadosEntradaModelo::DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                                       double areaMembrana, int numFibras, double diametroFibra):
        geometria(geometria),
        distribuicao(distribuicao),
        areaMembrana(areaMembrana),
        numFibras(numFibras),
        diametroFibra(diametroFibra)
{
}

/**
 * @brief Construtor completo da classe de entrada de dados.
 *
 * @param geometria : Especificação da geometria do volume de controle.
 * @param distribuicao : Especificação do tipo de distribuição de fibras ao longo do volume de controle.
 * @param areaMembrana : Área total de fibras no volume de controle.
 * @param numFibras : Número de fibras no volume de controle.
 * @param diametroFibra : Diâmetro médio das fibras no volume de controle.
 * @param empacotamento : Fator de empacotamento das fibras no volume de controle.
 * @param volume : Volume do volume de controle.
 * @param razaoComprimentoDiametroFibra : Razão entre comprimento da fibra e do diâmetro da fibra (TEMPORÁRIO).
 */
DadosEntradaModelo::DadosEntradaModelo(DadosEntradaModelo::TipoGeometria geometria,
                                       DadosEntradaModelo::TipoDistribuicao distribuicao, double areaMembrana,
                                       int numFibras, double diametroFibra, double empacotamento, double volume,
                                       double razaoComprimentoDiametroFibra) :
        geometria(geometria),
        distribuicao(distribuicao),
        areaMembrana(areaMembrana),
        numFibras(numFibras),
        diametroFibra(diametroFibra),
        empacotamento(empacotamento),
        volume(volume),
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
 * @return Área total de transferência no volume de controle.
 */
double DadosEntradaModelo::getAreaMembrana() const {
    return areaMembrana;
}

/**
 * @return Número de fibras no volume de controle.
 */
int DadosEntradaModelo::getNumFibras() const {
    return numFibras;
}

/**
 * @return Diâmetro médio das fibras no volume de controle.
 */
double DadosEntradaModelo::getDiametroFibra() const {
    return diametroFibra;
}

/**
 * @return Volume do volume de controle.
 */
double DadosEntradaModelo::getVolume() const {
    return volume;
}


