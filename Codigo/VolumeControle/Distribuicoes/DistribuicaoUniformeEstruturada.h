/**
 * @file DistribuicaoUniforme.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de distribuição uniforme estruturada de fibras no volume de controle
 * @version 0.1
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 */
#ifndef MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORMEESTRUTURADA_H
#define MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORMEESTRUTURADA_H

#include <cmath>
#include "DistribuicaoBase.h"

/**
 * @brief Subclasse da classe 'DistribuicaoBase'. Implementa os cálculos para uma distribuição uniforme estruturada
 * de fibras cilíndricas em um volume de controle com geometria cúbica.
 */
class DistribuicaoUniformeEstruturada : public DistribuicaoBase {
private:
    const double porosidadeMaximaTeorica1D = 1 - M_PI_4;
    double distanciaFibras;

public:
    DistribuicaoUniformeEstruturada();
    static double calcularDistanciaFibras(double porosidade);
    void setDistanciaFibras(double valor);
    [[nodiscard]] double getDistanciaFibras() const;
};


#endif //MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORMEESTRUTURADA_H
