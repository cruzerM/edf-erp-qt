#ifndef ACTIONNAIRE_H
#define ACTIONNAIRE_H

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
#include "budget.h"


class Actionnaire
{
    int IdActionnaire;
    QString NomActionnaire;
    int TauxDividende;
    double Montant;
    QString DateAchat;
    bool Statut;

public:

    Actionnaire ();
    bool ajouterActionnaire();
    bool supprimerActionnaire();
    bool supprimerTTActionnaire();
    bool modifierActionnaire();
    bool validerActionnaire();
    double calculerDividende();
    int calculerDuree();
    bool afficherActionnaire();
    bool verifierExistenceActionnaire();
    QSqlQueryModel *afficherHistoriqueActionnaire();
    QSqlQueryModel *afficherActionnaireNV();
    /////////////////////
    void setIDACTIONNAIRE(int);
    void setNOMACTIONN(QString);
    void setTDIV(int);
    void setMNT(double);
    void setDATEACHAT(QString);
    void setSTATUT(bool);

    int getIDACTIONNAIRE();
    QString getNOMACTIONN();
    int getTDIV();
    double getMNT();
    QString getDATEACHAT();
    bool getSTATUT();
    //////////////////////

    Connexion C;
};

#endif // ACTIONNAIRE_H
