#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class Personajes : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Personajes(QObject *parent = nullptr);


    enum Dir { None, Left, Right, Up, Down };
    Dir diract;

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;
    float ancho;
    float alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Actualizacion();

};
#endif // PERSONAJES_H
