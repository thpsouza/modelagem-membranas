//
// Created by LABCFD on 5/27/2024.
//

#ifndef GERAIS_H
#define GERAIS_H

#include <vector>
#include <functional>
#include <string>
#include <iostream>

std::vector<double> linspace(double start, double stop, int n = 50);

std::vector<double> transform(std::vector<double> x, std::function<double(double)> f);

void exportarDados(const std::string& path, const std::vector<std::string>& propriedades,
                   const std::vector<double>& X, const std::vector<std::vector<double>>& Y);

template<typename ...Args>
void print(Args && ...args) {
    (std::cout << ... << args);
}


#endif //GERAIS_H
