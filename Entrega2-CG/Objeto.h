#ifndef OBJETO_H
#define OBJETO_H

#include <QString>
#include <QList>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QPointF>
#include <cmath>

enum TipoObjeto {
    PONTO,
    RETA,
    POLIGONO
};

struct Matriz3x3 {
    float m[3][3];

    Matriz3x3() {
        setIdentidade();
    }

    void setIdentidade() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m[i][j] = (i == j) ? 1.0f : 0.0f;
            }
        }
    }

    void multiplicar(const Matriz3x3& B) {
        Matriz3x3 resultado;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                resultado.m[i][j] = m[i][0] * B.m[0][j] + m[i][1] * B.m[1][j] + m[i][2] * B.m[2][j];
            }
        }
        *this = resultado;
    }

    QPointF transformarPonto(const QPointF& p) const {
        float x = p.x();
        float y = p.y();
        float novoX = x * m[0][0] + y * m[1][0] + 1 * m[2][0];
        float novoY = x * m[0][1] + y * m[1][1] + 1 * m[2][1];
        return QPointF(novoX, novoY);
    }
};

class ObjetoGeometrico
{
public:
    ObjetoGeometrico(const QString& nome, TipoObjeto tipo);
    virtual ~ObjetoGeometrico() {}

    virtual void desenhar(QPainter& pintar, const Matriz3x3& matrizVisualizacao) = 0;
    virtual QPointF getCentroGeometrico() const = 0;

    void addPonto(const QPoint& p);
    QString getNome() const;
    TipoObjeto getTipo() const;
    const QList<QPoint>& getPontos() const;

    void selecionar();
    void deselecionar();

    void transladar(double dx, double dy);
    void escalar(double sx, double sy);
    void rotacionar(double angulo, const QPointF& pivo);

    QPointF getTotalTranslacao() const;
    QPointF getTotalEscala() const;
    double getTotalRotacao() const;

protected:
    QString nome;
    TipoObjeto tipo;
    QList<QPoint> pontos;
    Matriz3x3 m_transform;
    QPointF m_total_translacao = QPointF(0, 0);
    QPointF m_total_escala = QPointF(1.0, 1.0);
    double m_total_rotacao = 0.0;
    bool selecionado = false;
};

class Ponto : public ObjetoGeometrico
{
public:
    Ponto(const QString& nome, const QPoint& p);
    void desenhar(QPainter& pintar, const Matriz3x3& matrizVisualizacao) override;
    QPointF getCentroGeometrico() const override;
};

class Reta : public ObjetoGeometrico
{
public:
    Reta(const QString& nome, const QPoint& p1, const QPoint& p2);
    void desenhar(QPainter& pintar, const Matriz3x3& matrizVisualizacao) override;
    QPointF getCentroGeometrico() const override;
};

class Poligono : public ObjetoGeometrico
{
public:
    Poligono(const QString& nome);
    void finalizar();
    void desenhar(QPainter& pintar, const Matriz3x3& matrizVisualizacao) override;
    QPointF getCentroGeometrico() const override;
private:
    bool finalizado;
};

#endif // OBJETO_H
