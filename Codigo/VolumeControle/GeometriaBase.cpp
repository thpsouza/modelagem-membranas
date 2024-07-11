//
// Created by LABCFD on 7/11/2024.
//

#include "GeometriaBase.h"

/// Construtores
GeometriaBase::GeometriaBase() {
}

//GeometriaBase::GeometriaBase(double volume) :
//volume(volume)
//{
//}

void GeometriaBase::calcularVolume() {
}

void GeometriaBase::setVolume(double valor) {
    volume = valor;
}

double GeometriaBase::getVolume() const {
    return volume;
}