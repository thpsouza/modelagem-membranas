//
// Created by LABCFD on 7/11/2024.
//

#include "CuboPerfeito.h"

CuboPerfeito::CuboPerfeito(double aresta) :
aresta(aresta)
{

}

void CuboPerfeito::calcularAreaFace() {
    areaFace = aresta * aresta;
}

void CuboPerfeito::calcularVolume() {
    setVolume(aresta * aresta * aresta);
}


/// Setters and Getters
void CuboPerfeito::setAresta(double valor) {
    aresta = valor;
}

void CuboPerfeito::setAreaFace(double valor) {
    areaFace = valor;
}

double CuboPerfeito::getAresta() const {
    return aresta;
}

double CuboPerfeito::getAreaFace() const {
    return areaFace;
}
