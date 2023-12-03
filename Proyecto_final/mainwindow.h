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
#include "rick.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Juego juego;
    void cargarnivel();
    Rick *rick;
    float x,y,ancho,alto;

};
#endif // MAINWINDOW_H
