#include "arma.h"
#include <QGraphicsScene>
Arma::Arma(Rick *personaje, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(), personaje(personaje)
{


}

void Arma::disparar()
{
    QPointF principalpos = personaje->getpos();
    Personajes::Dir direccionDisparo = personaje->diract;
    QGraphicsPixmapItem *proyectil = new QGraphicsPixmapItem(QPixmap(":/fuentes/entorno/ShotN.png"));
    proyectil->setPos(principalpos.x(), principalpos.y());
    proyectil->setScale(0.5);

    scene()->addItem(proyectil);

    QTimer *timerproy = new QTimer(this);
    connect(timerproy, &QTimer::timeout, this, [=]() {
        qreal velproy = 10.0;

        switch (direccionDisparo) {
        case Personajes::Left:
            proyectil->setPos(proyectil->x() - velproy, proyectil->y());
            break;
        case Personajes::Right:
            proyectil->setPos(proyectil->x() + velproy, proyectil->y());
            break;
        default:
            break;
        }

        QList<QGraphicsItem*> colisiones = proyectil->collidingItems();
        QList<QGraphicsItem*>::iterator it;

        for (it = colisiones.begin(); it != colisiones.end(); ++it) {
            QGraphicsItem* item = *it;

            if (Enemigos* enemigo = dynamic_cast<Enemigos*>(item)) {
                scene()->removeItem(enemigo);
                delete enemigo;

                scene()->removeItem(proyectil);
                delete proyectil;

                timerproy->stop();
                timerproy->deleteLater();
                return;
            }
        }

        if (proyectil->x() > scene()->sceneRect().right() || proyectil->y() > scene()->sceneRect().bottom()) {
            scene()->removeItem(proyectil);
            delete proyectil;
            timerproy->stop();
            timerproy->deleteLater();
        }
    });
    timerproy->start(30);
}

