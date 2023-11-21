#ifndef JUEGO_H
#define JUEGO_H
#include "obstaculos.h"
#include <QList>


class Juego
{
public:
    Juego();
    void crearplataformas(int nronivel);
    const QList<Obstaculos*>& getplataformas();


private:
    QList<Obstaculos*> plataformas;
};

#endif // JUEGO_H
