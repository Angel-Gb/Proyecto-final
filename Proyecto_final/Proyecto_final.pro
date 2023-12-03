QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arma.cpp \
    enemigos.cpp \
    juego.cpp \
    main.cpp \
    mainwindow.cpp \
    objeto_grafico.cpp \
    obstaculos.cpp \
    personajes.cpp \
    rick.cpp

HEADERS += \
    arma.h \
    enemigos.h \
    juego.h \
    mainwindow.h \
    objeto_grafico.h \
    obstaculos.h \
    personajes.h \
    rick.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    graficos.qrc

DISTFILES += \
    fuentes/personajes/Enemy Blerg.png \
    fuentes/personajes/Enemy Flargo.png \
    fuentes/personajes/Enemy Gagigabber.png \
    fuentes/personajes/Enemy Mortydrangea.png \
    fuentes/personajes/Enemy Prax.png \
    fuentes/personajes/Enemy Scary Terry.png \
    fuentes/personajes/Enemy Shmupiedoop.png \
    fuentes/personajes/Enemy Xqutoopikk.png


