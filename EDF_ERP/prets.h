#ifndef PRETS_H
#define PRETS_H

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
class Pret
{
    int IdPret;
    double MontantPret;
    QString DatePretD;
    QString DatePretF;
    QString NomBanque;
    QString Cause;
    double TauxInteret;
    double MontantFinal;
    bool Statut;

public:
    Pret();
    bool ajouterPret();
    bool supprimerPret();
    bool supprimerTTPret();
    bool modifierPret();
    bool validerPret();
    void calculerInteret();
    int calculerDureePret();
    bool afficherPret();
    bool verifierExistencePret();
    QSqlQueryModel *afficherHistoriquePret();
    QSqlQueryModel *afficherPretsNV();
    ////////////////////
    void setIDPRET(int);
    void setMONTPRET(double);
    void setDatePretD(QString);
    void setDatePretF(QString);
    void setNOMBANQUE(QString);
    void setCAUSE(QString);
    void setTINT(int);
    void setMONTF(double);
    void setSTATUT(bool);

    int getIDPRET();
    double getMONTPRET();
    QString getDatePretD();
    QString getDatePretF();
    QString getNOMBANQUE();
    QString getCAUSE();
    int getTINT();
    double getMONTF();
    bool getSTATUT();
    /////////////////////

    Connexion C;
};

#endif // PRETS_H
