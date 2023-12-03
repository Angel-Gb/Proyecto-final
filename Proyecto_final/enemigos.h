#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>


class Enemigos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Enemigos(const QString &spritePath, int x, int y, int tipoEnemigo, QObject *parent = nullptr);

public slots:

};

#endif // ENEMIGOS_H
