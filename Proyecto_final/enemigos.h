#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "personajes.h"
#include "arma.h"

class Enemigos : public Personajes
{
    Q_OBJECT

public:

    Enemigos(const QString &spritePath, int x, int y, QObject *parent = nullptr);
    ~Enemigos();
    qreal getinipos() const;
    void disparar();

public slots:

private slots:
    void comportamiento();


private:

    int direccion;
    int distanciarec;
    int distanciamax;
    QTimer *timerDisparo;
};

#endif // ENEMIGOS_H
