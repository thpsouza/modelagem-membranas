//
// Created by LABCFD on 7/5/2024.
//

#include "DadosEntradaModelo.h"

DadosEntradaModelo::DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                                       double empacotamento, double volume, double razaoComprimentoDiametroFibra):
        geometria(geometria),
        distribuicao(distribuicao),
        empacotamento(empacotamento),
        volume(volume),
        razaoComprimentoDiametroFibra(razaoComprimentoDiametroFibra)
{
}

DadosEntradaModelo::TipoGeometria DadosEntradaModelo::getGeometria() const {
    return geometria;
}

DadosEntradaModelo::TipoDistribuicao DadosEntradaModelo::getDistribuicao() const {
    return distribuicao;
}

double DadosEntradaModelo::getEmpacotamento() const {
    return empacotamento;
}

double DadosEntradaModelo::getVolume() const {
    return volume;
}

