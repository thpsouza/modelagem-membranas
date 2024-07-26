import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import subprocess


def executar_cpp(build_command, run_command):
    exit_code = subprocess.check_call(build_command)
    if exit_code == 0:
        # "[100%] Built target modelagem_membranas"
        subprocess.check_call(run_command)
    else:
        print(exit_code)


def ler_dados(path: str):
    # with open(path, "r+") as file:
    #    dados = file.read()
    # return dados
    df = pd.read_csv(path, sep=';')
    return df


def regredir_dados(dados: pd.DataFrame):
    x = dados.iloc[:, 0]
    Y = dados.iloc[:, 1:]
    fitted = np.empty((Y.shape[1], 2))
    for i, (_, y) in enumerate(Y.items()):
        fitted[i] = np.polyfit(x, y.array, 1)
    return fitted


def plotar_dados(dados: pd.DataFrame, regressoes: np.ndarray, razao_cf_df: float):
    legendas = [
        "Porosidade\n" + f"f(x) = {round(regressoes[0][0],4)}*x + {round(regressoes[0][1],4)}",
        "Número de fibras\n" + f"f(x) = {round(regressoes[1][0],4)}*x + {round(regressoes[1][1],4)}",
        "Área total de transferência\n" + f"f(x) = {round(regressoes[2][0],4)}*x + {round(regressoes[2][1],4)}"
    ]
    axes = dados.plot(x=0, subplots=True, figsize=(10, 6),
                      title=f"Variação das propriedades para um volume unitário, com cf = {razao_cf_df}df")
    for i, ax in enumerate(axes):
        ax.legend([legendas[i]])
    plt.show()


def main():
    # Definir razão comprimento e diâmetro fibras:
    cf_df = 10

    # Importar path absoluto do cmake:
    with open("cmake_path.txt") as f:
        cmake_path = f.read()

    # Paths relativos
    build_dir_path = "..\\cmake-build-debug"
    csv_file_path = "dados.csv"
    run_path = build_dir_path + "\\modelagem_membranas.exe"

    build_command = f'"{cmake_path}" --build "{build_dir_path}" --target modelagem_membranas -- -j 10'
    run_command = f'"{run_path}" "{csv_file_path}" "{cf_df}"'

    executar_cpp(build_command, run_command)
    dados = ler_dados(csv_file_path)
    plotar_dados(dados, regredir_dados(dados), cf_df)


if __name__ == "__main__":
    main()
