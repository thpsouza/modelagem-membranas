import matplotlib.pyplot as plt
import pandas as pd
import subprocess
import os


def executar_cpp(build_command, run_command):
    exit_code = subprocess.getoutput(build_command)
    if exit_code == "[100%] Built target modelagem_membranas":
        subprocess.run(run_command)
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
    cmake_path = "E:\\Program Files\\JetBrains\\CLion 2023.3.4\\bin\\cmake\\win\\x64\\bin\\cmake.exe"
    build_dir_path = "C:\\Users\\EQ\\Desktop\\Thiago Souza\\modelagem-membranas\\Codigo\\cmake-build-debug"
    csv_file_path = "C:\\Users\\EQ\\Desktop\\Thiago Souza\\modelagem-membranas\\Codigo\\AnaliseGrafica\\dados.csv"

    build_command = f'"{cmake_path}" --build "{build_dir_path}" --target modelagem_membranas -- -j 10'
    run_command = f'"{build_dir_path}\\modelagem_membranas.exe" "{csv_file_path}"'

    print(build_command, run_command, sep='\n')

    return
    executar_cpp(build_command, run_command)
    # dados = ler_dados(csv_file_path)
    # plotar_dados(dados)


if __name__ == "__main__":
    main()
