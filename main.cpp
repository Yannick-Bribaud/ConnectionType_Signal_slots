#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "Emetteur.h"
#include "Recepteur.h"

//Changer ici le numéro du TP
#define TP 8

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Emetteur e;
    Recepteur r;

    qDebug() << "TP n°" << TP;
    qDebug() << "";

#if(TP == 1 || TP == 5)
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::AutoConnection);
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::QueuedConnection);
#endif

#if(TP == 2 || TP == 6)
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::QueuedConnection);
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::QueuedConnection);
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, static_cast<Qt::ConnectionType>(Qt::QueuedConnection | Qt::UniqueConnection));
#endif

#if(TP == 3 || TP == 7)
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::QueuedConnection);
    QObject::connect(&e, &Emetteur::signalSignal2, &r, &Recepteur::onSignal, Qt::DirectConnection);
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::UniqueConnection);
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::QueuedConnection);
#endif

#if(TP == 4 || TP == 8)
    QObject::connect(&e, &Emetteur::signalSignal1, &r, &Recepteur::onSignal, Qt::BlockingQueuedConnection);
#endif

    e.emetSignal1();
    e.emetSignal2();

#if(TP < 5)
    qDebug() << "";
    qDebug() << "N'oubliez pas de forcer la fermeture de l'application...";
    qDebug() << "";
    return a.exec();
#endif
}
