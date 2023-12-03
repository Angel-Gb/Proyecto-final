#ifndef JUEGO_H
#define JUEGO_H
#include "obstaculos.h"
#include "enemigos.h"
#include <QList>


class Juego
{

public:

    Juego();
    void crearplataformas(int nronivel);
    const QList<Obstaculos*>& getplataformas();
    void crearEnemigos(int nronivel);
    QList<Enemigos*> obtenerEnemigos() const { return enemigos; }


private:

    QList<Obstaculos*> plataformas;
    QList<Enemigos*> enemigos;

};

#endif // JUEGO_H
