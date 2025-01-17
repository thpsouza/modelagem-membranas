import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button, RadioButtons


def avaliar_fibra_dentro_VC(R, r, i, j):
    def x_fibra(R, r, i, j):
        return r*(2*i+1) + (r*np.sqrt(2)/2*(r*(2*i+1)-R)) / np.sqrt((R-r)**2 + 2*r*(j*(r*(1+j)-R) + i*(r*(1+i)-R)))
    def x_VC(R, r, i, j):
        return R + (R*np.sqrt(2)/2*(r*(2*i+1)-R)) / np.sqrt((R-r)**2 + 2*r*(j*(r*(1+j)-R) + i*(r*(1+i)-R)))

    if i == j == (R/r-1)/2:
        d = R - r
    elif i > (R/r-1)/2:
        d = x_VC(R, r, i, j) - x_fibra(R, r, i, j)
    else:
        d = x_fibra(R, r, i, j) - x_VC(R, r, i, j)    
    
    return d>=0#, d


def calcular_propriedades():
    ...


def calcular_area_fibras(Nf, r):
    return Nf * np.pi * r**2


def calcular_empacotamento(area_fibras, raio_VC):
    return area_fibras/(np.pi*raio_VC**2)


def plotar_VC(ax, pos, radius, **kwargs):
    volume_de_controle = plt.Circle(
        pos, radius,
        linewidth=2,
        edgecolor='tab:red',
        facecolor='none',
        **kwargs)
    ax.add_artist(volume_de_controle)
    return volume_de_controle


def plotar_fibra(ax, pos, raio, **kwargs):
    if 'color' not in kwargs.keys():
        kwargs['color']='tab:blue'
    fibra = plt.Circle(
        pos, raio,
        linewidth=2,
        alpha=0.5,
        **kwargs)
    ax.add_artist(fibra)
    return fibra


def limpar_fibras(fibras):
    for fibra in fibras:
        fibra.remove()
    fibras.clear()


def plotar_fibras(ax, R, r, n, l, fibras=None, **kwargs):
    if fibras is None:
        fibras = []
    contador_fibras_dentro_VC = 0
    for i in range(n):
        for j in range(n):
            pos = (l/2 + r + i*(l+2*r), l/2 + r + j*(l+2*r))
            if avaliar_fibra_dentro_VC(R, r, j, i): 
                fibra = plotar_fibra(ax, pos, r, color='tab:green', **kwargs)
                contador_fibras_dentro_VC += 1
            else:
                fibra = plotar_fibra(ax, pos, r, **kwargs)
            fibras.append(fibra)
    return fibras, contador_fibras_dentro_VC


def plotar_linhas(ax, fibras, r, n):
    x0,y0 = fibras[0].center
    x1,y1 = fibras[1].center
    x2,y2 = fibras[n].center
    l1 = ax.plot((x0, x1), (y0+r, y1-r), '--', color='tab:grey')
    l2 = ax.plot((x0+r, x2-r), (y0, y2), '--', color='tab:grey')
    return (l1,l2), []


def update_VC(VC, R, pos):
    VC.set_radius(R)
    VC.center = pos


def update_fibras(fibras, r, n, l):
    for i in range(n):
        for j in range(n):
            pos = (l/2 + r + i*(l+2*r), l/2 + r + j*(l+2*r))
            fibras[i*n + j].center = pos


def update_linhas(ax, fibras, linhas, anotacoes, r, n, l):
    x0,y0 = fibras[0].center
    x1,y1 = fibras[1].center
    x2,y2 = fibras[n].center
    linhas[0][0].set_xdata((x0, x1))
    linhas[0][0].set_ydata((y0+r, y1-r))
    linhas[1][0].set_xdata((x0+r, x2-r))
    linhas[1][0].set_ydata((y0, y2))
    if anotacoes:
        anotacoes[0].remove()
        anotacoes[1].remove()
        anotacoes.clear()
    if l > 0:
        ann1 = ax.annotate("$\ell$", (0.5, 0.5), xycoords=linhas[0][0], fontsize=14, ha='right', va='center')
        ann2 = ax.annotate("$\ell$", (0.5, 0.5), xycoords=linhas[1][0], fontsize=14, ha='center', va='bottom')
        anotacoes.append(ann1)
        anotacoes.append(ann2)


def update_slider_distancia_fibras(val, fig, ax, propriedades, plots):
    r, l, Nf, n, area_fibras, contador_fibras_dentro_VC = propriedades.values()
    contorno_VC, fibras, linhas, anotacoes, texto = plots
    # Recalcular propriedades a partir da nova distância entre fibras
    propriedades["l"] = l = val
    R = r*n + l*(n-1)/2 + l/2
    empacotamento = calcular_empacotamento(area_fibras, R)
    pos = R,R
    # Redefinir dimensões
    update_VC(contorno_VC, R, pos)
    update_fibras(fibras, r, n, l)
    update_linhas(ax, fibras, linhas, anotacoes, r, n, l)
    # Reescrever textos
    texto.set_text(f"r = {r}$\mu$m,      R = {R:.2f}$\mu$m,      F.E. = {empacotamento:.4f},    Fibras no VC: {propriedades["contador"]}/{propriedades["Nf"]}")
    # Reescale dinâmico com o lado do VC
    ax.set_xlim(-0.01*(2*R), (2*R)*1.01)
    ax.set_ylim(-0.01*(2*R), (2*R)*1.01)
    fig.canvas.draw_idle()


