cmake_minimum_required(VERSION 3.27)

set( CMAKE_CXX_COMPILER "C:\\msys64\\mingw64\\bin\\clang++.exe" )
set( CMAKE_C_COMPILER "C:\\msys64\\mingw64\\bin\\clang.exe" )
set(CMAKE_CXX_STANDARD 17)

project(teste_compilador)

add_executable(teste_compilador teste.cpp
)