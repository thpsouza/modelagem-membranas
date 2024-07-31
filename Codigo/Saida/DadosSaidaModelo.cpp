/**
 * @file DadosSaidaModelo.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 * 
 */

#include "DadosSaidaModelo.h"


DadosSaidaModelo::DadosSaidaModelo() {

}

void DadosSaidaModelo::setPorosidade(double value) {
    porosidade = value;
}

void DadosSaidaModelo::setNumFibras(int value) {
    numFibras = value;
}

void DadosSaidaModelo::setAreaTotalTransferencia(double value) {
    areaTransferenciaTotal = value;
}

double DadosSaidaModelo::getPorosidade() const {
    return porosidade;
}

int DadosSaidaModelo::getNumFibras() const {
    return numFibras;
}

double DadosSaidaModelo::getAreaTotalTransferencia() const {
    return areaTransferenciaTotal;
}




