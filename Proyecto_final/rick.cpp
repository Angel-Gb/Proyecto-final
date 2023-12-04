#include "rick.h"
#include <QGraphicsScene>

Rick::Rick(const QString &spritePath, QObject *parent, Personajes::Dir dirInicial) : Personajes(spritePath, parent)
{
    diract = dirInicial;
}

QPointF Rick::getpos() const
{
    return pos();
}
