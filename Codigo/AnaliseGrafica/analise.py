import matplotlib.pyplot as plt
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


def plotar_dados(dados: pd.DataFrame):
    dados.plot(x=0)
    plt.show()


def main():
    # Importar path absoluto do cmake:
    with open("cmake_path.txt") as f:
        cmake_path = f.read()

    # Paths relativos
    build_dir_path = "..\\cmake-build-debug"
    csv_file_path = "dados.csv"
    run_path = build_dir_path+"\\modelagem_membranas.exe"

    build_command = f'"{cmake_path}" --build "{build_dir_path}" --target modelagem_membranas -- -j 10'
    run_command = f'"{run_path}" "{csv_file_path}"'

    executar_cpp(build_command, run_command)
    dados = ler_dados(csv_file_path)
    plotar_dados(dados)


if __name__ == "__main__":
    main()
