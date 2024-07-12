//
// Created by LABCFD on 7/11/2024.
//

#include "FibraBase.h"


/// Construtor
FibraBase::FibraBase() {

}

/// Calculos
void FibraBase::calcularAreaSuperficial() {
}

void FibraBase::calcularVolume() {
}


/// Setters e Getters
void FibraBase::setComprimento(double valor) {
    comprimento = valor;
}

void FibraBase::setDiametro(double valor) {
    diametroMedio = valor;
}

void FibraBase::setAreaSuperficial(double valor) {
    areaSuperficial = valor;
}

void FibraBase::setVolume(double valor) {
    volume = valor;
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

double FibraBase::getVolume() const {
    return volume;
}
