#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "personajes.h"

class Enemigos : public Personajes
{
    Q_OBJECT

public:

    Enemigos(const QString &spritePath, int x, int y, QObject *parent = nullptr);
    qreal getinipos() const;



public slots:

private slots:
    void comportamiento();


private:

    int direccion;
    int distanciarec;
    int distanciamax;

};

#endif // ENEMIGOS_H
