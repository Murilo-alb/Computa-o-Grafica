#include "tela.h"
#include <QPainter>

// Declaração antecipada das funções globais que estão em objeto.cpp
Matriz3x3 criarMatrizTranslacao(float dx, float dy);
Matriz3x3 criarMatrizRotacao(float angulo);
Matriz3x3 criarMatrizEscala(float sx, float sy);

// Função auxiliar para converter nossa Matriz3x3 para uma QTransform do Qt
QTransform MatrizParaQTransform(const Matriz3x3& matriz) {
    // A ordem dos parâmetros no construtor do QTransform é (m11, m12, m21, m22, dx, dy)
    // Onde m11, m12, etc, se referem à matriz de transformação linear 2x2
    // e dx, dy são os fatores de translação.
    return QTransform(matriz.m[0][0], matriz.m[0][1],
                      matriz.m[1][0], matriz.m[1][1],
                      matriz.m[2][0], matriz.m[2][1]);
}


Tela::Tela(QWidget *parent) : QFrame(parent)
{
    setMouseTracking(true);
    setFrameStyle(QFrame::Box | QFrame::Sunken);
}

void Tela::DisplayFile(QList<ObjetoGeometrico*> *file)
{
    this->displayFile = file;
}

void Tela::PoligonoAtual(Poligono *poligono)
{
    this->poligonoAtual = poligono;
}

void Tela::setVisualizacao(const QPointF& centro, double zoom, double angulo)
{
    m_wc = centro;
    m_zoom = zoom;
    m_angulo = angulo;
    update(); // Força um redesenho com os novos parâmetros
}

void Tela::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter pintar(this);
    pintar.setRenderHint(QPainter::Antialiasing);

    if (!displayFile) {
        return;
    }

    // 1. Define o Viewport (usando o tamanho do widget)
    double xv_min = 0, yv_min = 0;
    double xv_max = this->width(), yv_max = this->height();

    // Proteção contra divisão por zero se a janela for muito pequena
    if (yv_max == 0) return;

    // 2. Calcula o tamanho da Window com base no zoom e no aspect ratio do viewport
    double window_height = m_zoom;
    double window_width = m_zoom * (xv_max / yv_max);

    // Proteção contra divisão por zero se a window for muito pequena
    if (window_width == 0 || window_height == 0) return;

    // 3. Monta a matriz de transformação de visualização (composta)
    Matriz3x3 matrizVisualizacao;

    // Passo A: Transladar o mundo para que o centro da window (m_wc) vá para a origem
    matrizVisualizacao.multiplicar(criarMatrizTranslacao(-m_wc.x(), -m_wc.y()));

    // Passo B: Rotacionar o mundo ao redor da origem com o ângulo inverso da câmera
    matrizVisualizacao.multiplicar(criarMatrizRotacao(-m_angulo));

    // Passo C: Escalar para mapear a window para o viewport (e inverter o Y)
    double sx = (xv_max - xv_min) / window_width;
    double sy = (yv_min - yv_max) / window_height; // Y invertido!
    matrizVisualizacao.multiplicar(criarMatrizEscala(sx, sy));

    // Passo D: Transladar para a posição final do viewport na tela
    double tx = (xv_max + xv_min) / 2.0;
    double ty = (yv_max + yv_min) / 2.0;
    matrizVisualizacao.multiplicar(criarMatrizTranslacao(tx, ty));

    // Converte para QTransform e calcula a inversa para usar nos cliques do mouse
    QTransform qtTransform = MatrizParaQTransform(matrizVisualizacao);
    m_matrizInversa = qtTransform.inverted();

    // Loop de desenho: cada objeto recebe a matriz e se desenha
    const QList<ObjetoGeometrico*>& lista = *displayFile;
    for (const auto& objeto : lista)
    {
        objeto->desenhar(pintar, matrizVisualizacao);
    }
}

void Tela::mousePressEvent(QMouseEvent *event)
{
    if (poligonoAtual)
    {
        // Pega a coordenada do clique (em pixels da tela)
        QPoint coordenadaDoMouse = event->pos();

        // Converte a coordenada da tela de volta para a coordenada do mundo
        QPointF coordenadaDoMundo = m_matrizInversa.map(coordenadaDoMouse);

        // Adiciona o ponto convertido ao polígono
        poligonoAtual->addPonto(coordenadaDoMundo.toPoint());

        // Avisa a MainWindow que o objeto mudou
        emit objetoModificado();

        // Pede para a tela se redesenhar
        update();
    }
}
