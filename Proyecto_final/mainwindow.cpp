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
    int nronivel=2;

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
    Rick->setPos(200,530);
    //
//    QTimer *gameTimer = new QTimer(this);
//    connect(gameTimer, &QTimer::timeout, Rick, &Personajes::Actualizacion);
//    gameTimer->start(16); // Comienza el bucle del juego para actualizar a 60 FPS

}

MainWindow::~MainWindow()
{
    delete ui;
}
