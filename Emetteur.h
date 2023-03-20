#ifndef EMETTEUR_H
#define EMETTEUR_H

#include <QObject>

class Emetteur : public QObject
{
    Q_OBJECT
public:
    explicit Emetteur(QObject *parent = nullptr);
    void emetSignal1();
    void emetSignal2();

signals:
    void signalSignal1();
    void signalSignal2();

public slots:
};

#endif // EMETTEUR_H
