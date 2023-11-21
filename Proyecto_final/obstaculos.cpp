#include "obstaculos.h"

Obstaculos::Obstaculos(int x, int y, int plataformaN) : QGraphicsPixmapItem()

{
    QPixmap plataformaPixmap(":/fuentes/entorno/P" + QString::number(plataformaN) + ".png");
    int width = plataformaPixmap.width() * 0.5;
    int height = plataformaPixmap.height() * 0.5;
    setPixmap(plataformaPixmap.scaled(width, height));
    setPos(x, y);

}
