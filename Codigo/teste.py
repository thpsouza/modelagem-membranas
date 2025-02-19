from math import pi, sqrt

# Dados módulo real
d = 300e-6
D = 8.9/100
L = 14.2/100
N = 30000

# Comparacao número de fibras
FE_max_estruturada = pi / 4
FE_max_alternada = sqrt(3) * pi / 6
Atf = pi * d**2 / 4
AtM = pi * D**2 / 4
Nf = AtM/Atf * FE_max_estruturada
# Nf = AtM/Atf * FE_max_alternada
print(f"Número de fibras teórico: {int(Nf)}") # Utilizando alguma das distribuições
print(f"Número de fibras real: {N}")

# Comparacao densidade superficial de fibras do módulo
print(f"Densidade superficial de fibras teórica do módulo: {round(1 - Atf*Nf / AtM, 4)}")
print(f"Densidade superficial de fibras real do módulo: {round(1 - Atf*N / AtM, 4)}")
 
# Comparacao area de transferencia total
Af = d*pi*L
A1 = Af*Nf
A2 = Af*N
print(f"Área transferência teórica com o modelo: {round(A1,2)} m²") # Utilizando o número de fibras calculado
print(f"Área transferência teórica sem o modelo: {round(A2,2)} m²") # Utilizando o número de fibras informado
print("Área transferência real: 2.10 m²")
