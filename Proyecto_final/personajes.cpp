#include "personajes.h"

Personajes::Personajes(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer();

    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/fuentes/personajes/Rick.png");

    //dimenciones de las imagenes

    ancho = 100;
    alto = 100;

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
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 0, ancho, alto);
        break;
    }
}
