#include "enemigos.h"

Enemigos::Enemigos(const QString &spritePath, int x, int y, QObject *parent)
    : Personajes(spritePath, parent)
{
    setPos(x, y);
    setScale(0.5);
    distanciamax = getinipos() + 10;
    direccion = 1;
    distanciarec = 0;

    connect(timer, &QTimer::timeout, this, &Enemigos::comportamiento);


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
