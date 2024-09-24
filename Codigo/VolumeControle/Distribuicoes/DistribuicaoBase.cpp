/**
 * @file DistribuicaoBase.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 */

#include "DistribuicaoBase.h"

DistribuicaoBase::DistribuicaoBase() {
}

double DistribuicaoBase::calcularDistanciaFibras(double ladoVC, double raio, int numCentroFibras) {
    return 0;
}

std::vector<double[2]>
DistribuicaoBase::calcularCoordenadasFibras(double raioFibra, double distanciaEntreFibras, int numCentroFibras) {
    return {};
}

double DistribuicaoBase::calcularNumeroEfetivoDeFibras(int numCentroFibras, int numSobreposicoes, double razaoAreas) {
    return 1;
}

/**
 * @brief Define um novo valor para o distanciamento médio de fibras.
 * @param valor : Nova distância entre fibras calculada.
 */
void DistribuicaoBase::setDistanciaFibras(double valor) {
    distanciaFibras = valor;
}

/**
 * @brief Retorna o distanciamento médio entre as fibras.
 * @return double
 */
double DistribuicaoBase::getDistanciaFibras() const {
    return distanciaFibras;
}
