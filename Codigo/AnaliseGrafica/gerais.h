/**
 * @file gerais.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com algumas funcionalidades relevantes para a análise gráfica da modelagem.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GERAIS_H
#define GERAIS_H

#include <vector>
#include <functional>
#include <string>
#include <iostream>

std::vector<double> linspace(double start, double stop, int n = 50);

std::vector<double> transform(std::vector<double> x, std::function<double(double)> f);

void exportarDados(const std::string& path, const std::vector<std::string>& cabecalhos,
                   const std::vector<double>& X, const std::vector<std::vector<double>>& Y);

/**
 * @brief Macro para facilitar imprimir texto no console
 * 
 * @tparam Args  
 * @param args  
 */
template<typename ...Args>
void print(Args && ...args) {
    (std::cout << ... << args);
}


#endif //GERAIS_H
