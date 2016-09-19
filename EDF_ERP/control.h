#ifndef CONTROL_H
#define CONTROL_H
#include <QString>
#include "connexion.h"
#include <QSqlQuery>
#include <QDebug>

class Control
{
    int Identifiant;
    QString Qualite;
    QString Echeances;
    QString Type;


public:

    Control();
    Control(int, QString, QString, QString);

    void setIdentifiant(int);
    int getIdentifiant();

    void setQualite(QString);
    QString getQualite();

    void setEcheances(QString);
    QString getEcheances();

    void setType(QString);
    QString getType();

    bool addControlCycle();
    bool controlExistance(int);
};



#endif // CONTROL_H
