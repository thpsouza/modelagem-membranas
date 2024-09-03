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
 * @brief
 *
 * @param dadosVC : Estrutura com os dados de entrada relacionados ao volume de controle.
 * @param dadosModulo : Estrutura com os dados de entrada relacionados ao módulo de memberanas como um todo.
 */
DadosEntradaModelo::DadosEntradaModelo(const DadosVC &dadosVC, const DadosModulo &dadosModulo) :
    dadosVC(dadosVC),
    dadosModulo(dadosModulo)
{
}

const DadosEntradaModelo::DadosModulo &DadosEntradaModelo::getDadosModulo() const {
    return dadosModulo;
}

const DadosEntradaModelo::DadosVC &DadosEntradaModelo::getDadosVC() const {
    return dadosVC;
}



///**
// * @brief Construtor completo da classe de entrada de dados.
// *
// * @param geometria : Especificação da geometria do volume de controle.
// * @param distribuicao : Especificação do tipo de distribuição de fibras ao longo do volume de controle.
// * @param numTotalFibras : Número de fibras total no módulo de membranas.
// * @param areaTotalMembrana : Área total de fibras no módulo de membranas.
// * @param volumeTotalModulo : Volume total do módulo de membranas.
// * @param diametroFibra : Diâmetro médio das fibras do módulo de membranas.
// * @param volumeVC : Volume do volume de controle.
// * @param numFibrasVC : Número de fibras dentro do volume de controle.
// * @param distanciaFibras : Distância média entre fibras no volume de controle.
// * @param empacotamento : Fator de empacotamento das fibras no volume de controle.
// * @param razaoComprimentoDiametroFibra : Razão entre comprimento da fibra e do diâmetro da fibra (TEMPORÁRIO).
// */
//DadosEntradaModelo::DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
//                                       int numTotalFibras, double areaTotalMembrana, double volumeTotalModulo, double diametroFibra,
//                                       double volumeVC, int numFibrasVC, double distanciaFibras,
//                                       double empacotamento, double razaoComprimentoDiametroFibra) :
//
//        geometria(geometria),
//        distribuicao(distribuicao),
//        numTotalFibras(numTotalFibras),
//        areaTotalMembrana(areaTotalMembrana),
//        volumeTotalModulo(volumeTotalModulo),
//        diametroFibra(diametroFibra),
//        volumeVC(volumeVC),
//        numFibrasVC(numFibrasVC),
//        distanciaFibras(distanciaFibras),
//        empacotamento(empacotamento),
//        razaoComprimentoDiametroFibra(razaoComprimentoDiametroFibra)
//{
//}
//
//
///**
// * @return Tipo de geometria do volume de controle.
// */
//DadosEntradaModelo::TipoGeometria DadosEntradaModelo::getGeometria() const {
//    return geometria;
//}
//
///**
// * @return Tipo de distribuição de fibras no volume de controle.
// */
//DadosEntradaModelo::TipoDistribuicao DadosEntradaModelo::getDistribuicao() const {
//    return distribuicao;
//}
//
///**
// * @return Fator de empacotamento das fibras no volume de controle.
// */
//double DadosEntradaModelo::getEmpacotamento() const {
//    return empacotamento;
//}
//
///**
// * @return Área total de transferência no módulo de membranas.
// */
//double DadosEntradaModelo::getAreaTotalMembrana() const {
//    return areaTotalMembrana;
//}
//
///**
// * @return Número total de fibras no módulo de membranas.
// */
//int DadosEntradaModelo::getNumTotalFibras() const {
//    return numTotalFibras;
//}
//
///**
// * @return Diâmetro médio das fibras no volume de controle.
// */
//double DadosEntradaModelo::getDiametroFibra() const {
//    return diametroFibra;
//}
//
///**
// * @return Volume total do módulo de membranas
// */
//double DadosEntradaModelo::getVolumeTotalModulo() const {
//    return volumeTotalModulo;
//}
//
///**
// * @return Distância média entre fibras.
// */
//double DadosEntradaModelo::getDistanciaFibras() const {
//    return distanciaFibras;
//}
//
///**
// * @return Número de fibras no volume de controle.
// */
//int DadosEntradaModelo::getNumFibrasVC() const {
//    return numFibrasVC;
//}
//
///**
// * @return Volume do volume de controle.
// */
//double DadosEntradaModelo::getVolumeVC() const {
//    return volumeVC;
//}


