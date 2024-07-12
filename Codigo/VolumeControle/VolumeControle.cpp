//
// Created by LABCFD on 7/11/2024.
//

#include "VolumeControle.h"


VolumeControle::VolumeControle() {

}



/// Calculadoras
void VolumeControle::calcularAreaTotalTransferencia() {
}

void VolumeControle::calcularPorosidade() {
}



/// Setters and Getters
void VolumeControle::setAreaTransferenciaTotal(double valor) {
    areaTransferenciaTotal = valor;
}

void VolumeControle::setPorosidade(double valor) {
    porosidade = valor;
}



double VolumeControle::getAreaTransferenciaTotal() const {
    return areaTransferenciaTotal;
}

double VolumeControle::getPorosidade() const {
    return porosidade;
}


