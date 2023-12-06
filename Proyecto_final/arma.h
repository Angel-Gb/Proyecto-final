#ifndef ARMA_H
#define ARMA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include "enemigos.h"
#include "rick.h"

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
