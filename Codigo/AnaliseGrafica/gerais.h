//
// Created by LABCFD on 5/27/2024.
//

#ifndef GERAIS_H
#define GERAIS_H

#include <vector>
#include <functional>

std::vector<double> linspace(double start, double stop, int n = 50);
std::vector<double> transform(std::vector<double> x, std::function<double(double)> f);

#endif //GERAIS_H
