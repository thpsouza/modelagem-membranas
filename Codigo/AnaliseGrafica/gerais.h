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

/**
 * @brief Retorna um vetor com num numeros igualmente distribuidos no intervalo [start, stop
 *
 * @param start inicio do intervalo
 * @param stop fim do intervalo
 * @param num quantidade de numeros
 * @return vetor com os numeros distribuidos
 */
std::vector<double> linspace(double start, double stop, int num = 50);



/**
 * @brief Recebe um vetor e retorna uma copia com os elementos modificados por uma dada transformacao.
 *
 * @param x vetor de referencia
 * @param f operacao a se realizar
 * @return vetor com elementos operados
 */
std::vector<double> transform(std::vector<double> x, std::function<double(double)> f);



/**
 * @brief Exporta os dados para uma arquivo .csv. Cada série de propriedade será inserida ao longo de uma coluna.
 * A primeira linha contém os headers.
 *
 * @param path caminho para salvar o arquivo .csv
 * @param cabecalhos vetor de strings com os headers das cabecalhos a serem salvas
 * @param X vetor de dados do eixo x
 * @param Y matriz de séries do eixo y
 */
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
