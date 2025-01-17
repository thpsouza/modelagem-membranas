import numpy as np
import sympy as sp



def teste2():    
    R, r, i, j, x1, x2 = sp.symbols('R r i j x1 x2')
    i = j = (R/r-1)/2
    
    f_VC = R - sp.sqrt(R**2 - (x1-R)**2)
    df_VC = (x1 - R)/sp.sqrt(R**2 - (x1-R)**2)
    f_fibra = r*(2*j+1) - sp.sqrt(r**2 - (x2 - r*(2*i+1))**2)
    df_fibra = (x2 - r*(2*i+1))/sp.sqrt(r**2 - (x2 - r*(2*i+1))**2)
    
    print(sp.simplify(f_VC))
 

def teste1():
    teste = np.array(
        [0,0,0,1,2,2,3,4,4,5,6,7,8,8,9,10,11,12]
    )

    M = np.array(
        [0,1,4,8,13,22,30,41,54,69,83,98,117,139,162,183,206,234]    
    )

    m = np.array(range(0,len(M)))
    Ni = np.array(M+m)*4 + 1 
    grad_M = np.array(["-"] + [M[i+1] - M[i] for i in m[:-1]])
    grad_Ni = np.array(["-"] + [Ni[i+1] - Ni[i] for i in m[:-1]])
    for i, ni in enumerate(Ni):
        print(f"m = {i}: M = {M[i]}, Ni = {ni} - Variação: {grad_M[i]} ({grad_Ni[i]})")



def raio_VC(m, r):
    return (2*m+1)*r


def coordenadas_centro_VC(R):
    return (R, R)


def coordenadas_centro_fibras(i, j, r, l):
    return np.array([i,j])*(2*r+l) + (l/2+r)


def curvas_VC(x, R):
    y1 = R + np.sqrt(R**2 - (x - R)**2)
    y2 = R - np.sqrt(R**2 - (x - R)**2)



def verificar_fibra_contida_VC():
    if 1:...


def main():
    r = 1
    l = 0
    m=5
    #R = raio_VC(m, r)
    #coord_VC = coordenadas_centro_VC(R)
    #coords_fibras = []
    #coordenadas_centro_fibras()
    
    teste2()




if __name__ == "__main__":
    main()