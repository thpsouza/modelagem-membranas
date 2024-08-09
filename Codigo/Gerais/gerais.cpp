/**
 * @file gerais.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "gerais.h"
#include <stdexcept>
#include <utility>
#include <fstream>
#include <algorithm>


std::vector<double> linspace(double start, double stop, int num) {
    std::vector<double> v(num);
    // Defesa - Retorna vetor com apenas o primeiro valor se num=1; Retorna vetor vazio se num=0; Levanta erro se num<0;
    if (num <= 1) {
        if (num < 0)
            throw std::invalid_argument("num deve ser um inteiro positivo");

        else if (num == 1)
            v[0] = (start);

        return v;
    }

    double step = (stop - start) / (num - 1);

    for(int i=0; i < num - 1; i++)
        v[i] = (start + step * i);

    v[num - 1] = (stop);

    return v;
}


std::vector<double> transform(std::vector<double> x, std::function<double(double)> f) {
    std::vector<double> ret(x.size());
    std::transform(x.begin(), x.end(), ret.begin(), std::move(f));
    return ret;
}


bool isClose(double x, double y, double tolerancia) {
    return (std::abs(x-y) <= tolerancia);
}


void exportarDados(const std::string& path, const std::vector<std::string>& cabecalhos,
                   const std::vector<double>& X, const std::vector<std::vector<double>>& Y) {
    std::ofstream file;
    file.open(path);

    // Headers
    for (const auto& p : cabecalhos) {
        if (p != cabecalhos[0]) {
            file << ";";
        }
        file << p;
    } file << std::endl;

    // Dados
    for (int j = 0; j < X.size(); j++) {
        file << X[j] << ";";
        for (const auto& y : Y) {
            if (y != Y[0]) {
                file << ";";
            }
            file << y[j];
        } file << std::endl;
    }
    file.close();
}


