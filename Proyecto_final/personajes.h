#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>



class Personajes : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Personajes(QObject *parent = nullptr);

    /*
    float velocidadY; // Velocidad vertical del personaje
    static constexpr float gravedad = 9.8f; // Aceleración debida a la gravedad (ajustable)*/

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;
    float ancho;
    float alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    //void tocandoSuelo(); // Señal cuando el personaje toca el suelo

public slots:
    void Actualizacion();

};
#endif // PERSONAJES_H
