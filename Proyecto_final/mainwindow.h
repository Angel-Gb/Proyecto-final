#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QRect>
#include <QScreen>
#include <QApplication>
#include "juego.h"

#include "personajes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Juego juego;
    void cargarnivel();


    Personajes *Rick;

    float x,y,ancho,alto;

};
#endif // MAINWINDOW_H
