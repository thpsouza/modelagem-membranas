#include "gerais.h"
#include <stdexcept>
#include <utility>
#include <fstream>


/**
 * @brief Retorna um vetor com n numeros igualmente distribuidos no intervalo [start, stop
 *
 * @param start inicio do intervalo
 * @param stop fim do intervalo
 * @param n quantidade de numeros
 * @return vetor com os numeros distribuidos
 */
std::vector<double> linspace(double start, double stop, int n) {
    std::vector<double> v;

    /// Defesa
    /// Retorna vetor com apenas o primeiro valor se n=1; Retorna vetor vazio se n=0; Levanta erro se n<0;
    if (n <= 1) {
        if (n < 0) {
            throw std::invalid_argument("n deve ser um inteiro positivo");
        }
        if (n == 1) {
            v.push_back(start);
        }
        return v;
    }

    double step = (stop - start) / (n - 1);

    /// Preenche o corpo do vetor
    for(int i=0; i < n-1; i++) {
        v.push_back(start + step * i);
    }
    v.push_back(stop);

    return v;
}


/**
 * @brief Recebe um vetor e retorna uma copia com os elementos modificados por uma dada transformacao.
 *
 * @param x vetor de referencia
 * @param f operacao a se realizar
 * @return vetor com elementos operados
 */
std::vector<double> transform(std::vector<double> x, std::function<double(double)> f) {
    std::vector<double> ret(x.size());
    std::transform(x.begin(), x.end(), ret.begin(), std::move(f));
    return ret;
}


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