#include "personajes.h"
#include "obstaculos.h"

Personajes::Personajes(const QString &spritePath, QObject *parent)
    : QObject{parent}
{
    timer = new QTimer();

    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(spritePath);

    //dimensiones de las imagenes

    ancho = 64;
    alto = 84;
    timer->start(120);

    connect(timer,&QTimer::timeout,this,&Personajes::Actualizacion);
}


void Personajes::Actualizacion()
{
    columnas += 64;
    if(columnas >= 250)
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
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, alto*2, ancho, alto);
        break;
    case Right:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, alto, ancho, alto);
        break;
    case Up:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 0, ancho, alto);
        break;
    case Down:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 0, ancho, alto);
        break;
    default:
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, alto, ancho, alto);
        break;
    }
}

void Personajes::gravedad()
{
    if (pos().y() < yorig) {
        velocidadY += 0.5;
        setPos(pos().x(), pos().y() + velocidadY);
        checkcol();
    } else {
        velocidadY = 0;
        setPos(pos().x(), yorig);
    }
}

void Personajes::salto()
{
    if (!saltando) {
        qreal alsalto  = 150.0;
        qreal velsalto  = 10.0;

        saltando = true;

        QTimer *tsalto = new QTimer(this);
        connect(tsalto, &QTimer::timeout, this, [=]() {
            qreal nuevalt = pos().y() - velsalto ;

            if (nuevalt < yorig - alsalto ) {
                nuevalt = yorig - alsalto ;
            }

            setPos(pos().x(), nuevalt);
            checkcol();
            gravedad();

            if (nuevalt >= yorig) {
                saltando = false;
                setPos(pos().x(), yorig);
                tsalto->stop();
                tsalto->deleteLater();
            }
        });

        tsalto->start(20);
    }
}


void Personajes::checkcol()
{
    QList<QGraphicsItem*> collidingItemsList = collidingItems();

    for (QList<QGraphicsItem*>::iterator ptf = collidingItemsList.begin(); ptf != collidingItemsList.end(); ++ptf) {
        QGraphicsItem* item = *ptf;

        if (dynamic_cast<Obstaculos*>(item)) {
            saltando = false;


            if (dynamic_cast<Obstaculos*>(item)) {
                qreal nuevaY = item->pos().y() - boundingRect().height()/4;
                yorig = nuevaY;
                setPos(pos().x(), nuevaY);

            }

            return;
        }
    }
}
