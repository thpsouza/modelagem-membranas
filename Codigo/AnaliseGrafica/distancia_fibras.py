import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button, RadioButtons


def calcular_propriedades():
    ...


def calcular_area_fibras(Nf, r):
    return Nf * np.pi * r**2


def calcular_empacotamento(area_fibras, lado_VC):
    return area_fibras/lado_VC**2


def plotar_VC(ax, pos, L, **kwargs):
    volume_de_controle = plt.Rectangle(
        pos, L, L,
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


def plotar_fibras(ax, r, n, l, fibras=None, **kwargs):
    if fibras is None:
        fibras = []
    for i in range(n):
        for j in range(n):
            pos = (l/2 + r + i*(l+2*r), l/2 + r + j*(l+2*r))
            fibra = plotar_fibra(ax, pos, r, **kwargs)
            fibras.append(fibra)
    return fibras


def plotar_linhas(ax, fibras, r, n):
    x0,y0 = fibras[0].center
    x1,y1 = fibras[1].center
    x2,y2 = fibras[n].center
    l1 = ax.plot((x0, x1), (y0+r, y1-r), '--', color='tab:grey')
    l2 = ax.plot((x0+r, x2-r), (y0, y2), '--', color='tab:grey')
    return (l1,l2), []


def update_VC(VC, L):
    VC.set_height(L)
    VC.set_width(L)


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
    r, l, n, area_fibras = propriedades.values()
    contorno_VC, fibras, linhas, anotacoes, texto = plots
    # Recalcular propriedades a partir da nova distância entre fibras
    propriedades["l"] = l = val
    L = (2*r + l) * n
    empacotamento = calcular_empacotamento(area_fibras, L)
    # Redefinir dimensões
    update_VC(contorno_VC, L)
    update_fibras(fibras, r, n, l)
    update_linhas(ax, fibras, linhas, anotacoes, r, n, l)
    # Reescrever textos
    texto.set_text(f"r = {r}$\mu$m,      L = {L:.2f}$\mu$m,      F.E. = {empacotamento:.4f}")
    # Reescale dinâmico com o lado do VC
    ax.set_xlim(-0.01*L, L*1.01)
    ax.set_ylim(-0.01*L, L*1.01)
    fig.canvas.draw_idle()


def update_slider_numero_fibras(val, fig, ax, propriedades, plots):
    r, l, n, area_fibras = propriedades.values()
    contorno_VC, fibras, linhas, anotacoes, texto = plots
    # Recalcular propriedades a partir do novo número de fibras
    N = val
    propriedades["n"] = n = int(N**(1/2))
    L = (2*r + l) * n
    propriedades["area"] = area_fibras = calcular_area_fibras(N, r)
    empacotamento = calcular_empacotamento(area_fibras, L)
    # Redefinir dimensões e plotar novamente as fibras
    update_VC(contorno_VC, L)
    limpar_fibras(fibras)
    plotar_fibras(ax, r, n, l, fibras=fibras)
    update_linhas(ax, fibras, linhas, anotacoes, r, n, l)
    # Reescrever textos
    texto.set_text(f"r = {r}$\mu$m,      L = {L:.2f}$\mu$m,      F.E. = {empacotamento:.4f}")
    # Reescale dinâmico com o lado do VC
    ax.set_xlim(-0.01*L, L*1.01)
    ax.set_ylim(-0.01*L, L*1.01)
    fig.canvas.draw_idle()


def plotar_geral(dados, fig):
    r = dados["raio_fibras"]
    N_max = dados["num_fibras_maximo"]
    l_max = dados["distancia_fibras_maxima"]
    ax = fig.add_subplot()

    ## Cálculos e definições das propriedades
    Nf = N_min = 4
    l = l_min = 0
    n = int(Nf**(1/2))
    L = (2*r + l) * n
    area_fibras = calcular_area_fibras(Nf, r)
    empacotamento = calcular_empacotamento(area_fibras, L)

    ## Plots
    contorno_VC = plotar_VC(ax, (0,0), L)
    fibras = plotar_fibras(ax, r, n, l)
    linhas, anotacoes = plotar_linhas(ax, fibras, r, n)

    ## Texto das propriedades
    fig.subplots_adjust(top=0.9)
    text_ax = fig.add_axes([0.185, 0.95, 0.65, 0.03], autoscale_on=True)
    texto = text_ax.text(
        0.5, 0.5, f"r = {r}$\mu$m,      L = {L:.2f}$\mu$m,      F.E. = {empacotamento:.4f}",
        va='center', ha='center', fontsize=12
    )

    fig.subplots_adjust(bottom=0.25)
    propriedades = {"r":r, "l":l, "n":n, "area":area_fibras}
    plots = [contorno_VC, fibras, linhas, anotacoes, texto]

    ## Slider da distancia entre fibras
    slider_distancia_fibras_ax = fig.add_axes([0.2, 0.10, 0.65, 0.03], autoscale_on=True)
    slider_distancia_fibras = Slider(slider_distancia_fibras_ax, '$\ell [\mu m]$\n{$0\leq\ell\leq2r$}', l_min, l_max, valinit=0)
    slider_distancia_fibras.label.set_size(14)
    slider_distancia_fibras.label.set_multialignment('center')
    slider_distancia_fibras.on_changed(lambda x: update_slider_distancia_fibras(x, fig, ax, propriedades, plots))

    # Slider do numero de fibras
    numeros_fibras_possiveis = np.array(range(int(np.sqrt(N_min)),int(np.sqrt(N_max))+1))**2
    slider_numero_fibras_ax = fig.add_axes([0.2, 0.175, 0.65, 0.03], autoscale_on=True)
    slider_numero_fibras = Slider(slider_numero_fibras_ax, "$N_{f}$", N_min, N_max, valinit=1, valstep=numeros_fibras_possiveis)
    slider_numero_fibras.label.set_size(14)
    slider_numero_fibras.on_changed(lambda x: update_slider_numero_fibras(x, fig, ax, propriedades, plots))

    ## Configuracoes e escala dos axes
    text_ax.axis('off')
    ax.axis('off')
    ax.set_aspect(1)
    ax.set_xlim(-0.01*L, L*1.01)
    ax.set_ylim(-0.01*L, L*1.01)

    plt.show()


def main():
    dados = {}
    dados["raio_fibras"] = 300
    dados["num_fibras_maximo"] = 100
    dados["distancia_fibras_maxima"] = 2 * dados["raio_fibras"]

    fig = plt.figure(figsize=(7,6))
    plotar_geral(dados, fig)


if __name__ == "__main__":
    main()
