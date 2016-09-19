#ifndef BUDGET_H
#define BUDGET_H

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


class Budget
{
    int IdBudget;
    double BudgetGlobal;
    double MontantRevenus;
    double MontantDepenses;
    double TaxeRev;

public:

    Budget ();
    QString afficherDepenses();
    QString afficherRevenus();
    QString calculerBudgetGlobal();
    ////////////////////////
    void setIDBUDGET(int);
    void setBUDGETGLOB(double);
    void setMNTREV(double);
    void setMNTDEP(double);
    void setTAXEREV(double);


    int getIDBUDGET();
    double getBUDGETGLOB();
    double getMNTREV();
    double getMNTDEP();
    double getTAXEREV();
    ////////////////////////

    Connexion C;

};

#endif // BUDGET_H
