/**
 * @file GeometriaBase.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "GeometriaBase.h"

/**
 * @brief Construtor da classe base de geometria do volume de controle.
 * 
 */
GeometriaBase::GeometriaBase() {
}

//GeometriaBase::GeometriaBase(double volume) :
//volume(volume)
//{
//}


/**
 * @brief Método base para calcular a área da face do volume de controle. Será reimplementado em cada caso, para cada geometria.
 * 
 */
void GeometriaBase::calcularAreaFace() {
}

/**
 * @brief Método base para calcular o volume total do volume de controle. Será reimplementado em cada caso, para cada geometria.
 * 
 */
void GeometriaBase::calcularVolume() {
}


/**
 * @brief Define o volume total do volume de controle.
 * 
 * @param valor : Novo volume total.
 */
void GeometriaBase::setVolume(double valor) {
    volume = valor;
}

/**
 * @brief Define o valor da área da face do volume de controle.
 * 
 * @param valor : Nova área da face.
 */
void GeometriaBase::setAreaFace(double valor) {
    areaFace = valor;
}

/**
 * @brief Retorna o valor do volume total do volume de controle.
 * 
 * @return double 
 */
double GeometriaBase::getVolume() const {
    return volume;
}

/**
 * @brief Retorna o valor da área da face do volume de controle.
 * 
 * @return double 
 */
double GeometriaBase::getAreaFace() const {
    return areaFace;
}