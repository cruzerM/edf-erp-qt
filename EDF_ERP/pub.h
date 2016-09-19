#ifndef PUB_H
#define PUB_H


#include <QString>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "connexion.h"


class Pub
{
    int IdPub;
    double CoutPub;
    bool Statut;

public:
    Pub();
    bool validerCoutPub();
    QSqlQueryModel *afficherPubsNV();
    ///////////
    void setSTATUT(bool);
    void setIDPUB(int);

    bool getSTATUT();
    int getIDPUB();
    //////////

    Connexion C;

};





#endif // PUB_H
