#include "tela.h"
#include <QPainter> // Inclui a classe para realizar o desenho em 2D.


Tela::Tela(QWidget *parent) : QFrame(parent)
{
    // Define a área de desenho para rastrear os movimentos do mouse,
    // o que é útil para futuras interações (como arrastar objetos).
    setMouseTracking(true);

     // Como foi conversado em aula. Aplica um estilo de borda ao widget para visualizá-lo na interface.
    setFrameStyle(QFrame::Box | QFrame::Sunken);
}

// Recebe um ponteiro para a QList de objetos da classe MainWindow e o armazena. A classe Tela agora tem acesso à lista para desenhar.
void Tela::DisplayFile(QList<ObjetoGeometrico*> *file)
{
    this->displayFile = file;
}


// Recebe um ponteiro para o polígono que está sendo construído.
// A classe Tela usará este ponteiro para adicionar pontos a ele.
void Tela::PoligonoAtual(Poligono *poligono)
{
    this->poligonoAtual = poligono;
}

// Este método é chamado automaticamente pelo Qt sempre que o widget precisa ser redesenhado.
void Tela::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter pintar(this);

    // Define uma dica de renderização para melhorar a qualidade do desenho, suavizando bordas.
    pintar.setRenderHint(QPainter::Antialiasing);

     // Verifica se o ponteiro da lista de objetos é válido antes de tentar usá-lo.
    if (!displayFile) {
        return;
    }

     // Cria uma referência constante para evitar cópias desnecessárias do container do Qt.
    const QList<ObjetoGeometrico*>& lista = *displayFile;

    // Loop de desenho polimórfico: cada objeto sabe como se desenhar.
    for (const auto& objeto : lista)
    {
        objeto->desenhar(pintar);
    }
}

// Este método é chamado automaticamente quando um botão do mouse é pressionado dentro da área do widget.
void Tela::mousePressEvent(QMouseEvent *event)
{
     // Verifica se há um polígono em construção. Se não houver, o clique é ignorado.
    if (poligonoAtual)
    {
         // Obtém as coordenadas do clique do mouse em relação ao widget.
        QPoint coordenada = event->pos();
        poligonoAtual->addPonto(coordenada);
        update(); // Solicita um redesenho para mostrar o novo ponto
    }
}
