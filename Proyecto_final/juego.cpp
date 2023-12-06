#include "juego.h"

Juego::Juego()
{

}

void Juego::crearplataformas(int nronivel)
{
    int x = 0;
    int y = 0;

    if (nronivel == 1) {

        int disty = 70;
        int distx = 80;

        for (int i = 1; i < 8; i++) {
            Obstaculos* plataforma = new Obstaculos(x, y, i);
            plataformas.append(plataforma);
            x += distx;
            y += disty;
        }
    }

    else if (nronivel == 2) {

        int disty = 70;
        int distx = 200;

        for (int i = 1; i < 8; i++) {
            if (i%2==0){
                x -= distx;
            }
            Obstaculos* plataforma = new Obstaculos(x, y, i);
            plataformas.append(plataforma);

            x += distx;
            y += disty;
        }
    }
}


const QList<Obstaculos*>& Juego::getplataformas()
{
    return plataformas;
}


void Juego::crearEnemigos(int nronivel)
{
    int x = 0;
    int y = 0;

    if (nronivel == 1) {

        int disty = 70;
        int distx = 80;

        for (int i = 1; i < 8; i++) {
            Enemigos* enemigo = new Enemigos(":/fuentes/personajes/Enemy" + QString::number(i) + ".png", x+10, y-20);
            enemigos.append(enemigo);
            x += distx;
            y += disty;
        }
    }

    else if (nronivel == 2) {

        int disty = 70;
        int distx = 200;

        for (int i = 7; i > 0; i--) {
            if (i%2==0){
                x -= distx;
            }

            Enemigos* enemigo = new Enemigos(":/fuentes/personajes/Enemy" + QString::number(i) + ".png", x+10, y-20);
            enemigos.append(enemigo);
            x += distx;
            y += disty;

        }
        Enemigos* enemigofinal = new Enemigos(":/fuentes/personajes/Enemy8.png", 20 , 20);
        enemigos.append(enemigofinal);

        enemigofinal->movcircular(50, 0.1);


    }
}

const QList<Enemigos*>& Juego::getenemigos()
{
    return enemigos;
}
