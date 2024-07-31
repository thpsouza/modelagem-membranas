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


/// Calculadoras
void GeometriaBase::calcularAreaFace() {
}

void GeometriaBase::calcularVolume() {
}


/// Setters and Getters
void GeometriaBase::setVolume(double valor) {
    volume = valor;
}

void GeometriaBase::setAreaFace(double valor) {
    areaFace = valor;
}

double GeometriaBase::getVolume() const {
    return volume;
}

double GeometriaBase::getAreaFace() const {
    return areaFace;
}