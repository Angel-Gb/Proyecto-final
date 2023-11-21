#ifndef SPRITES_H
#define SPRITES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class sprites : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit sprites(QObject *parent = nullptr);



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

#endif // SPRITES_H
