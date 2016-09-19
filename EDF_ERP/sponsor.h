#ifndef SPONSOR_H
#define SPONSOR_H

#include <QString>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

#include "connexion.h"
#include "budget.h"



class Sponsor
{
    int IdSponsor;
    QString NomSponsor;
    double Somme;
    QString DateDebut;
    QString DateFin;
    int Duree;
    bool Statut;

public:

    Sponsor();
    bool ajouterSponsor();
    bool supprimerSponsor();
    bool supprimerTTSponsor();
    bool modifierSponsor();
    bool validerSponsor();
    bool afficherSponsor();
    void calculerDuree();
    bool verifierExistenceSponsor();
    QSqlQueryModel *afficherHistoriqueSponsor();
    QSqlQueryModel *afficherSponsorNV();
    //////////////////////
    void setIDSPONSOR(int);
    void setNOMSPONSOR(QString);
    void setSOMME(double);
    void setDATEDEBUT(QString);
    void setDATEFIN (QString);
    void setDUREE(int);
    void setSTATUT(bool);


    int getIDSPONSOR();
    QString getNOMSPONSOR();
    double getSOMME();
    QString getDATEDEBUT();
    QString getDATEFIN();
    int getDUREE();
    bool getSTATUT();
    //////////////////////

    Connexion C;

};


#endif // SPONSOR_H
