#include "personajes.h"
#include "obstaculos.h"

Personajes::Personajes(QObject *parent)
    : QObject{parent}
{

    timer = new QTimer();

    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/fuentes/personajes/Rick.png");

    //dimensiones de las imagenes

    ancho = 85;
    alto = 80;

    timer->start(120);

    connect(timer,&QTimer::timeout,this,&Personajes::Actualizacion);
}

void Personajes::Actualizacion()
{
    columnas += 100;
    if(columnas >= 600)
    {
        columnas = 0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
    anpos = pos();

}

QRectF Personajes::boundingRect() const
{

    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

void Personajes::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    switch (diract) {
    case Left:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 200, ancho, alto);
        break;
    case Right:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 100, ancho, alto);
        break;
    case Up:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 0, ancho, alto);
        break;
    default:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 100, ancho, alto);
        break;
    }
}

void Personajes::checkcol()
{
    QList<QGraphicsItem*> collidingItemsList = collidingItems();

    for (QList<QGraphicsItem*>::iterator ptf = collidingItemsList.begin(); ptf != collidingItemsList.end(); ++ptf) {
        QGraphicsItem* item = *ptf;

        if (dynamic_cast<Obstaculos*>(item)) {
            setPos(anpos);
            return;
        }
    }
}


void Personajes::salto()
{
    if (!saltando) {

        qreal alsalto = 80.0;
        qreal velsalto = 7.0;

        setPos(pos().x(), pos().y() - alsalto);
        saltando = true;

        QTimer *tsalto = new QTimer(this);
        connect(tsalto, &QTimer::timeout, [=]() {
            setPos(pos().x(), pos().y() + velsalto);

            if (pos().y() >= yorig) {
                saltando = false;
                setPos(pos().x(), yorig);
                tsalto->stop();
                tsalto->deleteLater();
            }
        });

        tsalto->start(30);
    }
}

