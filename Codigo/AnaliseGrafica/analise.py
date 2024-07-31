import numpy as np
import pandas as pd
import subprocess
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button, RadioButtons


def build_cpp(build_command):
    exit_code = subprocess.check_call(build_command)
    if exit_code != 0:
        raise Exception("Build error.\n")


def run_cpp(run_command):
    exit_code = subprocess.check_call(run_command)
    if exit_code != 0:
        raise Exception("Run error.\n")


def obter_dados(cf_df: float, build=True) -> pd.DataFrame:
    # Importar path absoluto do cmake:
    with open("cmake_path.txt") as f:
        cmake_path = f.read()

    # Paths relativos
    build_dir_path = "..\\cmake-build-debug"
    csv_file_path = "dados.csv"
    run_path = build_dir_path + "\\modelagem_membranas.exe"
    build_command = f'"{cmake_path}" --build "{build_dir_path}" --target modelagem_membranas -- -j 10'
    run_command = f'"{run_path}" "{csv_file_path}" "{cf_df}"'

    if build:
        build_cpp(build_command)
    run_cpp(run_command)
    df = pd.read_csv(csv_file_path, sep=';')
    return df


def regredir_dados(dados: np.ndarray) -> np.ndarray:
    x = dados[:, 0]
    Y = dados[:, 1:].T
    fitted = np.empty((Y.shape[1], 2))
    for i, y in enumerate(Y):
        fitted[i] = np.polyfit(x, y, 1)
    return fitted


def plotar_dados(dados: pd.DataFrame, razao_cf_df: float, interativo=False):
    dados = dados.to_numpy()
    construir_legendas = lambda regressoes: [
        "Porosidade\n" + f"f(x) = {round(regressoes[0][0], 4)}*x + {round(regressoes[0][1], 4)}",
        "Número de fibras\n" + f"f(x) = {round(regressoes[1][0], 4)}*x + {round(regressoes[1][1], 4)}",
        "Área total de transferência\n" + f"f(x) = {round(regressoes[2][0], 4)}*x + {round(regressoes[2][1], 4)}"
    ]

    prop_cycle = plt.rcParams['axes.prop_cycle']
    colors = prop_cycle.by_key()['color']
    fig, axes = plt.subplots(3, 1, figsize=(10, 8), sharex=True)
    fig.suptitle("Variação das propriedades para um volume unitário")

    lines = []
    scatters = []
    X = np.linspace(dados[0,0], dados[-1,0], 100)
    for i, ax in enumerate(axes):
        sctr = ax.scatter(dados[:, 0], dados[:, i + 1], color=colors[i], s=15,
                          label=construir_legendas(regredir_dados(dados))[i])
        [line] = ax.plot(X, np.poly1d(regredir_dados(dados)[i])(X), color="grey")

        lines.append(line)
        scatters.append(sctr)
        ax.legend()

    if interativo:
        fig.subplots_adjust(bottom=0.25)
        slider_ax = fig.add_axes([0.185, 0.1, 0.65, 0.03], autoscale_on=True)
        slider = Slider(slider_ax, 'cf/df', 1, 50.0, valinit=razao_cf_df)

        def update_slider(val):
            novos_dados = obter_dados(slider.val, build=False).to_numpy()
            regressoes = regredir_dados(novos_dados)
            novo_Y = novos_dados[:, 1:]
            for i, ax in enumerate(axes):
                lines[i].set_ydata(np.poly1d(regressoes[i])(X))
                scatters[i].remove()
                scatters[i] = ax.scatter(novos_dados[:, 0], novos_dados[:, i + 1], color=colors[i], s=15,
                                      label=construir_legendas(regressoes)[i])
                ax.legend()
                ax.relim()
                ax.autoscale_view()
            fig.canvas.draw_idle()

        slider.on_changed(update_slider)

    plt.show()


def main():
    # Definindo a razão comprimento/diâmetro das fibras:
    cf_df = 10
    dados = obter_dados(cf_df)
    plotar_dados(dados, cf_df, interativo=True)


if __name__ == "__main__":
    main()
