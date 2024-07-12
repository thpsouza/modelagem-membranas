//
// Created by LABCFD on 7/11/2024.
//

#include <cmath>
#include "FibraCilindrica.h"


/// Construtor
FibraCilindrica::FibraCilindrica() {
}


/// Calculadoras
void FibraCilindrica::calcularAreaTransversal() {
    setAreaTransversal(M_PI/4 * getDiametro() * getDiametro());
}

void FibraCilindrica::calcularAreaSuperficial() {
    setAreaSuperficial(M_PI * getDiametro() * getComprimento());
}

void FibraCilindrica::calcularVolume() {
    setVolume(M_PI/4 * getDiametro() * getDiametro() * getComprimento());
}


/// Setters e Getters
void FibraCilindrica::setAreaTransversal(double valor) {
    areaTransversal = valor;
}

double FibraCilindrica::getAreaTransversal() const {
    return areaTransversal;
}
