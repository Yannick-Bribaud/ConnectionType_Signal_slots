#include "Emetteur.h"

Emetteur::Emetteur(QObject *parent) : QObject(parent)
{

}

void Emetteur::emetSignal1() {
    emit signalSignal1();
}

void Emetteur::emetSignal2() {
    emit signalSignal2();
}
