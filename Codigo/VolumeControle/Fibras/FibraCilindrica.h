/**
 * @file FibraCilindrica.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de geometria cilindrica das fibras do módulo de membranas.
 * @version 0.1
 * @date 2024-07-11
 *
 * @copyright Copyright (c) 2024
 */

#ifndef MODELAGEM_MEMBRANAS_FIBRACILINDRICA_H
#define MODELAGEM_MEMBRANAS_FIBRACILINDRICA_H

#include "FibraBase.h"

/**
 * @brief Subclasse da classe 'FibraBase'. Implementa os cálculos para uma fibra com formato de um cilindro perfeito.
 */
class FibraCilindrica : public FibraBase {
private:
    double areaTransversal;
public:
    // Construtor
    FibraCilindrica();
    FibraCilindrica(double comprimento, double diametro);
    // Calculadoras
    void calcularAreaTransversal();
    void calcularAreaSuperficial() override;
    void calcularVolume() override;
    // Setter e Getter
    void setAreaTransversal(double valor);
    double getAreaTransversal() const;
};


#endif //MODELAGEM_MEMBRANAS_FIBRACILINDRICA_H
