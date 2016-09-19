#ifndef PROJETS_H
#define PROJETS_H


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


class Projet
{
    int IdProjet;
    double BudgetProjet;
    bool Statut;

public:

    Projet();
    bool validerBudgetProjet();
    QSqlQueryModel *afficherProjetsNV();

    ///////////
    int getIDPROJET();
    double getBUDPROJ();
    bool getSTATUT();

    void setIDPROJET(int);
    void setBUDPROJ(double);
    void setSTATUT(bool);
    ///////////

    Connexion C;

};


#endif // PROJETS_H
