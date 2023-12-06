#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cargarnivel();
    arma = new Arma(rick);
    scene->addItem(arma);
    arma->startTimer(30);
}

void MainWindow::cargarnivel()
{
    QPixmap background(":/fuentes/entorno/B" + QString::number(nronivel) + ".png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette back;

    back.setBrush(QPalette::Window, background);
    this->setPalette(back);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setStyleSheet("background: transparent;");
    ui->graphicsView->setFrameStyle(QFrame::NoFrame);
    scene->setBackgroundBrush(Qt::transparent);
    ui->graphicsView->setScene(scene);


    juego.crearplataformas(nronivel);
    for (Obstaculos* plataforma : juego.getplataformas())  {
        scene->addItem(plataforma);
    }

    cargarpersonajes();

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    scene->setSceneRect(0, 0, 800, 500);
    QPointF actualp = rick->pos();
    qreal ran = 10.0;
    QRectF limitemov = scene->sceneRect();

    switch (event->key()) {
    case Qt::Key_A:
        if (actualp.x() - ran >= limitemov.left()){
            rick->setPos(actualp.x() - ran, actualp.y());
            rick->diract = Personajes::Left;
            rick->checkcol();

        }
        break;
    case Qt::Key_D:
        if (actualp.x() + ran <= limitemov.right()){
            rick->setPos(actualp.x() + ran, actualp.y());
            rick->diract = Personajes::Right;
            rick->checkcol();

        }
        break;
    case Qt::Key_W:
        if (actualp.y() - ran >= limitemov.top()){
            rick->setPos(actualp.x(), actualp.y() - ran);
            rick->salto();
            rick->checkcol();
            rick->gravedad();

        }
        break;
    case Qt::Key_S:
        if (actualp.y() + ran <= limitemov.bottom()){
            rick->setPos(actualp.x(), actualp.y() + ran);
            rick->checkcol();
        }
        break;
    case Qt::Key_Space:
        arma->disparar();
        break;
    default:
        rick->diract = Personajes::Up;
        break;
    }
}



void MainWindow::cargarpersonajes()
{

    juego.crearEnemigos(nronivel);
    for (Enemigos* enemigo : juego.getenemigos()) {
        scene->addItem(enemigo);
    }

    rick = new Rick(":/fuentes/personajes/Rick.png");
    scene->addItem(rick);
    rick->setPos(100, 500);
    rick->setScale(0.5);

}



MainWindow::~MainWindow()
{
    delete ui;
}
