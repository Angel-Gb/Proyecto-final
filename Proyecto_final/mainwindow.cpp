#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap background(":/fuentes/entorno/B1.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette back;
    back.setBrush(QPalette::Window, background);
    this->setPalette(back);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setStyleSheet("background: transparent;");
    scene->setBackgroundBrush(Qt::transparent);
    ui->graphicsView->setScene(scene);


    // Obtén la geometría de la pantalla principal
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = screenGeometry.x();
    int y = screenGeometry.y();
    int ancho = screenGeometry.width() - 100; // Ajusta según sea necesario
    int alto = screenGeometry.height() - 100; // Ajusta según sea necesario

    scene = new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    Donald = new sprites();
    scene->addItem(Donald);

    Donald->setPos(300,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

