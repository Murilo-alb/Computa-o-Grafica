#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Inclui a classe base para a janela principal do Qt
#include "Objeto.h" // Inclui a definição da classe base para os objetos geométricos.

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    // Construtor: Inicializa a janela. O parâmetro 'parent' define o widget
    // pai, com 'nullptr' sendo o valor padrão para uma janela de nível superior.
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    // Slot acionado quando o botão 'btn_novoPoligono' é clicado.
    void on_btn_novoPoligono_clicked();

     // Slot acionado quando o botão 'btn_reset' é clicado.
    void on_btn_reset_clicked();

    // Slot acionado quando o botão 'btn_desenhar' é clicado.
    void on_btn_desenhar_clicked();

    // Slot acionado quando a linha selecionada em 'listWidget_opcoes' muda.
    // 'currentRow' contém o índice da nova linha selecionada.
    void on_listWidget_opcoes_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;

    // A lista principal que armazena todos os objetos a serem desenhados
    // na tela. É o "arquivo de exibição" (display file) do programa.
    QList<ObjetoGeometrico*> displayFile;

     // Um contador para nomear os novos polígonos de forma sequencial.
    int contadorPoligonos = 0;

    // Ponteiro para o polígono que está sendo construído no momento.
    // É usado para adicionar novos pontos ao polígono ativo.
    Poligono* poligonoEmConstrucao = nullptr;
};
#endif // MAINWINDOW_H
