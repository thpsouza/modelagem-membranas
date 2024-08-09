/**
 * @file FibraCilindrica.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-11
 *
 * @copyright Copyright (c) 2024
 */

#include <cmath>
#include "FibraCilindrica.h"


// Construtores
/**
 * @brief Construtor trivial da subclasse de geometria de fibras 'FibraCilindrica'.
 */
FibraCilindrica::FibraCilindrica() : FibraBase() {
}

/**
 * @brief Construtor da subclasse de geometria de fibras 'FibraCilindrica'.
 *
 * @param diametro : Diâmetro médio das fibras no módulo de membranas.
 */
FibraCilindrica::FibraCilindrica(double diametro) :
        FibraBase(diametro)
{
}

/**
 * @brief Construtor da subclasse de geometria de fibras 'FibraCilindrica'.
 *
 * @param diametro : Diâmetro médio das fibras no módulo de membranas.
 * @param areaSuperficial : Área superficial média das fibras no módulo de membranas.
 */
FibraCilindrica::FibraCilindrica(double diametro, double areaSuperficial) :
    FibraBase(diametro, areaSuperficial)
{
}

/**
 * @brief Construtor da subclasse de geometria de fibras 'FibraCilindrica'.
 *
 * @param comprimento : Comprimento das fibras no módulo de membranas.
 * @param diametro : Diâmetro médio das fibras no módulo de membranas.
 * @param areaSuperficial : Área superficial média das fibras no módulo de membranas.
 * @param volume : Volume médio das fibras no módulo de membranas.
 */
FibraCilindrica::FibraCilindrica(double comprimento, double diametro, double areaSuperficial, double volume)
        : FibraBase(comprimento, diametro, areaSuperficial, volume) {

}


// Calculadoras
/**
 * @brief Método para calcular o diâmetro de uma fibra cilíndrica perfeita.
 */
void FibraCilindrica::calcularDiametro() {
    setDiametro(getAreaSuperficial() / (M_PI * getComprimento()));
}

/**
 * @brief Método para calcular o comprimento de uma fibra cilíndrica perfeita.
 */
void FibraCilindrica::calcularComprimento() {
    setDiametro(getAreaSuperficial() / (M_PI * getDiametro()));
}

/**
 * @brief Método para calcular a área transversal de uma fibra cilíndrica perfeita.
 */
void FibraCilindrica::calcularAreaTransversal() {
    setAreaTransversal(M_PI/4 * getDiametro() * getDiametro());
}

/**
 * @brief Reimplementação do método calculador da área de superfície, para a fibra cilíndrica perfeita.
 */
void FibraCilindrica::calcularAreaSuperficial() {
    setAreaSuperficial(M_PI * getDiametro() * getComprimento());
}

/**
 * @brief Reimplementação do método calculador do volume, para a fibra cilíndrica perfeita.
 */
void FibraCilindrica::calcularVolume() {
    setVolume(M_PI/4 * getDiametro() * getDiametro() * getComprimento());
}


// Setters e Getters
/**
 * @brief Define o valor da área transversal da fibra cilíndrica perfeita.
 *
 * @param valor : Nova área transversal.
 */
void FibraCilindrica::setAreaTransversal(double valor) {
    areaTransversal = valor;
}

/**
 * @brief Retorna o valor da área transversal da fibra cilíndrica perfeita.
 *
 * @return double
 */
double FibraCilindrica::getAreaTransversal() const {
    return areaTransversal;
}





