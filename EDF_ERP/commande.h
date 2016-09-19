#ifndef COMMANDE_H
#define COMMANDE_H

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


class Commande
{
    int IdCommande;
    double Somme;
    bool Statut;

public:
    Commande();
    bool validerCommande();
    QSqlQueryModel *afficherCommandesNV();

    /////////////
    void setSTATUT(bool);
    void setIDCOMMANDE(int);

    bool getSTATUT();
    int getIDCOMMANDE();
    /////////////

    Connexion C;
};

#endif // COMMANDE_H