def update_slider_numero_fibras(val, fig, ax, propriedades, plots):
    r, l, Nf, n, area_fibras, contador_fibras_dentro_VC = propriedades.values()
    contorno_VC, fibras, linhas, anotacoes, texto = plots
    # Recalcular propriedades a partir do novo número de fibras
    Nf = val
    propriedades["Nf"] = Nf
    propriedades["n"] = n = int(Nf**(1/2))
    R = r*n + l*(n-1)/2 + l/2
    pos = R,R
    # Redefinir dimensões e plotar novamente as fibras
    update_VC(contorno_VC, R, pos)
    limpar_fibras(fibras)
    _, contador_fibras_dentro_VC = plotar_fibras(ax, R, r, n, l, fibras=fibras)
    update_linhas(ax, fibras, linhas, anotacoes, r, n, l)
    # Fibras totalmente contidas no volume de controle
    propriedades["contador"] = contador_fibras_dentro_VC
    propriedades["area"] = area_fibras = calcular_area_fibras(contador_fibras_dentro_VC, r)
    empacotamento = calcular_empacotamento(area_fibras, R)
    # Reescrever textos
    texto.set_text(f"r = {r}$\mu$m,      R = {R:.2f}$\mu$m,      F.E. = {empacotamento:.4f},    Fibras no VC: {contador_fibras_dentro_VC}/{Nf}")
    lista.append((int(Nf), int(contador_fibras_dentro_VC)))
    # Reescale dinâmico com o lado do VC
    ax.set_xlim(-0.01*(2*R), (2*R)*1.01)
    ax.set_ylim(-0.01*(2*R), (2*R)*1.01)
    fig.canvas.draw_idle()


def plotar_geral(dados, fig):
    r = dados["raio_fibras"]
    N_max = dados["num_fibras_maximo"]
    l_max = dados["distancia_fibras_maxima"]
    ax = fig.add_subplot()

    ## Cálculos e definições das propriedades
    Nf = N_min = 9
    l = l_min = 0
    n = int(Nf**(1/2))
    R = r*n + l*(n-1)/2 + l/2

    ## Plots
    x0,y0,width,height = ax.get_position().bounds
    contorno_VC = plotar_VC(ax, (n*r,n*r), R)
    fibras, contador_fibras_dentro_VC = plotar_fibras(ax, R, r, n, l)
    linhas, anotacoes = plotar_linhas(ax, fibras, r, n)

    ## Fibras contidas no volume de controle
    area_fibras = calcular_area_fibras(contador_fibras_dentro_VC, r)
    empacotamento = calcular_empacotamento(area_fibras, R)

    ## Texto das propriedades
    fig.subplots_adjust(top=0.9)
    text_ax = fig.add_axes([0.185, 0.95, 0.65, 0.03], autoscale_on=True)
    texto = text_ax.text(
        0.5, 0.5, f"r = {r}$\mu$m,      R = {R:.2f}$\mu$m,      F.E. = {empacotamento:.4f},     Fibras no VC: {contador_fibras_dentro_VC}/{Nf}",
        va='center', ha='center', fontsize=12
    )

    fig.subplots_adjust(bottom=0.25)
    propriedades = {"r":r, "l":l, "Nf":Nf, "n":n, "area":area_fibras, "contador":contador_fibras_dentro_VC}
    plots = [contorno_VC, fibras, linhas, anotacoes, texto]

    ## Slider da distancia entre fibras
    #slider_distancia_fibras_ax = fig.add_axes([0.2, 0.10, 0.65, 0.03], autoscale_on=True)
    #slider_distancia_fibras = Slider(slider_distancia_fibras_ax, '$\ell [\mu m]$\n{$0\leq\ell\leq2r$}', l_min, l_max, valinit=0)
    #slider_distancia_fibras.label.set_size(14)
    #slider_distancia_fibras.label.set_multialignment('center')
    #slider_distancia_fibras.on_changed(lambda x: update_slider_distancia_fibras(x, fig, ax, propriedades, plots))

    # Slider do numero de fibras np.array(range( n, ))**2
    numeros_fibras_possiveis = np.array( range(int(np.sqrt(N_min)), int(np.sqrt(N_max))+1, 2) )**2
    slider_numero_fibras_ax = fig.add_axes([0.2, 0.175, 0.65, 0.03], autoscale_on=True)
    slider_numero_fibras = Slider(slider_numero_fibras_ax, "$N_{f}$", N_min, N_max, valinit=1, valstep=numeros_fibras_possiveis)
    slider_numero_fibras.label.set_size(14)
    slider_numero_fibras.on_changed(lambda x: update_slider_numero_fibras(x, fig, ax, propriedades, plots))

    ## Configuracoes e escala dos axes
    text_ax.axis('off')
    ax.axis('off')
    ax.set_aspect(1)
    ax.set_xlim(-0.01*(2*R), (2*R)*1.01)
    ax.set_ylim(-0.01*(2*R), (2*R)*1.01)

    plt.show()

lista = [(9,5)]

def main():
    dados = {}
    dados["raio_fibras"] = 300
    dados["num_fibras_maximo"] = 35*35
    dados["distancia_fibras_maxima"] = 2 * dados["raio_fibras"]

    fig = plt.figure(figsize=(7,6))
    plotar_geral(dados, fig)
    
    
    #with open("dados.txt", "w+") as f:
    #    for i in lista:
    #        f.write(str(i))
    


if __name__ == "__main__":
    main()
