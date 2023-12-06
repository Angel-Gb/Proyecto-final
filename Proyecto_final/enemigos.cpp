#include "enemigos.h"

Enemigos::Enemigos(const QString &spritePath, int x, int y, QObject *parent)
    : Personajes(spritePath, parent), timerDisparo(new QTimer(this))
{
    setPos(x, y);
    setScale(0.5);
    distanciamax = getinipos() + 10;
    direccion = 1;
    distanciarec = 0;

    connect(timer, &QTimer::timeout, this, &Enemigos::comportamiento);

    connect(timerDisparo, &QTimer::timeout, this, &Enemigos::disparar);
    timerDisparo->start(5000);
}


Enemigos::~Enemigos()
{
    timerDisparo->stop();
    timerDisparo->deleteLater();
}


qreal Enemigos::getinipos() const
{
    return pos().x();
}

void Enemigos::comportamiento()
{
    setPos(x() + (2 * direccion), y());
    distanciarec += 10;

    if (distanciarec >= distanciamax) {
        direccion *= -1;
        distanciarec = 0;
    }
}

void Enemigos::disparar()
{
    QGraphicsPixmapItem *proyectiln = new QGraphicsPixmapItem(QPixmap(":/fuentes/entorno/Shot.png"));
    proyectiln->setPos(pos());
    scene()->addItem(proyectiln);
    proyectiln->setScale(0.5);

    QTimer *timerpr = new QTimer(this);
    connect(timerpr, &QTimer::timeout, this, [=]() {
        qreal velProy = 5.0;
        proyectiln->setPos(proyectiln->x() + velProy, proyectiln->y());


        QList<QGraphicsItem*> colisiones = proyectiln->collidingItems();
        QList<QGraphicsItem*>::iterator it;

        for (it = colisiones.begin(); it != colisiones.end(); ++it) {
            QGraphicsItem* item = *it;

            if (Rick* rick = dynamic_cast<Rick*>(item)) {
                scene()->removeItem(rick);
                delete rick;

                scene()->removeItem(proyectiln);
                delete proyectiln;

                timerpr->stop();
                timerpr->deleteLater();
                return;
            }
        }

        if (proyectiln->x() > scene()->sceneRect().right() || proyectiln->y() > scene()->sceneRect().bottom()) {
            scene()->removeItem(proyectiln);
            delete proyectiln;
            timerpr->stop();
            timerpr->deleteLater();
        }
    });


    timerpr->start(100);
}


void Enemigos::movcircular(qreal radio, qreal velangular) {
    QTimer* tmovc = new QTimer(this);
    connect(tmovc, &QTimer::timeout, this, [=]() {
        qreal nuevaX = scene()->width() - radio * qCos(angulo) - boundingRect().width() / 2;
        qreal nuevaY = radio * qSin(angulo) + boundingRect().height() / 2;

        setPos(nuevaX, nuevaY);

        angulo += velangular;

        if (angulo >= 2 * M_PI) {
            angulo = 0.0;
        }
    });

    tmovc->start(30);
}

