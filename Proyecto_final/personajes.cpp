#include "personajes.h"
#include "obstaculos.h"
#include <QGraphicsScene>

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


void Personajes::checkcol()
{
    QList<QGraphicsItem*> collidingItemsList = collidingItems();

    for (QList<QGraphicsItem*>::iterator ptf = collidingItemsList.begin(); ptf != collidingItemsList.end(); ++ptf) {
        QGraphicsItem* item = *ptf;

        if (dynamic_cast<Obstaculos*>(item)) {
            saltando = false;
            setPos(anpos);
            return;
        }
    }
}


void Personajes::salto()
{
    if (!saltando) {

        qreal alsalto = 150;
        qreal velsalto = 7.0;

        setPos(pos().x(), pos().y() - alsalto);
        saltando = true;

        QTimer *tsalto = new QTimer(this);
        connect(tsalto, &QTimer::timeout, this, [=]() {
            setPos(pos().x(), pos().y() + velsalto);
            checkcol();
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
// nuevo
void Personajes::verificarColisionConProyectil() {
    QList<QGraphicsItem*> items = scene()->collidingItems(this);
    foreach(QGraphicsItem* item, items) {
        if (QVariant(item->data(0)).toString() == "proyectil") {
            // Suponiendo que cada proyectil quita 1 punto de vida
            puntosVida -= 1;
            scene()->removeItem(item);
            delete item;

            if (puntosVida <= 0) {
                // señal para manejar la eliminación
                emit personajeEliminado(this);  // Suponiendo que tienes esta señal en la clase Personajes
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}

 //llamar a este método en el ciclo principal
