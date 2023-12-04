#include "rick.h"
#include <QGraphicsScene>

Rick::Rick(const QString &spritePath, QObject *parent) : Personajes(spritePath, parent)
{

}

QPointF Rick::getpos() const
{
    return pos();
}
