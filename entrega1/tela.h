#ifndef TELA_H
#define TELA_H

#include <QFrame> // Classe base para um widget que pode ter uma moldura.
#include <QMouseEvent> // Usada para lidar com eventos do mouse.
#include "Objeto.h" // Inclui a classe base ObjetoGeometrico e suas derivadas.


class Tela : public QFrame
{
     Q_OBJECT

public:
     explicit Tela(QWidget *parent = nullptr);

    // Método para passar o ponteiro da lista de objetos que devem ser desenhados.
    // Ele recebe um ponteiro para a QList<ObjetoGeometrico*> que está em MainWindow.
     void DisplayFile(QList<ObjetoGeometrico*> *file);

     // Método para definir qual polígono está sendo construído no momento.
     // É usado para adicionar novos pontos ao clicar na tela.
     void PoligonoAtual(Poligono *poligono);

 protected:
     void paintEvent(QPaintEvent *event) override;
     void mousePressEvent(QMouseEvent *event) override;

 private:
     QList<ObjetoGeometrico*> *displayFile = nullptr;
     Poligono *poligonoAtual = nullptr;

};

#endif // TELA_H
