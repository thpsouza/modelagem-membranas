#include "gerais.h"
#include <stdexcept>
#include <utility>

/**
 * Retorna um vetor com n numeros igualmente distribuidos no intervalo [start, stop
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
 * Recebe um vetor e retorna uma copia com os elementos modificados por uma dada transformacao.
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
