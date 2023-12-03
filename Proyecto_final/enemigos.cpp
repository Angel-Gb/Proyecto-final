#include "enemigos.h"

Enemigos::Enemigos(const QString &spritePath,int x, int y, int tipoEnemigo, QObject *parent) : QObject(parent), QGraphicsPixmapItem()

{
    QPixmap enemigoPixmap(spritePath + QString::number(tipoEnemigo) + ".png");
    int width = enemigoPixmap.width() * 0.5;
    int height = enemigoPixmap.height() * 0.5;
    setPixmap(enemigoPixmap.scaled(width, height));
    setPos(x, y);
}
