/**
 * @file FibraBase.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-11
 *
 * @copyright Copyright (c) 2024
 */


#include "FibraBase.h"


// Construtores
/**
 * @brief Construtor triviaL da classe base das fibras do módulo de membranas.
 */
FibraBase::FibraBase() {
}

/**
 * @brief Construtor da classe base das fibras do módulo de membranas.
 */
FibraBase::FibraBase(double diametro) :
    diametroMedio(diametro)
{
}

/**
 * @brief Construtor da classe base das fibras do módulo de membranas.
 */
FibraBase::FibraBase(double diametro, double areaSuperficial) :
    diametroMedio(diametro),
    areaSuperficial(areaSuperficial)
{
}

/**
 * @brief Construtor da classe base das fibras do módulo de membranas.
 */
FibraBase::FibraBase(double comprimento, double diametro, double areaSuperficial, double volume) :
    comprimento(comprimento),
    diametroMedio(diametro),
    areaSuperficial(areaSuperficial),
    volume(volume)
{
}



// Cálculos
/**
 * @brief Método base para calcular o diâmetro médio das fibras. Será reimplementado em cada caso, para cada tipo de fibra.
 */
void FibraBase::calcularDiametro() {

}

/**
 * @brief Método base para calcular o comprimento das fibras. Será reimplementado em cada caso, para cada tipo de fibra.
 */
void FibraBase::calcularComprimento() {

}

/**
 * @brief Método base para calcular a área de superfície de uma fibra. Será reimplementado em cada caso, para cada tipo de fibra.
 */
void FibraBase::calcularAreaSuperficial() {
}

/**
 * @brief Método base para calcular o volume de uma fibra. Será reimplementado em cada caso, para cada tipo de fibra.
 */
void FibraBase::calcularVolume() {
}


// Setters e Getters
/**
 * @brief Define o valor do comprimento da fibra.
 *
 * @param valor : Novo comprimento da fibra.
 */
void FibraBase::setComprimento(double valor) {
    comprimento = valor;
}

/**
 * @brief Define o valor do diâmetro da fibra.
 *
 * @param valor Novo diâmetro da fibra.
 */
void FibraBase::setDiametro(double valor) {
    diametroMedio = valor;
}

/**
 * @brief Define o valor da área superficial da fibra.
 *
 * @param valor : Nova área superficial da fibra.
 */
void FibraBase::setAreaSuperficial(double valor) {
    areaSuperficial = valor;
}

/**
 * @brief Define o volume total da fibra.
 *
 * @param valor : Novo volume total.
 */
void FibraBase::setVolume(double valor) {
    volume = valor;
}

/**
 * @brief Retorna o valor do comprimento da fibra.
 *
 * @return double
 */
double FibraBase::getComprimento() const {
    return comprimento;
}

/**
 * @brief Retorna o valor do diâmetro da fibra.
 *
 * @return double
 */
double FibraBase::getDiametro() const {
    return diametroMedio;
}

/**
 * @brief Retorna o valor da área superficial da fibra.
 *
 * @return double
 */
double FibraBase::getAreaSuperficial() const {
    return areaSuperficial;
}

/**
 * @brief Retorna o valor do volume da fibra.
 *
 * @return double
 */
double FibraBase::getVolume() const {
    return volume;
}









