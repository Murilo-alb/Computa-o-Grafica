#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tela.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Passa o ponteiro da lista de objetos ('displayFile') para a tela de desenho ('Frame').
    ui->Frame->DisplayFile(&displayFile);

    // Define o item selecionado na lista de opções para a linha 2.
    ui->listWidget_opcoes->setCurrentRow(2);
}

MainWindow::~MainWindow()
{
    // Limpa todos os objetos na lista 'displayFile' para evitar vazamentos de memória.
    qDeleteAll(displayFile);

    // Limpa a lista em si, removendo todos os ponteiros.
    displayFile.clear();

    // Deleta o objeto da interface de usuário.
    delete ui;
}


void MainWindow::on_btn_novoPoligono_clicked()
{
    // Limpa o estado atual de construção, garantindo que nenhum polígono antigo seja modificado.
    poligonoEmConstrucao = nullptr;
    ui->Frame->PoligonoAtual(nullptr);

    contadorPoligonos++;
    QString nomePoligono = QString("Objeto_%1").arg(contadorPoligonos);

     // Adiciona o nome do novo polígono à lista de opções na interface.
    ui->listWidget_opcoes->addItem(nomePoligono);

    // Cria um novo objeto Poligono dinamicamente.
    Poligono *novoPoligono = new Poligono(nomePoligono);
    displayFile.append(novoPoligono);

     // Seleciona o novo item na lista de opções.
    ui->listWidget_opcoes->setCurrentRow(displayFile.size());

     // Define o novo polígono como o objeto em construção.
    this->poligonoEmConstrucao = novoPoligono;

    // Informa à tela de desenho qual polígono está sendo modificado.
    ui->Frame->PoligonoAtual(this->poligonoEmConstrucao);

    ui->Frame->update();
}


void MainWindow::on_btn_desenhar_clicked()
{
    // Percorre a lista usando um índice para evitar a cópia
    for (int i = 0; i < displayFile.size(); ++i) {
        ObjetoGeometrico* objeto = displayFile.at(i);
        if (objeto->getTipo() == POLIGONO) {
            Poligono* p = static_cast<Poligono*>(objeto);
            p->finalizar();
        }
    }

    // Chama o slot para desmarcar qualquer item da lista de opções.
    on_listWidget_opcoes_currentRowChanged(-1);

    poligonoEmConstrucao = nullptr;
    ui->Frame->PoligonoAtual(nullptr);
    ui->Frame->update();
}

void MainWindow::on_btn_reset_clicked()
{
    // Reseta o estado de construção.
    poligonoEmConstrucao = nullptr;
    ui->Frame->PoligonoAtual(nullptr);

    qDeleteAll(displayFile);
    displayFile.clear();
    contadorPoligonos = 0;
    ui->listWidget_opcoes->clear();
    ui->Frame->update();
}

void MainWindow::on_listWidget_opcoes_currentRowChanged(int currentRow)
{
     // Primeiro, deseleciona todos os objetos na lista.
    for (int i = 0; i < displayFile.size(); ++i) {
        displayFile.at(i)->deselecionar();
    }

    // Verifica se um item válido foi selecionado.
    if(currentRow >= 0 && currentRow < displayFile.size()){

        // Obtém o ponteiro do objeto selecionado na lista.
        ObjetoGeometrico *objetoSelecionado = displayFile.at(currentRow);

        objetoSelecionado->selecionar();

        if(objetoSelecionado->getTipo() == POLIGONO){
            poligonoEmConstrucao = static_cast<Poligono*>(objetoSelecionado);
            ui->Frame->PoligonoAtual(poligonoEmConstrucao);
        }
    }
     // Se a seleção for inválida (ex: -1), o estado de construção é limpo
    else {
        poligonoEmConstrucao = nullptr;
        ui->Frame->PoligonoAtual(nullptr);
    }

    ui->Frame->update();
}











