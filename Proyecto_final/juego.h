#ifndef JUEGO_H
#define JUEGO_H
#include <QList>
#include "obstaculos.h"
#include "enemigos.h"


class Juego
{

public:

    Juego();
    void crearplataformas(int nronivel);
    const QList<Obstaculos*>& getplataformas();
    void crearEnemigos(int nronivel);
    const QList<Enemigos*>& getenemigos();


private:

    QList<Obstaculos*> plataformas;
    QList<Enemigos*> enemigos;

};

#endif // JUEGO_H
