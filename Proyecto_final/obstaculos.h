#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Obstaculos : public QGraphicsPixmapItem
{
public:
    Obstaculos(int x, int y, int plataformaN);
};

#endif // OBSTACULOS_H
