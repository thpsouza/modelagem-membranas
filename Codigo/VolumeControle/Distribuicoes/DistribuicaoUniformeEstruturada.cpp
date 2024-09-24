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


double DistribuicaoUniformeEstruturada::calcularDistanciaFibras(double porosidade) {
    double d;
    if (1-porosidade > M_PI_4) { // pi/4 ~ 0.785 é a densidade superficial máxima para uma distribuição em retículo quadrado.
        d = 1;
    }
    return d;
}

/**
 * @brief Define um novo valor para o distanciamento médio de fibras.
 * @param valor : Nova distância entre fibras calculada.
 */
void DistribuicaoUniformeEstruturada::setDistanciaFibras(double valor) {
    distanciaFibras = valor;
}

/**
 * @brief Retorna o distanciamento médio entre as fibras.
 * @return double
 */
double DistribuicaoUniformeEstruturada::getDistanciaFibras() const {
    return distanciaFibras;
}
