#include "Recepteur.h"
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QMetaMethod>

Recepteur::Recepteur(QObject *parent) : QObject(parent)
{

}

void Recepteur::onSignal() {
    QString signalName = QObject::sender()->metaObject()->method(QObject::senderSignalIndex()).name();
    qDebug() << QString("Signal %1 reçu le %2").arg(signalName).arg(QDateTime::currentMSecsSinceEpoch());
}

