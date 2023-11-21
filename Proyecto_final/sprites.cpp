#include "sprites.h"

sprites::sprites(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer();

    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/fuentes/personajes/Rick-final.png");

    //dimenciones de las imagenes

    ancho = 100;
    alto = 100;

    timer->start(120);

    connect(timer,&QTimer::timeout,this,&sprites::Actualizacion);
}

void sprites::Actualizacion()
{
    columnas += 100;
    if(columnas >= 600)
    {
        columnas = 0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF sprites::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void sprites::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}


