//
// Created by LABCFD on 7/11/2024.
//

#include "FibraBase.h"

/// Construtor
FibraBase::FibraBase() {

}


/// Setters and Getters
void FibraBase::setComprimento(double valor) {
    comprimento = valor;
}

void FibraBase::setDiametro(double valor) {
    diametroMedio = valor;
}

void FibraBase::setAreaSuperficial(double valor) {
    areaSuperficial = valor;
}

double FibraBase::getComprimento() const {
    return comprimento;
}

double FibraBase::getDiametro() const {
    return diametroMedio;
}

double FibraBase::getAreaSuperficial() const {
    return areaSuperficial;
}
