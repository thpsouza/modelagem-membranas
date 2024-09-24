/**
 * @file DistribuicaoUniformeAlternada.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de distribuição uniforme alternada de fibras no volume de controle
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORMEALTERNADA_H
#define MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORMEALTERNADA_H

#include <cmath>
#include "DistribuicaoBase.h"

/**
 * @brief Subclasse da classe 'DistribuicaoBase'. Implementa os cálculos para uma distribuição uniforme alternada
 * de fibras cilíndricas, sem sobreposição, em um volume de controle com geometria cúbica.
 */
class DistribuicaoUniformeAlternada : public DistribuicaoBase {
    const double porosidadeMaximaTeoricaAlternada1D = 1 - M_PI * sqrt(3) / 6;
};


#endif //MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORMEALTERNADA_H
