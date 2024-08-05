/**
 * @file DistribuicaoUniforme.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de distribuição uniforme de fibras no volume de controle
 * @version 0.1
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 */
#ifndef MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORME_H
#define MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORME_H

#include <cmath>
#include "DistribuicaoBase.h"

/**
 * @brief Subclasse da classe 'DistribuicaoBase'. Implementa os cálculos para uma distribuição uniforme de fibras cilíndricas,
 * sem sobreposição, em um volume de controle com geometria cúbica.
 */
class DistribuicaoUniforme : public DistribuicaoBase {
private:
    const double porosidadeMaximaTeorica = M_PI * sqrt(3) / 6;
};


#endif //MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORME_H
