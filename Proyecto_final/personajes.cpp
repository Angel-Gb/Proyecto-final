#include "Personajes.h"

Personajes::Personajes(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer();

    //timer->start(); // Iniciar el temporizador
    //velocidadY = 0; // Inicializar la velocidad vertical

    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/fuentes/personajes/Rick.png");

    //dimenciones de las imagenes

    ancho = 100;
    alto = 100;

    timer->start(120);

    connect(timer,&QTimer::timeout,this,&Personajes::Actualizacion);
}

void Personajes::Actualizacion()
{

//    const float deltaTime = 120.0 / 1000.0; // Convertimos ms a segundos


//    // Aplicar gravedad
//    velocidadY += gravedad * deltaTime;
//    float newY = y() + velocidadY * deltaTime;
//    // Detectar colisiones
//    QList<QGraphicsItem *> itemsColisionados = scene()->collidingItems(this);
//    bool enElSuelo = false;
//    foreach (QGraphicsItem *item, itemsColisionados) {
//        //determinar cómo identificar el suelo u otros elementos con los que colisiona
//        if (/* item es el suelo u obstáculo */) {
//            enElSuelo = true;
//            newY = /* altura del suelo */ - boundingRect().height(); // Ajustar la posición Y
//            velocidadY = 0; // Detener la caída
//            emit tocandoSuelo(); // Emitir la señal si es necesario
//        break;
//    }
//}

//    // Aplicar la nueva posición
//    if (!enElSuelo) {
//    setPos(x(), newY);
//    }

    //
    columnas += 100;
    if(columnas >= 600)
    {
        columnas = 0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Personajes::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Personajes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,100,ancho,alto);
}
