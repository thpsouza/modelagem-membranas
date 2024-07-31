/**
 * @file CuboPerfeito.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de geometria cúbica perfeita para o volume de controle.
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MODELAGEM_MEMBRANAS_CUBOPERFEITO_H
#define MODELAGEM_MEMBRANAS_CUBOPERFEITO_H

#include "GeometriaBase.h"

/**
 * @brief Subclasse da classe 'GeometriaBase'. Implementa os cálculos para uma geometria de cubo perfeito.
 */
class CuboPerfeito : public GeometriaBase {
private:
    double aresta;

public:
    // Construtor
    CuboPerfeito();
    explicit CuboPerfeito(double aresta);
    // Demais métodos
    void calcularAreaFace() override;
    void calcularVolume() override;
    void setAresta(double valor);
    double getAresta() const;
};


#endif //MODELAGEM_MEMBRANAS_CUBOPERFEITO_H
