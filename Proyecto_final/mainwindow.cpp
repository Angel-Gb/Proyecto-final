#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cargarnivel();

}

void MainWindow::cargarnivel()
{
    int nronivel=1;

    QPixmap background(":/fuentes/entorno/B" + QString::number(nronivel) + ".png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette back;
    back.setBrush(QPalette::Window, background);
    this->setPalette(back);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setStyleSheet("background: transparent;");
    scene->setBackgroundBrush(Qt::transparent);
    ui->graphicsView->setScene(scene);

    juego.crearplataformas(nronivel);
    for (Obstaculos* plataforma : juego.getplataformas())  {
        scene->addItem(plataforma);
    }

    Rick = new Personajes();
    scene->addItem(Rick);
    Rick->setPos(200,500);
    Rick->setScale(0.5);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    scene->setSceneRect(0, 0, 800, 500);
    QPointF actualp = Rick->pos();
    qreal ran = 10.0;
    QRectF limitemov = scene->sceneRect();

    switch (event->key()) {
    case Qt::Key_A:
        if (actualp.x() - ran >= limitemov.left()){
            Rick->setPos(actualp.x() - ran, actualp.y());
            Rick->diract = Personajes::Left;
            Rick->checkcol();

        }
        break;
    case Qt::Key_D:
        if (actualp.x() + ran <= limitemov.right()){
            Rick->setPos(actualp.x() + ran, actualp.y());
            Rick->diract = Personajes::Right;
            Rick->checkcol();

        }
        break;
    case Qt::Key_W:
        if (actualp.y() - ran >= limitemov.top()){
            Rick->setPos(actualp.x(), actualp.y() - ran);
            Rick->diract = Personajes::Up;
            Rick->checkcol();
            Rick->salto();
        }
        break;
    case Qt::Key_S:
        if (actualp.y() + ran <= limitemov.bottom()){
            Rick->setPos(actualp.x(), actualp.y() + ran);
            Rick->checkcol();
}
        break;
    default:
        Rick->diract = Personajes::None;
        break;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
