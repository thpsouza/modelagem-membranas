//
// Created by LABCFD on 7/5/2024.
//

#include "DadosEntradaModelo.h"

DadosEntradaModelo::DadosEntradaModelo(TipoGeometria geometria, double empacotamento, double volumeControle) :
    geometria(geometria),
    empacotamento(empacotamento),
    volumeControle(volumeControle)
{
}

DadosEntradaModelo::TipoGeometria DadosEntradaModelo::getGeometria() const {
    return geometria;
}

double DadosEntradaModelo::getEmpacotamento() const {
    return empacotamento;
}

double DadosEntradaModelo::getVolumeControle() const {
    return volumeControle;
}
