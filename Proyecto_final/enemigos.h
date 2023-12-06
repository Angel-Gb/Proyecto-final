#ifndef ENEMIGOS_H
#define ENEMIGOS_H
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
    void movcircular(qreal radio, qreal velangular);


public slots:

private slots:
    void comportamiento();


private:

    int direccion;
    int distanciarec;
    int distanciamax;
    QTimer *timerDisparo;
    qreal angulo=0.0;



};

#endif // ENEMIGOS_H
