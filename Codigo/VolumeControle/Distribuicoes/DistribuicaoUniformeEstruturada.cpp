/**
 * @file DistribuicaoUniforme.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 */

#include "DistribuicaoUniformeEstruturada.h"


DistribuicaoUniformeEstruturada::DistribuicaoUniformeEstruturada() {
}

/**
 * @brief
 * @param ladoVC : Valor do lado do VC.
 * @param raioFibras : Raio médio das fibras.
 * @param numCentroFibras : Número de fibras cujos centros estão contidos no VC.
 * @return
 */
double DistribuicaoUniformeEstruturada::calcularDistanciaFibras(double ladoVC, double raioFibras, int numCentroFibras) {
    return ladoVC / sqrt(numCentroFibras) - 2 * raioFibras;
}

/**
 * @brief Calcula as coordenadas dos centros das fibras para a distribuição uniforme estruturada.
 * @param raioFibra : Raio médio das fibras.
 * @param distanciaEntreFibras : Distância média entre as fibras no VC.
 * @param numCentroFibras : Número de fibras cujos centros estão contidos no VC.
 * @return
 */
std::vector<double[2]>
DistribuicaoUniformeEstruturada::calcularCoordenadasFibras(double raioFibra, double distanciaEntreFibras,
                                                           int numCentroFibras) {
    return std::vector<double[2]>();
}


double DistribuicaoUniformeEstruturada::calcularNumeroEfetivoDeFibras(int numCentroFibras, int numSobreposicoes,
                                                                      double razaoAreas) {
    return 0;
}

