#ifndef RECEPTEUR_H
#define RECEPTEUR_H

#include <QObject>

class Recepteur : public QObject
{
    Q_OBJECT
public:
    explicit Recepteur(QObject *parent = nullptr);

signals:

public slots:
    void onSignal();
};

#endif // RECEPTEUR_H
