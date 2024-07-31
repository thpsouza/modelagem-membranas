/**
 * @file CuboPerfeito.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "CuboPerfeito.h"

/**
 * @brief Construtor trivial da subclasse de geometria 'CuboPerfeito'.
 */
CuboPerfeito::CuboPerfeito() : GeometriaBase()
{
    temFace = true;
}

/**
 * @brief Construtor da subclasse de geometria 'CuboPerfeito'.
 * 
 * @param aresta : Tamanho da aresta do cubo perfeito considerado.
 */
CuboPerfeito::CuboPerfeito(double aresta) :
    GeometriaBase(),
    aresta(aresta)
{
    temFace = true;
}


/**
 * @brief Reimplementação do método calculador da área da face, para a geometria cúbica perfeita.
 */
void CuboPerfeito::calcularAreaFace() {
    setAreaFace(aresta * aresta);
}

/**
 * @brief Reimplementação do método calculador do volume, para a geometria cúbica perfeita.
 */
void CuboPerfeito::calcularVolume() {
    setVolume(aresta * aresta * aresta);
}


/**
 * @brief Define o valor da aresta do volume de controle, para uma geometria cúbica perfeita.
 * 
 * @param valor : Nova aresta.
 */
void CuboPerfeito::setAresta(double valor) {
    aresta = valor;
}

/**
 * @brief Retorna o valor da aresta do volume de controle, para uma geometria cúbica perfeita.
 * 
 * @return double 
 */
double CuboPerfeito::getAresta() const {
    return aresta;
}


