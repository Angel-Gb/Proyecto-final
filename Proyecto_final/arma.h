#ifndef ARMA_H
#define ARMA_H

#include "rick.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Arma : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Arma(Rick *personaje, QObject *parent = nullptr);

public slots:
    void disparar();

private:
    Rick *personaje;
};

#endif // ARMA_H
