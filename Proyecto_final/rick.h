#ifndef RICK_H
#define RICK_H
#include "personajes.h"

#include <QKeyEvent>

class Rick: public Personajes
{
    Q_OBJECT

public:
    explicit Rick(const QString &spritePath, QObject *parent = nullptr, Personajes::Dir dirInicial = Personajes::Up);
    QPointF getpos() const;


};

#endif // RICK_H
