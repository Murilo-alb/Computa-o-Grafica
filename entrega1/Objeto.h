#ifndef OBJETO_H
#define OBJETO_H


// Inclui as classes do Qt necessárias para gerenciar strings, listas, pontos e desenho.
#include <QString>
#include <QList>
#include <QPoint>
#include <QPainter>
#include <QPen>


// Define um tipo enumerado para classificar os objetos geométricos.
// Isso é útil para determinar o tipo de um objeto em tempo de execução.
enum TipoObjeto {
    PONTO,
    RETA,
    POLIGONO
};

// Esta é a classe base abstrata para todos os objetos na nossa "cena" gráfica.
// Ela define a interface comum.
class ObjetoGeometrico
{
public:
    ObjetoGeometrico(const QString& nome, TipoObjeto tipo) : nome(nome), tipo(tipo) {}

// Destrutor virtual: Garante que os destrutores das classes filhas
    virtual ~ObjetoGeometrico() {}

    // As classes filhas (Ponto, Reta, Poligono) são obrigadas a fornecer sua própria implementação para esta função.
    virtual void desenhar(QPainter& pintar) = 0;

    void addPonto(const QPoint& p) {
        pontos.append(p);
    }

    QString getNome() const { return nome; }
    TipoObjeto getTipo() const { return tipo; }
    const QList<QPoint>& getPontos() const { return pontos; }

    void selecionar(){
        this->selecionado = true;
    }
    void deselecionar(){
        this->selecionado = false;
    }

    // Membros de dados protegidos, acessíveis pelas classes filhas.
    protected:
    QString nome;
    TipoObjeto tipo;
    QList<QPoint> pontos;


    bool selecionado = false;
};

// Representa um único ponto no plano.
class Ponto : public ObjetoGeometrico
{
public:
    Ponto(const QString& nome, const QPoint& p) : ObjetoGeometrico(nome, PONTO) {
        pontos.append(p);
    }

    // Implementação do método virtual "desenhar".
    void desenhar(QPainter& pintar) override {
        if (pontos.isEmpty()) return;
        pintar.setPen(QPen(Qt::red, 5));
        pintar.drawPoint(pontos.first());
    }
};

// Representa uma reta definida por dois pontos.
class Reta : public ObjetoGeometrico
{
public:
    Reta(const QString& nome, const QPoint& p1, const QPoint& p2) : ObjetoGeometrico(nome, RETA) {
        pontos.append(p1);
        pontos.append(p2);
    }

    void desenhar(QPainter& pintar) override {
        if (pontos.size() < 2)
        return;
        pintar.setPen(QPen(Qt::green, 2));
        pintar.drawLine(pontos[0], pontos[1]);
    }


};

// Representa um polígono, que pode ser uma forma fechada ou aberta.
class Poligono : public ObjetoGeometrico
{
public:
    Poligono(const QString& nome) : ObjetoGeometrico(nome, POLIGONO), finalizado(false) {}

    // Método que marca o polígono como finalizado, permitindo que ele seja desenhado
    // como uma forma fechada.
    void finalizar() {
        this->finalizado = true;
    }

    // Se o polígono estiver finalizado e tiver mais de 1 ponto, ele é desenhado como uma forma fechada.
    void desenhar(QPainter& pintar) override {
        if (pontos.isEmpty())
            return;

        if (finalizado && pontos.size() > 1) {
            pintar.setPen(QPen(Qt::blue, 2));
            pintar.drawPolygon(pontos.constData(), pontos.size());
        }

        if(this->selecionado){
            pintar.setPen(QPen(Qt::yellow, 7));
        }else{
            pintar.setPen(QPen(Qt::red, 5));
        }
        pintar.setPen(QPen(Qt::red, 5));
        for(const QPoint& ponto : pontos) {
            pintar.drawPoint(ponto);
        }
    }

private:
    bool finalizado;

};

#endif // OBJETO_H
