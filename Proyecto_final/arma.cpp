#include "arma.h"
#include <QGraphicsScene>

Arma::Arma(Rick *personaje, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(), personaje(personaje)
{

}

void Arma::disparar()
{
    QPointF principalpos = personaje->getpos();

    QGraphicsPixmapItem *proyectil = new QGraphicsPixmapItem(QPixmap(":/fuentes/entorno/Shot.png"));
    proyectil->setPos(principalpos.x(), principalpos.y());
    scene()->addItem(proyectil);

    QTimer *timerproy = new QTimer(this);
    connect(timerproy, &QTimer::timeout, this, [=]() {
        qreal velproy = 10.0;

        proyectil->setPos(proyectil->x() + velproy, proyectil->y());
        proyectil->setScale(0.5);

        if (proyectil->x() > scene()->sceneRect().right() || proyectil->y() > scene()->sceneRect().bottom()) {
            scene()->removeItem(proyectil);
            delete proyectil;
            timerproy->stop();
            timerproy->deleteLater();
        }
    });
    timerproy->start(30);
}
