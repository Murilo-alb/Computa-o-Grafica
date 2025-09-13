#ifndef TELA_H
#define TELA_H

#include <QFrame>
#include <QMouseEvent>
#include <QTransform> // NOVO INCLUDE
#include "Objeto.h"

class Tela : public QFrame
{
    Q_OBJECT

public:
    explicit Tela(QWidget *parent = nullptr);

    void DisplayFile(QList<ObjetoGeometrico*> *file);
    void PoligonoAtual(Poligono *poligono);
    void setVisualizacao(const QPointF& centro, double zoom, double angulo);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QList<ObjetoGeometrico*> *displayFile = nullptr;
    Poligono *poligonoAtual = nullptr;

    // Parâmetros da Câmera/Visualização
    QPointF m_wc {0, 0};
    double m_zoom {500.0};
    double m_angulo {0.0};

    // Guarda a matriz de transformação inversa para converter os cliques do mouse
    QTransform m_matrizInversa;

signals:
    void objetoModificado();

};

#endif // TELA_H
