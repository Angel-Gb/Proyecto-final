#include "juego.h"
#include <QPixmap>
#include <QApplication>
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

        int disty = 80;
        int distx = 250;

        for (int i = 1; i < 8; i++) {
            if (i%2==0){
                x -= distx * 2;
            }
            Obstaculos* plataforma = new Obstaculos(x, y, i);
            plataformas.append(plataforma);
            Obstaculos* plataforma2 = new Obstaculos(x+distx, y+disty, i + 1);
            plataformas.append(plataforma2);
            x += distx;
            y += disty;
        }
    }
}

const QList<Obstaculos*>& Juego::getplataformas()
{
    return plataformas;
}

