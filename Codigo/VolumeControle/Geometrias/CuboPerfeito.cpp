//
// Created by LABCFD on 7/11/2024.
//

#include "CuboPerfeito.h"

/// Construtor
CuboPerfeito::CuboPerfeito() : GeometriaBase()
{
    temFace = true;
}

CuboPerfeito::CuboPerfeito(double aresta) :
    GeometriaBase(),
    aresta(aresta)
{
    temFace = true;
}


/// Calculadoras
void CuboPerfeito::calcularAreaFace() {
    setAreaFace(aresta * aresta);
}

void CuboPerfeito::calcularVolume() {
    setVolume(aresta * aresta * aresta);
}


/// Setters and Getters
void CuboPerfeito::setAresta(double valor) {
    aresta = valor;
}

double CuboPerfeito::getAresta() const {
    return aresta;
}


